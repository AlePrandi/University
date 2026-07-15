#include <stdio.h>
#include <stdlib.h>

typedef struct list ListNode, *List;
typedef struct tree TreeNode, *Tree;

struct list{
    int data;
    List next;
};

struct tree{
    int data;
    Tree left;
    Tree right;
};

List ordinaDec(List head, int val){
    List prec = NULL;
    List curr = head;
    while(curr && curr->data > val){
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


/**
 * @brief funzione che dato un'array lo inserisce in una lista in ordine Dec
 */
List arr2listDec(int arr[], int n){
    List head = NULL;
    for(int i = 0; i < n; i++){
        head = ordinaDec(head, arr[i]);
    }
    return head;
}

int compare(const void *a, const void *b){
    return (*(int *)a) - (*(int *)b);
}

/**
 * @brief funzione che data una lista ritorna un'array ordinato
 */

int *list2arr(List l){
    if(!l) return;
    List scorri = l;
    int dim = 0;
    while(scorri){
        dim++;
        scorri = scorri->next;
    }

    int arr[] = (int *)malloc(sizeof(int) * dim);
    List curr = l;
    for(int i = 0; i < dim; i++){
        arr[i] = curr->data;
        curr = curr->next;
    }

    qsort(arr, sizeof(int), dim, compare);

    return arr;
}

Tree creaRamo(int val){
    Tree root = (Tree)malloc(sizeof(TreeNode));
    root->data = val;
    root->left = root->right = NULL;
    return NULL;
}

/**
 * @brief dato un'array ordinato crea un BST bilanciato
 */
Tree arr2tree(int arr[], int n){
    Tree root = NULL;
    switch(n)
    {
    case 0:
        break;

    case 1:
        root = creaRamo(arr[0]);
        break;

    case 2:
        root = creaRamo(arr[1]);
        root->left = creaRamo(arr[0]);
        break;

    case 3:
        root = creaRamo(arr[1]);
        root->left = creaRamo(arr[0]);
        root->right = creaRamo(arr[2]);
        break;
    
    default:
        root = creaRamo(arr[n/2]);
        root->left = arr2tree(arr, n/2);
        root->right = arr2tree(arr + (n/2) + 1, n/2);
        break;
    }

    return root;
}

Tree arr2treeSeba(int arr[], int len){
    if(len == 0) return NULL;

    int mid = len/2;

    Tree root = creaRamo(arr[mid]);
    root->left = arr2treeSeba(arr, mid);
    if(len != 2) root->right = arr2treeSeba(arr+mid+1, mid);
    return root;
}

int contanodi(Tree root){
    if(!root) return 0;
    return 1 + contanodi(root->left) + contanodi(root->right);
}

// la i tiene conto del prossimo elemento in cui vado a scrivere
int popolaArray(Tree root, int arr[], int i){
    if(!root) return i;
    i = popolaArray(root->left, arr, i);
    arr[i] = root->data;
    i = popolaArray(root->right, arr, i+1);
    return i;
}

/**
 * @brief dato un BST inserire i valori in modo ordinato in un array
 */
int *tree2arr(Tree root){
    int dim = contanodi(root);
    int arr[] = (int *)malloc(sizeof(int)*dim);
    popolaArray(root, arr, 0);

    return arr;
}