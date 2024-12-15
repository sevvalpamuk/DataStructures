#include <stdio.h>


void printArray(int a[], int n);
int Partition(int a[],int left,int right);
void QuickSort(int a[],int low,int high);
void swap(int* a, int* b);
int h(char *key, int TableSize) {
    // Key uzunluğunu kontrol et
    if (strlen(key) < 11) {
        printf("Error: Key must be at least 11 characters long.\n");
        return -1; // Hata durumunda -1 döndür
    }

    // İlgili karakterleri al
    char digits[5]; // 4 karakter + null sonlandırıcı
    digits[0] = key[1];  // 2. karakter
    digits[1] = key[4];  // 5. karakter
    digits[2] = key[7];  // 8. karakter
    digits[3] = key[10]; // 11. karakter
    digits[4] = '\0';    // Null sonlandırıcı
    
    for (int i = 0; i < 5; i++)
    {
        printf("%s",digits[i]);
    }
    
    // Karakterleri tam sayıya çevir
    int number = atoi(digits);

    // Hash değeri hesapla (Tablo boyutuyla mod al)
    return number % TableSize;
}
int main(){
    int array[]={7,3,5,25,8,9,1,4,6};
    int count=sizeof(array)/sizeof(array[0]);
    
  //  QuickSort(array,0,count-1);
   // printArray(array,count);

   h("sevval",10);
    
}
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void QuickSort(int a[],int low,int high){
    
    if (low < high) {  
        //pivotla islem yapılıyor sonra solu kendiisinden kücük sağı buyuk
        // olacak şekilde yerleşiyo ,pi de yerleştiği yer
        int pi = Partition(a, low, high); 
        
        QuickSort(a, low, pi - 1);  
        QuickSort(a, pi + 1, high);  
    }  


}

int Partition(int a[],int low,int high){

    int pi= a[high];
    int i= low-1;

    for(int j=low; j<high; j++){
        if(a[j]<pi){
            i++;
            swap(&a[i],&a[j]);//i ve jnin adresi yolla
        }
    }
    swap(&a[i+1],&a[high]);
    return ( i+1); //pivotu döndür

}
void swap(int* a, int* b) {  
    int t = *a;  //a adresindeki degeri al
    *a = *b;  
    *b = t;  
}  