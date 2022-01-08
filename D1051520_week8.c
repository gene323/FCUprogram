#include <stdio.h>

int upper(int);//function prototype
int lower(int);//function prototype
int string_length(char* );//function prototype

int main()
{
    char string[] = "HellO? World!!!/^^";

    printf("%s\n\n", string);

    printf("string length: %d\n", string_length(string));//input length of string

    for(int i = 0; i < string_length(string); i++)//to lower
    {
        printf("%c", upper(string[i]));    
    }

    printf("\n");

  

    for(int i = 0 ; i < string_length(string) ; i++)//to upper
    {

        printf("%c", lower(string[i]));
    }

    printf("\n");

}//end main function

int upper(int character)
{
    if('A' <= character && character <= 'Z')
        return character + 32;
    else
        return character;

}//end function upper

int lower(int character)
{
    if('a' <= character && character <= 'z')
        return character - 32;
    else
        return character ;

}//end function lower

int string_length(char* string)
{
    int count = 0;
    while(string[count] != '\0')
        count++;
    
    return count;

}//end function string_length