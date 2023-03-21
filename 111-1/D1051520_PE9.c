//not completed 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef struct Gate{
    char name[5];
    int delay;
    int input;
}Gate;

typedef struct Node{
    char name[5];
    struct Node* next;
}Node;

typedef struct Edge{
    int src;
    int dest;
    int delay;
}Edge;

int findNode(Node*, char*);

int main(){

    FILE* gatesFile = fopen("Gates.txt", "r");
    FILE* circuitFile = fopen("Circuit.txt", "r");

    int n;
    fscanf(gatesFile, "%d", &n);
    Gate* gate = calloc(n, sizeof(Gate));

    //define the all of Gates and its delay time and input number
    for(int i=0; i<n; i++){
        char name[5];
        int input, delay;
        fscanf(gatesFile, "%s %d %d", name, &input, &delay);
        strcpy(gate[i].name, name);
        gate[i].input = input;
        gate[i].delay = delay;
    }

    int input, output;
    int k = 0;
    Node* node = calloc(N, sizeof(Node));
    Edge* edge = calloc(N, sizeof(Edge));
    fscanf(circuitFile, "%d %d %d", &input, &output, &n);

    for(int i=0; i<input; i++){
        char name[5];
        fscanf(circuitFile, "%s", name);
        strcpy(node[k++].name, name);
    }
    for(int i=0; i<output; i++){
        char name[5];
        fscanf(circuitFile, "%s", name);
        strcpy(node[k++].name, name);
    }

    for(int i=0; i<n; i++){

    }

    fclose(gatesFile);
    fclose(circuitFile);
    return 0;
}

int findNode(Node* node, char* name){
    for(int i=0; i<N; i++){
        if(strcmp(node[i].name, name) == 0)
            return 1;
    }
    return 0;
}
