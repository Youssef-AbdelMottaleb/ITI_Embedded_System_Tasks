/*
Write a code that will ask the user to enter 3 
numbers, the program will print the maximum number of them.
*/

#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter the first number: ");
    scanf("%d", &num1);
	printf("Enter the second number: ");
    scanf("%d", &num2);
	printf("Enter the third number: ");
    scanf("%d", &num3);

    int max = num1;

    if (num2 > max) {
        max = num2;
    }

    if (num3 > max) {
        max = num3;
    }

    printf("The maximum number is: %d\n", max);

    return 0;
}
