#include<stdio.h>

void head_function(int head)
{
    int temp_head = 1;

    for(int i=0; i<head; i++)
    {

        for(int j=0; j<head-i; j++)
            printf(".");

        printf("*");

        if(i>0 && i!=head-1)
        {
            for(int j=0; j<temp_head; j++)
                printf(".");

            temp_head +=2;

            printf("*");
        }

        else if(i == head-1)
        {
            for(int j=0; j<head*2 -2; j++)
                printf("*");
        }
        for(int j=0; j<head-i; j++)
            printf(".");


        printf("\n");

    }//end of for loop

}//end head_function

void body_function(int body, int head)
{
    for(int i=0; i<body; i++)
    {
        for(int j=0; j<2; j++)
            printf(".");

        for(int j=0; j<(head*2+1)-4; j++)
            printf("*");

        for(int j=0; j<2; j++)
            printf(".");

        printf("\n");

    }//end of for loop

}//end body_function

void leg_function(int leg, int head)
{
    for(int i=0; i<leg; i++)
    {
        for(int j=0; j<(head*2+1-3)/2; j++)
            printf(".");

        for(int j=0; j<3; j++)
            printf("*");

        for(int j=0; j<(head*2+1-3)/2; j++)
            printf(".");

        printf("\n");

    }//end of for loop

}//end leg_function

int main()
{
    int head;//3 < head < 100
    int body;//0 < body < 100
    int leg; //0 < leg < 100

    while(scanf("%d%d%d", &head, &body, &leg))
    {
        if(head == 0 && body == 0 && leg == 0)
            break;

        head_function(head);
        body_function(body, head);
        leg_function(leg, head);

    }//end of while
}
