#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Vocabulary{
    bool flag;
    char voc[6];
    struct Vocabulary *nextVoc;
}Vocabulary;

FILE *history;
FILE *words;

void isFileOpen(char *path);
int countVoc(FILE *fp);
bool isExistVoc(FILE *sourcefp, char str[]);
Vocabulary* fillVoc(FILE *sourcefp, const int COUNT);
void lowerString(char str[]);
void printVoc(Vocabulary *headVoc, Vocabulary *curVoc);
void searchVoc(char guessStr[], char resultStr[], Vocabulary **headVoc,
        Vocabulary **curVoc, Vocabulary **tailVoc);
void freeVoc(Vocabulary **headVoc, Vocabulary **curVoc, Vocabulary **tailVoc);

int main(){

    isFileOpen("history.txt");
    isFileOpen("words.txt");

    FILE *history = fopen("history.txt", "r");
    FILE *words = fopen("words.txt", "r");

    Vocabulary *headVoc, *curVoc, *tailVoc;
    const int COUNT = countVoc(words);

    fseek(words, 0, SEEK_SET);
    char str[6];
    for(int i=0; i<COUNT; i++){
        curVoc = (Vocabulary*) malloc(sizeof(Vocabulary));
        fscanf(words, "%s", str);

        //define value
        curVoc->flag = isExistVoc(history, str);
        strcpy(curVoc->voc, str);

        if(i == 0){
            headVoc = curVoc;
        }
        else
            tailVoc->nextVoc = curVoc;
        curVoc->nextVoc = NULL;
        tailVoc = curVoc;
    }

    printVoc(headVoc, curVoc);
    char guessStr[6];
    char resultStr[6];
    do{
        printf("Your answer: ");
        scanf("%s", guessStr);
        printf("Your result: ");
        scanf("%s", resultStr);

        searchVoc(guessStr, resultStr, &headVoc, &curVoc, &tailVoc);
        printVoc(headVoc, curVoc);
    //when strcmp == 0
    //break loop
    }while(strcmp(guessStr, "ggggg") && strcmp(resultStr, "ggggg"));


    curVoc = headVoc;
    while(curVoc != NULL){
        tailVoc = curVoc;
        curVoc = curVoc->nextVoc;
        free(tailVoc);
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

bool isExistVoc(FILE *sourcefp, char str[]){

    fseek(sourcefp, 17, SEEK_SET);
    char targetStr[6];
    while(fscanf(sourcefp, "%*s %*s %s", targetStr) != EOF){
        lowerString(targetStr);
        if(strcmp(targetStr, str) == 0){ return true; }
    }
    return false;
}//end isExistVoc func


int countVoc(FILE *fp){
    int count = 0;
    while(fscanf(fp, "%*s") != EOF){
        ++count;
    }
    fseek(fp, 0, SEEK_SET);
    return count;
}//end countVoc func

Vocabulary* fillVoc(FILE *sourcefp, const int COUNT){

    fseek(sourcefp, 0, SEEK_SET);
    char str[6];
    Vocabulary *firstVoc, *curVoc, *tailVoc;

    for(int i=0; i<COUNT; i++){
        curVoc = (Vocabulary*) malloc(sizeof(Vocabulary));
        fscanf(sourcefp, "%s", str);

        //define value
        curVoc->flag = isExistVoc(history, str);
        strcpy(curVoc->voc, str);

        if(i == 0){
            firstVoc = curVoc;
        }
        else
            tailVoc->nextVoc = curVoc;
        curVoc->nextVoc = NULL;
        tailVoc = curVoc;
    }
    return firstVoc;
}

void searchVoc(char guessStr[], char resultStr[], Vocabulary **headVoc,
        Vocabulary **curVoc, Vocabulary **tailVoc){
    for(int i=0; i<5; i++){
        if(resultStr[i] == 'g'){
            *curVoc = *headVoc;
            char targetStr[6];
            while(*curVoc != NULL){
                strcpy(targetStr, (*curVoc)->voc);
                if(targetStr[i] != guessStr[i]){
                    (*curVoc)->flag = 1;
                }
                (*curVoc) = (*curVoc)->nextVoc;
            }
        }
        else if(resultStr[i] == 'b'){
            *curVoc = *headVoc;
            char targetStr[6];
            while(*curVoc != NULL){
                strcpy(targetStr, (*curVoc)->voc);
                for(int j=0; j<5; j++){
                    if(guessStr[i] == targetStr[j] && resultStr[j] != 'g'){
                        (*curVoc)->flag = 1;
                        break;
                    }
                }
                *curVoc = (*curVoc)->nextVoc;
            }
        }
        else if(resultStr[i] == 'y'){
            *curVoc = *headVoc;
            char targetStr[6];
            while(*curVoc != NULL){
                bool judge = true;
                strcpy(targetStr, (*curVoc)->voc);
                for(int j=0; j<5; j++){
                    if(guessStr[i] == targetStr[j] && i != j){
                        judge = false;
                        break;
                    }
                }
                if(judge){
                    (*curVoc)->flag = 1;
                }
                (*curVoc) = (*curVoc)->nextVoc;
            }
        }
    }
}

void printVoc(Vocabulary *headVoc, Vocabulary *curVoc){
    curVoc = headVoc;
    int ret = 0;
    puts("");
    while(curVoc != NULL){
        if(curVoc->flag == 0){
            printf("%s ", (curVoc)->voc);
            if( !((ret+1) % 10) ) puts("");
            ++ret;
        }
        curVoc = (curVoc)->nextVoc;
    }
    printf("\n\nThe above are all possible answers\n");
}
void lowerString(char str[]){
    int len = strlen(str);
    for(int i=0; i<len; i++)
        str[i] = tolower(str[i]);
}//end lowerString func

void freeVoc(Vocabulary **headVoc, Vocabulary **curVoc, Vocabulary **tailVoc){
    *curVoc = *headVoc;
    while(*curVoc != NULL){
        free( (*curVoc));
        *curVoc = (*curVoc)->nextVoc;
    }
    free(*tailVoc);
}
