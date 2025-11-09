#include<iostream>
using namespace std;
int main()
{
	// The frisr 
	
	/*
	int i=2;
	while(i<=10)
	{
		cout<<i<<" ";
		i+=2;
	}
	cout<<endl;
	*/
	//-------------------------------
	 
	 //The second 
	 
	 int i;
	 do
	 {
 		cout <<"Enter  a number"<<endl;
 		cin>>i;
 		if (i>0)
 		{
		 	cout<<"The number you entered is: "<<i<<endl;
		 }
		 else if(i<0)
		 {
 			continue;
 		}
 		else
 		{
		 	cout<<"Thinks for trying this program !"<<endl;
		 }
 		
 	}while(i!=0);
}