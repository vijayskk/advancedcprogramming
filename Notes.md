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

# Section 9
## Advanced control flow
### The ```goto``` statement.

Causes a program to jump to a particular line of code.
A label is needed and it follows same naming rules as a variable.

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int index = 0;
    while (1)
    {
        printf("%d\n",index);
        if (index == 100)
        {
            goto exit;
        }
        index++;
    }
    exit:printf("The loop finished ");
    return 0;
}
```
We can also provide multiple statements to a label.
```c
exit:
    printf("The loop finished ");
    printf("\nExitting....");
```
### Problems of ```goto``` 
- Inturrupts the natural flow of the code so it is harder to follow and maintain.
 
- Using many goto together makes the program impossible to follow

### Avoiding goto

We are not required to use a ```goto``` statement in our codes except some programming languages like fortran etc ... 

| Need | Method | 
| :---: | :---: |
| To skip an iteration |  ```continue``` |
| To breakout the loop |  ```break``` |
| When to exit multiple nested loops at one time |  ```goto``` |

### The Null Statement

Null statement differs from null pointer or object. It is a statement that can be told when you need to do absolute nothing and you don't want a syntax error. Null statement is essentially just a ```;``` and C will interpret any semicolon as an end of statement. Eg:

```c
while(*text++ = getchar() != '\n'){
    // Empty
}
```
This generates an empty body loop syntax error. There we can use the null statement.

```c
while(*text++ = getchar() != '\n'){
    ; // Null statment
}
```

### The comma operator ```,```

Don't be confused with normal seperator commas, This comma can used to put operations in place of expressions. Eg:

```c
while(i<100){
    sum += data[i] ,i++;
    // This will add and save data[i] and then increment i.
}
```
Another example when using paranthasis:
```c
int j = (f1(),f2());
// f1() will be executed first and then f2() will be executed and then the result of f2() will be saved to j.
```
Another one:
```c
x = (y=3,(z= ++y + 2) + 5);
// Here y=3 will execute first then y incremented and added by 2 and that value stored in z. and then add it with 5 and stored to x. So x will be 11.
```
Can be appied in loops:
```c
for(i=0,j=0;i<=10;i++,j++);
// This loop will increment both i and j.
```
Also if we need to run functions just use a comma :-).
```c
printf("Hello"),
printf("World"),
printf("Vijay");
```

### The ```setjmp()``` and ```longjmp()``` functions

They are functions which lets you advanced controll flow in C. 
Mainly used to implement exception handling in C.
As a C++ alternative ```setjmp()``` can be said as ```try``` and  ```longjmp()``` can be said as ```throw```.

```c
void function1(){
    void function2(){
        // Say here an error
    }
}
```
returning the values one by one will be a tedious task and we can't use a global variable for errors. So in this situation we can use ```setjmp()``` and ```longjmp()```.

They are basically similiar to ```goto``` but one of the disadvantage of goto is it can only jump to labels in same function. Here we can jump into any function or even a different file.

### How it works

- ```setjmp()``` saves a copy of program counter and the current stack top pointer.
- ```c
    int i = setjmp(jmp_buf buf)

    ```
    Use the variable ```buf``` to remember where we are now.
- Now wherever we call ```longjmp()``` with a value it will return that value to the ```setjmp()``` varaible and continue executing there.

```c
#include <stdio.h>
#include <setjmp.h> // This must be added
#include <stdlib.h>

jmp_buf buf;
int main(int argc, char const *argv[])
{
    int i = setjmp(buf); // This creates a process and saves it
    printf("i = %d\n",i);

    if (i > 0)
    {
        exit(0); // This will run if it longjumped.
    }
    

    longjmp(buf,42); // This returns the value 42 to the saved process and continue from there.

    printf("This will not print."); // This will not print
    return 0;
}
```

This can be also done from functions:
```c
#include <stdio.h>
#include <setjmp.h> // This must be added
#include <stdlib.h>

jmp_buf buf;

void myFunction(){
    printf("At myFunction\n");

    longjmp(buf,40); // This jumps to the main function to the saved process and returns 40.

    printf("This will not be printed");
}

int main(int argc, char const *argv[])
{
    int i = setjmp(buf); // This creates a process and saves it
    printf("i = %d\n",i);

    if (i > 0)
    {
        exit(0); // This will run if it longjumped.
    }
    
    myFunction();
    

    printf("This will not print."); // This will not print
    return 0;
}
```

### Use case

We can define error codes and we can handle the errors across the program.

```c
#define NOT_FOUND 404
#define BAD_REQUEST 304
#define SERVER_DOWN 504

#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf errbuf;

void function1()
{
    // A not found error occures here...
    longjmp(errbuf, NOT_FOUND);
}

void function2()
{
    // A bad request error occures here...
    longjmp(errbuf, BAD_REQUEST);
}

void function3()
{
    // A server error occures here...
    longjmp(errbuf, SERVER_DOWN);
}

void handleError()
{
    switch (setjmp(errbuf))
    {
    case NOT_FOUND:
        printf("\nThe webpage you looking not found...");
        exit(0);
        break;

    case BAD_REQUEST:
        printf("\nBad request found...");
        exit(0);
        break;

    case SERVER_DOWN:
        printf("\nThe server is down...");
        exit(0);
        break;
    case 0:
        break;
    default:
        printf("\nUndiscovered error occured...");
        exit(0);
        break;
    }
}

int main(int argc, char const *argv[])
{

    handleError();

    printf("Main function executes");

    function1();
    function2();
    function3();

    return 0;
}
```

### What you know

What will be the output of the following program? #include <stdio.h> int main() { printf("%d ", 1); goto l1; printf("%d ", 2); l1:goto l2; printf("%d ", 3); l2:printf("%d ", 4); }

What will be the output of the following program? #include <stdio.h> int main() { printf("%d ", 5); goto l1; printf("%d ", 6); } void foo() { l1 : printf(“7 ", 7); }

The "null statement" is an expression statement with the expression missing  (T/F)

What is the output of the following program?int x = (249,500); printf(“x is %d\n”, x);

The below code is an example of using the comma operator (T/F)int a = 1, b = 2;

What is the output of the following program?#include <stdio.h> int main(void) { int i; char ch; for (i = 0, ch = 'A'; i < 4; i++, ch += 2 * i) printf("%c", ch); return 0; }

What is the output of the following program?#include <setjmp.h> #include <stdio.h> jmp_buf buf; int main(void) { int i = setjmp(buf); printf("i = %d\n", i); longjmp(buf, 42); printf("Does this line get printed?\n"); return 0; }

The setjmp and longjmp function call is equivalent to the goto statement (T/F)

# Section 10
## Input and Output

The ```stdio.h``` includes all the necessory input and output functions we needed. When we run any C program,```stdin```,```stdout```,```stderr``` are automatically executed (defined in ```stdio.h```). They are required by the terminal they run on. Anyway we have to include it (```stdio.h```) in our program to use it. The don't take any advantages of a specfic system so they are portble to any os.

### Input functions

#### ```char``` 
 First let's look at the char functions.
#### ```getc()```
```getc``` can be used to print from both a file and the ```stdin``` (terminal)
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = '\0';
    FILE * fp;
    fp = fopen("hello.txt","rw");
    while (ch != EOF)
    {
        ch = getc(fp);
        printf("%c",ch);
    }
    return 0;
} // This will print the file out
```

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = ' ';
    int firstTime = 1;
    while (1)
    {
        ch = getc(stdin);
        if (firstTime == 1)
        {
            printf("You said : ");
            firstTime = 0;
        }
        printf("%c", ch);
        if (ch == '\n')
        {
            firstTime = 1;
        }
    }
    return 0;
}
// This will repeat what you give in stdin.
```

#### ```fgetc()```
Similiar to the ```getc``` we can use ```fgetc```
```c
#define FILENAME "hello.txt"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * fp = NULL;
    fp = fopen(FILENAME,"rw");
    if (fp == NULL)
    {
        printf("Opening %s failed...",FILENAME);\
        exit(0);
    }else{
        printf("File %s Opened....\n\n",FILENAME);

    }
    
    char ch = ' ';
    while (ch = fgetc(fp),ch != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);
    printf("\n\nFile %s Closed....\n",FILENAME);
    return 0;
}

```
#### ```ungetc()```
If we have to skip a charecter we can use ungetc.

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = ' ';
    while ((ch = (char)getc(stdin)) == ' '  )
    {
        ungetc(ch,stdin); // skips and gives the next charecter to ch.
    }
    printf("Char is : %c",ch);
    return 0;
}
```
### Output Functions

#### ```putc()```
Puts a single charecter into a file or stdout if it is provided with stream.
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[] = "Vijay";
    FILE * fp = fopen("hello.txt","w");
    for (int i = 0; i < sizeof(name) - 1; i++)
    {
        putc(name[i],fp);
    }
    fclose(fp);
    return 0;
}
```
Using stdout:
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[] = "Vijay";
    for (int i = 0; i < sizeof(name) - 1; i++)
    {
        putc(name[i],stdout);
    }
    return 0;
}
```
#### ```fputc()```
```fputc()``` is exclusively for files.
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("hello.txt" , "w");
    for (char i = 'A'; i <= 'Z'; i++)
    {
        fputc(i,fp);
    }
    fclose(fp);
    return 0;
}
```

### String Functions

#### ```gets()```
Reads a line from ```stdio```. Reads until the *EOF* or ```'\n'``` is found.
```c
char * gets(char * str);
```
**DO NOT USE**

**DEPRICATED**

**STAY THE F*CK OUT**

Problems:
- No check for buffer overflow is permitted
- It is impossible to tell without knowing advance how much data will ```gets()``` read. 

#### ```fgets()```

Reading entire line of data from file/stream. Have similiar behavior to ```gets```. Accept two additional arguments.
- The number of charecters to read.
- An input stream 

We can specify a maximum buffer and it will read untill a newline charecter occures or the maximum of buffer reached.
Not Recommended for performace reasons.

***DEPRICATED***

Problems: 
- A null charecter is not specified.

```c
#define MAXLEN 30
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[MAXLEN];
    fgets(str,MAXLEN,stdin);
    printf("%s\n",str);
    return 0;
}
```
#### ```getline()```
```getline()``` is the latest function for reading string from stream.
- Have to pass a double pointer allocated by ```malloc``` or ```calloc```.
- Automatically calls ```realloc``` when needed so no memory shortage.
- Have to pass the pointer to the ```size_t``` type variable which holds the size of first parameter.
- Third is an input stream.

```c
ssize_t getline(char ** buffer,ssize_t * size,FILE * stream);
```
Example:
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char * buffer = NULL;
    char buffer[32];
    size_t bufsize = 32;
    size_t charecters;

    buffer = (char *) malloc(bufsize * sizeof(char));

    if (buffer == NULL)
    {
        exit(1);
    }

    printf("Type Something: ");
    charecters = getline(&buffer,&bufsize,stdin);
    printf("You typed: %s\nNumber of charecters read: %zu \n",buffer,charecters - 1);
    

    return 0;
}
```
#### ```puts()```
Puts method can be used to display a string to the stdout and it automatically adds a newline charecter to the end of the string.

It is much more safe and simple but it cannot do any formatting as of the ```printf```. So if you need to rely on variables stay away from ```puts```.

```c
int puts(const char * string);
```
It also have a sibling function called fputs. It simply write the string to the stream provided.
```c
int fputs(const char * string,FILE * fptr);
```

Example: 
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[30] = "Hello Vijay...";

    FILE * fp = fopen("output.txt","w");
    puts(string);
    if (fp !=  NULL)
    {
        fputs(string,fp);
    }
    
    return 0;
}
```
### Formating Functions
#### ```sprintf()```

Outputs formated string to another string. 
```c
int sprintf(char * string,const char * format, ... );
```
- Returns the number of charecters stored inside the string. 
- Unsafe because it won't check the destination's size before saving the string.

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100];
    sprintf(string,"\n   \033[4mNAME CARD\033[0m\n\n Name: %s\n Age: %s\n\n",argv[1],argv[2]);
    puts(string);
    return 0;
}
```
#### ```fscanf()``` and ```fprintf()```
Does the same as scanf and printf but for a stream. Nothing more.

#### ```sscanf()```
scan data from a formatted string unlike ```stdin```.
```c
int sscanf(const char * str, const char * input,...);
```
#### ```fflush()```
It is used to clean a buffer or file.
```c
int fflush(FILE * fp);
```

### What you know

What is the output of the following code?#include <stdio.h> #include <stdlib.h> #include <ctype.h> int main(int argc, char *argv[]) { int ch; FILE *fp; if (argc < 2) exit(EXIT_FAILURE); if ( (fp = fopen(argv[1], "r")) == NULL) exit(EXIT_FAILURE); while ( (ch= getc(fp)) != EOF ) if( isdigit(ch) ) putchar(ch); fclose (fp); return 0; }

What is the default return type of getchar()?

What is EOF?

ungetc() is used __________

The gets() function checks for a buffer overflow. (T/F)

The syntax of the fgets function is:char *fgets(char *line, int maxline, FILE *fp)Which of the below statements is true regarding fgets?
### What you should review

Is putchar(getchar()) a valid expression; what does it do? Is getchar(putchar()) also valid?

What will be the output of the following code? #include <stdio.h> int main() { int n = 0; scanf("%d", &n); ungetc(n, stdin); scanf("%d", &n); printf("%d\n", n); return 0; }

The fputs()function adds a newline character to the end of the string that is written. (T/F)

What is the difference between each statement below?printf("Hello, %s\n", name); fprintf(stdout, "Hello, %s\n", name); fprintf(stderr, "Hello, %s\n", name);

# Section 11
## Advanced Function concepts
### Variadic Functions
Variadic functioms are functions which can have variable number of arguments.```printf()``` is an example for that. Has two parts:
- Mandatory arguments
    - Need atleast one and it should be first
    - Order is important
- Optional arguments
    - Listed after mandatory arguments


The standard library ```stdarg.h``` provides the macro for writing our own varadic functions. Common practice is to pass the number of arguments as the first argument.

**Steps to create a variadic function**
- Provide a function prototype using an ellipse (three dots).
    - Ellipse indicates there will be variables
    - Atleast need one fixed argument
    ```c
    int addNumbers(int a,int b,...);
    ```
- Create a ```va_list``` type variable ( It is basically a list of arguments )
- Copy the arguments list to that variable  using ```va_start```
    -   ```c
        int addNumbers(int a,int b,...){
            va_list list;
            va_start(list,b);

            int c = va_arg(list,int);
            int d = va_arg(list,int);
            va_end(list);
        }
        ```
- Then use the ```va_arg()``` to retrieve the variable.
- Using multiple times will retrive the variable next.
- Reset the ```va_list``` variable for starting from first optional variable again

Example:
```c
#include <stdio.h>
#include <stdarg.h>

int addNumbers(int n, ...)
{
    va_list list;
    va_start(list, n);
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
```
#### ```va_copy()```
once an argument is retrieved it cannot be retreived again. So it is good to keep a copy of that for future uses. We can make a copy of the original va_list for future uses. We should do the copying before doing anything ( atfer ```va_start``` ) to the list.
```c
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
```
### Recursion
For some types of programs, it is usefull to have a function call itself. Can be usefull when we have to do operations repeatedly. Ofcurse we can use loops. Only advantage of recursion is less code. 

Example:
```c
#include <stdio.h>

int fact(int n){
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n-1);
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n",fact(5));
    return 0;
}
```
The value of the argument must converge or else this will create an infinite loop.

Each time we call a function it puts the instance into a stack and when the last functions returns a value the stack is removed one by one.

### Inline functions
When running a function it take execution time to setup the call,pass arguents,jump to function code etc. So C99 introduced a feature called inline functions to avoid this overhead.

Inline declaration is a hint to the compiler that function is worth running fast. Compiler will avoid calling the function and replace it with inline code.
It is just a suggestion not a guarantee to make it fast. It can make the code more lengthy and large program file size. Use it for short functions.

To declare an inline function just give the ```inline``` keyword in the function declaration and the compiler will make the calling of this function inline.
```c
#include <stdio.h>

int addNumbers(int a,int b){
    return a+b;
} // This function can be in another file.

inline int addNumbers(int a,int b);

int main(int argc, char const *argv[])
{
    printf("%d",addNumbers(10,20));
    return 0;
}
```
### ```_Noreturn``` functions
This function type specifier is added in C11. This specifier tells the compiler to not to return the control from the function after it excecuted. Helps to prevent missusing of the function. This is just a hint to the compiler not a guarantee. 

The ```exit()``` function is an example for _Noreturn function. After it called the control will not be given back. 

You should not return anything explicitly from the function.

```c
#include <stdio.h>
#include <stdnoreturn.h>
#include <stdlib.h>

noreturn void exitfrom(char * process,int code);
 
void exitfrom(char * process,int code){
    printf("Exitting from %s...",process);
    exit(code);
}

int main(int argc, char const *argv[])
{
    exitfrom("Download",1);
    return 0;
}
```
### What you know

What will be the output of the following code? #include <stdio.h> #include <stdarg.h> void func(int, ...); int main() { func(2, 3, 5, 7, 10, 13); return 0; } void func(int n, ...) { int number, i = 0; va_list start; va_start(start, n); while (i != 4) { number = va_arg(start, int); i++; } printf("%d", number); }

Which of the following variadic functions with an ellipsis are illegal?

Which header file includes a macro for variable number of arguments?

Which of the following macros extracts an argument from the variable argument list and advances the pointer to the next argument?

The type va_list in an argument list is used ________

What is the purpose of va_end?

What will be the output of the following code?int main() { int n; n=f1(5); printf("%d",n); } f1(int x) { int b; if(x==1) return 1; else b=x*f1(x-1); return b; }

Iteration requires more system memory than recursion (T/F)

A function whose definition can be substituted at a place where its function call is made is known as.

What will be the error (if any) in the following code?void static inline func1(float b) { printf ("%lf\n",b*2); } int main() { inline func1(2.2); return 0; }

The _NoReturn function specifier was added in C11. (T/F)

Which header file includes the convenience macro noreturn?

The purpose of the _Noreturn specifier is to inform the compiler that a particular function will not return control to the calling program when it completes execution.  The compiler will then use this information to always optimize your code.  (T/F)
### What you should review

In the absence of an exit condition in a recursive function, the following error occurs.

# Section 12
## Unions
Union is a derrived type (like struct) with members that store same storage space. Sometimes same type of construct need different type of data.
- Can be used to save space and for alternating data.
- A union doesn't waste storage on variables that are not being used.

Each element in a union is called a member similiar to struct. Only one member can have a value at a given time. So only one member can be accessed at a time.

The members of union can be any type. In most cases union will contain two or more datatypes. It is our responsiblity to ensure that the data is referenced with proper datatype.

Operations on a union are:
- Assigning of a union to another with the same type.
- taking the address (&) of a union varable.
- Accessing union members.
### Use cases
- Usefull in embeded programming with a low memory requierment because unions save memory.
- For representing a table with mixed dayatypes.
- Creating muli datatype arrays.
- Representing files with different record types.
- Representing a network interface containing different requests.

| Struct | Union |
| --- | --- |
| Allocates space for all it's members seperately | one common memory space for all members |
| Memory space calculated for each member | Memory space calculated for the largest member. Programmers can decide what to put there

```c
struct mystruct{
    char a;
    float b;
}mystruct;
```
```c
union myunion{
    char a;
    float b;
}mystruct;
```

### Defining a union
Defenition is similiar to the struct. use the ```union``` keyword instead.
```c
union data{
    int a;
    float b;
    char c[20];
}
```
This will take 20 bytes of memory because of ```c``` is the highest datatype. Structures can be defined containing unions.

Unions can also be defined as arrays and can store as much as union elements we want in an array.
```c
#include <stdio.h>

union Data
{
    int a;
    float b;
    char c[20];
};
struct Person
{
    char name[30];
    int age;
    union Data data;
    union
    {
        int isDead;
        char occupation[20];
    };
};

struct
{
    char *name;
    enum symbolType;
    union
    {
        int i;
        float f;
        char c;
    } data;
} table[10];

int main(int argc, char const *argv[])
{
    union Data data1, data2, *data3;
    struct Person p1;
    printf("%ld\n", sizeof(data1)); // OUT: 20
    printf("%ld\n", sizeof(p1));    // OUT: 20
    return 0;
}
```
### Accessing union members.
Accessing and assigning is also similiar to the struct.
- dot (.) operator to access the members.
- ```->``` operator to access the pointer type variables.

Eg: ```name.member```

### What you know

A union will allocate storage space for all its members separately (T/F)

Which of the following share a similarity in syntax to a Union?1. Object, 2. Structure, 3. Arrays, 4. Pointers

What will be the output of the following code?union myUnion { int ival; float fval; }; void main() { union myUnion r; r.fval = 5.2; printf("%f", r.fval); }

The size of a union is determined by the size of the __________

What would be the size of the following union declaration?(Assuming size of double = 8, size of int = 4, size of char = 1)?union uTemp { double a; int b[10]; char c; } u;

Members of a union are accessed as________________

What will be the output of the following code?union p { int x; char y; }; int main() { union p a, b; a.y = 60; b.x = 12; printf("%d\n", a.y); }
### What you should review

How can you access the first character of the string sval?struct { char *name; union { char *sval; } u; } tab[10];

# Section 13
## Preprocessors
The process of creating a c program involves: 
- Preprocessing 
- Compilation
- Assembling
- linking
- loading

The preprocessor is evoked before the compiling. It is basically a text substitution tool.
Preprocessor will do three steps
1. Removes all comments: It is just for engineers understanding not needed for the execution.
2. Includes all the files from various libraries that is needed to compile. We have to specify them using the ```#include``` directive.
3. Expansion of macro defenitions.

Commands used by preprocesors are called preprocessor directives. It should be the first nonblank charecter and should begin in the first column

```c
#include <stdio.h>
#define MAXLENGTH 10
```
### Conditional Compilation 
Often used to compile a single program according to the host machine. Usefull when we have a larger software with more dependancies. Can also be used to switch certain statements like debugging on or off.

Each if the conditional preprocessor directives checks a constat integer expression;
#### ```#ifdef``` 
Checks whether the identifier is defined or not. To set an identifier:

```#define UNIX 1``` or ```#define UNIX```

Or we can also use commandline arguments to define an identifier
```bash
gcc hello.c -D UNIX
```

The ```#ifdef``` can be used as :

```c
#ifdef UNIX
// Code specific for UNIX
#endif
```
The ```#ifndef``` is just an opposite of ```#ifdef```.
We can also use ```#else``` and ```#elif``` directives.
```c
#ifdef WINDOWS
// Code specific for windows
#elif MAC
// Code specific for macos
#else
// Code Specific for other platforms
#endif
```

Example:
```c
#define LIMIT 10
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        ;
        #ifdef DEBUG
        printf("%dth loop runned\n",i+1);
        #endif
    }
    printf("Loop Finished...\n");
    return 0;
}
```
Output:
```bash
vijaysatheesh@Vijays-MacBook-Air Section 13 % gcc conditcompile.c
vijaysatheesh@Vijays-MacBook-Air Section 13 % ./a.out 
Loop Finished...
vijaysatheesh@Vijays-MacBook-Air Section 13 % gcc conditcompile.c -D DEBUG
vijaysatheesh@Vijays-MacBook-Air Section 13 % ./a.out                     
1th loop runned
2th loop runned
3th loop runned
4th loop runned
5th loop runned
6th loop runned
7th loop runned
8th loop runned
9th loop runned
10th loop runned
Loop Finished...
```
#### Include guards and ```#undef```
The ```#ifndef``` is commonly used to prevent multiple inclussions.

```c
#ifndef _STDIO_H
#define _STDIO_H
// include statements 
#endif
```
Now we cannot include the same headerfile again.

#### ```#undef```

This preprocessor directive is used to undefine a previously defined identifier.
```c
#define SPEED

#ifdef WINDOWS
#undef SPEED // JK :-P
#endif
```
### ```#pragma``` 
The ```#pragma``` direcive allows us to place compiler instructions in sourcecode. Usefull when the program is large and we have to use the most capablities of the compiler.
It can be used to:
- Control the memory kept for automatic variables
- Set the strictness of error checking
- Enable nonstandard language features

Generally each compiler have their own pragmas.
```c
#pragma token_name
```
We have to look at the compiler documentation for available pragmas. Some example for GCC are:
```c
#pragma GCC dependancy
#pragma GCC poison
#pragma GCC system_header
#pragma once 
#pragma GCC warning
#pragma GCC error
#pragma message
```
```c
#pragma GCC dependancy "hello.c"
// Warning issued if the hello.c file is recent than the current compiling file.
```
```c
#pragma GCC poison puts gets
// Removes an identifier completely from the program. Error will be displayed if appears.
```
```c
#pragma GCC system_header 
// Considers the rest of the header files as system headers and GCC avoids warning of system headers.
```
```c
#pragma GCC once
// Ensures the include specifed included only once even if it included multiple times by the programmer. Less portable version of include guards.
```
```c
#pragma GCC message "This will be printed"
#pragma GCC warning "I will kill you"
#pragma GCC error "Just kidding no error"
// Generates custom warnings errors and compiler messages. 
```
### ```#error```
Issues an error by the preprocessor. Portable because it is independent of the compiler. Even vscode shows warning🤣
```c
#error You Are Done Go To Hell
```
Also we can use :
```c
#warning Behave yourself
#line 69 yourlife.c
```

### What you know

The C preprocessor is the first step of the compiliation process

The C preprocessor may have compiler specific features

Every preprocessor directive must begin with a  __________.

Only __________ characters may appear before a preprocessor directive on a line.

__________ allows a programmer to produce different executables (code) for different platforms.

Which of the following are C preprocessors directives that allow for Conditional Compiliation?

This preprocessor directive is used to remove the definition of an identifier which was previously defined with #define?

Write some code that will print out your name if the  identifier MY_NAME is defined

The __________ and __________ directives allow a program to extend the #if and #ifdef/#ifndef directives to test for multiple cases

What will be the output of the following C program?#include <stdio.h> #define SWAP int main() { int x = 3, y = 5; #ifdef SWAP x = 5; y = 3; #endif printf("%d, %d", x, y); }

What will be the output of the following program?#include<stdio.h> #define TEXT void main() { #ifndef TEXT printf("hello"); #else printf("hi"); #endif }

This preprocessor directive is used to give additional information to the compiler, beyond which is provided in the language

This pragma is used to remove an identifier completely from a program.

The purpose of using the preprocessor directive #error is that ____________
### What you should review

What is a preprocessor?

This preprocessor directive checks whether a constant expression results in a zero or non-zero value.

# Section 14
## Macros

Macro is a code piece based of the #define statement. Macros are a text processing feature and are expanded and replced by macro defenitions. Little outdated nowadays but still makes programmers day better.
```c
#define MACRO macro_body
```
It simply replaces the occurance of ```MACRO``` with ```macro_body```.
Eg:
```c
#include <stdio.h>

#define PRINT_HI printf("Hi...");

int main(int argc, char const *argv[])
{
    PRINT_HI
    return 0;
}
``` 
Some things to remember:
- There can't be space in macro name but can have space in macro body.
- Macros are not terminated by semicolon.
- They run until the first newline following the ```#```
- Limited to one line in length but can use ```\``` operator for continuation.

| Macros | Functions |
| --- | --- |
| All macros are preprocessed means all will be processed before the program compiles. | Functions are compiled not preprocessed. |
| Macro is faster because it is executed as inline code. | Function is slower because the program control must shift to where the function defined. |
| Macros dont have to allocate a seperate data or stackframe it is just a text substitution. | Function have to make room for arguments and other variables. | 
| A macro produces inline code so the filesize of the program increases. | Function only defined once so no such overhead. | 
| Macros don't have to worry about variable types. Just substitute the values | Have to deal with variable types |  
| Same macro can be used with any datatype and it won't give errors of type checking | Functions do type checking |


Some compiler will limit the macros to single line. So we have to observe that even if our compiler doesn't. Inline functions are an alternative to macro but it have it's own place.

We can see the preprocessed code by the command:
```bash
gcc -E file.c
```
### Preprocessor Operators
The preprocessor includes some operators for making the macros easy. They are :
- ```\``` operator : This will allow the continuation of a macro to the next line. A macro is always a single logic line so ```\``` will be usefull.
- ```defined()``` operator is used when we have to know whether an identifier is defined using ```#define``` or not.
- ```#``` and ```##``` operators are used to merge two tokens into one while expanding macros. 
- ```#``` operator causes the replacement text to be substituted as a string surrounded by quotes. 
- ```##``` operator is used to join two tokens together.
```c
#define TOKENCONCAT(a,b) a ## b
int main(){
    printf("TOKENCONCAT(O,K)");
}
```
### Predefined Macros
C provide some symbolic constants as macros.
- ```__FILE__``` gives the current filename working with.
- ```__LINE__``` gives the current line.
- ```__func__``` gives the current function name (not standard).
- ```__DATE__``` gives the compiled date in MMM DD YYYY format.
- ```__TIME__``` gives the compiled time in hh:mm:ss format.
- ```__STDC__``` will return the value 1 if compiler support standard C.


These macros cannot be placed inside a preprocessor directive.It should begin and end with the two underscores.

# Section 15 
## Advanced debugging,analysys and compiler options
### GCC compiler options
There are various compiler options to control the execution process of a c program.
For example there are options to stop at a particular process. Some options stop at preprocessing some at compiling and some do liniking and loading.
| Option | Purpous |
|:---:|:---:|
| ```-c``` | Do the compiling only and generate an object file.|
| ```-Wall``` | Enables all warnings. |
| ```-E``` | Dumps the preprocessed code. | 
| ```-S``` | Generates assembly code. | 
| ```-save-temps``` | Saves all the files from all steps. |
| ```-l``` | For linking shared libraries ( Eg: ```-l m``` for math library )|
| ```-g``` | For storing debug info in the object file |
| ```-v``` | Enable verbous |
| ```-ansi``` | Follow the ANSI standard |
| ```-fsigned-char``` | Treat charecters as signed |
| ```-funsigned-char``` | Treat charecters as unsigned |
| ```-D``` | Defining macros | 
| ```-Werror``` | Convert all warnings to errors |

We can also include an optfile containing all the options and use with the @ symbol.
```bash
gcc hello.c @optfilename
```
### Optimization flags
We can find out optimizers for a compiler using help. As in GCC we can give the command to get help:
```bash
GCC -Q --help=optimizers
```
### Debugging with the preprocessor
We can use the conditional compiling directives to turn on or off debugging statements. 
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char name[30];
    scanf("%s",name);
    for (int i = 0; i < strlen(name); i++)
    {
        #ifdef DEBUG
        printf("%c -> %c\n",name[i],name[i] + 1);
        #endif
        name[i] += 1;
    }
    printf("%s\n",name);
    return 0;
}
```
We can also use a macro to do the same.
```c
#define DEBUGME(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
```
Now we can also wrap in this a ifdef so that we just have to call the debug statements.
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBON
#warning DEBUGGER IS ON 
#define DEBUGME(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define DEBUGME(fmt,...)
#endif

int main(int argc, char const *argv[])
{
    char name[30];
    scanf("%s",name);
    for (int i = 0; i < strlen(name); i++)
    {
        DEBUGME("%c -> %c\n",name[i],name[i] + 1);
        name[i] += 1;
    }
    printf("%s\n",name);
    return 0;
}
```
### Debugging with LLDB
LLDB ( low-level debugger ) is a command line tool used for debugging. It allows us to see inside of a program and what crashes the program. The LLDB alternatives for GDB commands are:

Switching from GDB to LLDB can be straightforward since many commands are quite similar. Here's a list of useful LLDB commands along with their GDB counterparts to help you transition:

#### Basic Commands

| Task                         | GDB Command                  | LLDB Command                 |
|------------------------------|------------------------------|------------------------------|
| Start debugging              | `gdb ./a.out`                | `lldb ./a.out`               |
| Run the program              | `run`                        | `run`                        |
| Set a breakpoint by function | `break my_function`          | `breakpoint set --name my_function` |
| Set a breakpoint by file/line| `break file.c:10`            | `breakpoint set --file file.c --line 10` |
| List breakpoints             | `info breakpoints`           | `breakpoint list`            |
| Delete a breakpoint          | `delete breakpoint 1`        | `breakpoint delete 1`        |
| Continue execution           | `continue`                   | `continue`                   |
| Step into a function         | `step`                       | `step`                       |
| Step over a function         | `next`                       | `next`                       |
| Step out of a function       | `finish`                     | `finish`                     |
| Print a variable             | `print var`                  | `print var`                  |
| Print call stack             | `backtrace`                  | `bt`                         |
| List source code             | `list`                       | `list`                       |
| Display local variables      | `info locals`                | `frame variable`             |
| Quit debugger                | `quit`                       | `quit`                       |

#### Advanced Commands

| Task                         | GDB Command                  | LLDB Command                 |
|------------------------------|------------------------------|------------------------------|
| Watch a variable             | `watch var`                  | `watchpoint set variable var` |
| Examine memory               | `x`                          | `memory read`                |
| Change variable value        | `set var x = 5`              | `expr x = 5`                 |
| Conditional breakpoint       | `break if i == 3`            | `breakpoint set --name my_function --condition "i == 3"` |
| Enable breakpoint            | `enable break 1`             | `breakpoint enable 1`        |
| Disable breakpoint           | `disable break 1`            | `breakpoint disable 1`       |
| Command history              | `show commands`              | `command history`            |
| Attach to a process          | `attach pid 1234`            | `process attach --pid 1234`  |
| Detach from process          | `detach`                     | `process detach`             |
| Set environment variable     | `set environment VAR=VAL`    | `settings set target.env-vars VAR=VAL` |
| Redirect I/O                 | `run < input > output`       | `run < input > output`       |
| Call a function              | `call func()`                | `expr func()`                |


First we have to enable the debugging information in our code. Use the -g flag for that.
```bash
gcc -g filename.c
```
Next we can look into the executable using GDB
```bash
lldb a.out
```
This will open up a gdb prompt like this:
```bash
(lldb) target create "a.out"
Current executable set to '/Users/vijaysatheesh/Advanced C Programming/Section 15/a.out' (arm64).
(lldb) 
```
For running the code under the control of lldb, Use command:
```bash
(lldb) run
```
This will execute the program normally and it will throw errors if it have. If you want to know the value of a variable at the time of crash, use the command:
```bash
print <variable_name>
```
This will also work on arrays and structures.
In order to set a variable, We can use the command:
```bash
expr <variable_name> = <value>
```
The variable must be in current active function and the process must be running in order to work with variables. To display all the variables just use:
```bash
frame variables
```
### Core files
A core dump is generated when a program is crashed or terminated abnormally because of segmentation fault.
A Segmentation fault is a specific kind of error caused by accessing memory that "do not belongs you". The core file contains the snapshot of the memory at the time of termination. Can be used to analyse the crash and compare to another crashes offsite.

Because of large size the compiler may disable the core dumping. You can enable it by running:
```bash
ulimit -c unlimited
```
### Profiling
Profiling is a form of dynamic programming analysis that measures the:
- Space complexity
- Time Complexity
- Usage of particular instructions 
- The frequency and duration of function calls

This serves data to optimize the program. Achieved by instrumenting the source code by some profiling tools. Profilers will use various techniques like event based,statistical,instrumented,and simulated methods.

#### gprof
gprof (GNU Profiler) is a tool used to profile the executable.It uses a hybrid approach of compiler assisted instrumentation and sampling. The instrumentation is used to gather function call insformation ( call graphs ).

To gather runtime info a sampling process is used.
The program counter is inturrupted at regular intervals of time. The resultant data is not exact but are statistical approximations.

use ```gcc -pg profiling.c``` to enable analysis and use ```gprof a.out gmon.out``` to get the call graph and analysys report.

#### valgrind
valgrind is another program to check memory leaks. It is a really slow program but detects the memory leaks.
```bash
valgrind --leak-check=yes ./a.out
```
### Static analysys
Static analysys is the method of examining the source code automatically without running it. This makes us an understanding about the code structure and industry standards.
Eg:
- Coverity ( by Synopsis )
- CodeSonar ( by Grammatech )
    - Used by US food and drugs Administration and NASA
# Section 16
## Advanced Pointers
### Double Pointers
We know that we can create pointers to any datatypes including user defined structs. What if we can make a pointer to another pointer variable. Double pointer is a pointer to a variable which stores an address of another variable. It can be created by:
```c
int ** dp;
```
Example code:
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int * p = &a;
    int ** dp = &p;
    printf("Value of dp: %p\n",dp);
    printf("Value of p from dp: %p\n",*dp);
    printf("Value of p directly: %p\n",p);
    printf("Value of a from p: %d\n",*p);
    printf("Value of a : %d\n",a);
    return 0;
}
```
We can also directly access the pointer to the pointer pointing data with a ```**```.
```c
printf("Value of a from dp: %d",**dp);
```
#### Use Cases
1. When you have to change the value of a pointer that is passed to a function. 
Example:
```c
#include <stdio.h>
#include <stdlib.h>

void myfun(int *p)
{
    int a = 5;
    p = &a;
} // This function cannot affect the value of p globally.

void myFunD(int ** dp)
{
    int b = 5;
    *dp = &b;
} // This can assign the address of local variable b to a pointer and we can access it from higher scope.

int main(int argc, char const *argv[])
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    printf("Value of ptr data is: %d\n", *ptr);
    myfun(ptr);
    printf("Value of ptr data is: %d\n", *ptr); // Same Output

    int ** dp = &ptr;
    myFunD(dp);
    printf("Value of ptr data is: %d\n", *ptr); // The value will be changed.
    return 0;
}
```
### Function Pointers
There are some addresses for a function also. We can:
- Pass them to another functions
- Returnded from functions
- stored in arrays
- assigned to another function pointers.

The common use case is to tell another functions that which function to use next as an argument. Also we can use ```qsort()``` function which takes a user defined function as an argument to sort.

Another use case is to build a dispatch table which is an array of function pointers which points to which function to use in a series. Menu driven programs are using this technique.

Unlike normal pointers we have to define the whole prototype of the function when declaring a function pointer. Because the pointer only shows the address of the code of the function. We need more info.
```c
int (*pfunc)(int,int);
```
Example:
```c
#include <stdio.h>

int addtwo(int a,int b){
    return a + b;
}
int subtwo(int a,int b){
    return a - b;
}

int main(int argc, char const *argv[])
{
    int (*pfunc)(int,int);
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
```
We can also use typedef for simplifying the declaration.
```c
typedef int(*funType)(int,int);

funtype pfunc = addtwo;
```
### Void Pointers
Void pointers are pointers which do not have a specific datatype and we can store any type of data into them. Declared by:
```c
void * vp
```
Example:
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    void * vp;
    int a = 10;
    vp = &a;
    printf("%p\n",vp);
    // To get the value,
    printf("%d\n",*(int *)vp);

    float b = 10.5;
    vp = &b;
    printf("%p\n",vp);
    // To get the value,
    printf("%f\n",*(float *)vp);
    return 0;
}
```
# Section 17 
## Static libraries and shared objects
We can create our own libraries and use the same code across the programs. They are called static libraries. Also we can share code using dynamic libraries at runtime. 

library is a group of files
- a header ```.h``` file containing the prototypes called **Interface**.
- The actual implementation is stored in another c file.

In order to access a c function across applications it have to be seperated from the source and implemented as a library.
### Advantages
- Fast compilation times.
- Allows to make APIs for vendors.
- Allows modular development.
- Software reuse.
- Version management.
- Component specialization

The linker software is responsible for collecting the libraries object files and making them available for the main program. The linker accomplishes this in two ways.
- Static linking
    - In static linking all the object code for the used library functions are compied into the main object file.
- Dynamic linking
    - In dynamic linking the binary file itself is taken into RAM in the runtime, and labeled in the main object file.
### Static Linking
When you perform a static linking the library code is a part of your application. The primary advantage is speed. 
- There is no program entity resolution at the runtime. Everything is resolved.
- Every piece of library is part of the main executable.
- We don't have to worry about client's available library and versions.
Disadvantages:
- Creates a larger binary files.
- Once program is linked you have no way of correcting bugs in the library function.
### Dynamic linking
Performs linking on the fly as the programs executed.
- Libraries are loaded to memory only when it is executed.
- Only have to recompile the library when any chnages are needed.
- Also we can put a downloaded library and put it on the system and good to go ( No recompilation ).
- More modern approach, and has a much smaller executable size.
- More efficient use of disk and quicker linking with a runtime penalty.
- Helps more in performance because of libraries are attatched to the process only when in need.

### Static Library
- Uses static linking.
- each process gets a copy of the code
- Known as an archive with a filetype of ```.a```

### Shared Object library
- Dynamically linked at the runtime.
- Not included in the executable and linked to the process in runtime.
- Code is shared between and data is specific to each process.
### Library conventions
- Dynamic libraries are useally named ```libsomething.so```.
- Static libraries are called ```libsomething.a``` ( on windows ```libsomething.lib``` ).
### Creating a Static Library (*archive*)
It is a bunch of object files that are wrapped into a single file. Created by an archive utility.

Steps:
- First create a directory and store the source fil(main.c) and header file (myLib.h).
- use gcc to compile the main file (headers will be automatically compiled).
```bash
gcc -c main.c -o lib-myLib.o
```
- Then use the ar utiliy to pack the .o files into a .a file.
```bash
ar rcs lib_myLib.a lib-myLib.o 
```
- Test the object files in a .a file with:
```bash
ar -t lib_myLib.a
```
- Now come back to the main program and compile it using -c.
```bash
gcc -I myLib/ -c sharedlib.c -o main.o
```
- Now link it using:
```bash
gcc main.o myLib/lib_myLib.a 
```
- You'll get a.out and be happy.
### Creating a dynamic library
Steps:
- First create a directory and store the source fil(main.c) and header file (myLib.h).
- use gcc to compile the main file.
```bash
gcc -g -fPIC main.c -shared -o libdynLib.so
```
- Now come back to the main program and compile it using -c.
```bash
gcc -I dynLib/ -c mycode.c -o main.o
```
- Now link the program to the shared library
```bash
gcc -o main.out main.o -L dynLib/ -l dynlib
```
- In order to run it we have to set an environment variable.
```bash
export LD_LIBRARY_PATH=/Users/vijaysatheesh/Advanced\ C\ Programming/Section\ 17/dynlib
```
- You'll get a.out and be happy.

### Dynamic loading
This is used when we don't need the libraries at compile time and only needs when the program executes. So we load it dynamically. 
There is an API for doing this. It is included in ```<dlfcn.h>```.
- The first function ```dlopen()``` opens a library and prepares it for use.
- ```void * dlopen(const char * filename,int flag)```.
- There are two flags.```RTLD_LAZY``` or ```RTLD_NOW```
- RTLD_LAZY means to resolve undefined function calls.
- RTLD_NOW means to resolve all undefined function calls before dlopen() returns and fail if not possible (used for debugging).
- dlopen() returns a handle and it is used for other routines.

```dlerror()``` function returns the errors from last call.

The main routine for using a dynamic library is ```dlsym()``` function. This looks up for a value of a function call in an opened library. Returnes NULL if the symbol not found.
```c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
    void * handle = NULL;
    double (*cosine) (double) = NULL;
    char * error = NULL;

    handle = dlopen("/usr/lib/aarch64-linux-gnu/libm.so.6",RTLD_LAZY);

    if(!handle){
        putc(dlerror(),stderr);
        exit(1);
    }

    dlerror();

    cosine = dlsym(handle,"cos");

    if(!handle){
        putc(dlerror(),stderr);
        exit(1);
    }

    printf("%f\n",cosine(0.5));

    dlclose(handle);
    return 0;
}
```
# Section 18
## Usefull C libraries
### Assert
Assert is a run time checking library which is defined in assert.h. It enables us to test expressions in our program and mostly used for debugging.
The program will be terminated with a diagnostic message. The termination is held by calling the abort function. This is only for finding logical errors.
```c
#include <stdio.h>
#include <assert.h>
#ifndef BATT
#define BATT 10
#endif

int main(int argc, char const *argv[])
{
    assert(BATT > 25); // Because Battery is important for further working..
    printf("Working...\n");
    return 0;
}
```
Output:
```bash
Assertion failed: (BATT > 25), function main, file assertfn.c, line 9.
zsh: abort      ./a.out
```
The assertions can be switched off by defining NDEBUG before the inclusion of assert.h
```c
#define NDEBUG
// #undef NDEBUG will turn assertions on
#include <stdio.h>
#include <assert.h>
#ifndef BATT
#define BATT 10
#endif

int main(int argc, char const *argv[])
{
    assert(BATT > 25);
    printf("Working...\n");
    return 0;
}
```
 
We can also use assert.h library for compile time assertions. using the ```static_assert()``` macro.
```c
static_assert(expression,"Message");
```
Example:
```c
#include <stdio.h>
#include <assert.h>

#ifndef BATT
#define BATT 10
#endif

int main(int argc, char const *argv[])
{
    static_assert(BATT > 25,"Battery low.Compiling aborted...");
    
    return 0;
}
```
Output:
```bash
staticassert.c:10:5: error: static assertion failed due to requirement '10 > 25': Battery low.Compiling aborted...
    static_assert(BATT > 25,"Battery low.Compiling aborted...");
```
### General Functions
#### ```exit()```
This is used to forcefully terminate the main function with an integer return value.
```c
int exit(int status);
```
Advantages:
- Flushes all output and input streams
- Closes all opened streams.
- Closes all temperory files created by calls to the standard I/O function tempfile().

#### ```atexit()```
This function allow us to call a function when the exit() function is evoked. Pass the pointer to the function. We can set upto 32 functions. The function cannot have any return types or arguments should be void. Typically these functions will do the housekeeping tasks.

Example: 
```c
#include <stdio.h>
#include <stdlib.h>

void sign_off()
{
    printf("Program is Quitting...\nGoodbye...\n");
}

void another_fn()
{
    printf("Dummy...\n");
}

int main(int argc, char const *argv[])
{
    atexit(sign_off);
    atexit(another_fn);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        if (i > 5)
        {
            exit(0);
        }
    }

    return 0;
}
```

#### ```abort()```
This causes an abnormal termination of the program. A signal SIGABRT will be raised ( more about signals later ). It geerates a noticable failiure and dumps core.
During abort:
- File buffers are not flushed.
- Streams are not closed.
- Temporory files are not deleted.
- Functions passed to atexit() are not called.
```c
void abort(void);
```
#### ```qsort()```
Quick sort is an efficient algorithm for sorting. It is particularly good for larger arrays. 
```c
void qsort( void * base,
            size_t nmemb,
            size_t size,
            int (*compare)(const void *,const void *)
  )
```
Example:
```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(int argc, char const *argv[])
{
    int data[5] = {12, 43, 23, 12, 1};

    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", data[i]);
    }
    printf("\n");

    qsort(data, 5, sizeof(int), compare);

    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", data[i]);
    }
    printf("\n");

    return 0;
}

int compare(const void *pa, const void *pb)
{
    const int a = *(const int *)pa;
    const int b = *(const int *)pb;
    return b - a; // a-b for ascending
};
```
#### ```atoi()```
This converts the ascii string numbers to integer type.
```c
int atoi(const char * string);
```
Example:
```c
#include <stdlib.h>

int main(){
    char a[10] = "100";
    int value = atoi(a); // Outputs 100 as integer.
}
```

#### ```atof()```
This converts the ascii string floating numbers to float type.
```c
float atof(const char * string);
```
Example:
```c
#include <stdlib.h>

int main(){
    char a[10] = "3.14";
    float value = atof(a); // Outputs 3.14 as float.
}
```

#### ```atol()```
This converts the ascii string long numbers to long integer type.
```c
long atol(const char * string);
```
Example:
```c
#include <stdlib.h>

int main(){
    char a[10] = "1000000000";
    long value = atol(a); // Outputs 1000000000 as long integer.
}
```

#### ```strtod()```
This converts the ascii string double numbers including trailing letters ( They will be automatically removed ) to double type.
```c
double strtod(const char * string, char ** st_end);
```
Example:
```c
#include <stdlib.h>

int main(){
    char a[10] = "3.14 14.3";
    char * end;
    double value = strtod(a,&end); // Outputs 3.14 as double.
    double value 2 = strtod(end,NULL);// Gets the next value.

}
```

#### ```strtol()```
This converts the ascii string long numbers to long type with a base.
```c
double strtol(const char * string, char ** st_end,int base);
```
Example:
```c
#include <stdlib.h>

int main(){
    char a[10] = "300000 14000000000";
    char * end;
    long value = strtod(a,&end,10); // Outputs 300000 as long.
    long value 2 = strtod(end,NULL,10);// Gets the next value.

}
```
### Random numbers
C provides two functions for generating random numbers.```rand()``` and ```srand()```. It generally uses hardware sources for generating random numbers like time and network traffic. It is a really hard job and it provides a seed for every random number.

#### ```rand()```
It provides a random integer number. RAND_MAX defines the maximum value of a random variable in a system. It is defined in stdlib.h and have a minimum value of 32767.
```c
int rand(void); 
```
#### ```srand()```
It controls the seed of the generated random numbers. Seed is defaulted into 1.
```c
void srand(unsigned seed);
```
Example:
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        srand(atoi(argv[1]));
    }else{
        srand(1);
    }
    printf("%d\n",rand());
    return 0;
}
```
### ```system()```
This function executes a system command in a shell.
```c
void system(char * command);
```
Example:
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    system("ls -la");
    return 0;
}
```
### ```getenv()```
This function returns the environment varaiable value that is passed in. Returns NULL if not found.
```c
char * getenv(const char * name);
```
Example:
```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%s",getenv("HOME"));
    return 0;
}
```
Output:
```bash
/Users/vijaysatheesh
```
### ```memcpy()```
This copies content from consecutive memory location to another.
```c
void * memcpy(void * s1,const void * s2, size_t n);
```
### ```memmoves()```
This moves content from consecutive memory location to another.
```c
void * memmove(void * s1,const void * s2, size_t n);
```
### ```strdup() and strndup()```
This is used to duplicate a string.
```c
char * strdup(char * source);
```
```c
char * strndup(char * source,int length);
```
### Date and time functions
#### ```clock()```
This function returns the processor time. Often since execution began.
```c
clock_t clock(void);
```
Typically measured at the start and end of the program.
```c
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    clock_t start,end;
    double cputime = 0.0;

    start = clock();
    for (int i = 0; i < 100000000; i++)
    {
        printf("");
    }
    end = clock();
    cputime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("CPU took %f seconds.\n",cputime);
    return 0;
}
``` 
#### ```time()```
Returnes the elapsed seconds from Jan 1 1970 (Calendar time).
```c
time_t time(time_t * timer);
```
The function ```difftime()``` returnes the differences between two times.
```c
double difftime(time_t t1,time_t t2);
```

#### ```ctime()```
Used to get todays time as a string. 
```c
char * ctime(const time_t * timer);
```
Example:
```c
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t currtime;
    currtime = time(0);
    printf("%s",ctime(&currtime));//Sat Jul 20 16:30:36 2024
    return 0;
}
```
#### ```localtime()```
Returnes the struct that includes all of the callendar details.
```c
struct tm * localtime(const time_t * timer);
```
Example:
```c
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t currtime = time(0);
    struct tm * localdata = localtime(&currtime);
    printf("Year is: %d\n",localdata->tm_year + 1900);
    printf("Month is: %d\n",localdata->tm_mon);
    printf("Day is: %d\n",localdata->tm_mday);
    return 0;
}
```
#### ```asctime()```
This function generates a string from the calendar data.
```c
char * asctime(const struct tm * time_data);
```
Example:
```c
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t currtime = time(0);
    struct tm * localdata = localtime(&currtime);
    printf("%s\n",asctime(localdata));
    return 0;
}
```
#### ```mktime()```
This function will provide all info from a date. We have to make a tm struct and fill year month and day and feed into this function. The function will replace all other values. Returns -1 for a failiure.
```c
time_t mktime(struct tm * ptime);
```
#### ```gmtime()```
This function is used to covert a time value into UTC in form of struct tm.
```c
struct tm * gmtime(const time_t * time);
```
