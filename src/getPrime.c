/*
**所有方法均排偶
*/
#include "getPrime.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

/*
**简单遍历
*/
#ifndef SIMPLE
void getPrime_simple(int n){
    if(n<=1)return;
    else{
        printf("2 ");
//n是输入的数,i是小于等于n的所有奇数，j是为了判断i是否为素数的因子
        for(int i =3;i<=n;i+=2){
            bool is_prime=true;

            for(int j=2;j<i;j++){
                if(i%j == 0){
                is_prime = false;
                break;
                }
            }

            if(is_prime){
                printf("%d ",i);
            }
        }
    }
    printf("\n");
}
#endif

/*
**仅遍历到sqrt(n)，节省时间,这个思想后面的方法也用到了
*/
#ifndef SQRT
void getPrime_sqrt(int n){
    if(n<=1)return;
    else{
        printf("2 ");
//n是输入的数,i是小于等于n的所有奇数，j是为了判断i是否为素数的因子
        for(int i =3;i<=n;i+=2){
            bool is_prime=true;
            for(int j=3;j*j<=i;j+=2){
                if(i%j == 0){
                is_prime = false;
                break;
                }
            }

            if(is_prime){
/*          
与simple方法相比，这里是j*j,相当于只遍历到sqrt(n)节省了时间
在n比较小时，大于sqrt(n)的因子会成对出现，比如n=a*b，有a>sqrt(n)，b<sqrt(n)，因此在n比较小的时候，该方法更高效
*/
            printf("%d ",i);
          }
        }
    }
    printf("\n");
}
#endif

/*
**Eratosthenes法
*/
#ifndef ERATOSTHENES
void getPrime_eratosthenes(int n){
    if(n<=1)return;
    else{
        printf("2 ");
    
        bool prime[n+1];
        memset(prime,true,sizeof(prime));  //初始化

        int i=1;
        do{
            i+=2;
            if(prime[i]){
                for(int j=i*i; j<=n; j+=i){ //从i^2开始，以i递增，这些数都是合数，比如3*2+3=3*4
                    prime[j]=false;
                }
            }
        }while(i*i<=n);

        for(int i=3;i<=n;i+=2){
            if(prime[i])printf("%d ",i);
        }
        printf("\n");
    }
}
#endif

/*
**线性法，网上找的，但不知道为什么叫线性@_@，可能只是因为prime和_prime两个数组都只遍历了一次，时间复杂度为O(n)
*/
#ifndef LINEAR
void getPrime_linear(int n){
    if(n<=1)return;
    else{
        bool prime[n+1];                   //bool数组
        int _prime[n+1];                   //整型数组，用_区分
        _prime[0]=2;                       //初始化
        memset(prime,true,sizeof(prime));  //初始化

        int count = 1;

        for(int i=3;i<=n;i+=2){
            if(prime[i])_prime[count++]=i;               //所有小于等于n的奇数储存在_prime的前面count个位置上

            for(int j=0;j<count && i*_prime[j]<=n;j++){  //所有奇数的组合相乘都是合数，全改为false
                prime[i*_prime[j]]=false;
                if(i%_prime[j]==0)break;                 //保留素数
            }
        }

        for(int i=0;i<count;i++)printf("%d ",_prime[i]);
        printf("\n");
    }
}
#endif

/*
**limit之前的合数用Eratosthenes法找，limit之后的合数，以limit前已经找出的素数，用线性法找
**时间复杂度O(n*log(logn))
*/
#ifndef SEGMENT
void getPrime_segment(int n){
    if(n<=1)return;
    else{
        int limit=sqrt(n)+1;        //segment上界,向上取整
        bool prime[limit+1];
        memset(prime,true,sizeof(prime));

        for(int i=3;i*i<=limit;i+=2){//用上面的eratosthenes法，找到小于等于limit的所有素数
            if(prime[i]){for(int j =i*i;j<=limit;j+=i)prime[j]=false;}   //合数
        }

        int _prime[limit+1];
        _prime[0]=2;                 //初始化
        int count = 1;

        for(int i=3;i<=limit;i+=2){
            if(prime[i])_prime[count++]=i;
        }

        bool segment[n+1];
        memset(segment,true,sizeof(segment));  //初始化标记数组

        for(int i=0; i<count;i++){
            int current_prime = _prime[i];
            int start=current_prime*current_prime;
          
            for(int j=start;j<=n;j+=current_prime)segment[j]=false; //比如3*3+3+3是合数
        }

        for(int i=2;i<=n;i++){
            if(segment[i])printf("%d ",i);
        }
        printf("\n");
    }
}
#endif

/*
**本质上就是线性法
*/
#ifndef EULER
void getPrime_euler(int n){
    getPrime_linear(n);
}
#endif

/*
**用位图记录合数与素数，1为合数，0为素数，节省内存
*/
#ifndef BITMAP
void getPrime_bitmap(int n){
    if(n<=1)return;
    else{
        printf("2");

        int bytes_needed = (n + 7) / 8;                     //计算需要的字节数，每个字节8个位，+7是为了保证字节足够
        
        uint8_t *bitmap = (uint8_t *)malloc(bytes_needed);  //创建储存位的数组并分配内存
        memset(bitmap, 0, bytes_needed);                    //1为合数，0为素数

        for(int i=0;i<bytes_needed;i++)bitmap[i] |=0xAA;    //10101010把每个字节里面偶数位先全标记为合数

        for (int i = 2; i * i <= n; i++) {
            if (!(bitmap[i / 8] & (1 << (i % 8)))) {        //bitmap[i / 8] & (1 << (i % 8))表示检查第[i / 8]字节的第(i % 8)位是否为1，比如5就是第一字节第五位，而初始化时第一字节第五位为0，不为1
                for (int j = i * i; j <= n; j += i) {       //同Eratosthenes法
                    bitmap[i / 8] |= (1 << (i % 8));        //合数标为1
                }
            }
        }

        for (int i = 3; i <= n; i+=2) {
            if (!(bitmap[i / 8] & (1 << (i % 8)))) printf("%d ", i);
        }
        printf("\n");

        free(bitmap);                                       //释放内存
    }
}
#endif

/*
**用OpenMP库进行多线程运行
*/
#ifndef PARALLEL
void getPrime_parallel(int n){
    if(n<=1)return;
    else{
        printf("2 ");

        bool *prime = (bool *)malloc((n+1)*sizeof(bool));   //bool prime[n+1]换个方式
        memset(prime,true,(n+1)*sizeof(bool));                   //初始化

        #pragma omp parallel
        {
            #pragma omp for
            for(int i=3;i*i<=n;i+=2){
                if(prime[i]){
                    for(int j=i*i;j<=n;j+=i)prime[j]=false;     //同Eratosthenes法
                }
            }
        }

        #pragma omp parallel
        {
            #pragma omp for
            for(int i=3;i<=n;i+=2){
                if(prime[i])printf("%d ",i);
            }
        }
        printf("\n");

        free(prime); 
    }
}
#endif