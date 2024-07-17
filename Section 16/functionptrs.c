#include <stdio.h>
typedef int(*funType)(int,int);


int addtwo(int a,int b){
    return a + b;
}
int subtwo(int a,int b){
    return a - b;
}

int main(int argc, char const *argv[])
{
    funType pfunc;
    int option;
    printf("Add (1) or Subtract(2) : ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        pfunc = addtwo;
        break;
    case 2:
        pfunc = subtwo;
        break;
    default:
        printf("Invalied Option...\n");
        break;
    }
    printf("Answer is %d\n",pfunc(10,20));
    return 0;
}
