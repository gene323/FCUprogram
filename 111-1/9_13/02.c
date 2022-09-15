#include <stdio.h>

void AC(){
    //NxN 2d array
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    int row = 0, col = 0;
    while(row < n && col < n){
        int r = row, c = col;
        while(r >= 0 && c < n){
            printf("%d", arr[r][c]);
            r--, c++;
            //avoid output the last space
            if(r >= 0 && c < n)
                printf(" ");
        }
        puts("");
        if(row + 1 < n){
            row++;
        }
        else{
            col++;
        }
    }
}
int main(){
    //life hacker;
    AC();
    return 0;
}
