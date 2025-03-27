#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List* createList() {
    List* L = (List*)malloc(sizeof(List));
    if (!L) return NULL;

    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;

    return L;// Esta ya me funciono
}

void * firstList(List * list) {
    list->current = list->head;
    if (list->current) return list -> current -> data;

    else return NULL;// Esta ya me funciono
}

void * nextList(List * list) {
    if (list->current!=NULL)
    list->current = list->current->next;
    if (list->current!=NULL)
    return list->current->data;


    return NULL;
}

void* lastList(List* list) {
    if (!list || !list->tail) return NULL;

    list->current = list->tail;
    return list->current->data;// esta ya me funciono
}

void * prevList(List * list) {
    if (list->current!=NULL)
    list->current = list->current->prev;
    if (list->current!=NULL)
    return list->current->data;

    else return NULL; //Esta ya me funciono
}

void pushFront(List * list, void * data) {
    if (!list) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }

    list->head = newNode;         
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    if(!list) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;

    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = List -> current;

    if(list -> current){

        newNode -> next = list -> current -> next;
        list -> current -> next = newNode;     
    }

    else{
        list->head = newNode;
    }

}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}