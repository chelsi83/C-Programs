#include <stdio.h>
#include <string.h>

// Define a structure for a Person
struct Person {
    char name[50];
    int age;
    float height;
};

int main()
 {
    // Declare a structure variable
    struct Person person1;

    // Declare a pointer to the structure
    struct Person *ptr;

    // Initialize the structure variable
    strcpy(person1.name, "Alice");
    person1.age = 30;
    person1.height = 5.5;

    // Point the pointer to the structure variable
    ptr = &person1;

    // Access and modify structure members using the pointer
    printf("Using pointer to display information\n");
    printf("Name: %s\n", ptr->name);        // Accessing name using pointer
    printf("Age: %d\n", ptr->age);          // Accessing age using pointer
    printf("Height: %.1f\n", ptr->height);  // Accessing height using pointer

    // Modify structure members using the pointer
    ptr->age = 31;                          // Modifying age using pointer
    strcpy(ptr->name, "Alice Johnson");     // Modifying name using pointer
    ptr->height = 5.6;                      // Modifying height using pointer

    // Display the modified data
    printf("\nModified Information\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.1f\n", person1.height);

    return 0;
}

