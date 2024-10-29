#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a person
struct Person 
{
    char name[50];
    int age;
};

int main()
 {
    // Create an array of pointers to Person structures
    struct Person *people[3];

    // Allocate memory and initialize each Person structure
    for (int i = 0; i < 3; i++)
     {
        people[i] = (struct Person *)malloc(sizeof(struct Person));
        if (people[i] == NULL) 
	{
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Initialize data
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", people[i]->name);
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &people[i]->age);
    }

    // Pointer to the array of Person pointers
    struct Person **ptr = people;

    // Access and print information using the pointer to the array
    printf("\nDisplaying Information:\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("Person %d: Name = %s, Age = %d\n", i + 1, ptr[i]->name, ptr[i]->age);
    }

    // Free the allocated memory
    for (int i = 0; i < 3; i++) 
    {
        free(people[i]);
    }

    return 0;
}

