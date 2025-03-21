#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

void queue_enqueue(Queue* q, Data d){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = d;
        new_node->next = NULL;
        
        if (q->tail == NULL) {
            q->head = new_node;
            q->tail = new_node;
        } else {
            q->tail->next = new_node;
            q->tail = new_node;
        }
    }
}

Data queue_dequeue(Queue* q){
    if (q->head == NULL) {
        return -1; 
    }
    Node* temp = q->head;
    Data front_data = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) { 
        q->tail = NULL;
    }
    free(temp);
    return front_data;
}

bool queue_is_empty(Queue* q){
    return (q->head == NULL);
}

Data queue_front(Queue* q){
    if (q->head == NULL) {
        return -1; 
    }
    return q->head->data;
}

void queue_empty(Queue* q){
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q){
    queue_empty(q);
    free(q); 
}