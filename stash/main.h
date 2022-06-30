#ifndef MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{char *str;
	unsigned int len;
	struct list_s *next;
} list_t;



/*Represent a node of singly linked list */ 
struct node{  
    int data;
	char *name;  
    struct node *next;  
};      
   
void createNode(int data, char *name);
void displayNodes();



#endif
