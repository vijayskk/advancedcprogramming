#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
    void * handle = NULL;
    double (*cosine) (double) = NULL;
    char * error = NULL;

    handle = dlopen("/usr/lib/aarch64-linux-gnu/libm.so.6",RTLD_LAZY);

    if(handle == NULL){
        exit(1);
    }

    dlerror();

    cosine = dlsym(handle,"cos");


    printf("%f\n",cosine(0.5));

    dlclose(handle);
    return 0;
}
