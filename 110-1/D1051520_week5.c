#include <stdio.h>

void cola(int); //function prototype
int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        cola(n);
    }
}

void cola(int n)
{
    int sum = n;

    while (n - 3 >= 0)
    {
        sum = sum + 1;
        n = n - 3 + 1;
    }
    if (n == 2)
        sum += 1;

    printf("%d\n", sum);

} //end function cola