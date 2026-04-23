/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Implementation of Linked List Library
 * Purpose: List ADT as linked list
 * ===========================================================
 */

#ifndef LISTASLINKEDLIST_H
#define LISTASLINKEDLIST_H

// Define a node of the linked list
typedef struct node {
    unsigned long data;
    struct node* next;
    struct node* prev;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct linkedList {
    Node* head;
    Node* tail;
    unsigned int numberOfElements;
    unsigned int maxSize;
} LinkedList;

// Functions that manipulate a linked list

/** createLinkedList()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
LinkedList* createLinkedList();

/** deleteLinkedList(()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - a ptr to the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased
 */
void deleteLinkedList(LinkedList* list);

/** appendElementLinkedList()
 * @brief - addes a new element to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param element - the value to append to the list
 * @pre   - linked list before element added
 * @post  - linked list one element longer
 */
void appendElementLinkedList(LinkedList* list, double element);

/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; size of linked list returned
 */
int lengthOfLinkedList(LinkedList* list);

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list elements printed
 */
void printLinkedList(LinkedList* list);

/** getElementLinkedList()
 * @brief  - retrieves element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @return - value at 'position', -1 on failure
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; value at 'position' returned
 */
double getElementLinkedList(LinkedList* list, int position);

/** deleteElementLinkedList()
 * @brief  - deletes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 * @pre    - unmodified linked list
 * @post   - modified linked list; value at 'position' removed
 */
void deleteElementLinkedList(LinkedList* list, int position);

/** insertElementLinkedList()
 * @brief  - adds element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - value to be added
 * @pre    - unmodified linked list
 * @post   - modified linked list; value add at 'position'
 */
void insertElementLinkedList(LinkedList* list, int position, double element);

/** changeElementLinkedList()
 * @brief  - changes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - new value
 * @pre    - unmodified linked list
 * @post   - modified linked list; value changed at 'position'
 */
void changeElementLinkedList(LinkedList* list, int position, double newElement);

/** findElementLinkedList()
 * @brief  - finds the postion of a given element, if it exists
 * @param  list - a ptr to the linked list structure
 * @param  element - value to find
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; position returned if found
 */
int findElementLinkedList(LinkedList* list, double element);

/** selSortLinkedList()
 * @brief - Perform an selection sort on a LinkedList
 * @param list - the LinkedList to sort
 * @pre    - unmodified linked list
 * @post   - sorted linked list
 */
void selSortLinkedList(LinkedList* list);

/** insertSortLinkedList()
 * @brief - Perform an insertion sort on a LinkedList
 * @param list - the LinkedList to sort
 * @pre    - unmodified linked list
 * @post   - sorted linked list
 */
void insertSortLinkedList(LinkedList* list);

#endif  // LISTASLINKEDLIST_H