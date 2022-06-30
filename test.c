#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
size_t count=0;    
while(h!=NULL){
printf("inside print list: %s\n",h->str);
count++;
h=h->next;
 }   

return (count);
}
