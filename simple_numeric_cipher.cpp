#include<iostream>
#include<string>  
using namespace std;

int main()
{
    int choice;
   
    string message; 
    string codeStr;
    do 
    {
    cout<<"---------------------The Menu---------------------"<<endl;  
    cout<<"1-Send \n2-Receive\n3-Exit"<<endl;
    cin>>choice;
    cin.ignore();  
    
    switch(choice)
    {
        case 1:  
        {
            cout<<"Enter the message: ";  
            getline(cin, message); 
            
            cout<<"The code is :"<<endl;  
            for(int i=0; i < message.length(); i++)  
            {
                switch(message[i])  
                {
                   
                    case 'a':
                    case 'A':
                    cout<<"09999";
                    break;
                    case 'b':
                    case 'B':
                    cout<<"19999";
                    break;
                    case 'c':
                    case 'C':
                    cout<<"29999";
                    break;
                    case 'd':
                    case 'D':
                    cout<<"07700";
                    break;
                    case 'e':
                    case 'E':
                    cout<<"03000";
                    break;
                    case 'f':
                    case 'F':
                    cout<<"99996";
                    break;
                    case 'g':
                    case 'G':
                    cout<<"00299";
                    break;
                    case 'H':
                    case 'h':
                    cout<<"09900";
                    break;
                    case 'i':
                    case 'I':
                    cout<<"01790";
                    break;
                    case 'j':
                    case 'J':
                    cout<<"09990";
                    break;
                    case 'k':
                    case 'K':
                    cout<<"62500";
                    break;
                    case 'l':
                    case 'L':
                    cout<<"00100";
                    break;
                    case 'm':
                    case 'M':
                    cout<<"94300";
                    break;
                    case 'n':
                    case 'N':
                    cout<<"77320";
                    break;
                    case 'o':
                    case 'O':
                    cout<<"99019";
                    break;
                    case 'P':
                    case 'p':
                    cout<<"99995";
                    break;
                    case 'q':
                    case 'Q':
                    cout<<"99994";
                    break;
                    case 'r':
                    case 'R':
                    cout<<"09998";
                    break;
                    case 's':
                    case 'S':
                    cout<<"99999";
                    break;
                    case 't':
                    case 'T':
                    cout<<"72600";
                    break;
                    case 'u':
                    case 'U':
                    cout<<"06970";
                    break; 
                    case 'v':
                    case 'V':
                    cout<<"59640";
                    break;
                    case 'w':
                    case 'W':
                    cout<<"79900";
                    break;
                    case 'x':
                    case 'X':
                    cout<<"99993";
                    break;
                    case 'y':
                    case 'Y':
                    cout<<"49990";
                    break;
                    case 'z':
                    case 'Z':
                    cout<<"59990";
                    break;
                    case ' ':
                    cout<<"00000";
                    break;
                    case '0':
                    cout<<"05000";
                    break;
                    case '1':
                    cout<<"04000";
                    break;
                    case '2':
                    cout<<"04400";
                    break;
                    case '3':
                    cout<<"06100";
                    break;
                    case '4':
                    cout<<"04170";
                    break;
                    case '5':
                    cout<<"02430";
                    break;
                    case '6':
                    cout<<"00200";
                    break;
                    case '7':
                    cout<<"01900";
                    break;
                    case '8':
                    cout<<"05100";
                    break;
                    case '9':
                    cout<<"04700";
                    break;
                    default:
                    cout<<"ERROR";
                    break;
                }
            }
            break;  
        }
        
        case 2:
        {
            cout<<"Enter the code:"<<endl;
            getline(cin, codeStr);
            
            
            if(codeStr.length() % 5 != 0) {  
                cout<<"Invalid code length!"<<endl;
                break;
            }
            
            for(int i=0; i < codeStr.length()-4; i+=5)  
            {
                int chick = 0;  
                for(int j=0; j<5; j++)  
                {
                    chick += (codeStr[i+j] - '0');  
                }
                
                switch(chick)  
                {
                    
                    case 5:
                    cout<<'0';
                    break;
                    case 4:
                    cout<<'1';
                    break;
                    case 8:
                    cout<<'2';
                    break;
                    case 7:
                    cout<<'3';
                    break;
                    case 12:
                    cout<<'4';
                    break;
                    case 9:
                    cout<<'5';
                    break;
                    case 2:
                    cout<<'6';
                    break;
                    case 10:
                    cout<<'7';
                    break;
                    case 6:
                    cout<<'8';
                    break;
                    case 11:
                    cout<<'9';
                    break;
                    case 36:
                    cout<<'a';
                    break;
                    case 37:
                    cout<<'b';
                    break;
                    case 38:
                    cout<<'c';
                    break;
                    case 14:
                    cout<<'d';
                    break;
                    case 3:
                    cout<<'e';
                    break;
                    case 42:
                    cout<<'f';
                    break;
                    case 20:
                    cout<<'g';
                    break;
                    case 18:
                    cout<<'h';
                    break;
                    case 17:
                    cout<<'i';
                    break;
                    case 27:
                    cout<<'j';
                    break;
                    case 13:
                    cout<<'k';
                    break;
                    case 1:
                    cout<<'l';
                    break;
                    case 16:
                    cout<<'m';
                    break;
                    case 19:
                    cout<<'n';
                    break;
                    case 28:
                    cout<<'o';
                    break;
                    case 41:
                    cout<<'p';
                    break;
                    case 40:
                    cout<<'q';
                    break;
                    case 35:
                    cout<<'r';
                    break;
                    case 45:
                    cout<<'s';
                    break;
                    case 15:
                    cout<<'t';
                    break;
                    case 22:
                    cout<<'u';
                    break;
                    case 24:
                    cout<<'v';
                    break;
                    case 25:
                    cout<<'w';
                    break;
                    case 39:
                    cout<<'x';
                    break;
                    case 31:
                    cout<<'y';
                    break;
                    case 32:
                    cout<<'z';
                    break;
                    case 0:
                    cout<<' ';
                    break;
                    default:
                    cout<<"?"; 
                    break;
                }
            }
            break;  
        }
        case 3:
        cout<<"Thanks for use this app"<<endl;
        break;
        default:  
            cout<<"Invalid choice!"<<endl;
            break;
    }
    
    cout<<endl;
    
}while(choice!=3);
return 0;
}