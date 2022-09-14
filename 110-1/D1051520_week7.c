#include <stdio.h>
#include <string.h>

int main()
{
    int n; //the loop times
    char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str[10000];
    int letter[26] = {0}; //the times the letter appears

    scanf("%d", &n);
    getchar(); //ignore enter

    while (n--)
    {
        fgets(str, sizeof(str), stdin);
        for (int i = 0; i < strlen(str); i++)
        {
            if ('a' <= str[i] && str[i] <= 'z')
            {
                int temp = (int)str[i] - 'a';
                letter[temp]++;
            }
            else if ('A' <= str[i] && str[i] <= 'Z')
            {
                int temp = (int)str[i] - 'A';
                letter[temp]++;
            }
        }
    } //end while loop

    for (int i = 0; i < 26; i++)
    {
        if (letter[i] > 0)
            printf("%c %d\n", abc[i], letter[i]);
    }
}