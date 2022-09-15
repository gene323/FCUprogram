#include "bubble.h"

void bubbleSort(int * const arr, const int size, int (*cmp)(int, int)){
    
    void swap(int *aptr, int *bptr);
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size - i - 1; j++){
            if((*cmp)(arr[j], arr[j+1])){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//swap two element
void swap(int *aptr, int *bptr){
    int temp = *aptr;
    *aptr = *bptr;
    *bptr = temp;
}

int ascending(int a, int b){
    return b < a;
}

int descending(int a, int b){
    return b > a;
}
