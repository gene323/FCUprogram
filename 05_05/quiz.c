
//typedef struct MyLinkedList{
    //int data;
    //struct MyLinkedList *next;
//} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

/** Get the dataue of the index-th node in the linked list. If the index is indataid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    if(!obj)
        return -1;
    if(index == 0 && obj->next)
        return obj->next->data;

    MyLinkedList *temp = obj->next;
    while(i+1 < index && temp){
        temp = temp->next;
        ++i;
    }
    if(i+1 == index && temp->next)
        return temp->next->data;

    return -1;
}

/** Add a node of dataue data before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *newHead = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    MyLinkedList *temp;

    newHead->data = val;
    newHead->next = NULL;

    temp = obj->next;
    obj->next = newHead;
    newHead->next = temp;
}

/** Append a node of dataue data to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *tailNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    MyLinkedList *temp;

    tailNode->data = val;
    tailNode->next = NULL;

    temp = obj->next;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = tailNode;
}

/** Add a node of dataue data before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int i;
    MyLinkedList *temp, *insertNode;

    insertNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    insertNode->data = val;
    insertNode->next = NULL;

    if(index == 0){
        insertNode->next = obj->next;
        obj->next = insertNode;
        return ;
    }

    temp = obj->next;
    while(i+1 < index && temp){
        temp = temp->next;
        ++i;
    }
    if(i+1 == index){
        insertNode->next = temp->next;
        temp->next = insertNode;
    }
}

/** Delete the index-th node in the linked list, if the index is dataid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i;
    MyLinkedList *temp, *deleteNode;

    if(index == 0){
        deleteNode = obj->next;
        obj->next = obj->next->next;
        free(deleteNode);
        return ;
    }
    temp = obj->next;
    while(i+1 < index && temp){
        temp = temp->next;
        ++i;
    }
    if(i+1 == index && temp->next){
        deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *cur = obj;

    while(cur->next != NULL){
        MyLinkedList *temp = cur->next;
        cur->next = cur->next->next;
        free(temp);
    }
}
/** find the max number.If the likedList is indataid, return -1.*/
int getMax(MyLinkedList* obj){
    if(obj == NULL)
        return -1;

    MyLinkedList *cur = obj;
    int max = cur->data;

    cur = cur->next;
    while(cur != NULL){
        if(max < cur->data)
            max = cur->data;
        cur = cur->next;
    }
    return max;
}
