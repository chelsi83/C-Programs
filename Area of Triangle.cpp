#include<stdio.h>
int main()
{ 
//declare the variables
 float a,b,h;
 //take input from user
 printf("Enter the base : ");
 scanf("%f",&b);
 printf("Enter the height : ");
 scanf("%f",&h);
 //apply formula of area of triangle 0.5*b*h
  a=0.5*b*h;
 printf("Area is %f",a);
}
