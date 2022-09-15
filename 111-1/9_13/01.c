#include <stdio.h>

void AC(){
    char ch;
    int n, len;
    //len is height
    scanf("%c%d%d", &ch, &len, &n);

    if(len < 1 || n < 1)
        return ;
    else if(len == 1){
        for(int i=0; i<n; i++){
            printf("%c", ch);
            if(i != n - 1)
                puts("");
        }
    }
    else{
        for(int k=0; k<n; k++){
            for(int i=0; i<len; i++){
                for(int j=0; j<=i; j++){
                    printf("%c", ch);
                }
                puts("");
            }
            for(int i=len-1; i>1; i--){
                for(int j=i; j>0; j--){
                    printf("%c", ch);
                }
                puts("");
            }
            if(k == n - 1)
                printf("%c", ch);
        }
    }
    return ;
}

int main(){
    //life hacker
    AC();
    return 0;
}
