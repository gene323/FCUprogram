#include "bubble.h"
#define swap(a, b) a^=b^=a^=b

void bubbleSort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
