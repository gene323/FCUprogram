//Faro shuffle
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
void shuffle(Card * const wDeck);
void faroShuffle(Card * wDeck);
void deal(const Card * const wDeck);

int main(void){
 
    Card deck[CARDS]; // define array of Cards

    // initialize array of pointers
    const char *face[] = {
    "Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten",
    "Jack", "Queen", "King"};

    // initialize array of pointers
    const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(NULL)); // randomize

    fillDeck(deck, face, suit); // load the deck with Cards
    shuffle(deck); // put Cards in random order
    faroShuffle(deck);
    deal(deck); // deal all 52 Cards
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

void shuffle(Card * const wDeck){

    Card tmp;
    int numRand;
    for(size_t i=0; i<CARDS; i++){
        tmp = wDeck[i];
        numRand = rand() % (CARDS - i) + i;
        wDeck[i] = wDeck[numRand];
        wDeck[numRand] = tmp;
    }
}
//faro shuffle
void faroShuffle(Card * wDeck){
 
    Card deckA[CARDS], deckB[CARDS];
    int count = 0;
    int cntA = 0;
    int cntB = 0;
    // loop through wDeck randomly swapping Cards
    for (size_t i = 0; i < CARDS; ++i) { 
        (count == 0)?(deckA[cntA] = wDeck[i]) : (deckB[cntB] = wDeck[i]);
        (count == 0) ? (cntA++) : (cntB++);
        count = !count;
    }
    cntA = 0;
    cntB = 0;
    for(size_t i=0; i<CARDS; i++){
        (i%2) ? (wDeck[i] = deckA[cntA]) : (wDeck[i] = deckB[cntB]);
        (i%2) ? (cntA++) : (cntB++);
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
