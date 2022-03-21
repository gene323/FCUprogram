#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Vocabulary{
    bool flag;
    char voc[6];
    struct Vocabulary *nextVoc;
};
typedef struct Vocabulary Vocabulary;

void isFileOpen(char *path);
bool isExistVoc(FILE *historyfp, char str[]);
void fillVoc(FILE *historyfp, FILE *wordsfp, Vocabulary **headVoc);
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

    fillVoc(history,words, &headVoc);
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


    freeVoc(&headVoc, &curVoc, &tailVoc);
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

bool isExistVoc(FILE *historyfp, char str[]){

    fseek(historyfp, 17, SEEK_SET);
    char targetStr[6];
    while(fscanf(historyfp, "%*s %*s %s", targetStr) != EOF){
        lowerString(targetStr);
        if(strcmp(targetStr, str) == 0){ return true; }
    }
    return false;
}//end isExistVoc func

void fillVoc(FILE *historyfp, FILE *wordsfp, Vocabulary **headVoc){

    fseek(wordsfp, 0, SEEK_SET);
    Vocabulary *tempVoc, *tailVoc;
    char str[6];
    bool judge = 1;
    while(fscanf(wordsfp, "%s", str) != EOF){
        tempVoc = (Vocabulary*) malloc(sizeof(Vocabulary));

        //define
        tempVoc->flag = isExistVoc(historyfp, str);
        strcpy(tempVoc->voc, str);

        if(judge){
            *headVoc = tempVoc;
            judge = 0;
        }
        else
            tailVoc->nextVoc = tempVoc;
        tempVoc->nextVoc = NULL;
        tailVoc = tempVoc;
    }
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
        *tailVoc = *curVoc;
        *curVoc = (*curVoc)->nextVoc;
        free(*tailVoc);
    }
}
