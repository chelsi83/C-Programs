#include<stdio.h>
int main()
{
	//declaration of variables
	int numerator1, numerator2, denominator1, denominator2, 
num_result, denom_result ;
	//take i/p from user of numerator & denominator
	printf("Please provide the first numerator:\n");
	scanf("%d",&numerator1);
	printf("Please provide the first denominator:\n");
	scanf("%d",&denominator1);
 	printf("Please provide the second numerator:\n");
        scanf("%d",&numerator2);
	printf("Please provide the second denominator:\n");
	scanf("%d",&denominator2);
	//compare the denominators by using statement
	if ( denominator1 == denominator2 ) 
	{
		num_result = numerator1 + numerator2;
		denom_result = denominator1;
	}
	 else 
	{
		num_result = (numerator1 * denominator2) + (numerator2 * denominator1 );
		denom_result = denominator1 * denominator2;
	}
	printf("The result of %d / %d  + %d / %d  is: %d / %d \n", numerator1,denominator1, numerator2, denominator2,num_result,denom_result);
	return 0;
}
