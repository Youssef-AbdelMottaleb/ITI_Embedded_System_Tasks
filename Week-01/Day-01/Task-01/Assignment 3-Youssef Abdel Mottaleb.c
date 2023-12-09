// Assognment 3 Write a code that takes 2 numbers and print their summation, subtraction, anding, oring, and Xoring

#include <stdio.h>

int main()
{
	// Variables Declaration
	
	int number1, number2;
	
	// Getting the values from the user
	
	printf("Enter The First Number: ");
	scanf("%d", &number1);
	printf("Enter The Second Number: ");
	scanf("%d", &number2);
	
	// Summation
	printf("Summation is: %d\n", number1 + number2);
	
	// Subtraction
	printf("Subtraction is: %d\n", number1 - number2);
	
	// Bitwise AND
    printf("Bitwise AND is: %d\n", number1 & number2);

    // Bitwise OR
    printf("Bitwise OR is: %d\n", number1 | number2);

    // Bitwise XOR
    printf("Bitwise XOR is: %d\n", number1 ^ number2);

    return 0;
}
