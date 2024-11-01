#include <stdio.h>

int isPrime(int n)
 {
    if (n <= 1)
     {
        return 0; // Numbers less than 2 are not prime
    }
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)
	 {
            return 0; // If divisible by any number other than 1 and itself, it's not prime
        }
    }
    return 1; // If no divisors found, it's prime
}

int main()
 {
    int num;
    printf("Enter a number");
    scanf("%d", &num);

    if (isPrime(num))
     {
        printf("%d is a prime number.\n", num);
    } 
    else
     {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

