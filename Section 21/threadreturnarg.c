#include <stdio.h>
#include <pthread.h>

struct thread_data{
    int dummyvalue;
    char * message;
};

void * thread1(void * message){
    struct thread_data * m = (struct thread_data *) message;
    printf("This is thread 1. Dummy is %d and pass is %s\n",m->dummyvalue,m->message);
    char * result1 = "This is a result from thread 1";
    return (void * ) result1;
}

void * thread2(void * message){
    struct thread_data * m = (struct thread_data *) message;
    printf("This is thread 2. Dummy is %d and pass is %s\n",m->dummyvalue,m->message);
    char * result2 = "This is a result from thread 2";
    return (void * ) result2;
}

int main(int argc, char const *argv[])
{
     
    struct thread_data d1 = {10,"Hi thread 1..."};
    struct thread_data d2 = {30,"Hi thread 2..."};
    pthread_t t1,t2;

    int t1ret = pthread_create(&t1,NULL,thread1,(void *) &d1);
    int t2ret = pthread_create(&t2,NULL,thread2,(void *) &d2);

    char * result1;
    char * result2;

    pthread_join(t1,(void **) &result1);
    pthread_join(t2,(void **) &result2);

    printf("Process finished and T1 returned %d with result \"%s\".\n",t1ret,result1);
    printf("Process finished and T2 returned %d with result \"%s\".\n",t2ret,result2);
    return 0;
}
