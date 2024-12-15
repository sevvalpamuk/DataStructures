#include<stdio.h>

void printArray(int a[], int n);
void QuickSort(int a[],int left,int right);


int main(){
    int array[]={1,9,7,4,5,9,2,6};
    int count=8;
    
    QuickSort(array,0,count-1);
    printArray(array,count);
    
}
void printArray(int A[], int n){
   for(int i =0; i<n ; i++ ){
    printf("%d   ",A[i]);
   }
}
void QuickSort(int a[],int left,int right){

   int k, j, q, temp;

   k = left;
   j = right;

   q = a[(left+right)/2];   //pivot

    do{
      while ((a[k] < q) )
         k++;
      while ((a[j] > q) )
         j--;
      if (k <= j) { //exchange D[k] & D[j]
         temp = a[k];
         a[k] = a[j];
         a[j] = temp;
         k++;    j--;
      }
   }while(k <= j); 
   
// Sort each part using quicksort
   if (left < j)
       QuickSort(a, left, j);
   if (k < right)
      QuickSort(a, k, right);
 }



