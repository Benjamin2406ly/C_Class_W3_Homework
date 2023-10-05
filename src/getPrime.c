/*
**所有方法均排偶
*/
#include <ins\getPrime.h>
#include <stdio.h>
#include <stdbool.h>

/*
**简单遍历
*/
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

/*
**仅遍历到sqrt(n)，节省时间
*/
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

/*
**Eratosthenes法
*/
#ifdef ERATOSTHENES
void getPrime_eratosthenes(int n){
    if(n<=1)return false;
    else{
        printf("2");
    
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
            if(prime[i])printf("%d",i);
        }
        printf("\n");
    }
}
#endif

/*
**线性法，网上找的，但不知道为什么叫线性@_@，可能只是因为prime和_prime两个数组都只遍历了一次，时间复杂度为O(n)
*/
#ifdef LINEAR
void getPrime_linear(int n){
    if(n<=1)return false;
    else{
        printf("2");

        bool prime[n+1];                   //bool数组
        int _prime[n+1];                   //整型数组，用_区分
        _prime[0]=2;                       //初始化
        memset(prime,true,sizeof(prime));  //初始化

        int count = 1;

        for(int i=3;i<=n,i+=2){
            if(prime[i])_prime[count++]=i;               //所有小于等于n的奇数储存在_prime的前面count个位置上

            for(int j=0;j<count && i*_prime[j]<=n;j++){  //所有奇数的组合相乘都是合数，全改为false
                prime[i*_prime[j]]=false;
                if(i%_prime[j]==0)break;                 //保留素数
            }
        }

        for(int i=0;i<count,i++)printf("%d",_prime[i]);
        printf("\n");
    }
}
#endif

/*
**limit之前的合数用Eratosthenes法找，limit之后的合数，以limit前已经找出的素数，用线性法找
**时间复杂度O(n*log(logn))
*/
#ifdef SEGMENT
void getPrime_segment(int n){
    if(n<=1)return false;
    else{
        printf("2");

        int limit=sqrt(n)+1;        //segment上界,向上取整
        bool prime[limit+1];
        memset(prime,true,sizeof(prime));

        for(int i=3;i*i<=limit;i+=2){//用上面的eratosthenes法，找到小于等于limit的所有素数
            if(prime[i])for(int j =i*i;j<=limit;j+=i)prime[j]=false;   //合数
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
          
            for(int j=start;j<=n;j+=current_prime)segment[j]=false; 比如3*3+3+3是合数
        }

        for(int i=2;i<=n;i++){
            if(segment[i])printf("%d",i);
        }
        printf("\n");
    }
}
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