#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist* next;
}node;

node* first=NULL; //mainlinkedlist    bu kök listi kaybeddersek linked liste erişemeyiz
node* last=NULL; // koşullar için bakıyoruz

void createlist(node** p,int num);
void printss(node* n);

node* search( int key);
node* delete(int key);
void insert(int key);


int main(){
  
    insert(5);
    insert(9);
    insert(6);
  printss(first);
    node *found = search(6);
    if(found){
        printf("Bulundu: %d\n", found->data);
    }
    found=search(5);
    if(found){
        printf("Bulundu: %d\n", found->data);
    }
    found=search(9);
    if(found){
        printf("Bulundu: %d\n", found->data);
    }
     node* deletee=delete(6);
     if(delete){
        printf("%d silindi:\n",deletee->data);
     }
       printss(first);

}
void printss(node* n){
    node* temp=n;
    printf(" Elemanlar: \n");
    while(temp !=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
}
void createlist(node ** p,int num){  //kalıcı değişiklik için
    *p=(node*)malloc(sizeof(node));
    if (*p==NULL){
        printf("Not memory.");
    }
    else{
        (*p)->data=num;
        (*p)->next=NULL;
    }
}
/*global olmayan linked list için:::::::::
 eğer bir değeri kalıcı değişmek için nasıl pointer kullanıyorsak, 
pointerin değişkenini değişmek içinde onun adresini değişmemiz lazım 
aşağıdaki de aynı işlemi yapar yapılan main listi döndürür
  böyle çağırabiliriz

void insert(node** main, int key) {   
    node* newlink = NULL;
    if (first == NULL) {
        createlist(main, key); // İlk düğümü oluştur
        first = *main;         // İlk düğüm, listenin başı olur, main zaten adres
        last = *main;          // İlk düğüm, listenin sonu olur
    } else {
        createlist(&newlink, key); // Yeni düğüm oluştur
        last->next = newlink;      // Son düğümü yeni düğüme bağla
        last = newlink;            // Yeni düğüm artık son düğüm olur
    }
    insert(&main_linked_list,5);  //main listeye 5 ekle
    insert(&main_linked_list,9);
    insert(&main_linked_list,6);
}*/ 

//global olduğu için * koymadık
void insert(int key) {
    node* newlink = NULL;

    if (first == NULL) {  // Eğer liste boşsa
        createlist(&first, key);
        last=first;  // İlk düğümü oluştur
    } 
    else {
        createlist(&newlink, key);  // Yeni düğüm oluştur
        last->next = newlink;       // Son düğümü yeni düğüme bağla
        last = newlink;             // Yeni düğüm artık son düğüm olur
    }

} 
node* search( int key){
    if(first==NULL){
        printf("List is empty");
        return NULL;
    }
    else {
        node* temp= first;
        while(temp!=NULL){
            if(temp->data == key){
                    return temp;
                break;
            }
            else{
                temp=temp->next;
            }
        }
    }
    return NULL;
}
//silinen düğümü döndürelim
node* delete(int key){
    node* current=first;
    node* pre;

   if(current==NULL){
        printf("List is empty");
        return NULL;
    }
    else {
        while(current!=NULL){
            if(current->data == key){
                break;
            }
            else{
                pre=current;
                current=current->next;
                
            }
        }
    }

   if (pre == NULL) { // İlk eleman siliniyor
        if (first == last) { // Tek eleman varsa
            first = NULL;
            last = NULL;
        } else {
            first = first->next;
        }
    } 
    else { // Orta veya son eleman siliniyor
        pre->next = current->next;
        if (pre == last) {
            last = pre;
        }
    free(current);
    return current;
}
}