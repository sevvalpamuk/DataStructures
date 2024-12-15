#include<stdio.h>
#include<stdlib.h>

void MergeSort(int a[], int left, int right);
void printArray(int a[], int n);
void Merge(int a[], int mid, int left, int right);

int main() {
    int array[] = {7, 3, 5, 25, 8, 9, 1, 4, 6};
    int count = 9;

    MergeSort(array, 0, count - 1); // Diziyi sıralar
    printArray(array, count);       // Sıralı diziyi yazdırır
    return 0;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void MergeSort(int a[], int left, int right) {

    if(left<right){
        int mid = (left + right) / 2;

        MergeSort(a, left, mid);      // Sol alt diziyi sıralar
        MergeSort(a, mid + 1, right); // Sağ alt diziyi sıralar
        Merge(a, mid, left, right);   // İki sıralı alt diziyi birleştirir
    }
   
}

void Merge(int a[], int mid, int left, int right) {
    int n1 = mid - left + 1; // Sol alt dizinin boyutu
    int n2 = right - mid;    // Sağ alt dizinin boyutu

    // Geçici diziler için bellek tahsisi yapıyoruz
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Bellek tahsisi hatası!\n");
        exit(1);  // Bellek tahsisi başarısız olduğunda programı sonlandırıyoruz
    }

    // Verileri geçici dizilere kopyala
    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = a[mid + 1 + i];
    }

    // Birleştirme işlemi
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Kalan elemanları kopyala   
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
