#include "shuffle.h"

//SUITS 4
//FACES 13
//CARDS 52
void shuffle(int poker[][FACES]){
    
    //i begin with 1, end with 52
    //choose each card randomly
    for(int i=1; i<=CARDS; i++){
        int row;
        int column;

        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        }while(poker[row][column] != 0);

        poker[row][column] = i;
    }
}