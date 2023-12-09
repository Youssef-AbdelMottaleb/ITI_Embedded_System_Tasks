/*
Write a C code that ask the user to enter his ID, if the ID is valid it will 
ask the user to enter his password, if the password is correct the 
program will print the user name, if the password is incorrect the 
program will print Incorrect Password.
In case of not existing ID, the program will print Incorrect ID
*/

#include <stdio.h>
#include <string.h>

// Create a structure to store user information
struct User {
    int id;
    char password[20];
    char name[30];
};

int main() {
    struct User users[] = {
        {1234, "password1", "Youssef Abdel Mottaleb"},
        {2345, "password2", "Ahmed Amr"},
        {3456, "password3", "Hossam Elzhar"}
    };
    
    int enteredId, validId = 0, userIdx = -1; // Index of the user in the users array
    char enteredPassword[20];
    
    printf("Enter your ID: ");
    scanf("%d", &enteredId);

    // Search for the entered ID
    for (int i = 0; i < sizeof(users) / sizeof(users[0]); i++) {
        if (users[i].id == enteredId) {
            userIdx = i;
            validId = 1;
            break;
        }
    }

    if (validId) {
        printf("Enter your password: ");
        scanf("%s", enteredPassword);

        if (strcmp(enteredPassword, users[userIdx].password) == 0) {
            printf("Welcome, %s!\n", users[userIdx].name);
        } else {
            printf("Incorrect Password\n");
        }
    } else {
        printf("Incorrect ID\n");
    }
    return 0;
}

