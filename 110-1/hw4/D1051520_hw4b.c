#include <stdio.h>

int checksystem1(int temp_ID)
{
    int sum = 0;
    int checknumber = temp_ID % 10;
    temp_ID /= 10;

    //the inspection process
    for (int i = 0; i < 5; i++)
    {
        int temp = temp_ID % 10;
        temp_ID /= 10;

        if (i % 3 == 0)
            temp *= 6;
        else if (i % 3 == 1)
            temp *= 7;

        else
            temp *= 8;

        while (temp > 0)
        {
            sum = sum + temp % 10;
            temp /= 10;
        }
    }

    if( (10 - sum % 10) % 10 == checknumber )
    {
        if(checknumber % 2 == 1)
            return 1;

        else
            return 2;
    }
    else
        return 0;

}//end of checksystem1



int checksystem2(int temp_ID)
{
    int sum = 0;
    int checknumber = temp_ID % 10;
    temp_ID /= 10;

    //the inspection process
    for (int i = 0; i < 6; i++)
    {
        int temp = temp_ID % 10;
        temp_ID /= 10;

        if (i % 3 == 0)
            temp *= 6;
        else if (i % 3 == 1)
            temp *= 7;

        else
            temp *= 8;

        while (temp > 0)
        {
            sum = sum + temp % 10;
            temp /= 10;
        }
    }

    if( (10 - sum % 10) % 10 == checknumber )
    {
        if(checknumber % 2 == 1)
            return 1;

        else
            return 2;
    }
    else
        return 0;

}//end of checksystem2


int main()
{
    int ID;
    int odd = 0;
    int even = 0;

    for (ID = 700000; ID <= 1099999; ID++)
    {
        int temp_ID = ID;

        if(ID<1000000)
        {
            if( checksystem1(temp_ID) == 1)
                odd += 1;

            else if( checksystem1(temp_ID) == 2)
                even += 1;
        }

        else
        {
            if( checksystem2(temp_ID) == 1)
                odd += 1;

            else if( checksystem2(temp_ID) == 2)
                even += 1;
        }


    }//end of for (ID = 700000; ID <= 1099999; ID++)

    printf("odd:%d even:%d", odd, even);
}
