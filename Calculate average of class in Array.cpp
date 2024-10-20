#include <stdio.h>

int main()
 {
    int i,sum=0,num;
    float avg;

    // take input for number of students from user
    printf("Enter number of students in class");
    scanf("%d",&num); 
    // Check if num is positive
    if (num<=0)
     {
        printf("Number of students must be positive");
        return 1;  
    }
    int marks[num];
    // take input for marks of each student from user
    printf("Enter marks of all students\n");
    for (i=0;i<num;i++)
     {
        scanf("%d",&marks[i]);  
        sum+=marks[i];        
    }
    avg = (float)sum / num;  // Calculate average
    printf("Average of class is: %.2f\n", avg);  // Print average
     return 0;
}

