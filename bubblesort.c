#include<stdio.h>

void BubbleSort(int a[],int n);
void printArray(int a[], int n);

int main(){
     int array[]={7,3,5,25,8,9,1,4,6};
    int count=9;
    
    BubbleSort(array,count);
    printArray(array,count);
}
void printArray(int A[], int n){
   for(int i =0; i<n ; i++ ){
    printf("%d   ",A[i]);
   }
}
void BubbleSort(int a[],int n){
    int temp;
    for(int i =0; i<n-1;i++){
    for(int j=0; j<(n-1-i); j++){  //bu iç döngüde her türlü bir tanesi sona gitmis oluyor sona bakmaya gerek yook

        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            
        }
    }


}



}
