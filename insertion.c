#include<stdio.h>

void InsertionFunc(int A[], int n);
void printArray(int a[], int n);

int main(){
    int array[]={7,3,5,25,8,9,1,4,6};
    int count=9;
    
    InsertionFunc(array,count);
    printArray(array,count);
    
}
void printArray(int A[], int n){
   for(int i =0; i<n ; i++ ){
    printf("%d   ",A[i]);
   }
}
void InsertionFunc(int a[], int n){
    int key,j,i;
    for(i=1; i<n;i++){
        key=a[i];
        for ( j=i-1; j>=0 && key<a[j]; j--){
            a[j+1]=a[j];
            
        }
        a[j+1]=key;

    }
}