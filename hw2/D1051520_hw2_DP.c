#include <stdio.h>

int climbStairs(int n){
    int stairs[45];
    stairs[0] = 1;
    stairs[1] = 2;
    for(int i=2; i<45; i++){
        stairs[i] = stairs[i-1] + stairs[i-2];
    }
    return stairs[n-1];
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", climbStairs(n));
    }
    return 0;
}