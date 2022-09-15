#include "deal.h"

//SUITS 4
//FACES 13
//CARDS 52
void deal(int poker[][FACES], const char *suit[], const char *face[]){

    for(int i=1; i<=CARDS; i++){
        int rowJudge = 0;
        for(int row=0; row<SUITS; row++){
            for(int column=0; column<FACES; column++){

                if(poker[row][column] == i){
                    printf("%5s of %-8s%c", face[column], suit[row], i%2==0?'\n':'\t');
                    rowJudge = 1;
                    break;
                }
            }
            if(rowJudge){
                break;
            }
        }
    }
}