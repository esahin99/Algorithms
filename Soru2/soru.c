#include<stdio.h>
#include<stdlib.h>

//Linked list için temel kısımlar oluşturulur.
struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev;
};

int main(){
  int sayi;
  struct Node* head = NULL;
  struct Node* tail;
  struct Node* orta;
  struct Node* temp;

  //head'e ilk node bağlanır ve headin nexti NULL olarak atanır daha sonra temp ve orta isimli nodelarda headin gösterdiği yeri gösterir
  head = (struct Node*)malloc(sizeof(struct Node));
  head -> next = NULL;
  head -> prev = NULL;
  tail=head;
  temp = head;
  orta = head;

  while(sayi != -1){
    //istenilen sayıda değer girilir ve her değer girildiğinde yeni bir node oluşturulur ve bir sonraki değer bu node a yerleştirilir.
    scanf("%d",&sayi);
    if(sayi == -1){break;}
    tail -> next = (struct Node*)malloc(sizeof(struct Node));
    tail -> data = sayi;
    tail = tail -> next;
    tail->prev = temp;
    temp = temp->next;
    tail -> next = NULL;
  }
  //en sondaki node a değer atanmadğı için el ile -1 değeri atanır.
  orta->prev = tail->prev;
  tail->data = -1;

  while(orta->next != NULL){
    while(orta->next != NULL){
      if(orta->data <= orta->next->data){
        printf("%d ",orta->data);
        orta = orta->next;
      }
      else if(orta->prev->data <= orta->data){
        printf("%d\n",orta->data);
        orta = orta->next;
      }
      else{
        break;
      }
    }
    if(orta->next == NULL){break;}
    while(orta->next != NULL){
      if(orta->data >= orta->next->data){
        printf("%d ",orta->data);
        orta = orta->next;      
      }
      else if(orta->prev->data >= orta->data){
        printf("%d\n",orta->data);
        orta = orta->next;
      }
      else{
        break;
      }
    } 
  }
  return 0;
}
