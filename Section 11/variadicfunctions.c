#include <stdio.h>
#include <stdarg.h>

int addNumbers(int n, ...)
{
    va_list list;
    va_list copiedList;

    va_start(list, n);
    va_copy(copiedList,list);

    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", addNumbers(2, 10, 20));
    return 0;
}
