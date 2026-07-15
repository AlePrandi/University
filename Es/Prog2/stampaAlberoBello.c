#include <stdio.h>
#include <stdlib.h>

typedef struct tree TreeNode, *Tree;
struct tree{
    char c;
    Tree left;
    Tree right;
};

void printPadding(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

Tree creaNodo(char c){
    Tree root = (Tree)malloc(sizeof(TreeNode));
    root->c = c;
    root->left=root->right=NULL;
    return root;
}

void freeTree(Tree root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printTree(Tree root, int depth, int maxDepth){
    if(!root) return;
    printTree(root->left, depth+1, maxDepth);
    printTree(root->right, depth+1, maxDepth);
    if(!root->left && !root->right){
        printPadding(6/depth);
        printf("%c", root->c);
        printPadding(6/depth);
    }
    puts("");
    if(root->left || root->right){
        printPadding(4/depth);
        if(root->left) printf("\\");
        else printf(" ");
        printPadding(4/depth);
        if(root->right) printf("/");
        else printf(" ");
        printPadding(4/depth);
        
    }
}

int main(void){
    
    Tree root = creaNodo('a');
    root->left = creaNodo('b');
    root->right = creaNodo('c');
    root->left->left = creaNodo('d');
    root->left->right = creaNodo('e');
    root->right->left = creaNodo('f');
    root->right->right = creaNodo('g');

    printTree(root,1,3);

    freeTree(root);

    return 0;
}