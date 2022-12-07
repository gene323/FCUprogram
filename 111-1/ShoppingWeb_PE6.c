#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define DELIMITER "------------------------------"

typedef struct Heap{
    int price;
    char name[50];
}Heap;

typedef struct Tree{
    char productName[50];
    Heap heap[16];
    int heapSize;
    struct Tree* left;
    struct Tree* right;
}Tree;

Tree* insert(Tree*, char*, char*, int);
Tree* delete(Tree*, char*);
Tree* minValueNode(Tree*);
Tree* buy(FILE*, Tree*, char*);
void lowerString(char*);
void initializeHeap(Tree*);
void minHeapify(Tree*, int);
void sort(FILE* file, Tree* tree);
void report(FILE* file);
void search(FILE*, Tree*, char*);
bool isHeapEmpty(Tree*, char*);
int countTreeHeight(Tree*);
int countTreeNode(Tree*);
int parent(int);
int left(int);
int right(int);

int insertSum = 0, searchSum = 0, buySum = 0, nodeSum = 0, height = 0;
int buyFailSum = 0, searchFailSum = 0;

int main(int argc, char** argv){

    FILE* searchTable = fopen("SearchTable.txt", "w");
    FILE* buyTable = fopen("BuyTable.txt", "w");
    FILE* sortTable = fopen("SortTable.txt", "w");
    FILE* logTable = fopen("LogTable.txt", "w");
    FILE* input = fopen(argv[1], "r");

    Tree* tree = NULL;

    char str[50];
    while(fscanf(input, "%s", str) != EOF){
        char productName[50] = "", name[50] = "";
        int price;

        if(strcmp(str, "insert") == 0){
            insertSum++;
            fscanf(input, "%s%s%d", productName, name, &price);
            lowerString(productName);
            tree = insert(tree, productName, name, price);
        }
        else if(strcmp(str, "buy") == 0){
            buySum++;
            fscanf(input, "%s", productName);
            lowerString(productName);
            tree = buy(buyTable, tree, productName);
            if(isHeapEmpty(tree, productName)){
                tree = delete(tree, productName);
            }
        }
        else if(strcmp(str, "search") == 0){
            searchSum++;
            fscanf(input, "%s", productName);
            lowerString(productName);
            search(searchTable, tree, productName);
        }
        else if(strcmp(str, "sort") == 0){
            sort(sortTable, tree);
            fprintf(sortTable, "%s\n", DELIMITER);
        }
        else if(strcmp(str, "report") == 0){
            nodeSum = countTreeNode(tree);
            height = countTreeHeight(tree);
            report(logTable);
        }
    }


    fclose(searchTable);
    fclose(buyTable);
    fclose(sortTable);
    fclose(logTable);
    fclose(input);
    return 0;
}

void search(FILE* file, Tree* tree, char key[]){
    if(!tree){
        fprintf(file, "%s doesn't exist!\n", key);
        fprintf(file, "%s\n", DELIMITER);
        searchFailSum++;
        return ;
    }
    if(strcmp(tree->productName, key) == 0){
        fprintf(file, "%s\n", key);
        for(int i=0; i<tree->heapSize; i++){
            fprintf(file, "%s %d\n",tree->heap[i].name, tree->heap[i].price);
        }
        fprintf(file, "%s\n", DELIMITER);
        return ;
    }
    if(strcmp(tree->productName, key) < 0){
        return search(file, tree->right, key);
    }
    return search(file, tree->left, key);
}

bool isHeapEmpty(Tree* tree, char key[]){
    if(!tree)
        return false;
    if(strcmp(tree->productName, key) == 0 && tree->heapSize == 0){
        return true;
    }
    if(strcmp(tree->productName, key) < 0){
        return isHeapEmpty(tree->right, key);
    }
    return isHeapEmpty(tree->left, key);
}

Tree* insert(Tree* tree, char productName[], char name[], int price){
    if(!tree){
        Tree* res;
        res = calloc(sizeof(Tree), 1);
        strcpy(res->productName, productName);
        strcpy(res->heap[0].name, name);
        res->heap[0].price = price;
        res->heapSize = 1;
        res->left = res->right = NULL;
        return res;
    }
    if(strcmp(tree->productName, productName) == 0){
        strcpy(tree->heap[tree->heapSize].name, name);
        tree->heap[tree->heapSize].price = price;
        int i = tree->heapSize;
        while(i != 0 && tree->heap[parent(i)].price > tree->heap[i].price){
            Heap tmp = tree->heap[i];
            tree->heap[i] = tree->heap[parent(i)];
            tree->heap[parent(i)] = tmp;
            i = parent(i);
        }
        tree->heapSize++;
        return tree;
    }
    else if(strcmp(tree->productName, productName) < 0){
        tree->right = insert(tree->right, productName, name, price);
    }
    else{
        tree->left = insert(tree->left, productName, name, price);
    }
    return tree;
}

Tree* delete(Tree* tree, char key[]){
    if(!tree)
        return tree;
    if(strcmp(tree->productName, key) > 0){
        tree->left = delete(tree->left, key);
    }
    else if(strcmp(tree->productName, key) < 0){
        tree->right = delete(tree->right, key);
    }
    else{
        if(tree->left == NULL){
            Tree* res = tree->right;
            free(tree);
            return res;
        }
        else if(tree->right == NULL){
            Tree* res = tree->left;
            free(tree);
            return res;
        }
        Tree* res = minValueNode(tree->right);
        strcpy(tree->productName, res->productName);
        tree->heapSize = res->heapSize;
        for(int i=0; i<tree->heapSize; i++){
            tree->heap[i] = res->heap[i];
        }
        tree->right = delete(tree->right, res->productName);
    }
    return tree;
}

Tree* minValueNode(Tree* tree){
    Tree* tmp = tree;
    while(tmp && tmp->left != NULL)
        tmp = tmp->left;
    return tmp;
}

Tree* buy(FILE* file, Tree* tree, char key[]){
    if(!tree){
        fprintf(file, "%s doesn't exist!\n", key);
        buyFailSum++;
        return tree;
    }
    if(strcmp(tree->productName, key) == 0){
        fprintf(file, "%s %s %d\n", tree->productName, tree->heap[0].name, tree->heap[0].price);
        if(tree->heapSize == 1){
            tree->heapSize--;
            return tree;
        }
        tree->heap[0] = tree->heap[--(tree->heapSize)];
        minHeapify(tree, 0);
    }
    else if(strcmp(tree->productName, key) < 0){
        tree->right = buy(file, tree->right, key);
    }
    else if(strcmp(tree->productName, key) > 0){
        tree->left = buy(file, tree->left, key);
    }
    return tree;
}


void lowerString(char* str){
    for(int i=0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
}

void minHeapify(Tree* tree, int i){
    int l = left(i);
    int r = right(i);
    int min = i;
    if(l < tree->heapSize && tree->heap[l].price < tree->heap[i].price){
        min = l;
    }
    if(r < tree->heapSize && tree->heap[r].price < tree->heap[min].price){
        min = r;
    }
    if(min != i){
        Heap tmp = tree->heap[i];
        tree->heap[i] = tree->heap[min];
        tree->heap[min]= tmp;
        minHeapify(tree, min);
    }
}

void sort(FILE* file, Tree* tree){
    if(tree == NULL)
        return ;

    sort(file, tree->left);
    fprintf(file, "%s\n", tree->productName);
    sort(file, tree->right);
}

void report(FILE* file){
    fprintf(file, "insert %d\n", insertSum);
    fprintf(file, "search %d %d\n", searchSum, searchFailSum);
    fprintf(file, "buy %d %d\n", buySum, buyFailSum);
    fprintf(file, "node_num %d\n", nodeSum);
    fprintf(file, "height %d", height);
}

int countTreeHeight(Tree* tree){
    if(!tree)
        return 0;
    int leftHeight = countTreeHeight(tree->left);
    int rightHeight = countTreeHeight(tree->right);
    return ((leftHeight > rightHeight)? leftHeight: rightHeight) + 1;
}

int countTreeNode(Tree* tree){
    if(!tree)
        return 0;
    return 1 + countTreeNode(tree->left) + countTreeNode(tree->right);
}

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return (2*i)+1;
}

int right(int i){
    return (2*i)+2;
}
