#include <stdio.h>
#include <stdlib.h>

int isPrime(long int number){
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int isOdd(long int number){
    if (number % 2 == 0)
    {
        return 0;
    }else{
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("numbers.txt","r");
    char * string;
    size_t stringsize = 30;
    size_t charecter = 1;

    string = (char *)malloc(stringsize * sizeof(char));

    while (1)
    {
        long int number = 0;
        charecter = getline(&string,&stringsize,fp);
        if (charecter == -1)
        {
            break;
        }
        sscanf(string,"%ld\n",&number);
        if (isPrime(number) == 1)
        {
            printf("Detected Prime number: %ld\n",number);
        }

        if (isOdd(number) == 1)
        {
            printf("Detected Odd number: %ld\n",number);
        }else{
            printf("Detected Even number: %ld\n",number);
        }
    }
    
    return 0;
}
