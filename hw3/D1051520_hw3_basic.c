#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Vocabulary{
    bool flag;
    char voc[10];
    struct Vocabulary *nextVoc;
}Vocabulary;

FILE *history;
FILE *words;

void isFileOpen(char *path);
int countWord(FILE *fp);

int main(){

    isFileOpen("history.txt");
    isFileOpen("words.txt");

    FILE *history = fopen("history.txt", "r");
    FILE *words = fopen("words.txt", "r");

    Vocabulary *headVoc, *curVoc, *tailVoc;
    const int COUNT = countWord(words);
    char str[10], targetStr[10];

    for(int i=0; i<COUNT; i++){
        curVoc = (Vocabulary*) malloc(sizeof(Vocabulary));
        fscanf(words, "%s", str);

        fseek(history, 17, SEEK_SET);
        while(fscanf(history, "%*s %*s %s", targetStr) != EOF){
            for(int i=0; i<strlen(targetStr); i++){
                targetStr[i] = tolower(targetStr[i]);
            }
            if(strcmp(targetStr, str) == 0){
                curVoc->flag = 1;
                break;
            }
            else{
                curVoc->flag = 0;
            }
        }
        strcpy(curVoc->voc, str);
        if(i == 0){
            headVoc = curVoc;
        }
        else
            tailVoc->nextVoc = curVoc;
        curVoc->nextVoc = NULL;
        tailVoc = curVoc;
    }
    curVoc = headVoc;
    while(curVoc != NULL){
        printf("%d %s\n", curVoc->flag, curVoc->voc);
        curVoc = curVoc->nextVoc;
    }

    return 0;
}//end main func

void isFileOpen(char *path){
    if( fopen(path, "r") == NULL){
        printf("The %s file can not open", path);
    }
    else{
        printf("The %s file open successfully", path);
    }
    puts("");
}//end isFileOpen func

int countWord(FILE *fp){
    int count = 0;
    while(fscanf(fp, "%*s") != EOF){
        ++count;
    }
    fseek(fp, 0, SEEK_SET);
    return count;
}//end countWord func
