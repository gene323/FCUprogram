#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}
int main(){

    int st;//the number of student
    scanf("%d", &st);

    int score[30] = {0};//every student's score
    int passScore = 100;//the lowest pass score
    int failScore = 0;//the highest failed score
    bool allPass = 1;
    bool allFail = 1;

    for(int i=0; i<st; i++){
        scanf("%d", &score[i]);
        if(score[i] < 60 && failScore < score[i]){
            failScore = score[i];
        }
        
        if(score[i] >= 60 && passScore > score[i])
            passScore = score[i];
        
        if(score[i] < 60){
            allPass = 0;
        }
        
        if(score[i] >= 60){
            allFail = 0;
        }
    }

    qsort(score, st, sizeof(int), cmp);//sort from low to high

    for(int i=0; i<st; i++){
        printf("%d", score[i]);
        if(i != st - 1)
            printf(" ");
    }
    puts("");
    if(allPass){
        printf("best case"
        "\n%d", passScore);
    }
    else if(allFail){
        printf("%d\n"
        "worst case", failScore);
    }
    else{
        printf("%d\n%d", failScore, passScore);
    }
    
}