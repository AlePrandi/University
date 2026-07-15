#include <stdio.h>
#include <stdlib.h>

typedef struct tree TreeNode, *Tree;

struct tree{
    int data;
    Tree left;
    Tree right;
};

typedef struct list ListNode, *List;

struct list{
    int data;
    List next;
};

Tree creaNodoTree(int val){
    Tree node = (Tree)malloc(sizeof(TreeNode));
    node->data = val;
    node->left=node->right=NULL;
    return node;
}

List inserisciOrdinato(List head, int val){
    List prec = NULL;
    List curr = head;
    while(curr && curr->data < val){
        prec = curr;
        curr = curr->next;
    }

    List newNode = (List)malloc(sizeof(ListNode));
    newNode->data = val;
    newNode->next = NULL;

    if(prec){
        prec->next = newNode;
        newNode->next = curr;
    }else{
        newNode->next = head;
        head = newNode;
    }

    return head;
}


Tree insertBST(Tree root, int val){
    if(!root){
        Tree root = creaNodoTree(val);
        return root;
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }else if(val > root->data){
        root->right = insertBST(root->right, val);
    }
    return root;
}

Tree createBST(List l){
    if(!l) return NULL;
    List curr = l;
    Tree root = NULL;
    while(curr){
        root = insertBST(root, curr->data);
        curr = curr->next;
    }
    return root;
}

List Tree2List(Tree root){
    if(!root) return NULL;
    List l = inserisciOrdinato(l, root->data);
    l = Tree2List(root->left);
    l = Tree2List(root->right);

    return l;
}

List BalancedTree2List(Tree root){
    if(!root) return NULL;
    List left = BalancedTree2List(root->left);

    List currNode = (List)malloc(sizeof(ListNode));
    currNode->data = root->data;
    currNode->next = NULL;

    List right = BalancedTree2List(root->right);

    List head = NULL;
    List tail = NULL;

    if(left){
        List tail = left;
        while(tail){
            tail = tail->next;
        }
        tail->next = currNode;
    }else{
        head = currNode;
    }
    currNode->next = right;
    return head;
}