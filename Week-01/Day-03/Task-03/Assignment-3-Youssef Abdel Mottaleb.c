// Write a C code that ask the user to enter 10 values and save them in an array using a for loop. Then print the minimum and the maximum of the values.

#include <stdio.h>

int main(){
    int values[10];

    // input values using a loop
    for(int i = 0; i < 10; i++){
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    // Find minimum and maximum values
    int min = values[0];
    int max = values[0];

    for (int i = 1; i < 10; i++){
        if( values[i] < min ){
            min = values[i];
        }
        if (values[i] > max ){
            max = values[i];
        }
    }
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}