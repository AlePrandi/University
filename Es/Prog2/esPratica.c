#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct list List, *ListPtr;
typedef struct tree Tree, *TreePtr;

struct tree{
    int data;
    TreePtr left;
    TreePtr right;
};


struct list{
    int data;
    ListPtr next;
};

void reverse (ListPtr *plst) {
    if(!plst || !(*plst)) return;
    ListPtr curr = *plst, inv = NULL;
    while(curr){
        ListPtr temp = curr;
        curr = curr->next;
        
        temp->next = inv;
        inv = temp;
    }
    *plst = inv;
    return;
}


ListPtr reverse_rec(ListPtr head){
    if(!head || !head->next) return head;
    
    ListPtr newHead = reverse_rec(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

void reverse (ListPtr *plst) {
    *plst = reverse_rec(*plst);
}


ListPtr divisorList(int num, int i){
    if(i > num) return NULL;
    if(num % i == 0){
        ListPtr node = malloc(sizeof(List));
        if(!node) return NULL;
        node->data = i;
        node->next = divisorList(num, i+1);
        return node;
    }
    return divisorList(num, i+1);
}

ListPtr invertiLista(ListPtr head){
    if(!head || !head->next) return head;
    ListPtr newHead = invertiLista(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void eliminaDuplicati(ListPtr *lPtr){
    //iterativo
    if(!lPtr || !(*lPtr)) return;
    ListPtr prec = NULL;
    ListPtr curr = *lPtr;
    while(curr && curr->next){
        if(curr->data == curr->next->data){
            if(prec){
                prec->next = curr->next;
            }else{
                *lPtr = curr->next;
            }
            ListPtr temp = curr;
            curr = curr->next;
            free(temp);
        }else{
            prec = curr;
            curr = curr->next;  
        }
    }
}

void eliminaDuplicatiGem(ListPtr *lPtr){
    //iterativo
    if(!lPtr || !(*lPtr)) return;
    ListPtr curr = *lPtr;
    while(curr && curr->next){
        if(curr->data == curr->next->data){
            ListPtr temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }else{
            curr = curr->next;
        }
    }
}

ListPtr fondiListe(ListPtr ls1, ListPtr ls2){
    if(!ls1 && !ls2) return NULL;
    if(!ls1) return ls2;
    if(!ls2) return ls1;
    ListPtr head = (ls1->data < ls2->data) ? ls1 : ls2;
    ListPtr tail = (ls1->data < ls2->data) ? ls1 : ls2;
    ListPtr temp1 = (ls1 == tail) ? ls1->next : ls1;
    ListPtr temp2 = (ls2 == tail) ? ls2->next : ls2;
    while(temp1 && temp2){
        if(temp1->data <= temp2->data){
            tail->next = temp1;
            tail = temp1;
            temp1 = temp1->next;
        }else if(temp1->data >= temp2->data){
            tail->next = temp2;
            tail = temp2;
            temp2 = temp2->next;
        }
    }
    if(!temp2){
        tail->next = temp1;
    }else{
        tail->next = temp2;
    }

    return head;
}

int haCiclo(ListPtr head){
    //slow = slow->next
    //fast = fast->next->next
    // if slow == fast return 1
    if(!head) return 0;
    ListPtr slow = head;
    ListPtr fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}

int maxCammino(TreePtr root){
    if(!root) return 0;
    int maxLeft = maxCammino(root->left);
    int maxRight = maxCammino(root->right);
    return root->data + ((maxLeft > maxRight) ? maxLeft : maxRight);
}

int isPalindrome(ListPtr ls){
    if(!ls) return 0;
    int n = 0;
    int *arr = NULL;
    ListPtr curr = ls;
    while(curr){
        arr = realloc(arr, (n+1) * sizeof(int));
        arr[n] = curr->data;
        curr = curr->next;
        n++;
    }
    for(size_t i = 0; i < n/2; i++){
        if(arr[i] != arr[n - i - 1]){
            free(arr);
            return 0;
        } 
    }
    free(arr);
    return 1;
}


int isValidBST(TreePtr root, int min, int max){
    if(!root) return 1;
    return (root->data >= min && root->data <= max) && isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
}

int wrapperIsValidBST(TreePtr root){
    return isValidBST(root, INT_MIN, INT_MAX);
}

int sommaLivelloK(TreePtr root, int k, int curr){
    if(!root) return 0;
    if(k == curr) return root->data;
    return sommaLivelloK(root->left, k, curr+1) + sommaLivelloK(root->right, k, curr+1);
}

int wrapperSommaLivelloK(TreePtr root, int k){
    return sommaLivelloK(root, k, 0);
}

ListPtr inserimentoOrdinato(ListPtr head, int val){
    ListPtr prec = NULL;
    ListPtr curr = head;
    while(curr && curr->data < val){
        prec = curr;
        curr = curr->next;
    }

    ListPtr node = (ListPtr)malloc(sizeof(List));
    node->data = val;

    if(prec){
        prec->next = node;
        node->next = curr;
    }else{
        node->next = head;
        head = node;
    }
    return head;
}

ListPtr eliminaNodo(ListPtr head, int target){
    if(!head) return NULL;
    ListPtr prec = NULL;
    ListPtr curr = head;
    while(curr){
        if(curr->data == target){
            if(prec){
                prec->next = curr->next;
            }else{
                head = curr->next;
            }
            ListPtr temp = curr;
            curr = curr->next;
            free(temp);
        }else{
            prec = curr;
            curr = curr->next;
        }
    }
    return head;
}

TreePtr inserisciBST(TreePtr root, int val){
    if(!root){
        TreePtr tree = (TreePtr)malloc(sizeof(Tree));
        if(!tree) return NULL;
        tree->data = val;
        tree->left = tree->right = NULL;
        return tree;
    }else{
        if(root->data < val) root->right = inserisciBST(root->right, val);
        else if(root->data > val) root->left = inserisciBST(root->left, val);
        return root;
    }
}

ListPtr eliminaDivisibili(ListPtr head, int k){
    if(!head) return NULL;
    ListPtr prec = NULL;
    ListPtr curr = head;
    while(curr){
        if(curr->data % k == 0){
            if(prec){
                prec->next = curr->next;
            }else{
                head = curr->next;
            }
            ListPtr temp = curr;
            curr = curr->next;
            free(temp);
        }else{
            prec = curr;
            curr = curr->next;
        }
    }

    return head;
}

ListPtr concatena(ListPtr l1, ListPtr l2) {
    if (!l1) return l2;
    l1->next = concatena(l1->next, l2);
    return l1;
}

ListPtr livelloK(TreePtr root, int k){
    if(!root) return NULL;
    if(k == 0){
        ListPtr node = (ListPtr)malloc(sizeof(List));
        node->data = root->data;
        node->next = NULL;
        return node;
    }else{
        return concatena(livelloK(root->left, k-1), livelloK(root->right, k -1));
    }
}

int main(void){

    return 0;
}