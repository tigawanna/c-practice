#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME  256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFUL)

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
}person;

person *hash_table[TABLE_SIZE];




unsigned int hash(char *name){
int length = strnlen(name,MAX_NAME);
unsigned int hash_value=0;
for(int i=0;i<length ;i++){
    hash_value += name[i];
    hash_value=(hash_value * name[i])%TABLE_SIZE;
}
return hash_value;
}

bool init_hash_table(){
for(int i=0;i<TABLE_SIZE;i++){
    hash_table[i]=NULL;
}
}

void print_table(){
printf("===============start=============\n");    
for(int i=0;i<TABLE_SIZE;i++){
    if(hash_table[i]!=NULL){
        printf("slot %d occupied by %s\n",i,hash_table[i]->name);
    }else{
         printf("slot %d empty\n",i);
         person *tmp=hash_table[i];
         while(tmp!=NULL){
            printf("%s --- ",tmp->name);
            tmp=tmp->next;
            }
            printf("\n");  
    }
}
printf("===============end=============\n");
}

bool hash_table_insert(person *p){
    if(p==NULL) return false;
    int index = hash(p->name);
    printf("index from hash ===> %d \n",index);
        printf("who lv 1 ===> %s \n",hash_table[index]->name);
    p->next = hash_table[index];
        printf("who lv 1 ===> %s \n",hash_table[index]->name);
    hash_table[index] = p;
        printf("who lv 1 ===> %s \n",hash_table[index]->name);
    return true;
}


person *hash_table_lookup(char *name){
int index =hash(name);
person *tmp =hash_table[index];

while(tmp!=NULL && strncmp(tmp->name,name,MAX_NAME)!=0){
    tmp =tmp->next;
}
return tmp;

}


person *hash_table_delete(char *name){
int index =hash(name);

person *prev =NULL;
person *tmp =hash_table[index];

while(tmp!=NULL && strncmp(tmp->name,name,MAX_NAME)!=0){
    prev=tmp;
    tmp =tmp->next;
}
if(tmp != NULL) return NULL;
if(prev==NULL){
    hash_table[index] =tmp->next;
}else{
    prev->next=tmp->next;
}
return tmp;

}

int main(){

init_hash_table();
print_table();

person jacob ={.name="Jacob",.age=30};
person kate ={.name="kate",.age=30};
person paul ={.name="paul",.age=30};
person ron ={.name="ron",.age=31};
person Maren ={.name="Maren",.age=32};
person Jane ={.name="Jane",.age=33};
person eliza ={.name="Eliza",.age=30};


hash_table_insert(&jacob);
hash_table_insert(&kate);
hash_table_insert(&paul);
hash_table_insert(&ron);
hash_table_insert(&Maren);
hash_table_insert(&Jane);
hash_table_insert(&eliza);



person *tmp = hash_table_lookup("Maren");
if(tmp ==NULL){
printf("maren not found\n");
}else{
 // should return ron because hashing function gave them both index 0   
printf("in Maren found %s\n",tmp->next->name);
}

person *tmp2 = hash_table_lookup("John");
if(tmp2 ==NULL){
printf("JOhn not found\n");
}else{
 // should return ron because hashing function gave them both index 0   
printf("in John found %s\n",tmp2->next->name);
}
// print_table();

// person *tmp2 = hash_table_delete("kate");
// if(tmp2 ==NULL){
// printf("kate not found\n");
// }else{
// printf("deleted %s\n",tmp2->name);
// }


print_table();

}
