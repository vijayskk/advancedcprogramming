#include <stdio.h>
#include <pthread.h>

struct thread_data{
    int dummyvalue;
    char * message;
};

void * thread1(void * message){
    struct thread_data * m = (struct thread_data *) message;
    printf("This is thread 1. Dummy is %d and pass is %s\n",m->dummyvalue,m->message);
    return NULL;
}

void * thread2(void * message){
    struct thread_data * m = (struct thread_data *) message;
    printf("This is thread 2. Dummy is %d and pass is %s\n",m->dummyvalue,m->message);
    return NULL;
}

int main(int argc, char const *argv[])
{
     
    struct thread_data d1 = {10,"Hi thread 1..."};
    struct thread_data d2 = {30,"Hi thread 2..."};
    pthread_t t1,t2;

    int t1ret = pthread_create(&t1,NULL,thread1,(void *) &d1);
    int t2ret = pthread_create(&t2,NULL,thread2,(void *) &d2);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Process finished and T1 returned %d and T2 returned %d\n",t1ret,t2ret);
    return 0;
}
