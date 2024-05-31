#include <stdio.h>

char * clrs[8] = {"Black","Red","Green","Yellow","Blue","Magenta","Cyan","White"} ;
char * styles[3] = {"Solid","Doted","Dashed"} ;
struct box{
    unsigned int fill:3;
    unsigned int :1;
    unsigned int brdrclr:3;
    unsigned int :1;
    unsigned int alpha:1;
    unsigned int haveBorder:1;
    unsigned int style:2;
    unsigned int :6;
};

void displayBox(struct box b) {
    printf("Fill Color: %s\n", clrs[b.fill]);
    printf("Border Color: %s\n", clrs[b.brdrclr]);
    printf("Alpha: %d\n", b.alpha);
    printf("Have Border: %d\n", b.haveBorder);
    printf("Style: %s\n", styles[b.style]);
}

int main(int argc, char const *argv[])
{
    struct box b1;
    b1.fill = 3;
    b1.brdrclr = 0;
    b1.alpha = 0;
    b1.haveBorder = 1;
    b1.style = 1;

    displayBox(b1);

    b1.fill = 5;
    b1.brdrclr = 2;
    b1.alpha = 1;
    b1.haveBorder = 0;
    b1.style = 2;
    
    displayBox(b1);
    
    printf("Size of struct box: %lu bytes\n", sizeof(struct box));

    return 0;
}
