/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node* curr = *list;
    int res;
    if (curr != NULL){
        *list = curr->next;
        res = curr->val;
        free(curr);
        return res; 
    }
    return -1;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node* curr = *list;
    if (curr == NULL){
        fprintf(stderr, "List is NULL\n");
        
    }else{
        Node* new = make_node(val, curr);
        *list = new;
    }
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) { 
    Node *curr = *list;
    Node *prev = NULL;
    while (curr != NULL) {
        if(curr->val == val){
            // if the first node has the value
            if(prev == NULL){
                *list = curr->next;
                free(curr);
                return 1;
            }else{
                prev->next = curr->next;
                free(curr);
                return 1;
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    return 0;
}

int swap(Node **list){
    Node *curr = *list;
    if(curr->next == NULL || curr==NULL){
        return -1;
    }
    Node *first = curr;
    Node *second = curr->next;
    Node *third = second ->next;
    *list = second;
    second->next = first;
    first->next = third;
    return 0;
}
/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    Node *prev = NULL;
    Node *curr = *list;
    Node *next = curr->next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        *list = curr;
        curr = next;
    }
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    remove_by_value(list, 11);
    print_list(list);

    remove_by_value(list, 2);
    print_list(list);

   

    push(list, 3);
    push(list, 2);
    push(list, 1);
    push(list, 0);
    print_list(list);
     swap(list);
    print_list(list);
    reverse(list);
    print_list(list);
    pop(list);
    print_list(list);
    reverse(list);
    print_list(list);
}
