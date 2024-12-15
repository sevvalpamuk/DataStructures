#include<stdio.h>

void SelectionFunc(int A[], int n);
void printArray(int a[], int n);

int main(){
    int array[]={7,3,5,25,8,9,1,4,6};
    int count=9;
    
    SelectionFunc(array,count);
    printArray(array,count);
    
}
void printArray(int A[], int n){
   for(int i =0; i<n ; i++ ){
    printf("%d   ",A[i]);
   }
}
void SelectionFunc(int a[], int n){
    int j,i,minindex,mincount;
    for(i=0; i<n-1;i++){
        minindex=i;
        
        for ( j=i+1; j<n; j++){
               if(a[minindex]>a[j]){
                  minindex=j;
                }
            }
            if ( minindex!=i){
            mincount=a[minindex];
            a[minindex]=a[i];
            a[i]=mincount; 
        }
    }
}