/*
Write a C program to act as simple calculator, first it will ask the user to enter the
operation ID, depending on the operation, the program will ask the user either to
enter 1 operand or 2 operands and the program will execute the operation and print
the result. Each operation should be implemented in a stand a long function.
*/

#include <stdio.h>

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Cannot divide by zero!\n");
        return 0.0;
    }
}

// Function to perform bitwise AND on two integers
int bitwiseAnd(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR on two integers
int bitwiseOr(int a, int b) {
    return a | b;
}

// Function to perform bitwise NOT on an integer
int bitwiseNot(int a) {
    return ~a;
}

// Function to perform bitwise XOR on two integers
int bitwiseXor(int a, int b) {
    return a ^ b;
}

// Function to calculate the remainder of two integers
int remainderFunction(int a, int b) {
    return a % b;
}

// Function to increment a number
double increment(double a) {
    return a + 1;
}

// Function to decrement a number
double decrement(double a) {
    return a - 1;
}

int main() {
    int operationId;
    printf("Enter operation ID:\n");
    scanf("%d", &operationId);

    switch (operationId) {
        case 1: {
            double operand1, operand2;
            printf("Enter two operands: ");
            scanf("%f %f", &operand1, &operand2);
            printf("Result: %.2f\n", add(operand1, operand2));
            break;
        }
        case 2: {
            double operand1, operand2;
            printf("Enter two operands: ");
            scanf("%f %f", &operand1, &operand2);
            printf("Result: %.2f\n", subtract(operand1, operand2));
            break;
        }
        case 3: {
            double operand1, operand2;
            printf("Enter two operands: ");
            scanf("%f %f", &operand1, &operand2);
            printf("Result: %.2f\n", multiply(operand1, operand2));
            break;
        }
        case 4: {
            double operand1, operand2;
            printf("Enter two operands: ");
            scanf("%f %f", &operand1, &operand2);
            printf("Result: %.2f\n", divide(operand1, operand2));
            break;
        }
        case 5: {
            int operand1, operand2;
            printf("Enter two operands: ");
            scanf("%d %d", &operand1, &operand2);
            printf("Result: %d\n", bitwiseAnd(operand1, operand2));
            break;
        }
        case 6: {
            int operand1, operand2;
            printf("Enter two operands: ");
            scanf("%d %d", &operand1, &operand2);
            printf("Result: %d\n", bitwiseOr(operand1, operand2));
            break;
        }
        case 7: {
            int operand;
            printf("Enter an operand: ");
            scanf("%d", &operand);
            printf("Result: %d\n", bitwiseNot(operand));
            break;
        }
        case 8: {
            int operand1, operand2;
            printf("Enter two operands: ");
            scanf("%d %d", &operand1, &operand2);
            printf("Result: %d\n", bitwiseXor(operand1, operand2));
            break;
        }
        case 9: {
            int operand1, operand2;
            printf("Enter two operands: ");
            scanf("%d %d", &operand1, &operand2);
            printf("Result: %d\n", remainderFunction(operand1, operand2));
            break;
        }
        case 10: {
            double operand;
            printf("Enter an operand: ");
            scanf("%f", &operand);
            printf("Result: %.2f\n", increment(operand));
            break;
        }
        case 11: {
            double operand;
            printf("Enter an operand: ");
            scanf("%f", &operand);
            printf("Result: %.2f\n", decrement(operand));
            break;
        }
        default:
            printf("Invalid operation ID.\n");
    }

    return 0;
}
