#include <stdio.h>

struct person{
    char * name;
    int age;
};

int main(int argc, char const *argv[])
{
    int arr[6] = {[0]=100,[4]=20};
    int arr2[22] = {[0 ... 9] = 1,[10 ... 20] = 11,[21]=111};

    for (int i = 0; i < 22; i++)
    {
        printf("%d ",arr2[i]);
    }
    
    struct person p1 = {.name = "Vijay" , .age = 20};
    return 0;
}
