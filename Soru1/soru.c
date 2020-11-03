#include<stdio.h>
int i = 1;
void obeb(int a,int b){
  if(a % 2 == 0 && b % 2 == 0){
    a = a / 2;
    b = b / 2;
    printf("a ");
    i = i + 1;
    obeb(a,b);
  }
  else if(a % 2 == 0 && b % 2 == 1){
    a = a / 2;
    printf("b ");
    obeb(a,b);
  }
  else if(b == 0){
    printf("c %d",a*i);
  }
  else if(a >= b){
    int temp;
    temp = a;
    a = b;
    b = temp - b;
    printf("d ");
    obeb(a,b);
  }
  else{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("e ");
    obeb(a,b);
  }
}
int main(){
  int sayi1,sayi2;
  scanf("%d %d",&sayi1,&sayi2);
  
  obeb(sayi1,sayi2);

  return 0;
}
