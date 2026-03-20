/* circular_queue.h */
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 10000

typedef unsigned int data;
typedef enum {FALSO, VERDADERO} boolean;

typedef struct {
    data buffer[FULL];  // Arreglo para la cola circular
    int front;          // Índice del primer elemento
    int rear;           // Índice del último elemento
    int cnt;            // Número de elementos
} circular_queue;

void cq_initialize(circular_queue *q);
void cq_enqueue(data d, circular_queue *q);
data cq_dequeue(circular_queue *q);
data cq_head(const circular_queue *q);
data cq_tail(const circular_queue *q);
boolean cq_empty(const circular_queue *q);
boolean cq_full(const circular_queue *q);

#endif
