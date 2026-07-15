#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;

struct treeNode {
  IntTree left;
  int data;
  IntTree right;
};

int contaNodi(IntTree tree){
    if(!tree) return 0;
    return 1 + contaNodi(tree->left) + contaNodi(tree->right);
}

IntTree creaNodo(int val){
    IntTree nodo = malloc(sizeof(IntTreeNode));
    nodo->data = val;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}

IntTree creaAlbero(int *arr, int n){
    if(n == 0) return NULL;
    if(n == 1){
        IntTree root = creaNodo(arr[0]);
        return root;
    }
    if(n == 2){
        IntTree root = creaNodo(arr[0]);
        root->right = creaNodo(arr[1]);
        return root;
    }
    if(n == 3){
        IntTree root = creaNodo(arr[1]);
        root->left = creaNodo(arr[0]);
        root->right = creaNodo(arr[2]);
        return root;
    }

    IntTree root = creaNodo(arr[n/2]);
    root->left = creaAlbero(arr, n/2);
    root->right = creaAlbero((arr + n/2 +1), n/2);
    return root;
}

int popolaArray(IntTree tree, int *arr, int i, int n){
    if(!tree || i > n) return 0;
    arr[i] = tree->data;
    int j = popolaArray(tree->left, arr, i+1, n);
    int k = popolaArray(tree->right, arr, i+j+1, n);
    return 1 + j + k;
}

void ordinaArray(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < n;i++){
        printf("%d --> ", arr[i]);
    }
}

int compare(const void* a, const void *b){
    return (*(int *)a) - (*(int *)b);
}

/**
 * Dato un albero binario tree, costruire un albero di ricerca binario
 * contenente tutti e soli i valori presenti in tree, (con struttura arbitraria)
 *
 * ESEMPI:
 *
 * 1) per tree== NULL, restituisce NULL;
 * 2) dato l'albero:
 *       1
 *      / \
 *     2   3
 * restituisce (ad esempio) l'albero:
 *       2
 *      / \
 *     1   3
 *
 **/
IntTree buildbinarysearch(IntTree tree){
    if(tree == NULL) return NULL;
    int n = contaNodi(tree);
    int *arr = malloc(sizeof(int) * n);
    popolaArray(tree, arr, 0, n);
    ordinaArray(arr, n);
    //qsort(arr, n, sizeof(int), compare);
    IntTree newTree = creaAlbero(arr,n);
    free(arr);
    return newTree;
}



/** Stampa l'albero */
void printTree(IntTree root, int level) {
  for (int i = 0; i < level; i++)
    printf(i == level - 1 ? "|-" : "  ");

  printf("%d\n", root ? root->data : -1);
  if(root) {
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);

  }
}

void freeTree(IntTree root) {
  if (root == NULL)
    return;

  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

int main(void) {
  IntTree root = creaNodo(1);
  root->left = creaNodo(2);
  root->right = creaNodo(3);
  root->left->left = creaNodo(5);
  root->left->right = creaNodo(10);

  printTree(root, 0);

  IntTree res = buildbinarysearch(root);

  printf("\nRES:\n");
  printTree(res, 0);

  freeTree(root);
  freeTree(res);
  return 0;
}