// Assognment 2 Write a code that scan 3 numbers from the user and print them in reversed order

#include <stdio.h>

int main() 
{
	// Variables Declaration
	int firstNumber, secondNumber, thirdNumber;
	
	// Getting the values from the user
    printf("Enter The First Number: ");
    scanf("%d", &firstNumber);
	printf("Enter The Second Number: ");
    scanf("%d", &secondNumber);
	printf("Enter The Third Number: ");
    scanf("%d", &thirdNumber);

	// displaying the reversed order
    printf("Reversed order: %d %d %d\n", thirdNumber, secondNumber, firstNumber);

    return 0;
}