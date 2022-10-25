#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursion(int children, int adult, int gen){
    if(gen == 1){
        printf("%d\n", children + adult);
        return 0;
    }

    return recursion(adult * 2, children + adult, gen - 1);
}

int main(){

    char ch[2];
    while(scanf("%s", ch)){
        getchar();
        if(strcmp(ch, "#") == 0){
            break;
        }

        int gen = atoi(ch);
        if(0 < gen && gen < 21){
            int children = 1;
            int adult = 0;
            recursion(1, 0, gen);
        }
        else{
            printf("Error!\n");
        }
    }

    //1, 1, 0
    //2, 0, 1
    //3, 2, 1
    //4, 2, 3
    //5, 6, 5

    return 0;
}
