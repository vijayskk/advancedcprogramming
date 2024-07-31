#include <stdio.h>
#include <pthread.h>

void * threadFn(){
    printf("This is a thread...\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread = 0;
    pthread_create(&thread,NULL,threadFn,NULL); // Creates a thread
    pthread_join(thread,NULL);  // Waits for the thread to finish
    pthread_exit(NULL); // Close all the threads
    return 0;
}
