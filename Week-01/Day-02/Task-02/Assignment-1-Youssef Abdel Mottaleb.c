/*
Write a C code that ask the user to enter 10
numbers, then ask him to enter another number
to search on it in the 10 numbers and print its
location in case it is found.
In case the number is not found, it will print
number no exist
*/

#include <stdio.h>

int main()
{
	
	int numbers[10], searchNumber, found = 0;  // Flag to indicate if the number is found
	
	printf("Enter 10 Numbers:\n");
	
	// Input loop to collect 10 numbers
    for (int i = 0; i < 10; i++)
	{
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
	
	printf("Enter a number to search for: ");
    scanf("%d", &searchNumber);
	
	// Search loop
	
	for(int i = 0; i < 10; i++)
	{
		if(numbers[i] == searchNumber)
		{
			printf("Number %d found at index %d\n", searchNumber, i);
			found = 1;
			break; // Exit the loop if the number is found
		}
	}
	
    if (!found)
	{
        printf("Number %d does not exist\n", searchNumber);
    }
	return 0;
}