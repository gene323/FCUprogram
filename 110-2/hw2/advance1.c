//Fisher-Yates shuffle is a fair shuffle
//step1. pick from the first to the last cards randomly
//step2. and then put the picked card into new deck
//step3. do again step1. and step2. until no card to picked
//return the new deck 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition                  
struct card {                                 
    const char *face; // define pointer face   
    const char *suit; // define pointer suit   
}; 

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck(Card * const wDeck, const char * wFace[], 
    const char * wSuit[]);
void shuffle(Card * const wDeck, Card * const shuffled);
void deal(const Card * const wDeck);

int main(void){
 
    Card deck[CARDS]; // define array of Cards
    Card shuffled[CARDS];
    // initialize array of pointers
    const char *face[] = {
    "Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten",
    "Jack", "Queen", "King"};

    // initialize array of pointers
    const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(NULL)); // randomize

    fillDeck(deck, face, suit); // load the deck with Cards
    shuffle(deck, shuffled); // put Cards in random order
    deal(shuffled); // deal all 52 Cards
} 

// place strings into Card structures
void fillDeck(Card * const wDeck, const char * wFace[], 
    const char * wSuit[]){
 
    // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) { 
        wDeck[i].face = wFace[i % FACES];//0 1 2--12,0 1 2 12,
        wDeck[i].suit = wSuit[i / FACES];//0 0 0 0--,1 1 1 ,
    } 
} 

// shuffle cards
void shuffle(Card * const wDeck, Card * const shuffled){

    int tmp;
    int record[CARDS] = { 0 };
    const int M = 51;
    const int m = 0;
    for(size_t i=0; i<CARDS; i++){
        tmp = rand() % (M - m + 1) + m;
       
        while(record[tmp]){
            tmp = rand() % (M - m + 1) + m;
        }
        shuffled[i] = wDeck[tmp];
        record[tmp] = 1;
    }
} 

// deal cards
void deal(const Card * const wDeck){

    // loop through wDeck
    for (size_t i = 0; i < CARDS; ++i) {

        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
         (i + 1) % 4 ? "  " : "\n");
    } 
}
