/* double_linked_queue.h */
#ifndef DOUBLE_LINKED_QUEUE_H
#define DOUBLE_LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 10000

typedef unsigned int data;
typedef enum {FALSO, VERDADERO} boolean;

typedef struct dl_elem {
    data d;
    struct dl_elem *next;
    struct dl_elem *prev;
} dl_elem;

typedef struct dl_queue {
    int cnt;
    dl_elem *head;
    dl_elem *tail;
} dl_queue;

/* Operaciones básicas */
void dl_initialize(dl_queue *q);
void dl_enqueue(data d, dl_queue *q);
data dl_dequeue(dl_queue *q);
data dl_head(const dl_queue *q);
data dl_tail(const dl_queue *q);
boolean dl_empty(const dl_queue *q);
boolean dl_full(const dl_queue *q);

#endif
