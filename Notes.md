# Section 4
All notes for the tutorial will be here

## Makefiles
Makefiles are tools used for automating the building task.
They have variables called **Macros**

A macro can be initialized as 
```makefile
CC = gcc
```
conventionaly CC is the program to be executed. We can define any value as a macro
```makefile
CC = gcc
CFLAGS = " -v "
```
Then we have something called a process. A process can be defined with the files that are being affected.
```makefile
main: main.c function.c
    $(CC) $? $(CFLAGS) -o $@.o
```
Tha make program will just fill in the macros and execute any command. The Macros will be distributed as:
* ``$(CC)`` and ``$(CFLAGS)`` will split out the values of the variables
* ``$?`` will give the changed filenames.
* ```$@``` will give the current process name in this case *main* 


## Variable Scopes

### Global variables

Global variables are defined in the top of a file and outside of any function

```c
#include <stdio.h>


int multip = 10; // This is a global variable 

void printmult(){
    printf("The Multiplier is %d\n",multip);
}

int main(int argc, char const *argv[])
{
    printf("%d\n",multip);
    printmult();
    return 0;
}
```
*Here all the functions inside the file can access the variable*

### External variables
External variables are variables which are declared in a file and can be accessed across any file in the project.

This is the *fun.c* file 
```c
#include "functions.h"
#include <stdio.h>

extern int myextern;  // The external variable is defined here

void getmyextern(){
    printf("%d\n",myextern);
}
```

The *main.c* file is: 
```c
#include <stdio.h>
#include "functions.h"

int myextern = 10; // This is the initialisation

int main(int argc, char const *argv[])
{
    printf("%d\n",myextern); // Output: 10
    getmyextern(); // Output: 10
    return 0;
}
```

## Header file uses
* A program can be divided into individual files and that can be maintained easyly.

* Macros , functions , enums and structers are all can be defined in a header file 
eg:
```c
extern int hello;
int myfunc(int a);
void getmyextern();
```

## Memory types
### Stack memory
* Memory that is used inside a function. 
* Locally available so easy to track.
* Uses LIFO (last in first out) method to save variables.
* Allocated and freed automatically.
### Heap memory
- Have a hierarchial structure.
- A larg pool which is used dynamicaly
- Managed by programer (not automatic)
- Accessed using pointers
- Created using ```malloc()```
- Deleted using ```free()```
- Restriction is only the physical size of memory.
- Global 
- Slower
### How to selct

|  Stack | Heap  |
|---|---|
|  For small memory |  When need larger memory |
| When only need to persist when the function is alive | When to keep the data for a long time |
| Easier and faster | When to allocate data dynamically (arrays,struct) |

# Section 5
## Storage classes
classified with respect to it's scope,visiblity and lifetime.
### Auto variable 
- The lifetime is defined automatically. 
- A variable in a function or loop is defaultly automatic.
- Because the default ```auto``` keyword is not used that much.

eg:
```c
#include <stdio.h>

int main(){
    for (int i = 0;i<=10;i++){
        auto int age = 18;
        printf("%d",age);
    }
    // age is destroyed when exited the loop 
}
```
### Extern variable
- The lifetime is as the program exits.
- Can initialize an external variable with a legal value where it declared.
- Can be accessed within files.
- every fle must reinitialize them to use. But the value will be same everywhere.

fun.c file:
```c
#include "functions.h"
#include <stdio.h>

extern int myextern;  // The extern varable is defined

void getmyextern(){
    printf("%d\n",myextern); // can be accessed in the same file
}
```

main.c file:
```c
#include <stdio.h>
#include "functions.h"


int myextern = 10;  // The variable is initialized.


int main(int argc, char const *argv[])
{
    printf("%d\n",myextern); // can be used in the same file
    getmyextern();
    return 0;
}

```

When using arrays we dont have to give the dimention of the size while defining an extern variable.

fun.c file:
```c
#include <stdio.h>

extern char password[];
void printpass(void){
    printf("%s\n",password);
}
```
main.c file:
```c
#include <stdio.h>
#include "functions.h"

char password[30] = "12345";
void printpass(void);

int main(int argc, char const *argv[])
{
    printf("%s\n",password);
    printpass();
    return 0;
}
```

for multi-dimentional arrays we have to specify the second size of the array.
```c
extern int data[][10];
```
This denotes a multi dimentional array with 10 fixed columns and as many rows as we initialize.

We can make functions also  



# Section 6
## Advanced Datatypes
### Variable length arrays
A variable length array have the length of an expression executed at the runtime.
It doesn't mean you can modify that after we create.
Just means that we can give a variable at the position of the size f the array.
```c
#include <stdio.h>

int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("array of %d elements created.",size);
}
```
### Flexible array members
Flexible array membes is a technique where we can specify the length of the array in runtime and also we can modify it. Here is an example code.
```c
#include <stdio.h>
#include <stdlib.h>
struct flexarr
{
    int arraysize;
    int array[];
};

int main(int argc, char const *argv[])
{
    int desiredSize = 5;
    struct flexarr * ptr;
    ptr = malloc(sizeof(struct flexarr) + desiredSize + sizeof(int));
    return 0;
}
```
### Complex Numbers
A number in the form of *a+ib*
```c
#include <stdio.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    double complex var = 12+10*I;
    printf("Real part : %f\nImaginary part : %f",creal(var),cimag(var));
    
    double complex sum = var + var;
    
    printf("\nSum is : %f+%fi",creal(sum),cimag(sum));
    
    return 0;
}

```
### Designated Initialization
Designated initializers are used to initialize only some certain members of the array. For example:
```c
int arr[6] = {[0]=100,[4]=20};
// Output: 100 0 0 0 20 0 
```
This initializes only 0th position and 4th position. All other elements are set to be zero.

Also we can specify a range of numbers to initialize.
```c
int arr2[22] = {[0 ... 9] = 1,[10 ... 20] = 11,[21]=111};
// Output: 1 1 1 1 1 1 1 1 1 1 11 11 11 11 11 11 11 11 11 11 11 111
```

Similiar will work in struct also.
```c
struct person{
    char * name;
    int age;
};

int main(){
    struct person p1 = {.name = "Vijay" , .age = 20};
}
```
### What you know

What is the output of the following program?#define NUMBER 55 #define NUMBER2 20 int main() { int i = NUMBER > NUMBER2; printf("%d", i); }

What will be the output of the following program?#include<stdio.h> #define x 4 int main() { int y; y= x*x*x; printf("%d",y); return 0; }

Write a preprocessor directive to accomplish each of the following:Define symbolic constant YES to have the value 1

The keyword typedef is used to define a new data type (T/F)

What will be the output of the following program?typedef int integer; int main() { int i = 22, *ptr; float f = 33; integer j = i; ptr = &j; printf("%d\n", *ptr); return 0; }

We want to declare x, y and z as pointers of type int. The alias name given is: int_ptrThe correct way to do this using the keyword typedef is:

One of the major differences between typedef and #define is that a typedef interpretation is performed by the _________________ where as a #define interpretation is performed by the _____________.

Declare an array of 100 ints and initialize it so that the last element is -1

An array whose length is defined in terms of a value determined at execution time is a __________.

A variable-length array can change in size during its lifetime. (T/F)

If you include the <complex.h> header, you can use the complex type (T/F)
### What you should review

What will be the output of the following program?#include<stdio.h> #define int char int main() { int x=8; printf ("sizeof (x) =%d", sizeof (x)); }

__________ allow us to initialize elements of an array explicitly by using a subscript.

Declare an array of 100 ints and initialize it so that elements 5, 10, 11, 12, and 3 are 101
Continue

# Section 7
## Type qualifiers
Type qualifiers can be used to give more information about the variable to the compiler.
Examples are const,volatile,restrict
### Const
const keyword represents a constant variable once it is initialized with a value it cannot be changed.
Trying to do so will produce an error.
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const double pi = 3.14;
    const int nums[2] = {1,2};
    typedef const int myvarname;
    const myvarname var = 10;
    const int * ptr;
    return 0;
}
```
### Volatile
volatile keyword represents that this variable will be changed during runtime so the compiler will supress various optimizations against reduntant assignments.
Also prevents caching of variables.

Chosable when:
- Programs that have a lot of threading 
- Programs where resources are scarce
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    volatile double loc1;
    volatile double *ptr1;
    volatile int clock;
    return 0;
}
```
### Restrict
Used as an optimization hint for type qualifiers. In case of pointers, restrict tells to compiler that this pointer is not going to be changed throughout it's lifetime and it is the sole object to save the data. This cancels all the other checks. Also there will be only that pointer which access a specific data. Anyway the compiler can chose to ignore it.
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int * restrict ptr2; 
    int * restrict ptr3;
    // Cannot have same address
    return 0;
}
```
### What you know

- What will be the output of the following program? #include <stdio.h> void main() { int k = 4; int *const p = &k; int r = 3; p = &r; printf("%d", p); }

- What will be the output of the following program? #include <stdio.h> void main() { int const k = 5; k++; printf("k is %d", k); }

- One of the main use cases for using the volatile type qualifier is to ensure that global variables accessed by multiple tasks within a multi-threaded application are not optimized by the compiler

- Can a pointer be volatile? Explain your answer.

- The restrict type qualifier can be applied to all data types (T/F)

- The restrict type qualifier is not supported by C++  (T/F)
### What you should review

- Which of the following statements is false?

- Can a parameter be both const and volatile? Explain your answer.

- The restrict type qualifier is an optimization hint for the compiler that is must follow (T/F)

# Section 8
## Bit Manipulation 
### Binary numbers or bits
bits for the basic datatypes in c are 

| type    | bits   | values |
| -------- | ------- | -------|
| bool | 1 | 0 to 1|
| char | 8 | -128 to 127 | 
| short int | 16 | -32768 to 32767 |
| long int | 32 | -2,147,483,648 to 2,147,483,647 | 
### Negative numbers
Negative numbers are represented in the computer using two's complement method. The leftmost bit indicates the sign. If it is 1 then it is a -ve number. 
To convert to two's complement, add 1 and complement the result

- -5  >>>  -4  >>> 00000100 >>> 11111011

To convert back: 
Complement all the bits, convert it to decimal,give -ve sign and subtract 1.


- 11111011 >>> 00000100 >>> 4 >>> -4 >>> -4-1 = -5

### Bitwise Operators
Bit manipulation is the act of manipulating data algorithamically that is shorter than a word (2 Bytes).

Use cases of bit manipulation are: 
- Low-level device control
- Error detection
- Correction algorithms
- Data compression
- Encryption
- Optimization 
Bit manipulation is far faster than any basic operation.

C offers logical as well as Shifting operators.
| Symbol | Operation |
|---|---|
| & | AND |
| \| | OR |
| ^ | XOR | 
| ~ | Ones cpl | 

*They are not regular logical operators ( && , || ).Don't be confused*

- They operate on each bit indepentend of the order ( to left or to right )

- All except ```~``` takes two operators so they are called binary operators.

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{

    long int a = 154;
    long int b = 100;
    long int c = 12;
    printf("%ld",~(a));
    printf("%ld",(a & b));
    printf("%ld",(a | b));
    printf("%ld",(b ^ c));
    return 0;
}
```
### Ones complement
If you don't know the bit size of a machine (32 or 64 or whatever) setting a bit to zero can be done by using complement method.
eg:
```
// know that w1 = 1 
w1 = w1 & 11111110;
```
This works fine if the system is 32 bit but what if it not?
```c
w1 = w1 & ~(1);
```
This works on any machine.
1 is converted to its complement as per the system.

### Bitwise shifting operators
C has leftshift and rightshift operators.
| Operator | Description |
|:---:|:---:|
| << | The leftshift operator. Shifts the entire binary to left. |
| >> | The rightshift operator. Shifts the entire bnary towards right. |

```c
int a = 8; // 0000 0000 0000 0000 0000 0000 0000 1000
a = a >> 1; // 0000 0000 0000 0000 0000 0000 0000 0100
a = a << 1; // 0000 0000 0000 0000 0000 0000 0000 1000
```
An example for a stepper motor driver:
```c
#include <stdio.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
    for (int j = 0; j < 100; j++)
    {
        int a = 8; // 0000 0000 0000 0000 0000 0000 0000 1000
        for (int i = 0; i < 4; i++)
        {
            dectobin(a, 4);
            a = a >> 1;
        }
    }

    return 0;
}
```
*If you shift beyond the bitsize of the computer you will get an undefined result*

### Bitmasks

Bitmask is a data that is used as a data for bitwise operations.

It can be any pattern.
eg: ```01101100```

Using bitmaps we can use a single variable to save 32 different boolean values and set each bit on or off or toggle. optimization at it's peak.

Using AND :

Lets say we have a mask ```00000010``` Which is binary of 2, Then we can use this to AND with a number and we can set all bit except the 2nd will be set to zero. eg:
```c
#include <stdio.h>
#include "functions.h"
int main(int argc, char const *argv[])
{
    int mask = 1;
    int num = 129;
    int result = num & mask;
    printf("%ld masked by %ld is %ld",dectobinr(num),dectobinr(mask), dectobinr(result));
    return 0;
    //Out: 10000001 masked by 1 is 1
}
```

Also using OR:

We can set a specific bit without touching others. eg:

```c
#include <stdio.h>
#include "functions.h"
int main(int argc, char const *argv[])
{
    int mask = 1;
    int num = 64;
    int result = num | mask;
    printf("%ld masked by %ld is %ld",dectobinr(num),dectobinr(mask), dectobinr(result));
    
    return 0;
    // Out: 1000000 masked by 1 is 1000001
}

```

Also We can do the opposite of first. Using and and complement we can turn of a specific bit without touching others ( above we did turn off all except one). Just complement the mask and AND it. eg: 
```c
#include <stdio.h>
#include "functions.h"
int main(int argc, char const *argv[])
{ 
    int mask = 1;
    int num = 255;
    int result = num & (~mask);
    printf("%ld masked by %ld is %ld",dectobinr(num),dectobinr(mask), dectobinr(result));
    return 0;
    // Out: 11111111 masked by 1 is 11111110
}

```
### Packing Data using BitOps
We can use bitwise opertions to pack datas consisting of boolean values.
For Example let's build a simple yes or no quiz and store the input in a single variable.
```c
#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
    int a = 0;
    for (int i = 0; i < 8; i++)
    {
        int temp;
        printf("question? (1 = Yes,0 = No) : ");
        scanf("%d", &temp);
        if (temp == 1)
        {
            a = a | (int)pow(2, i);
        }
    }
    printf("\nThe integer value is: %d\nBinary number is: ",a);
    dectobin(a, 8);
    return 0;
}
```
```
Output:
question? (1 = Yes,0 = No) : 1
question? (1 = Yes,0 = No) : 0 
question? (1 = Yes,0 = No) : 0
question? (1 = Yes,0 = No) : 1
question? (1 = Yes,0 = No) : 1
question? (1 = Yes,0 = No) : 1
question? (1 = Yes,0 = No) : 1
question? (1 = Yes,0 = No) : 1

The integer value is: 249
Binary number is: 11111001
```

### Packing using Bit fields
Bit fields allow us to specify the number of bits an integer can have in a struct.
Using a special syntax we can define a bitfield and define a name to it.
should use explicit declarations like signed or unsigned to avoid hardware issues.

 - Better Memory utilization.
- allow us to allocate a specified number of its.
- Can easily set and retrive data without any bitwise operations.

Eg:
```c
#include <stdio.h>

struct packed
{
    unsigned int :3; // Padding
    unsigned int f1:1; // Just some variables 
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
}; // This uses 4bytes

struct packed2
{
    unsigned int f1;
    unsigned int f2;
    unsigned int f3;
    unsigned int type;
    unsigned int index;
}; // This uses 20 bytes 


int main(int argc, char const *argv[])
{
    printf("%lu",sizeof(struct packed)); // Out : 4

    struct packed p1;

    p1.f1 = 1;  // 0000 0000 0000 0000 0000 0000 0000 00010
    // These are now easy as just variables.
    return 0;
}
```

### What you know

Convert the following decimal value to binary:123

Convert the following binary values to decimal:00010110

Convert the following binary values to decimal:01001100

The bits in the result of an expression using the __________ operator are set to 1 if the corresponding bits in each operand are set to 1. Otherwise, the bits are set to zero.

The bits in the result of an expression using the __________ operator are set to 1 if exactly one of the corresponding bits in either operand is set to 1. Otherwise, the bits are set to zero.

The __________ and __________ operators are used to shift the bits of a value to the left or to the right, respectively.

Evaluate the following expression; assume each value is 8 bits:~3

Evaluate the following expression; assume each value is 8 bits:3 & 6

Evaluate the following expressions; assume each value is 8 bits:1 | 6

Evaluate the following expression; assume each value is 8 bits:3 ^ 6

Evaluate the following expression; assume each value is 8 bits:7 >> 1

Evaluate the following expression; assume each value is 8 bits:7 << 2

What will be the output of the following program? #include <stdio.h> int main() { int c = 2 ^ 3; printf("%d\n", c); }
### What you should review

Convert the following decimal value to binary:5

Which of the following data types are accepted while declaring bit-fields?




