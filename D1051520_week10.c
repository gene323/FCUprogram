#include <stdio.h>

int main(){

    int fi[32];//fibonacci
    int size = sizeof(fi)/sizeof(fi[0]);
    fi[0] = 0;
    fi[1] = 1;
    for(int i=2; i<size; i++)
        fi[i] = fi[i-1] + fi[i-2];
    
    // for(int i=0; i<size; i++){
    //     printf("%d ", fi[i]);
    // }

    int time;
    scanf("%d", &time);
    while(time--){
        int a;
        int b;
        int sum = 0;
        scanf("%d%d", &a, &b);
        if(a > b)
            a^=b^=a^=b;//swap
        
        for(int i=a; i<=b; i++){
            for(int j=0; j<size; j++){
                if(i == fi[j]){
                    printf("%d\n", fi[j]);
                    sum++;
                }
            }

        }

        printf("%d", sum);
        //the last data would not print ------
        if(time > 0 ){
            printf("\n------\n");
        }
    }
}
