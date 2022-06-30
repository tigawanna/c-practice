#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME  256
#define TABLE_SIZE 10

typedef struct{
    char name[MAX_NAME];
    int age;
}person;

unsigned int hash(char *name){
return 5;
}

int main(){
printf("John => %u\n",hash("john"));
printf("natalie => %u\n",hash("natalie"));
printf("sarar => %u\n",hash("sarah"));
printf("Jane => %u\n",hash("jane"));
}
