#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


pthread_attr_t attr;

void * thread1(void * data){
    size_t mystacksize;
    pthread_attr_getstacksize(&attr,&mystacksize);
    printf("Thread %d started with stacksize of %li",pthread_self(),mystacksize);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    size_t stacksize;

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr,&stacksize);
    printf("Default stacksize: %li\nEnter the stacksize to override: ",stacksize);
    scanf("%li",&stacksize);

    pthread_attr_setstacksize(&attr,stacksize);
    printf("stacksize: %li\n",stacksize);
    pthread_t thread = 0;
    pthread_create(&thread,&attr,thread1,NULL);

    pthread_join(thread,NULL);


    return 0;
}
