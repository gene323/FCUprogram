#include <stdio.h>

int partition(int*, int, int);
void quickSort(int*, int, int);
void swap(int*, int*);

int main(){
    int arr[8] = {1,5,6,3,2,4,9,10};
    quickSort(arr, 0, 8 - 1);

    for(int i=0; i<8; i++){
        printf("%d ", arr[i]);
    }
}
void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high){

    
    int pivot = arr[high]; //pick the rightmost element
    
    int point = low; //pointer for greater element

    for(int i=low; i<high; i++){
        if(arr[i] <= pivot){

            //if element smaller than pivot be found
            //swap between arr[0...high-1] and arr[point] 
            swap(&arr[i], &arr[point]);
            point++;
        }
    }

    swap(&arr[point], &arr[high]);
    return point;
}//end partition function

void quickSort(int arr[], int low, int high){
    if(low < high){

        int p = partition(arr, low, high);//pivot
        
        //recursive call on the left part of pivot
        quickSort(arr, low, p - 1);
        //recursive call on the right part of pivot 
        quickSort(arr, p + 1, high);
    }
}//end quickSort function
