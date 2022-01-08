#include <stdio.h>

void reverse(int n, int m, int arr[n][m], int res[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            res[i][j] = arr[j][i];    
        }
    }
}
int main(){
    int n;
    int m;
    while(scanf("%d%d", &n, &m) != EOF){
        int arr[n][m];
        int arrAfter[m][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                scanf("%d", &arr[i][j]);
        }
        reverse(n ,m, arr, arrAfter);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                printf("%d ", arrAfter[i][j]);
            }
            puts("");
        }
    }
    return 0;
}