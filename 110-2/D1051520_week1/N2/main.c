#include "bubble.c"
#define SIZE 10

void printArray(int arr[], const int size);
int main(){
    
    int arr[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");
    printArray(arr, SIZE);
    puts("");

    //ascending 
    bubbleSort(arr, SIZE, ascending);
    puts("Data items in ascending order");
    printArray(arr, SIZE);
    puts("");

    //descending
    bubbleSort(arr, SIZE, descending);
    puts("Data items in descending order");
    printArray(arr, SIZE);
    puts("");

    return 0;
}

void printArray(int arr[], const int size){
    for(int i=0; i<size; i++){
        printf("%4d", arr[i]);
    }
}
