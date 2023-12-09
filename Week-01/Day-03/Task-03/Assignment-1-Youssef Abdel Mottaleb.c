/*
Write a C program the implement 2 function:
1- Function to get the maximum of 4 values
2- Function to get the minimum of 4 values
The program will ask the user first to enter the 4 values, then print the maximum
number and minimum number of them.
*/

#include <stdio.h>

// Function to get the maximum of 4 values
int max(int a, int b, int c, int d){
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

// Function to get the minimum of 4 values
int min(int a, int b, int c, int d) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}

int main(){
	int num1, num2, num3, num4;
	printf("Enter The First Number: ");
	scanf("%d", &num1);
	printf("Enter The Second Number: ");
	scanf("%d", &num2);
	printf("Enter The Third Number: ");
	scanf("%d", &num3);
	printf("Enter The Fourth Number: ");
	scanf("%d", &num4);

	int maximum = max(num1, num2, num3, num4);
	int minimum = min(num1, num2, num3, num4);

	printf("Maximum number is: %d\n", maximum);
    printf("Minimum number is: %d\n", minimum);

	return 0;
}