#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int climbStairs(int n){
    double estim = 0.4472135955 * pow(1.618033988745, n+1);
    if(fabs((ceil(estim)-estim)) < fabs(estim-floor(estim)))
        return ceil(estim);
    else
        return floor(estim); 
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", climbStairs(n));
    }
    return 0;
}