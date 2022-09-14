//array reverse
//zerojudge a015
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(int *arr, int *res, int n, int m){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            *((res+(i*n)+j)) = *((arr+(j*m)) +(i));
        }
    }
}

void printArray(int *res, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d" ,*(res+(i*n)+j));
            //output the blank
            if(j != n-1)
                printf(" ");
        }
        //new line
        puts("");
    }
}

int main(){
    int n;
    int m;
    while(scanf("%d%d", &n, &m) != EOF){
        //Actually, I can use arr[][] 
        int *arr = (int *)malloc(sizeof(int)*n*m);
        int *arrAfter = (int *)malloc(sizeof(int)*n*m);
        //initialize the arr with 0
        memset(arr, 0, sizeof(*arr)* m * n);
        //initialize the arrAfter with 0
        memset(arr, 0, sizeof(*arrAfter)* m * n);  

        for(int i=0; i<n*m; i++){
            scanf("%d", &arr[i]);
        }
        reverse((int *)arr, (int *)arrAfter, n ,m);
        printArray((int*)arrAfter, m, n);

        free(arr);
        free(arrAfter);
    }
    return 0;
}