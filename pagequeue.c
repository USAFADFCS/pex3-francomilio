/** pagequeue.c
 * ===========================================================
 * Name: _______________________, __ ___ 2026
 * Section: CS483 / ____
 * Project: PEX3 - Page Replacement Simulator
 * Purpose: Implementation of the PageQueue ADT — a doubly-linked
 *          list for LRU page replacement.
 *          Head = LRU (eviction end), Tail = MRU end.
 * =========================================================== */
#include <stdio.h>
#include <stdlib.h>
#include "pagequeue.h"

/**
 * @brief Create and initialize a page queue with a given capacity
 */
PageQueue *pqInit(unsigned int maxSize) {
    // TODO: malloc a PageQueue, set head and tail to NULL,
    // size to 0, maxSize to maxSize, and return the pointer
    PageQueue* pgQ = malloc(sizeof(PageQueue));
    pgQ->size = 0;
    pgQ->head = NULL;
    pgQ->tail = NULL;
    pgQ->maxSize = maxSize;
    return(pgQ);
}

/**
 * @brief Access a page in the queue (simulates a memory reference)
 */
long pqAccess(PageQueue *pq, unsigned long pageNum) {
    
    // TODO: Search the queue for pageNum (suggest searching tail->head
    //       so you naturally count depth from the MRU end).
    //
    // HIT path (page found at depth d):
    //   - Remove the node from its current position and re-insert
    //     it at the tail (most recently used).
    //   - Return d.
    //
    // MISS path (page not found):
    //   - Allocate a new node for pageNum and insert it at the tail.
    //   - If size now exceeds maxSize, evict the head node (free it).
    //   - Return -1.
    PqNode* currNode = pq->tail;
    for(int i = 0; i<pq->size; i++){
        
        if(currNode != NULL && (currNode->pageNum) == pageNum){//hit
            deleteElementpgQ(pq, pq->size-i);
            appendElementpgQ(pq, pageNum);
            return(i);
        }
        currNode = currNode->prev;
        
    }
    appendElementpgQ(pq, pageNum);
    if(pq->head != NULL && pq->size >= pq->maxSize){
        deleteElementpgQ(pq, 0); //might cause issues, idk if base 0
    }
    return -1;
}

/**
 * @brief Free all nodes in the queue and reset it to empty
 */
void pqFree(PageQueue *pq) {
    // TODO: Walk from head to tail, free each node, then free
    //       the PageQueue struct itself.
    PqNode* tempNode = pq->head;
    while(tempNode != NULL){
        PqNode* next = tempNode->next;
        free(tempNode);
        tempNode = next;
        pq->size--;
    }
    free(pq);
}

/**
 * @brief Print queue contents to stderr for debugging
 */
void pqPrint(PageQueue *pq) {
    // TODO (optional): Print each page number from head to tail,
    //                  marking which is head and which is tail.
    //                  Useful for desk-checking small traces.
    PqNode* tempNode = pq->head;
    for(int i = 0; i<pq->size; i++){
        printf("%ld\n",tempNode->pageNum);
        tempNode = tempNode->next;
    }
}


void appendElementpgQ(PageQueue* list, unsigned long element){
    if(list->size == 0){
        list->head = malloc(sizeof(PqNode));
        list->head->pageNum = element;
        list->tail = list->head;
    }
    else{
        PqNode* tailTemp = list->tail;
        list->tail->next = malloc(sizeof(PqNode));
        list->tail->next->pageNum = element;
        list->tail->next->prev = list->tail;
        list->tail = tailTemp->next;
    }
    list->tail->next = NULL;
    list->head->prev = NULL;
    list->size++;
}

void deleteElementpgQ(PageQueue* list, int position){
    PqNode* currentNode = list->head;

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
    list->size--;
    free(currentNode);
}