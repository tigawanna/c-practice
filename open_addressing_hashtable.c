#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME  256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFUL)

typedef struct{
    char name[MAX_NAME];
    int age;
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
    }else if(hash_table[i]==DELETED_NODE){
        printf("previously deleted node at %d\n",i);
    }else{
         printf("slot %d empty\n",i);  
    }
}
printf("===============end=============\n");
}

bool hash_table_insert(person *p){
    if(p==NULL) return false;
    int index =hash(p->name);

    for(int i=0;i<TABLE_SIZE;i++){
    int try = (i + index)% TABLE_SIZE;
     if(hash_table[try]==NULL|| hash_table[try] == DELETED_NODE){
     hash_table[try] = p;
     return true;
     }}

  return false;
}


person *hash_table_lookup(char *name){
int index =hash(name);

for(int i=0;i<TABLE_SIZE;i++){
int try = (index + i)%TABLE_SIZE;
if(hash_table[try]==NULL){
    return false;//not here
}
if(hash_table[try]==DELETED_NODE) continue;

if(hash_table[try]!=NULL && strcmp(name,hash_table[try]->name)==0){
    person *tmp =hash_table[try];
    return tmp;
}
return NULL;

}

}


person *hash_table_delete(char *name){
int index =hash(name);
for(int i=0;i<TABLE_SIZE;i++){
int try = (index + i)%TABLE_SIZE;
if(hash_table[try]==NULL){
    return NULL;//not here
}
if(hash_table[try]==DELETED_NODE) continue;
if(hash_table[try]!=NULL && strcmp(name,hash_table[try]->name)==0){
    person *tmp =hash_table[try];
    hash_table[try]=NULL;
    return tmp;
}
return NULL;

}
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



person *tmp = hash_table_lookup("kate");
if(tmp ==NULL){
printf("not found\n");
}else{
printf("found %s\n",tmp->name);
}

print_table();

person *tmp2 = hash_table_delete("kate");
if(tmp2 ==NULL){
printf("not found\n");
}else{
printf("deleted %s\n",tmp2->name);
}
// person *tmp = hash_table_lookup("kate");
// person *tmp = hash_table_lookup("paul");

// printf("John => %u\n",hash("Mry"));
// printf("natalie => %u\n",hash("natalie"));
// printf("sarar => %u\n",hash("sarah"));
// printf("Jane => %u\n",hash("jane"));
// printf("ron => %u\n",hash("maren"));
// printf("maren => %u\n",hash("ron"));

print_table();

}
