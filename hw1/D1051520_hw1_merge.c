#include <stdio.h>

void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void printArray(int*, int);

int main(){
    int arr[] = {1,3,5,7,8,123,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);   
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
}
void merge(int arr[], int head, int mid, int tail){
    //the length of left part
    int lenLeft = mid - head + 1;
    //the length of right part 
    int lenRight = tail - (mid+1) +1;

    int arrLeft[lenLeft];
    int arrRight[lenRight];

    for(int i=0; i<lenLeft; i++)
        arrLeft[i] = arr[head + i];
    for(int i=0; i<lenRight; i++)
        arrRight[i] = arr[mid+1 + i];
    
    int l = 0;
    int r = 0;
    int count = head;
    while(l < lenLeft && r < lenRight){
        if(arrLeft[l] < arrRight[r]){
            arr[count] = arrLeft[l];
            l++;
        }
        else{
            arr[count] = arrRight[r];
            r++;
        }
        count++;
    }
    //the rest part of arrLeft and arrRight
    while(l < lenLeft){
        arr[count] = arrLeft[l];
        l++;
        count++;
    }
    while(r < lenRight){
        arr[count] = arrRight[r];
        r++;
        count++;
    }
}//end merge function
void mergeSort(int arr[], int head, int tail){
    if(head < tail){
        int mid = (tail + head)/2;
        mergeSort(arr, head, mid);
        mergeSort(arr, mid + 1, tail);
        merge(arr, head, mid, tail);
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
}