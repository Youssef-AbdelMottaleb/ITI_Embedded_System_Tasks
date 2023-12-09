/*
Write a login program in C that ask the
user to enter his ID and his password, if
the ID is correct the system will ask the
user to enter his password up to 3 times,
if he enters the password right the
systems welcomes him, if the three times
are incorrect, the system print No more
tries. If the user ID is incorrect the
system print You are not registered
*/

#include <stdio.h>
#include <string.h>

// creating a structure to store information

struct User{
	char username[20], password[20];
};

int main(){
	
	struct User users[] = {
        {"Ahmed", "1234"},
        {"Amr", "5678"},
        {"Wael", "9870"}
    };
	
	int maxTries = 3, found = 0, userIdx = -1;
	char enteredUsername[20], enteredPassword[20];
	
	printf("Enter Your Username: ");
	scanf("%s", enteredUsername);
	
	// Search for the entered username
	for(int i = 0; i < sizeof(users) / sizeof(users[0]); i++){
		if(strcmp(users[i].username, enteredUsername) == 0){
			userIdx = i;
			found = 1;
			break;
		}
	}
	
	if(found){
		for(int tries = 0; tries < maxTries; tries++){
			printf("Enter Your Password (%d Attempts Left): ", maxTries - tries);
			scanf("%s", enteredPassword);
			
			if(strcmp(users[userIdx].password, enteredPassword) == 0 ){
				printf("Welcome, %s!\n", users[userIdx].username);
				break;
				
			} else {
				printf("Incorrect password\n");
			}
		}
		
		if(strcmp(users[userIdx].password, enteredPassword) != 0 ){
			printf("No More Tries Yabo 3amoo Kol 3ee4 \n");
		} 
	} else {
			printf("You are Not Registered");
		}
	
	
	return 0;
}