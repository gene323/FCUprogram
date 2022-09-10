#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct List{
    int val;
    struct List *next;
}List;

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){

    int val;
    bool isFirst = 1;
    int arrSize = 0;
    List *head[2] = {NULL, NULL};
    List *cur[2];
    List *mergeHead = NULL;
    List *mergeCur;

    for(int i=0; i<2; i++){
        while(scanf("%d", &val)){
            if(val == -1){
                isFirst = 1;
                break;
            }
            if(isFirst){
                head[i] = (List*)malloc(sizeof(List));
                head[i]->val = val;
                head[i]->next = NULL;
                cur[i] = head[i];
                isFirst = 0;
            }
            else{
                cur[i]->next = (List*)malloc(sizeof(List));
                cur[i] = cur[i]->next;
                cur[i]->val = val;
                cur[i]->next = NULL;
            }
            ++arrSize;
        }
    }

    int arr[arrSize];
    int pivot = 0;
    for(int i=0; i<2; i++){
        cur[i] = head[i];
        printf("List %d: ", i+1);
        while(cur[i]){
            printf("%d ", cur[i]->val);
            arr[pivot++] = cur[i]->val;
            cur[i] = cur[i]->next;
        }
        puts("");
    }

    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), cmp);
    for(int i=0; i<arrSize; i++){
        if(!i){
            mergeHead = (List*)malloc(sizeof(List));
            mergeHead->val = arr[i];
            mergeHead->next = NULL;
            mergeCur = mergeHead;
        }
        else{
            mergeCur->next = (List*)malloc(sizeof(List));
            mergeCur = mergeCur->next;
            mergeCur->val = arr[i];
            mergeCur->next = NULL;
        }
    }
    mergeCur = mergeHead;
    printf("merge: ");
    while(mergeCur){
        printf("%d ", mergeCur->val);
        mergeCur = mergeCur->next;
    }

    return 0;
}
