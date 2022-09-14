/**
typedef struct {
    int data;
    struct Node * next;
} Node;

typedef struct {
    Node *front; //開頭，刪除的地方
    Node *rear;  //結尾，加入的地方
} Queue;
**/

/** initialize your data structure here. */
Queue* Create() {
    Queue *obj = (Queue*)malloc(sizeof(Queue));
    obj->front = NULL;
    obj->rear  = NULL;
    return obj;
}

/** Insert an element into the queue. */
void Enqueue(Queue* obj, int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if(obj->front == NULL){
        obj->front = temp;
        obj->rear = temp;
        return ;
    }
    obj->rear->next = temp;
    obj->rear = obj->rear->next;
}

/** Delete an element from the queue. If is empty do noting. */
void Dequeue(Queue* obj) {
    if(obj->front == NULL)
        return ;

    Node *temp = obj->front;
    obj->front = obj->front->next;
    free(temp);
}

/** Get the front item from the queue. If is empty return -1.*/
int Front(Queue* obj) {
    if(obj->front == NULL)
        return -1;
    return obj->front->data;
}

/** Get the last item from the queue. If is empty return -1.*/
int Rear(Queue* obj) {
    if(obj->front == NULL)
        return -1;
    return obj->rear->data;
}

/** find the index of min element in the queue, if is empty return -1.*/
/** 從front開始，index為0。向後遞增*/
int GetIndexOfMin(Queue* obj){
    if(obj->front == NULL)
        return -1;

    int min = 10000;
    Node *temp = obj->front;
    while(temp){
        if(min > temp->data)
            min = temp->data;
        temp = temp->next;
    }

    temp = obj->front;
    int i = 0;
    while(temp){
        if(min == temp->data)
            return i;
        temp = temp->next;
        ++i;
    }
}
/** if Queue is empty print "NULL". */
void QueuePrint(Queue* obj){
    if(obj->front == NULL){
        printf("NULL\n");
        return ;
    }
    Node *temp = obj->front;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

