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
        printf("occupied by %s\n",hash_table[i]->name);
    }else{
        printf("slot %d empty\n",i);
    }
}
printf("===============end=============\n");
}

bool hash_table_insert(person *p){
    if(p==NULL) return false;
    int index =hash(p->name);
    if(hash_table[index]!=NULL) return false;
    hash_table[index]=p;
    return true;
}

int main(){

init_hash_table();
print_table();

person jacob ={.name="Jacob",.age=30};
person kate ={.name="kate",.age=30};
person paul ={.name="paul",.age=30};
person ron ={.name="ron",.age=30};
person maren ={.name="maren",.age=30};

hash_table_insert(&jacob);
hash_table_insert(&kate);
hash_table_insert(&paul);
hash_table_insert(&ron);
hash_table_insert(&maren);
// printf("John => %u\n",hash("Mry"));
// printf("natalie => %u\n",hash("natalie"));
// printf("sarar => %u\n",hash("sarah"));
// printf("Jane => %u\n",hash("jane"));
// printf("ron => %u\n",hash("maren"));
// printf("maren => %u\n",hash("ron"));

print_table();

}
