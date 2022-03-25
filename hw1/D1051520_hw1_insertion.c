#include <stdio.h>

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {2,5,123,45,5634,234,23411};
    //the size of arrary
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=1; i<size; i++){
        int point = arr[i];
        int move = i - 1;
        while(move > 0 && arr[move] > point){
            arr[move + 1] = arr[move];
            move -= 1;
        }
        //because move -= 1, let move + 1 back to the correct element
        arr[move + 1] = point;
    }
    printArray(arr, size);
}