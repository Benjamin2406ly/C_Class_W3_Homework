#include <ins\getPrime.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef SIMPLE
void getPrime_simple(int n){
    if(n<=1){
        return false;
    }
    if(n>=2){
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
void getPrime_simple()
#endif

#ifdef ERATOSTHENES
void getPrime_eratosthenes()
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