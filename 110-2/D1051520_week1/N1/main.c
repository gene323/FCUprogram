#include "bubble.c"
#define SIZE 40 // array size

void printMode(int* , int);
int main(){

    int arr[SIZE] =
    {1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
    1, 6, 3, 8, 6, 10, 3, 8, 2, 7,
    6, 5, 7, 6, 8, 6, 7, 5, 6, 6, 
    5, 6, 7, 5, 6, 4, 8, 6, 8, 10};
    int total = 0;
    float mean = 0;
    float median = 0;

    for(int i=0; i<SIZE; i++){
        total += arr[i];
    }
    
    mean = (float)total / SIZE;

    printf("The total is %d\n"
    "The mean is %.4f\n\n", total, mean);
    
    int mode[10] = {0};

    //sort array
    bubbleSort(arr,SIZE);
    printf("The sorted array is\n");
    for(int i=0; i<SIZE; i++){
        printf("%2d ", arr[i]);
        if((i+1)%20 == 0)
            puts("");
        
        //count the number of mode
        mode[arr[i]-1]++;
    }

    //new line
    puts("");
    median = (arr[SIZE/2] + arr[SIZE/2 -1]) / 2;
    printf("The median is %d\n", (int)median);

    //new line
    puts("");
    printMode(mode, 10);
    return 0;
}

void printMode(int mode[], int size){
    printf("Rating\tFrequency\n");
    for(int i=0; i<10; i++){
        printf("%6d\t%9d\n", i+1, mode[i]);
    }
}
