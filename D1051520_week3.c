#include <stdio.h>
#include <math.h>
int main()
{

    int ticket = 0; //movie ticket
    int drink = 0;  //the cup of drinks

    scanf("%d %d", &ticket, &drink);

    int planA = 1000000; //the a plan
    int planB = 1000000; //the b plan
    int planC = 1000000; //the c plan

    if (drink > 0 && ticket > 0)
        planA = ticket * 300 + drink * 40 - 10;

    if (ticket >= 2)
        planB = round((ticket * 300 + drink * 40) * 0.9);

    if (ticket >= 2 && drink > 0)
        planC = round((ticket * 300 + drink * 40) * 0.85 - 30);


    //output the cheapest plan
    if (planC < planA && planC < planB && planC != 1000000)
        printf("%d", planC);

    else if (planA < planB && planA < planC && planA != 1000000)
        printf("%d", planA);

    else if (planB < planA && planB < planC && planB != 1000000)
        printf("%d", planB);
}
