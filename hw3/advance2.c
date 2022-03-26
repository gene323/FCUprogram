//D1051520 hw3 advance2
//Date: 2022/03/26
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Vocabulary{
    bool flag;
    int vowel;
    char voc[6];
    struct Vocabulary *nextVoc;
};
typedef struct Vocabulary Vocabulary;

void openFile(FILE **fp, char *path);
bool isExistVoc(FILE *historyfp, char str[]);
void fillVoc(FILE *historyfp, FILE *wordsfp, Vocabulary **headVoc);
void lowerString(char str[]);
int countVowel(char *);
void printVoc(Vocabulary *headVoc, Vocabulary *curVoc);
void searchVoc(char*, char*, Vocabulary *, Vocabulary *, Vocabulary *);
void freeVoc(Vocabulary **headVoc, Vocabulary **curVoc, Vocabulary **tailVoc);
void sortVoc(Vocabulary *headVoc);

int main(){

    FILE *history, *words;
    openFile(&history, "history.txt");
    openFile(&words, "words.txt");

    Vocabulary *headVoc, *curVoc, *tailVoc;

    fillVoc(history, words, &headVoc);
    sortVoc(headVoc);
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
    char freqStr[10];
    bool judge = 1;
    while(fscanf(wordsfp, "%s", str) != EOF){
        tempVoc = (Vocabulary*) malloc(sizeof(Vocabulary));

        //assign value
        tempVoc->flag = isExistVoc(historyfp, str);
        tempVoc->vowel = countVowel(str);
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
            if(guessStr[i] == targetStr[j] && resultStr[j] != 'g'){
                (curVoc)->flag = 1;
                break;
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
                break;
            }
        }
        if(judge){
            (curVoc)->flag = 1;
        }
        (curVoc) = (curVoc)->nextVoc;
    }
}

void searchVoc
(char guessStr[], char resultStr[], Vocabulary *headVoc, Vocabulary *curVoc, Vocabulary *tailVoc){

    void greenLetter(char*, char*, int i , Vocabulary*, Vocabulary*);
    void blackLetter(char*, char* ,int i, Vocabulary*, Vocabulary*);
    void yellowLetter(char*, char*, int i, Vocabulary*, Vocabulary*);

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
    printf("\nAnd the first word is more possible than others\n");
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

int countVowel(char *str){
    bool letter[5] = { 0 };
    int res = 0;
    for(int i=0; i<strlen(str); i++){
        if(str[i] == 'a') ++letter[0];
        else if(str[i] == 'e') ++letter[1];
        else if(str[i] == 'i') ++letter[2];
        else if(str[i] == 'o') ++letter[3];
        else if(str[i] == 'u') ++letter[4];
    }
    for(int i=0; i<5; i++){
        res += letter[i];
    }
    return res;
}

void sortVoc(Vocabulary *headVoc){
    bool isSwap = 0;
    Vocabulary *ptr1;
    Vocabulary *ptr2 = NULL;

    if(ptr1 == NULL){ return ; }

    do{
        isSwap = 0;
        ptr1 = headVoc;

        while(ptr1->nextVoc != ptr2){
            if(ptr1->vowel < ptr1->nextVoc->vowel){
                int tempVow = ptr1->vowel;
                char tempStr[6];
                strcpy(tempStr, ptr1->voc);

                ptr1->vowel = ptr1->nextVoc->vowel;
                strcpy(ptr1->voc, ptr1->nextVoc->voc);
                ptr1->nextVoc->vowel = tempVow;
                strcpy(ptr1->nextVoc->voc, tempStr);

                isSwap = 1;
            }
            ptr1 = ptr1->nextVoc;
        }
        ptr2 = ptr1;
    }while(isSwap);
}
