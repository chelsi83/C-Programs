#include<stdio.h>
int main()
{
	//decalare the variables
	float r, a, c;
	//take input from user
	printf("enter the radius of circle\n");
	scanf("%f", &r);
	//taking value of pie to apply formula of area of circle
	a = 3.14*r*r;
	//apply formula of circumference of circle
	c = 2*3.14*r;
	printf("area = %f\n circumference = %f\n",a,c);
	return 0;
	
	
}
