#include<stdio.h>

int main(void)
{
    int x;
    int y;  //the true answer and transfer to ascii
    int z;  //king's answer
    scanf("%d", &z);

    x = z/3-9;  //decrypt
    y = (x+10)*3+6;  //decrypt
    printf("%d %c", x, y);  //output the true answer
}
