// Write a C code that defines a function which takes an array as input argument and apply the bubble sorting algorithm on it, then print the result

#include <stdio.h>
void displayArray(int array[], int size){
	
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubbleSort(int array[], int size){
	for(int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i - 1; j++)
		{
			if(array[j] > array[j+1]){
				// swap between numbers indices
				swap(&array[j], &array[j+1]);
			}
		}
		
	}
}

int main(){
	int array[] = {64, 22, 78,2,10,99,124,13,88,5};
	int size = sizeof(array) / sizeof(array[0]);
	printf(" The Original Array Sequence is: ");
	displayArray(array, size);
	bubbleSort(array, size);
	printf("Sorted Array Sequence is: ");
	displayArray(array, size);
	return 0;
}