#include <stdio.h>
#include <string.h>

void checksystem(char ID[8]) //check the ID whether real or not
{
    int sum = 0;
    int checknumber;

    for (int i = 0; i < 6; i++)
    {
        int temp = (int)ID[i] - '0'; //convert to number

        if (i % 3 == 0)
            temp *= 8;
        else if (i % 3 == 1)
            temp *= 7;
        else
            temp *= 6;

        while (temp > 0)
        {
            sum = sum + temp % 10;
            temp /= 10;
        }
    }

    checknumber = (10 - sum % 10) % 10;

    printf("Your student ID ");
    if(ID[6] == (char)checknumber+'0')
        printf("is real");

    else
        printf("is fake");
}

int main()
{
    char ID[8]; //student ID
    printf("typing your last seven digits of studetn ID \n");
    scanf("%7s", ID); //input the ID

    checksystem(ID);
}
