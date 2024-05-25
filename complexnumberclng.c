#include <stdio.h>
#include <complex.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    double complex var = 12+10*I;
    printf("Real part : %f\nImaginary part : %f",creal(var),cimag(var));
    
    // double complex sqrd = creal(var) + (cimag(var)*cimag(var)) * I;
    double complex sqrd = creal(var) + pow(cimag(var),2) * I;

    
    printf("\nSquared Imag is : %f+%fi",creal(sqrd),cimag(sqrd));
    
    return 0;
}

