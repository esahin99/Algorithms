#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10],i,S1[10],S2[10];
    int n = sizeof(arr)/sizeof(n);
    int bucket[10][10], bucket_cnt[10];
    int j, k, r, m=0, NOP = 0, divisor = 100,pass;
    int digits = 0,power = 1;
    int mx = 0, maximum = arr[0];

    for(i=0; i<10; i++){
        scanf("%d",&arr[i]);
    }
 
    for(int i=1;i<n;i++){
        if(maximum < arr[i])
            maximum = arr[i];
    }

    while(maximum > 0){
        digits++;
        maximum /= 10;
    }

    for(int i=0;i<digits;i++){

        int count[10];
 
        for(int j=0;j<10;j++)
            count[j] = 0;
 
        for(int j=0;j<n;j++){
 
            int num = (arr[j]/power) % 10;
 
            count[num]++;
        }
 
        for(int j=1;j<10;j++){
            count[j] += count[j-1];
        }
 
        for(int j=n-1;j>=0;j--){
 
            int num = (arr[j]/power) % 10;
 
            S1[count[num]-1] = arr[j];
            count[num]--;
        }
        power *= 10;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }

    while (mx > 0){
      NOP++;
      mx /= 10;
    }

    for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (arr[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = arr[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            arr[i] = bucket[k][j];
            i++;
         }
      }
      divisor /= 10;
    }

    for(i=0; i<10; i++){
        S2[i] = arr[i];
    }

    for(i=0; i<10; i++){
        if(S1[i] != S2[i]){
            m += 1;
        }
    }

    for(i=0; i<10; i++){
        printf("%d ",S1[i]);
    }
    printf("\n");
    for(i=0; i<10; i++){
        printf("%d ",S2[i]);
    }
    printf("\n");
    printf("%%%d hata",m*10);

    return 0;
}
