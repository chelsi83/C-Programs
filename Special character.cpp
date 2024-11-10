#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // Return null character if stack is empty
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>') ||
           (open == '[' && close == ']');
}

int isValidString(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        // Push opening brackets onto the stack
        if (str[i] == '(' || str[i] == '{' || str[i] == '<' || str[i] == '[') {
            push(str[i]);
        }
        // Check for matching closing brackets
        else if (str[i] == ')' || str[i] == '}' || str[i] == '>' || str[i] == ']') {
            char openBracket = pop();
            if (!isMatchingPair(openBracket, str[i])) {
                return 0;  // Not a valid string
            }
        }
    }

    // If stack is empty, all opening brackets have matching closing brackets
    return top == -1;
}

int main() {
    char str[100];

    // Input a string from the user
    printf("Enter a string with brackets");
    fgets(str, sizeof(str), stdin);

    // Check if the string is valid
    if (isValidString(str)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}

