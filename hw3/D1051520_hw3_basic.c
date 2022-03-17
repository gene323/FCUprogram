#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *history = fopen("history.txt", "r");
    FILE *words = fopen("words.txt", "r");

    if( (history = fopen("history.txt", "r")) == NULL){
        puts("The history file can not open");
    }
    else{
        puts("The history file open successfully");
    }

    if( (words = fopen("words.txt", "r")) == NULL){
        puts("The words file can not open");
    }
    else{
        puts("The words file open successfully");
    }

    char date[20];
    char day[20];
    char answer[20];

    fseek(history, 17, SEEK_SET);
    fscanf(history, "%*s %*s %s", answer);

    while(!feof(history)){
        printf("%s\n", answer);
        fscanf(history, "%*s %*s %s", answer);
    }
    return 0;
}
