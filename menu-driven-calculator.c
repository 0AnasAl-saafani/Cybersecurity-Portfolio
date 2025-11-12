#include<stdio.h>

void displaymenu ()
{
	printf("choose an option :\n");
	printf("1. Calaulate the area of a rectangle \n");
	printf("2. Calaulate the area of a circle \n");
	printf("3. Find the largest of two numbers \n");
}

double rectanglearea(double length,double width)
{
	return length * width ;
}

double circlearea (double radius)
{
	return 3.14 * radius * radius ;
}

double findlargest (double number1 , double number2)
{
	if (number1 > number2)
	{
		return number1;
	}
	else
	{
		return number2;
	}
}

int main()
{
	int choice;
	double length, width, radius, number1, number2;
	
	displaymenu();
	printf("Enter your choice: \n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		printf("Enter length: \n");
		scanf("%lf",&length);\
		printf("Enter width: \n");
		scanf("%lf",&width);
		printf("Area of rectangle = %.2lf \n",rectanglearea(length,width));
		break;
		
		case 2:
		printf("Enter radius: \n");
		scanf("%lf",&radius);
		printf("Area of circle = %.2lf \n",circlearea(radius));
		break;
		
		case 3:
		printf("Enter the frist number: \n");
		scanf("%lf",&number1);\
		printf("Enter the secand number: \n");
		scanf("%lf",&number2);
		printf("The largest number is  %.2lf \n",findlargest(number1 , number2));
		break;
	}
}
