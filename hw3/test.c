#include <stdio.h>
#include <string.h>
#define SUM 2315

typedef struct{
    int flag;
    char word[10];
}Voc;

void fillWord(Voc *voc){

    int index = SUM;
    while(index != 100){
        voc[index].flag = index;
        strcpy(voc[index].word, "haha");
        ++index;
    }
}
int main(){

    Voc voc[SUM];

    fillWord( voc );
    for(int i=0; i<100; i++){
        printf("%d %s\n", voc[i].flag, voc[i].word);
    }
    return 0;
}
