#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    IntSortedSetADT set = malloc(sizeof(IntSortedSetADT));

    set->first = NULL;
    set->last = NULL;

    set->size = 0;

    return set;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    if(!ssptr || !(*ssptr)) return false;
    while((*ssptr)->first){
        ListNodePtr temp = (*ssptr)->first;
        (*ssptr)->first = (*ssptr)->first->next;
        free(temp);
        temp = NULL;
    }

    free(*ssptr);
    *ssptr = NULL;
    return true;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if(!ss) return false;
    ListNodePtr NewNode = (ListNodePtr)malloc(sizeof(ListNode));
    if (!NewNode) return false;

    NewNode->elem = elem;
    NewNode->next = NULL;

    if(!ss->first){
        ss->first = NewNode;
        ss->last = NewNode;
    }else{
        ListNodePtr curr = ss->first, prev = NULL;
        while(curr && curr->elem < elem){
            prev = curr;
            curr = curr->next;
        }

        if(curr && curr->elem == elem){
            free(NewNode);
            NewNode = NULL;
            return false;
        } 

        if(!prev){
            NewNode->next = ss->first;
            ss->first = NewNode;
            if(!ss->last) ss->last = NewNode;
        }else{
            prev->next = NewNode;
            NewNode->next = curr;
            if(curr == NULL) ss->last = NewNode;
        }
    }
    ss->size++;
    return true;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if(!ss || !ss->first) return false;
    ListNodePtr curr = ss->first, prev = NULL;
    while(curr){
        if(curr && curr->elem == elem){
            if(!prev)ss->first = curr->next;
            else prev->next = curr->next;  

            if(!curr->next) ss->last = prev;
            free(curr);
            curr = NULL; 
            ss->size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if(!ss) return 0;

    ListNodePtr curr = ss->first;
    while(curr){
        if(curr->elem == elem){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    return (ss) ? ((!ss->first) ? 1 : 0) : 0;
}

int sset_size(const IntSortedSetADT ss) {
    return (ss) ? ss->size : -1;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if(!ss || !ss->first) return 0;

    int randPos = rand() % ss->size;
    ListNodePtr curr = ss->first;
    int count = 0;
    while(curr){
        if(count == randPos){
            *ptr = curr->elem;
            sset_remove(ss, curr->elem);
            return 1;
        }
        count++;
        curr = curr->next;
    }

    return 0;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2) return 0;
    if(s1->size != s2->size) return 0;
    ListNodePtr temp1 = s1->first;
    ListNodePtr temp2 = s2->first;
    while(temp1){
        if(temp1->elem != temp2->elem) return 0;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2) return 0;
    if(s1->size > s2->size) return 0;
    ListNodePtr temp1 = s1->first;
    ListNodePtr temp2 = s2->first;
    while(temp1 && temp2){
        if(temp1->elem == temp2->elem){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else{
            if(temp1->elem > temp2->elem) temp2 = temp2->next;
            else return 0;
        }
    }

    return temp1 == NULL;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2) return 0;
    if(s1->size >= s2->size) return 0;
    ListNodePtr temp1 = s1->first;
    ListNodePtr temp2 = s2->first;
    while(temp1 && temp2){
        if(temp1->elem == temp2->elem){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else{
            if(temp1->elem > temp2->elem) temp2 = temp2->next;
            else return 0;
        }
    }
    
    return temp1 == NULL;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2) return NULL;

    IntSortedSetADT su = mkSSet();
    ListNodePtr temp1 = (s1) ? s1->first : NULL;
    ListNodePtr temp2 = (s2) ? s2->first: NULL;

    while(temp1 && temp2){
        if(temp1->elem == temp2->elem){
            sset_add(su, temp1->elem);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } 
        else{
            if(temp1->elem < temp2->elem){
                sset_add(su, temp1->elem);
                temp1 = temp1->next;
            } 
            else{
                sset_add(su, temp2->elem);
                temp2 = temp2->next;
            } 
        }
        
    }

    if(!temp1){
        while(temp2){
            sset_add(su, temp2->elem);
            temp2 = temp2->next;
        }
    }

    if(!temp2){
        while(temp1){
            sset_add(su, temp1->elem);
            temp1 = temp1->next;
        }
    }

    return su; 
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2) return NULL;

    IntSortedSetADT su = mkSSet();
    ListNodePtr temp1 = (s1) ? s1->first : NULL;
    ListNodePtr temp2 = (s2) ? s2->first: NULL;

    while(temp1 && temp2){
        if(temp1->elem == temp2->elem){
            sset_add(su, temp1->elem);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } 
        else{
            if(temp1->elem < temp2->elem){
                temp1 = temp1->next;
            } 
            else{
                temp2 = temp2->next;
            } 
        }
        
    }

    return su; 
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(!s1 || !s2) return NULL;

    IntSortedSetADT su = mkSSet();
    ListNodePtr temp1 = (s1) ? s1->first : NULL;
    ListNodePtr temp2 = (s2) ? s2->first: NULL;

    while(temp1 && temp2){
        if(temp1->elem == temp2->elem){
            temp1 = temp1->next;
            temp2 = temp2->next;
        } 
        else{
            if(temp1->elem < temp2->elem){
                sset_add(su,temp1->elem);
                temp1 = temp1->next;
            } 
            else{
                temp2 = temp2->next;
            } 
        }
        
    }

    if(!temp2){
        while(temp1){
            sset_add(su, temp1->elem);
            temp1 = temp1->next;
        }
    }

    return su;    
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if(!ss || !ss->first) return 0;
    *ptr = ss->first->elem;
    return 1;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if(!ss || !ss->first) return 0;
    *ptr = ss->last->elem;
    return 1;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    if(!ss || !ss->first) return 0;
    *ptr = ss->first->elem;
    return sset_remove(ss, ss->first->elem);
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    if(!ss || !ss->first) return 0;
    *ptr = ss->last->elem;
    return sset_remove(ss, ss->last->elem);       
}
