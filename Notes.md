# Notes are pasted here
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




