#include <stdio.h>
#include <pthread.h>

void * thread1(void * message){
    printf("This is thread 1 and pass is %s\n",(char *) message);
    return NULL;
}

void * thread2(void * message){
    printf("This is thread 2 and pass is %s\n",(char *) message);
    return NULL;
}

int main(int argc, char const *argv[])
{
    char * mess1 = "STRONGPASS";
    char * mess2 = "ANOTHERSTRONGPASS";

    pthread_t t1,t2;

    int t1ret = pthread_create(&t1,NULL,thread1,(void *) mess1);
    int t2ret = pthread_create(&t2,NULL,thread2,(void *) mess2);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Process finished and T1 returned %d and T2 returned %d\n",t1ret,t2ret);
    return 0;
}
