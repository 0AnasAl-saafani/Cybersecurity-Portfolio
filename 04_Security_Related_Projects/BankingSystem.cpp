#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// هيكل الحساب البنكي
struct Account {
    string name;           // اسم العميل
    string phone;          // رقم الهاتف (مشفر)
    string accountNumber;  // رقم الحساب (مشفر)
    string password;       // كلمة السر (مشفر)
    string balanceStr;     // الرصيد (مشفر بالرموز الخاصة)
};

// --- دالات التشفير وفك التشفير للأرقام (الهاتف، الحساب، السر) ---
string encryptData(string input) {
    string encrypted = "";
    for (char c : input) {
        switch (c) {
            case '1': encrypted += '*'; break;
            case '2': encrypted += '&'; break;
            case '3': encrypted += '#'; break;
            case '4': encrypted += '$'; break;
            case '5': encrypted += '%'; break;
            case '6': encrypted += '^'; break;
            case '7': encrypted += '('; break;
            case '8': encrypted += ')'; break;
            case '9': encrypted += '?'; break;
            case '0': encrypted += '='; break;
            default: encrypted += c;
        }
    }
    return encrypted;
}

string decryptData(string input) {
    string decrypted = "";
    for (char c : input) {
        if (c == '*') decrypted += '1';
        else if (c == '&') decrypted += '2';
        else if (c == '#') decrypted += '3';
        else if (c == '$') decrypted += '4';
        else if (c == '%') decrypted += '5';
        else if (c == '^') decrypted += '6';
        else if (c == '(') decrypted += '7';
        else if (c == ')') decrypted += '8';
        else if (c == '?') decrypted += '9';
        else if (c == '=') decrypted += '0';
        else decrypted += c;
    }
    return decrypted;
}

// --- دالات تشفير وفك تشفير الرصيد ---
string encryptBalance(double amount) {
    string enc = "";
    int val = (int)amount;
    while (val >= 5000) { enc += "!"; val -= 5000; }
    while (val >= 1000) { enc += "@"; val -= 1000; }
    if (val > 0) enc += to_string(val); // الباقي يكتب كأرقام عادية
    return enc;
}

double decryptBalance(string enc) {
    double total = 0;
    string remainder = "";
    for (int i = 0; i < enc.length(); i++) {
        if (enc[i] == '!') total += 5000;
        else if (enc[i] == '@') total += 1000;
        else remainder += enc[i];
    }
    if (remainder != "") total += stod(remainder);
    return total;
}

// --- دالات إدارة الملفات والبيانات ---
void saveToFile(const vector<Account>& accounts) {
    ofstream outFile("bank_data.txt");
    for (const auto& acc : accounts) {
        outFile << acc.name << " " << acc.phone << " " << acc.accountNumber 
                << " " << acc.password << " " << acc.balanceStr << endl;
    }
    outFile.close();
}

vector<Account> loadFromFile() {
    vector<Account> accounts;
    ifstream inFile("bank_data.txt");
    Account temp;
    while (inFile >> temp.name >> temp.phone >> temp.accountNumber >> temp.password >> temp.balanceStr) {
        accounts.push_back(temp);
    }
    inFile.close();
    return accounts;
}

// --- الدوال الأساسية للعمليات ---
void createAccount() {
    Account acc;
    string rawPhone, rawAccNum, rawPass;
    double rawBalance;

    cout << "Enter Name: "; cin >> acc.name;
    cout << "Enter Phone: "; cin >> rawPhone;
    cout << "Enter Account Number: "; cin >> rawAccNum;
    cout << "Enter Password: "; cin >> rawPass;
    cout << "Enter Initial Balance: "; cin >> rawBalance;

    acc.phone = encryptData(rawPhone);
    acc.accountNumber = encryptData(rawAccNum);
    acc.password = encryptData(rawPass);
    acc.balanceStr = encryptBalance(rawBalance);

    vector<Account> accounts = loadFromFile();
    accounts.push_back(acc);
    saveToFile(accounts);
    cout << "Account Created Successfully!\n";
}

int login(const vector<Account>& accounts) {
    string accNum, pass;
    cout << "Account Number: "; cin >> accNum;
    cout << "Password: "; cin >> pass;

    for (int i = 0; i < accounts.size(); i++) {
        if (decryptData(accounts[i].accountNumber) == accNum && 
            decryptData(accounts[i].password) == pass) {
            return i;
        }
    }
    return -1;
}

void showBalance(Account acc) {
    cout << "\n--- Account Info ---" << endl;
    cout << "Name: " << acc.name << endl;
    cout << "Phone: " << decryptData(acc.phone) << endl;
    cout << "Balance: " << decryptBalance(acc.balanceStr) << "$" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Create Account\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) createAccount();
        else if (choice == 2) {
            vector<Account> accounts = loadFromFile();
            int index = login(accounts);
            if (index != -1) {
                int action;
                while (true) {
                    cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Logout\nChoice: ";
                    cin >> action;
                    if (action == 1) showBalance(accounts[index]);
                    else if (action == 2) {
                        double amount; cout << "Amount: "; cin >> amount;
                        double current = decryptBalance(accounts[index].balanceStr);
                        accounts[index].balanceStr = encryptBalance(current + amount);
                        saveToFile(accounts);
                    }
                    else if (action == 3) {
                        double amount; cout << "Amount: "; cin >> amount;
                        double current = decryptBalance(accounts[index].balanceStr);
                        if (amount <= current) {
                            accounts[index].balanceStr = encryptBalance(current - amount);
                            saveToFile(accounts);
                        } else cout << "Insufficient funds!\n";
                    }
                    else if (action == 4) {
                        string targetAcc; cout << "Target Account Number: "; cin >> targetAcc;
                        int targetIdx = -1;
                        for(int i=0; i<accounts.size(); i++) 
                            if(decryptData(accounts[i].accountNumber) == targetAcc) targetIdx = i;
                        
                        if (targetIdx != -1) {
                            double amt; cout << "Amount: "; cin >> amt;
                            double myBal = decryptBalance(accounts[index].balanceStr);
                            if (amt <= myBal) {
                                accounts[index].balanceStr = encryptBalance(myBal - amt);
                                accounts[targetIdx].balanceStr = encryptBalance(decryptBalance(accounts[targetIdx].balanceStr) + amt);
                                saveToFile(accounts);
                                cout << "Transfer Successful!\n";
                            }
                        } else cout << "Target account not found!\n";
                    }
                    else break;
                }
            } else cout << "Invalid Login!\n";
        }
        else break;
    }
    return 0;
}
