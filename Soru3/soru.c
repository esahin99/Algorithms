#include <stdio.h>
#include<stdlib.h>

struct Node { 
    int data1,data2; 
    struct Node* next; 
};

int main() {
  //Mainde tekrardan head node umuzu oluşturduk ve head in nextini NULL olarak atadık.
  int sayi;
  struct Node* head = NULL;
  struct Node* temp;
  head = (struct Node*)malloc(sizeof(struct Node));
  head -> next = NULL;
  temp = head;
  scanf("%d",&sayi);
  //bu döngüde girdiğimiz sayı kadar node oluşturduk ve ilk değerine sıra ile i yi atadık ikinci değerine default olarak 0 ı atadık.
  for(int i=1; i<=sayi; i++){
    temp -> next = (struct Node*)malloc(sizeof(struct Node));
    temp -> data1 = i;
    temp -> data2 = 0;
    temp = temp -> next;
    temp -> next = NULL;
  }
  temp = head;
  int x = 1;
  //bu 2 for dongüsünde ise her node u teker teker kontrol ettik eğer node un data1 i x ile bölünebiliyorsa o değerin data2 sini değiştirdik ve bir sonraki node geçiş yaptık.
  for(int j=1; j<=sayi; j++){
    for(int j=1; j<=sayi; j++){
      if(temp->data1 % x == 0){
        if(temp->data2 == 1){
          temp -> data2 = 0;
          temp = temp -> next;
        }
        else{
        temp -> data2 = 1;
        temp = temp -> next;
        }
      }
      else{
        temp = temp -> next;
      }
    }
    temp = head;
    x = x + 1;
  }
  temp = head;
  //son olarak ise data2 si 1 olan nodeların değerlerini bastırdık.
  for(int k=1; k<=sayi; k++){
    if(temp->data2 == 1){
      printf("%d ",temp->data1);
      temp = temp -> next;
    }
    else{
      temp = temp -> next;
    }
  }
  return 0;   
}
