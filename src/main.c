#include <stdio.h>
#include <time.h>
#include "getPrime.h"

int main(){
    #ifdef DEBUG
    clock_t start = clock();
    #endif

    getPrime_parallel(10000);

    #ifdef DEBUG
    clock_t end = clock();
    double time =(double)(end-start)/CLOCKS_PER_SEC;
    printf("time is:%.4fs\n",time);
    #endif

    return 0;
}
