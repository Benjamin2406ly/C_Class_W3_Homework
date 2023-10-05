#include <stdio.h>
#include <time.h>

int main(){
    #ifdef DEBUG
    clock_t start = clock();
    #endif


    #ifdef DEBUG
    clock_t end = clock();
    double time =(double)(end-start)/CLOCKS_PER_SEC;
    printf("该方法下，程序运行时长为:%.4f秒\n",time);
    #endif

    return 0;
}
