#include<stdio.h>
#include<string.h>

//HashTableImplementation with Quadratic Probing
#define TableSize 997

typedef struct a{
    char id[11]; //key olacak
    char  name[20];
    float gno;
}Students;


Students Hash[TableSize]; //GLOBAL HASH TABLE

void initializeHashTable();
int hashFunction(char *key ,int size);
void insert(Students r);
void printHashTable();
void SearchFunction(Students r);
int main(){
    initializeHashTable(); //baslangıcta bos deger atandı


    Students stud1={"2022555058", "SevvalPamu",2.7f};
    Students stud2={"2022111035","MuhammetEf",3.5f};
    insert(stud1);
    insert(stud2);
    printHashTable(); 
    SearchFunction(stud2);

}
void SearchFunction(Students r){
    int i,c,p,q;
    p=hashFunction(r.id,TableSize);  //r için bakılacak hücre deferi
    c=0;
    i=1;  q = p;

    while(strcmp(Hash[p].id,"")!=0 && i <= TableSize/2  ){
        if(strcmp(Hash[p].id, r.id) == 0){  /*String karşılaştırmasında dizinin elemanları birer karakterdir ve tüm elemanların
         sırasıyla karşılaştırılması gerekir. == operatörü bunu yapmaz, sadece adreslere bakar. Bu yüzden strcmp kullanılır:*/
            printf("You find it %d. sirada \n , Name is: %s",p,Hash[p].name);
            break;
        }
        p = q + i * i; 
        i++;
        if (p >= TableSize) { // Tabloyu aşmamak için mod alıyoruz
            p = p % TableSize;
        }
        
    } 

}
void printHashTable(){
    for (int i=0; i<TableSize; i++)
    if(strcmp (Hash[i].id,"")!=0){
        printf("%d.Sira , Name %s  \n ",i,Hash[i].name);
    }
}
void initializeHashTable(){
   int i;
   for (i=0; i<TableSize; i++)
    strcpy(Hash[i].id,""); //= kullansaydık pointer ataması olurdu
} 

int hashFunction(char *key ,int size){
    int i,j,k,result;
   // 48 is ASCII code of 0
   //eger key 'in ASCII degeri; 3151652515 gibi bir şey ise key[10]-48= '5'-48=5 olur;
   //key char dizisi olduğu için ASCII üzerinden islem yapılır

   //tabloya koymak için 3 eleman seçtik key içinden
   i = key[10]-48;   //last digit  
   j = key[9]-48;  // 2nd digit from last
   k = key[6]-48; // 5th digit from last

   result = (k*100 + j*10 + i) % size;

   return result;

}
void insert(Students r){
   int c,i,p,q;
   p=hashFunction(r.id,TableSize); //tabledaki bakılan hücre degeri
   c=0;
   i=1;  q = p;
   while ((strcmp(Hash[p].id,"")!=0) &&   //iki string eşitse 0 döndürür
          (strcmp(Hash[p].id,r.id)!=0) &&  
          (c <= TableSize/2)){ //bu koşul sonsuz döngüden korunmak için konulmuştur ,c deneme sayısıdır
      c++;
      p = q + i * i; 
      i++; // (quadratic probing çarpanı)
      if (p > TableSize-1)
         p = p % TableSize;
   }
   if (strcmp(Hash[p].id,"")==0){ //eger hücre boşsa
       Hash[p]=r;
    }
    else if(strcmp(Hash[p].id,r.id)==0){
        printf("Aynı key degerinden var");
    }
    else{
        printf("Overflow, counter has reached its limit\n");
    }
}

