#include <stdio.h>

union student
{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
}variable1,variable2;


int main(int argc, char const *argv[])
{
    variable1.exactGrade = 86.5;
    printf("\nLetter grade: %c\nRounded Grade: %d\nExact grade: %f\n\n",variable1.letterGrade,variable1.roundedGrade,variable1.exactGrade);
    
    variable2.letterGrade = 'A';
    printf("Letter grade : %c\n",variable2.letterGrade);
    variable2.roundedGrade = 100;
    printf("Letter grade : %d\n",variable2.roundedGrade);
    variable2.exactGrade = 99.5;
    printf("Letter grade : %f\n",variable2.exactGrade);
    return 0;
}
