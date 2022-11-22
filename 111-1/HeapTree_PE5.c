#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap{
    int capacity;
    int size;
    int* arr;
}Heap;

void insert(Heap*, int);
void swap(int*, int*);
void minHeapify(Heap*, int);
int parent(int);
int left(int);
int right(int);
int extractMin(Heap*);
Heap* createHeap(int);


int main(int argc, char** argv){

    FILE* input = fopen(argv[1], "r");

    char str[200];
    while(fscanf(input, "%[^\n]%*c", str) != EOF){
        char* tok = strtok(str, " ");
        Heap* heap = createHeap(atoi(tok));
        int cost = 0;

        //put number into heap
        tok = strtok(NULL, " "); //go to next number
        while(tok != NULL){
            insert(heap, atoi(tok));
            tok = strtok(NULL, " ");
        }

        while(heap->size > 1){
            int a = extractMin(heap);
            int b = extractMin(heap);
            cost += (a+b);
            insert(heap, a+b);
        }
        printf("%d\n", cost);
    }

    fclose(input);
    return 0;
}

void insert(Heap* heap, int key){
    int i = heap->size;
    heap->size++;
    heap->arr[i] = key;

    while(i != 0 && heap->arr[parent(i)] > heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

void minHeapify(Heap* heap, int i){
    int l = left(i);
    int r = right(i);
    int minimum = i;

    if(l < heap->size && heap->arr[l] < heap->arr[i]){
        minimum = l;
    }
    if(r < heap->size && heap->arr[r] < heap->arr[minimum]){
        minimum = r;
    }
    if(minimum != i){
        swap(&heap->arr[i], &heap->arr[minimum]);
        minHeapify(heap, minimum);
    }
}

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return i*2 + 1;
}

int right(int i){
    return i*2 + 2;
}

//return arr[0] and pop it out
int extractMin(Heap* heap){
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

Heap* createHeap(int cap){
    Heap* heap = malloc(sizeof(Heap));
    heap->capacity = cap;
    heap->size = 0;
    heap->arr = calloc(sizeof(int), cap);
    return heap;
}

void swap(int* i, int* j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
