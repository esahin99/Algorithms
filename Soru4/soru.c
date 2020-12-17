#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,l,m,s=0;
    scanf("%d",&n);
    int* arrA = malloc(n * sizeof(int));	//İlk önce dinamik bir array tanımlıyoruz
    int* arrB = malloc(n * sizeof(int));	//Daha sonra işlem kolaylığı açısından aynı boyutlu 1 dinamik array daha tanımlıyoruz
    
    for(i=1; i<=n; i++){
        scanf("%d",&arrA[i]);				    //Tanımladığımız arrA yı istediğimiz değerler ile dolduruyoruz
    }
    for(i=1; i<=n; i++){					      //Bize yardımcı olacak arrB ye ise tanımladığımız arrA arrayinin değerlerini atıyoruz
        arrB[i] = arrA[i];
    }
    
    j=0,k=0,l=1,m=n;
    for(i=1; i<=n;){					      	//İşlem zamanımız O(n) olabilmesi için iç içe dögü kullanmamamız gerekir dolayısıyla
        if(k == 0){						      	//işlemi yapabilmemiz için çeşitli koşullar koymalıyız.
            arrB[i] = 1;			    		//Benim burada yaptığım işlem ise kabaca i ifadesini her arttırdığımda
            k++;						        	//arrB nin değerini 1 e eşitliyorum çünkü aşağıda çarpma işlemi yaptığımda 1
        }								             	//Değerinin etkisiz eleman olmasını istiyorum.
        if(i == 1){							      //Yaptığım işlemler ise arrayin başı, arrayin ortaları ve arrayin sonu olmak üzere 3 e ayrıldı
            arrB[i] *= arrA[n-j];	    //ve her işlem başarılı bir şekilde sonuçlandığında i yi arttırdığım bir koşul var 
            j++;							        //O koşulda ise i dğerini arttırırken diğer yapılan işlemleri tekrar resetliyorum
        }								            	//Böylece tek 1 for dögüsü ile istenen sonucu basmış oluyorum
        else if(i>1 && i<n){
            if(m != i){
                arrB[i] *= arrA[m];
                m--;
                j++;
            }
            else if(m == i){
                m--;
            }
        }
        else if(i == n){
            arrB[i] *= arrA[n-l];
            l++;
        }
        if(j == n-1){
            i++;
            k = 0;
            j = 0;
            m = n;
        }
        if(l==n)break;
    }
    
    for(i=1; i<=n; i++){
        printf("%d ",arrB[i]);
    }
    

    return 0;
}

