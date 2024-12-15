#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node{
    char* key;
    struct Node* next;
    struct Node* prev;

}node; 

node* first=NULL;
node* last= NULL;

void printList(){
    node* n= first;
    while(n != NULL){
        printf("%s\n",n->key);
        n=n->next;
    }
}

node* createList(char* name){
    node* n= (node*)malloc(sizeof(node));
    if(n){
        n->next=NULL;
        n->prev=NULL;
         // 'key' için bellekte yer ayır
        n->key = (char*)malloc(strlen(name) + 1); // +1 '\0' için
        if (n->key) {
            strcpy(n->key, name); // İsmi kopyala
        } 
    }
    else{
        printf("Not memory.");
    }
    return n;
}
//sona eleman ekleme
void insert (char* name){  
    if(first==NULL){
        first=createList(name);
        last=first;
        
    }
    else {
        node* n= createList(name);
        last->next=n;
        n->prev = last;
        last=n;

    }
}
node* search(char* key){
    if(first==NULL){
        printf("List is empty \n");
    }
    else {
        node* n=first;
        while(n!=NULL){
            if(strcmp(n->key,key)==0){
                return n;
            }
            n=n->next;
        }
    }
    return NULL;
}
node* delete(char* key){
    node* n=first;
    while(n!=NULL){
        if(strcmp(n->key,key)==0){
            break;
        }
        n=n->next;
    }
    if(n==NULL){
        printf("List is empty \n");
        return NULL;
    }
    else if (n == last) {
        last = n->prev;  // last güncellenmeli
        if (last != NULL) {
            last->next = NULL;  // Yeni last'ın next'i NULL olmalı
        } else {
            first = NULL; // Eğer tek eleman varsa, first da NULL olmalı
        }
    }
    // İlk eleman mı?
    else if (n == first) {
        first = n->next;  // first güncellenmeli
        first->prev = NULL;  // Yeni first'ın prev'i NULL olmalı
    }
    // Ortadaki bir eleman
    else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
     printf("You deleted it: %s\n", n->key);
    free(n->key);
    free(n);
    return n;
   

}

int main(){
     
    insert("Sevval");
    insert("EFe");
    insert("Sulti");
    insert("Beyza");
    insert("Sema");
    insert("Gul");

    printList();
     
    node* n= search("Sevval");
    if(n){
        printf("You find it %s \n", n->key);
    }
     n= search("ewgfd");
    if(n){
        printf("You find it %s \n", n->key);
    }else{
         printf("You dont find it : ewgfd \n");
    }
    node* n2= delete("Gul");
    n2=delete("EFe");

    printList();
}