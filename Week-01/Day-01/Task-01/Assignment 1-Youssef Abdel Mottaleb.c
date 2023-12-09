// Assognment 1 Write a code that can draw this pyramid

#include <stdio.h>

int main()
{
	// Variables Declaration
	int rows, i, j;
	
	// getting the number of records to display from the user
	printf("Enter The Number of Rows for The Pyramid: ");
	scanf("%d", &rows);
	
	for (i = 1; i <= rows; i++)
	{
		// first we print spaces before asterisks
		for (j = 1; j <= rows - i; j++)
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
