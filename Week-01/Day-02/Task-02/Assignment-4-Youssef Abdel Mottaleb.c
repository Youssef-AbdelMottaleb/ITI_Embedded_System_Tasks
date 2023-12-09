/*
Write a C program that ask the user to
enter two numbers and print their
summation, this program should never
ends until the user close the window
*/

#include <stdio.h>

int main(){
	while(1){
		float num1, num2;
		printf("\nNumbers Summation press Ctrl C if you want to close the window \n\n");

		printf("Enter The First Number: ");
		scanf("%f", &num1);
		printf("Enter The Second Number: ");
		scanf("%f", &num2);
		
		float sum = num1 + num2;

        printf("Summation of the Two Numbers is: %.2f\n", sum);
	}
	return 0;
}