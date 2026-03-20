#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h> 

#define    EMPTY    0 
#define    FULL     10000 

typedef    unsigned int    data; 
typedef    enum {FALSO, VERDADERO}   boolean; 

struct dl_elem {           
    data            d; 
    struct dl_elem  *next;  
    struct dl_elem  *prev;  
}; 

typedef    struct dl_elem    dl_elem; 

struct dl_queue { 
    int         cnt;                             
    dl_elem     *head;                           
    dl_elem     *tail;                           
}; 

typedef     struct dl_queue  dl_queue;         

/* --- DEFINICIONES DE FUNCIONES --- */

void dl_initialize(dl_queue *q) {
    q->cnt = EMPTY;
    q->head = NULL;
    q->tail = NULL;
}

void dl_enqueue(data d, dl_queue *q) {
    if (q->cnt == FULL) return;

    dl_elem *nuevo = (dl_elem *)malloc(sizeof(dl_elem));
    nuevo->d = d;
    nuevo->next = NULL;
    nuevo->prev = q->tail; // Conecta hacia atrás con el antiguo tail

    if (q->head == NULL) { // Si la cola estaba vacía
        q->head = nuevo;
    } else {
        q->tail->next = nuevo; // El antiguo tail ahora apunta al nuevo
    }
    
    q->tail = nuevo; // El nuevo nodo es ahora el tail
    q->cnt++;
}

data dl_dequeue(dl_queue *q) {
    assert(q->cnt > EMPTY);
    
    dl_elem *temp = q->head;
    data valor = temp->d;
    
    q->head = q->head->next; // El segundo pasa a ser el primero
    
    if (q->head == NULL) {
        q->tail = NULL; // La cola quedó vacía
    } else {
        q->head->prev = NULL; // El nuevo frente no tiene a nadie atrás
    }
    
    free(temp);
    q->cnt--;
    return valor;
}

data dl_head(const dl_queue *q) {
    assert(q->cnt > EMPTY);
    return q->head->d;
}

data dl_tail(const dl_queue *q) {
    assert(q->cnt > EMPTY);
    return q->tail->d;
}

boolean dl_empty(const dl_queue *q) {
    return (q->cnt == EMPTY) ? VERDADERO : FALSO;
}

boolean dl_full(const dl_queue *q) {
    return (q->cnt == FULL) ? VERDADERO : FALSO;
}

/* --- FUNCIÓN PRINCIPAL PARA PROBAR EL INPUT --- */

int main() {
    dl_queue mi_cola;
    dl_initialize(&mi_cola);
    
    char op;
    data valor;

    // Lee el input: 'a' para enqueue, 'b' para dequeue
    while (scanf(" %c %u", &op, &valor) != EOF) {
        if (op == 'a') {
            dl_enqueue(valor, &mi_cola);
            printf("Enqueued: %u\n", valor);
        } else if (op == 'b') {
            if (!dl_empty(&mi_cola)) {
                printf("Dequeued: %u\n", dl_dequeue(&mi_cola));
            } else {
                printf("Cola vacía, no se puede hacer dequeue de: %u\n", valor);
            }
        }
    }

    return 0;
}
