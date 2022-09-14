#include <stdio.h>
#include <stdlib.h>

typedef struct POINT{
    int x;
    int y;
    int z;
}Point;

void string(int count, char ch);//function prototype

int cmp(const void* a, const void* b){
    Point tempA = *(Point*) a;
    Point tempB = *(Point*) b;
    if(tempA.x != tempB.x)
        return tempA.x - tempB.x;
    else if(tempA.y != tempB.y)
        return tempA.y - tempB.y;
    else
        return tempA.z -tempB.z;
}//end cmp funciton

int main(){
    int n;
    scanf("%d", &n);
    Point point[n];
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].z);
    }

    //sort from small to big
    qsort(point, n, sizeof(Point), cmp);
    for(int i=0; i<n; i++){
        printf("%d %d %d\n", point[i].x, point[i].y, point[i].z);
        if(i < n-1){
            string(10, '-');
            
            //new line
            puts("");
        }
    }
    return 0;
}//end main function

void string(int count, char ch){
    for(int i=0; i<count; i++)
        putchar(ch);
}//end string function