#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_QUEUE_SIZE 10

typedef struct Customer{
    char name[20];
    int arrTime;//the time that the customer arrived
    int serTime;//the time that the customer is serviced
    struct Customer *next;
}Customer;

typedef struct{
    int status;
    int count;
    int leftTime;
    Customer *front;
    Customer *rear;
}TellerQueue;

TellerQueue teller[MAX_QUEUE_SIZE];
int globalTime = 0;
int totalTeller;

int chooseTeller(){
    int id = 0;
    int min = INT_MAX;
    for(int i=0; i<totalTeller; i++){
        if(min > teller[i].count && teller[i].status == 2){
            id = i;
            min = teller[i].count;
        }
    }
    return id;
}

void push(char *name, int arrTime, int serTime){
    int id = chooseTeller();
    Customer *q = (Customer*)malloc(sizeof(Customer));

    strcpy(q->name, name);
    q->arrTime = arrTime;
    q->serTime = serTime;
    q->next = NULL;
    if(teller[id].front == NULL){
        teller[id].front = q;
        teller[id].rear = q;
    }
    else{
        teller[id].rear->next = q;
        teller[id].rear = q;
    }
    if(teller[id].count == 0){
        teller[id].leftTime = serTime;
    }
    teller[id].count++;
}

void pop(int id){
    if(teller[id].front != NULL){
        Customer *q = teller[id].front;
        teller[id].front= teller[id].front->next;
        free(q);
        teller[id].count--;
    }
}

void requeue(int id){
    if(teller[id].front == NULL)
        return ;
    Customer *q = teller[id].front->next;
    teller[id].front->next = NULL;
    while(q != NULL){
        Customer *tmp = q;
        push(q->name, q->arrTime, q->serTime);
        q = q->next;
        free(tmp);
    }
}

//print all information to debug
void show(char *action){
    printf("%4d  %-15s", globalTime, action);
    for(int i=0; i<totalTeller; i++){
        Customer *q = teller[i].front;
        printf("%d ", teller[i].status);
        while(q != NULL){
            printf("%s ", q->name);
            q = q->next;
        }
        printf("                         ");
    }
    puts("");
}

int main(){
    char filename[20];
    printf("Input file name: ");
    scanf("%s", filename);

    FILE *inputFile = fopen(filename, "r");
    FILE *outputFile = fopen("output.txt", "w");
    char name[20];
    int arrTime;
    int serTime;

    fscanf(inputFile, "%d", &totalTeller);
    //initialize the teller queue
    for(int i=0; i<totalTeller; i++){
        teller[i].status = 2;
        teller[i].count = 0;
        teller[i].leftTime = 0;
        teller[i].front = NULL;
        teller[i].rear = NULL;
    }

    while(fscanf(inputFile, "%s %d %d", name, &arrTime, &serTime) != EOF){
        while(globalTime < arrTime){
            globalTime++;
            for(int i=0; i<totalTeller; i++){
                //if there has customer in queue 
                if(teller[i].count && teller[i].leftTime && teller[i].front != NULL){
                    teller[i].leftTime--;
                }
                if(teller[i].count && teller[i].leftTime == 0 && teller[i].front != NULL){
                    fprintf(outputFile, "%s %d %d\n", teller[i].front->name, globalTime, i);
                    /*debug
                    char action[30];
                    sprintf(action, "%s quit", teller[i].front->name);
                    */
                    pop(i);
                    /*
                    show(action);
                    */
                    if(teller[i].front != NULL)
                        teller[i].leftTime = teller[i].front->serTime;
                }
            }
        }
        if(strcmp(name, "#") == 0){
            teller[serTime].status = 1;
            /*debug
            char action[30];
            sprintf(action, "close %d", serTime);
            show(action);
            */
            requeue(serTime);
        }
        else if(strcmp(name, "@") == 0){
            teller[serTime].status = 2;
            /*debug
            char action[30];
            sprintf(action, "open %d", serTime);
            show(action);
            */
        }
        else{
            push(name, arrTime, serTime);
            /*debug
            char action[30];
            sprintf(action, "%s in queue", name);
            show(action);
            */
        }
    }

    //the rest of queue
    while(globalTime){
        int flag = 1;
        globalTime++;
        for(int i=0; i<totalTeller; i++){
            if(teller[i].count && teller[i].leftTime && teller[i].front != NULL){
                flag = 0;
                teller[i].leftTime--;
            }
            if(teller[i].count && teller[i].leftTime == 0 && teller[i].front != NULL){
                flag = 0;
                fprintf(outputFile, "%s %d %d\n", teller[i].front->name, globalTime, i);
                /*debug
                char action[30];
                sprintf(action, "%s quit", teller[i].front->name);
                */
                pop(i);
                /*
                show(action);
                */
                if(teller[i].count && teller[i].front != NULL)
                    teller[i].leftTime = teller[i].front->serTime;
            }
        }
        if(flag)
            break;
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
