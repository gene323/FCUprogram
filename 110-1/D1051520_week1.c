#include<stdio.h>
int main(){


    char string[][13]=
    {
        "hello, world",
        "hello      ",
        "       world",
        "he          ",
        "he       r d",
        "   lo w     ",
        "    o     ld",
        "hello, world"
    };
    char flag = 0;

    for(int i=0;i<8;i++)
    {
        printf("%s", string[i]);
        scanf("%c", &flag);
    }
return 0;
}
