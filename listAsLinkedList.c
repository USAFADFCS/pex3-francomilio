/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Implementation of Linked List Library
 * Purpose: List ADT as linked list
 * ===========================================================
 */
#include "listAsLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
LinkedList* createLinkedList(){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->numberOfElements = 0;
    list->head = NULL;
    list->tail = NULL;
    list->maxSize = 0;
    return list;
}

void deleteLinkedList(LinkedList* list){
    Node* tempNode = list->head;
    while(tempNode != NULL){
        Node* next = tempNode->next;
        free(tempNode);
        tempNode = next;
        list->numberOfElements--;
    }
    free(list);
}

int lengthOfLinkedList(LinkedList* list){
    return(list->numberOfElements);
}

void appendElementLinkedList(LinkedList* list, double element){
    if(list->numberOfElements == 0){
        list->head = malloc(sizeof(Node));
        list->head->data = element;
        list->tail = list->head;
    }
    else{
        Node* tailTemp = list->tail;
        list->tail->next = malloc(sizeof(Node));
        list->tail->next->data = element;
        list->tail->next->prev = list->tail;
        list->tail = tailTemp->next;
    }
    list->tail->next = NULL;
    list->head->prev = NULL;
    list->numberOfElements++;
}


void insertElementLinkedList(LinkedList* list, int position, double element){
    if(list->numberOfElements == 0 || position >= list->numberOfElements){
        appendElementLinkedList(list,element);
    }
    else{
        Node* newNode = malloc(sizeof(Node));
        newNode->data = element;
        Node* currentNode = list->head;
        
        for(int currentPos = 0; currentPos < position; currentPos++){
            currentNode = currentNode->next;
        }
        Node* previousNode = currentNode->prev;

        newNode->next = currentNode;
        newNode->prev = previousNode;
        currentNode->prev = newNode;
        if(previousNode!=NULL){
            previousNode->next = newNode;
        }
        else{
            list->head=newNode;
        }
        list->numberOfElements++;
    }
}

void printLinkedList(LinkedList* list){
    Node* tempNode = list->head;
    for(int i = 0; i<list->numberOfElements; i++){
        printf("%ld\n",tempNode->data);
        tempNode = tempNode->next;
    }
}

double getElementLinkedList(LinkedList* list, int position){
    Node* currentNode = list->head;
    for(int currentPos = 0; currentPos < position; currentPos++){
        currentNode = currentNode->next;
    }
    return(currentNode->data);
}

void changeElementLinkedList(LinkedList* list, int position, double newElement){
    Node* currentNode = list->head;
    for(int currentPos = 0; currentPos < position; currentPos++){
        currentNode = currentNode->next;
    }
    currentNode->data = newElement;
}

int findElementLinkedList(LinkedList* list, double element){
    Node* currentNode = list->head;
    for(int i = 0; i< list->numberOfElements; i++){
        if(currentNode->data == element){
        return(i);
        }
        currentNode =currentNode->next;
    }
    return(-1);
}

void deleteElementLinkedList(LinkedList* list, int position){
    Node* currentNode = list->head;

    for(int currentPos = 0; currentPos < position; currentPos++){
        currentNode = currentNode->next;
    }

    if(currentNode->prev != NULL){
        currentNode->prev->next = currentNode->next;
    }
    else{
        list->head = currentNode->next;
    }
    if(currentNode->next != NULL){
        currentNode->next->prev = currentNode->prev;
    }
    else{
        list->tail=currentNode->prev;
    }
    list->numberOfElements--;
    free(currentNode);
}


// to free, free nodes with for loop and free header with one free, ONLY FREE THINGS U MALLOC