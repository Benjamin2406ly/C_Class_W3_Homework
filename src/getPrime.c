#include <ins\getPrime.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef SIMPLE
void getPrime_simple(int n){
    if(n<=1)return false;
    else{
        printf("2");
//n是输入的数,i是小于等于n的所有奇数，j是为了判断i是否为素数的因子
        for(int i =3;i<=n;i+=2){
          if(for(int j=3;j<=i;j+=2){if(i%j !== 0)return true}){
            printf("%d",i);
          }
        }
    }
    printf("\n");
}
#endif

#ifdef SQRT
void getPrime_sqrt(int n){
    if(n<=1)return false;
    else{
        printf("2");
//n是输入的数,i是小于等于n的所有奇数，j是为了判断i是否为素数的因子
        for(int i =3;i<=n;i+=2){
          if(for(int j=3;j*j<=i;j+=2){if(i%j !== 0)return true}){
/*          
与simple方法相比，这里是j*j,相当于只遍历到sqrt(n)节省了时间
在n比较小时，大于sqrt(n)的因子会成对出现，比如n=a*b，有a>sqrt(n)，b<sqrt(n)，因此在n比较小的时候，该方法更高效
*/
            printf("%d",i);
          }
        }
    }
    printf("\n");
}
#endif

#ifdef ERATOSTHENES
void getPrime_eratosthenes(int n){
    if(n<=1)return false;
    else{
        printf("2");
    
        bool prime[n+1];
        memset(prime,true,sizeof(prime));  //初始化

        int i=1;
        do{
            i++;
            if(prime[i]){
                for(int j=i*i; j<=n; j+=i){
                    prime[j]=false;
                }
            }
        }while(i*i<=n);

        for(int i=3;i<=n;i+=2){
            if(prime[i])printf("%d",i);
        }
        printf("\n");
    }
}
#endif

#ifdef LINEAR
void getPrime_linear()
#endif

#ifdef SEGMENT
void getPrime_segment()
#endif

#ifdef EULER
void getPrime_euler()
#endif

#ifdef BITWISE
void getPrime_bitwise()
#endif

#ifdef PARALLEL
void getPrime_parallel()
#endif