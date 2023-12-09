// Write a c program that draw a pyramid of stars with height entered by the user

#include <stdio.h>

int main()
{
	// Variables Declaration
	int height, i, j;
	
	// getting the number of records to display from the user
	printf("Enter The Height for The Pyramid: ");
	scanf("%d", &height);
	
	for (i = 1; i <= height; i++)
	{
		// first we print spaces before asterisks
		for (j = 1; j <= height - i; j++)
		{
			printf(" ");
		}
		
		// Print asterisks
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		// Move to the next line
        printf("\n");
	}
	
	return 0;
}
