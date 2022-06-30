#include "main.h"

struct node *head, *tail = NULL; 

 void createNode(int data,char *name){
    
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
    printf("Error , memory unavailable \n");
    return;
    }
    newNode->data = data;
    newNode->name = name;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    } 

}


//display() will display all the nodes present in the list  
void displayNodes() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of singly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
         printf("%s \n", current->name);  
        current = current->next;  
    }  
    printf("\n");  
}  
