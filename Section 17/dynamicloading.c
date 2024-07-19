#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
    void * handle = NULL;
    double (*cosine) (double) = NULL;
    char * error = NULL;

    handle = dlopen("pathtolib",RTLD_LAZY);

    if((error = dlerror()) != NULL){
        exit(1);
    }

    dlerror();

    cosine = dlsym(handle,"cos");

    if(!handle){
        exit(1);
    }

    printf("%f\n",cosine(0.5));

    dlclose(handle);
    return 0;
}
