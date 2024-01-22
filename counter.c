#include <stdio.h>

int count = 0;

void countNow(void){
    count++;
}
void sayCount(void){
    printf("The Count is %d\n",count);
}