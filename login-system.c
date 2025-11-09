#include<stdio.h>
#include<string.h>


/*int main()
{

	int secret ;	


	int the_secret =00000000;

	printf("Enter the secret number : ");
	scanf("%d",&secret);
	printf("==========================\n");
	if( secret == the_secret)
	{
		printf("Access granted.\n");
	}
	else 
	{
		printf("Access denied!.\n");
	}
}
*/

int main()
{
	char the_username [14]= "anasalsaafani";
	int the_password = 0000;
	char username [14];
	int password;
	printf("Enter your username : ");
	scanf("%s",username);
	printf("Enter your password : ");
	scanf("%d",&password);	
	if(strcmp(the_username , username)== 0 && the_password == password)
	{
		printf("Welcome !\n");
	}
	else{
		printf("Error : Invalid username or password \n");
	}
	
}