/*
typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;
*/
void Search(treeNode* root, int val){
    int level = 1;
    treeNode *temp = root;
    while(root != NULL && root->data != val){
        if(root->data < val)
            root = root->right;
        else if(root->data > val)
            root = root->left;
        ++level;
    }
    printf("level=%d\n", level);
}

treeNode* Insert(treeNode* root, int val){
    treeNode *temp = (treeNode*)malloc(sizeof(treeNode));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = val;

    if(root == NULL)
        root = temp;
    else if(root->data < val){
        root->right = Insert(root->right, val);
    }
    else{
        root->left = Insert(root->left, val);
    }
    return root;
}

treeNode* findMin(treeNode *root){
    treeNode *temp = root;

    while(temp && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

treeNode* Delete(treeNode* root, int key){
    if(root == NULL)
        return root;

    if(root->data < key)
        root->right = Delete(root->right, key);

    else if(root->data > key)
        root->left = Delete(root->left, key);

    else{
        if(root->left == NULL){
            treeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            treeNode *temp = root->left;
            free(root);
            return temp;
        }

        treeNode *temp = findMin(root->right);

        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}


void Inorder(treeNode* root){
    if(root != NULL){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

