#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[]){
    for(int i=0; i<8; i++){
        printf("%d ", arr[i]);
    }
    puts("");
}
int main(){
    int arr[8] = {1,5,6,3,2,4,9,10};
    for(int i=8 - 1; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
    printArray(arr);
}