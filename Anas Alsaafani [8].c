#include<stdio.h>

int main()
{
	int number[5];
	int temp;
	for(int i=0;i<5;i++)
	{
		printf("Enter the number [%d] : ",i+1);
		scanf("%d",&number[i]);
	}
	printf("the orginal order is {");
	for(int i=0;i<5; i++)
	{
		printf(" %d",number[i]);
	}
	printf("}\n");
	for( int i=0;i<4;i++)
	{						
		for (int j=i+1;j<5;j++)
		{
			if(number[i] > number[j])
			{
				temp=number[i];
				number[i]=number[j];
				number[j]=temp;
			}
		}
	}
	printf("The array after otder : {");
	for(int i=0;i<5;i++)
	{
		printf(" %d",number[i]);
		
	}
	printf("}\n");
	
}