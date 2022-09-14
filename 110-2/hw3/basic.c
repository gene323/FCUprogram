//D1051520 hw3 basic
//Date 2022/03/22
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

void openFile(FILE **fp, char *path);
bool isExistVoc(FILE *historyfp, char str[]);
void fillVoc(FILE *historyfp, FILE *wordsfp, Vocabulary **headVoc);
void lowerString(char str[]);
void printVoc(Vocabulary *headVoc, Vocabulary *curVoc);
void searchVoc(char*, char* , Vocabulary *, Vocabulary *, Vocabulary *);
void freeVoc(Vocabulary **, Vocabulary **, Vocabulary **);

int main(){

    FILE *history, *words;
    openFile(&history, "history.txt");
    openFile(&words, "words.txt");

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

        searchVoc(guessStr, resultStr, headVoc, curVoc, tailVoc);
        printVoc(headVoc, curVoc);
    //when strcmp == 0
    //break loop
    }while(strcmp(guessStr, "ggggg") && strcmp(resultStr, "ggggg"));


    freeVoc(&headVoc, &curVoc, &tailVoc);
    fclose(history);
    fclose(words);
    return 0;
}//end main func

void openFile(FILE **fp, char *path){
    if((*fp = fopen(path, "r")) == NULL){
        printf("The %s file can not open", path);
        puts("");
        return ;
    }
    printf("The %s file open successfully", path);
    puts("");
}//end openFile func

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

void greenLetter(char guessStr[], char resultStr[], int i, Vocabulary *headVoc, Vocabulary *curVoc){
    curVoc = headVoc;
    char targetStr[6];
    while(curVoc != NULL){
        strcpy(targetStr, (curVoc)->voc);
        if(targetStr[i] != guessStr[i]){
            (curVoc)->flag = 1;
        }
        (curVoc) = (curVoc)->nextVoc;
    }
}

void blackLetter(char guessStr[], char resultStr[], int i,
        Vocabulary *headVoc, Vocabulary *curVoc){
    curVoc = headVoc;
    char targetStr[6];
    while(curVoc != NULL){
        strcpy(targetStr, (curVoc)->voc);
        for(int j=0; j<5; j++){
            if(guessStr[i] == targetStr[j] && resultStr[j] != 'g' && curVoc->flag == 0){
                for(int k=0; k<5; k++){
                    if(guessStr[k] == targetStr[j] && resultStr[k] == 'y'){
                        curVoc->flag = 0;
                        break;
                    }
                    else
                        curVoc->flag = 1;
                }
            }
        }
        curVoc = (curVoc)->nextVoc;
    }

}

void yellowLetter(char guessStr[], char resultStr[], int i, Vocabulary *headVoc, Vocabulary *curVoc){
    curVoc = headVoc;
    char targetStr[6];
    while(curVoc != NULL){
        bool judge = true;
        strcpy(targetStr, (curVoc)->voc);
        for(int j=0; j<5; j++){
            if(guessStr[i] == targetStr[j] && i != j){
                judge = false;
            }
            if(guessStr[i] == targetStr[j] && i == j)
                (curVoc)->flag = 1;
        }
        if(judge){
            (curVoc)->flag = 1;
        }
        (curVoc) = (curVoc)->nextVoc;
    }
}

void searchVoc
(char guessStr[], char resultStr[], Vocabulary *headVoc, Vocabulary *curVoc, Vocabulary *tailVoc){

    void (*func[3])(char*, char*, int, Vocabulary*, Vocabulary*)
    = {greenLetter, blackLetter, yellowLetter};

    for(int i=0; i<5; i++){
        if(resultStr[i] == 'g'){
            func[0](guessStr, resultStr, i, headVoc, curVoc);
        }
        else if(resultStr[i] == 'b'){
            func[1](guessStr, resultStr, i, headVoc, curVoc);
        }
        else if(resultStr[i] == 'y'){
            func[2](guessStr, resultStr, i, headVoc, curVoc);
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

