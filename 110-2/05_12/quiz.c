/**
typedef struct {
	int data;
	struct Node * next;
} Node;

typedef struct {
	Node*topPtr;
} Stack;
**/

/** initialize your data structure here. */
Stack* Create() {
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->topPtr = NULL;
    return st;
}
/** pushes the element x onto the stack.*/
void Push(Stack* obj, int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = obj->topPtr;
    obj->topPtr = temp;
}
/** removes the element on the top of the stack, if empty do nothing. */
void Pop(Stack* obj) {
    if(obj->topPtr == NULL)
        return ;

    Node *temp = obj->topPtr;
    obj->topPtr = obj->topPtr->next;
    free(temp);
}
/** gets the top element of the stack, if is empty return 0. */
int Top(Stack* obj) {
    if(obj->topPtr == NULL)
        return 0;
    return obj->topPtr->data;
}
/** retrieves the minimum element in the stack, if is empty return -1.*/
int GetMin(Stack* obj) {
    if(obj->topPtr == NULL)
        return -1;

    Node *temp = obj->topPtr;
    int min = 10000;
    while(temp != NULL){
        if(min > temp->data)
            min = temp->data;
        temp = temp->next;
    }
    return min;
}
/** find the index of max element in the stack, if is empty return -1.*/
/** The index at the bottom of the stack is 0.*/
int GetIndexOfMax(Stack* obj){
    if(obj->topPtr == NULL)
        return -1;

    int index = -1;
    int max = -1;
    Node *temp = obj->topPtr;
    while(temp != NULL){
        if(max < temp->data)
            max = temp->data;
        ++index;
        temp = temp->next;
    }

    temp = obj->topPtr;
    while(temp != NULL){
        if(temp->data == max)
            return index;
        --index;
        temp = temp->next;
    }
}
/** if stack is empty print "NULL". */
void StackPrint(Stack* obj){
    if(obj->topPtr == NULL){
        printf("NULL\n");
        return ;
    }

    Node *temp = obj->topPtr;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

