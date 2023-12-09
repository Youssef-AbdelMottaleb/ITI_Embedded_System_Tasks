/*
Write a C code that allow the user to add
a node to linked list by pressing 0 and to
print the linked list by pressing 1. The
software shall continue forever till the
user enters 2. If the user enters any
other numbers the software shall print
incorrect entry. See the following
scenarios for more details.
*/

/*
Complete lab 2 by adding a new function that allow the user to delete certain
node. The user shall enter a value then the code shall delete any node that holds
this value

Complete lab 2 by adding a new function that allows the user to add a new node
at a certain position. The code shall ask the user to enter a value of the node and
the node index. the code shall add the new node to the received index and shift
all nodes to right.
*/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

// Define the structure of a linked list node
typedef struct Node {
    s32 data;
    struct Node* next;
} Node;

// Function to add a node to the end of the linked list
void addNode(Node** head, s32 newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = newData;
    newNode -> next = NULL;

    if( *head == NULL){
        *head = newNode;
    } else {
        Node* current = *head;
        while (current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = newNode;   
    }
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, s32 value){
    if (*head == NULL)
    {
        return;  // List is empty, nothing to delete
    }

    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (current -> data == value)
        {
            if (previous == NULL)
            {
                // delete the first node
                *head = current -> next;
            } else {
                previous -> next = current -> next;
            }
            free(current);
            return;  // Node deleted, exit function
        }
        previous = current;
        current = current -> next;
    }
}

void addNodeAtIndex(Node** head, s32 newData, s32 index){
    if (index < 0)
    {
        printf("Invalid index.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = newData;
    newNode -> next = NULL;

    if (index == 0)
    {
        newNode -> next = *head;
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    for (s16 i = 0; i < index - 1 && current != NULL; i++){
        current = current -> next;
    }
    if (current == NULL)
    {
        printf("Index out of bounds.\n");
        free(newNode);
        return;
    }
    newNode -> next = current -> next;
    current -> next = newNode;
}

int main(){
    Node* head = NULL;
    s32 choice, value, index;

    while (1)
    {
        printf("Press 0 to add a node, 1 to print the linked list, 2 to delete a node, 3 to add a node at an index, or 4 to exit: ");
        scanf("%d", &choice);

        if(choice == 0){
            printf("Enter the value to add: ");
            scanf("%d", &value);
            addNode(&head, value);
        } else if (choice == 1) {
            if (head == NULL) {
                printf("Linked List is empty.\n");
            } else {
                printf("Linked List: ");
                printLinkedList(head);
            }
        } else if(choice == 2){
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
        } else if(choice == 3){
            printf("Enter the value to add: ");
            scanf("%d", &value);
            printf("Enter the index to add at: ");
            scanf("%d", &index);
            addNodeAtIndex(&head, value, index);
        } else if (choice == 4){
            printf("Exiting...\n");
            break;
        } else {
            printf("Incorrect entry.\n");
        }
    }

    // Free the allocated memory for the linked list nodes
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current -> next;
        free(temp);
    }
    
    return 0;
}



