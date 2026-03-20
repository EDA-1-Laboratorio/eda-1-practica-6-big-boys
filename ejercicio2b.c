#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_ORDERS 6

typedef enum {FALSO, VERDADERO} boolean;

typedef struct {
    int id_mesa;
    char platillo[50];
    int prioridad;
} Pedido;

typedef struct nodo {
    Pedido info;
    struct nodo *siguiente;
} nodo;

typedef struct {
    nodo *frente;
    nodo *final;
    int cnt;
} Cola;

/* Funciones */
void inicializar(Cola *q) {
    q->frente = q->final = NULL;
    q->cnt = 0;
}

boolean vacia(Cola *q) {
    return (boolean)(q->cnt == 0);
}

boolean llena(Cola *q) {
    return (boolean)(q->cnt == MAX_ORDERS);
}

void enqueue(Pedido p, Cola *q) {
    if (llena(q)) {
        printf("No se pueden aceptar más órdenes, la cola está llena.\n");
        return;
    }
    nodo *nuevo = malloc(sizeof(nodo));
    nuevo->info = p;
    nuevo->siguiente = NULL;
    if (vacia(q)) {
        q->frente = q->final = nuevo;
    } else {
        q->final->siguiente = nuevo;
        q->final = nuevo;
    }
    q->cnt++;
}

Pedido dequeue(Cola *q) {
    assert(!vacia(q));
    nodo *p = q->frente;
    Pedido ped = p->info;
    q->frente = q->frente->siguiente;
    q->cnt--;
    free(p);
    return ped;
}

/* Función principal */
int main(void) {
    Cola ordenes;
    inicializar(&ordenes);

    char comando;
    Pedido p;
    int id = 1;

    printf("Sistema de comandas (máx %d órdenes).\n", MAX_ORDERS);

    while (1) {
        printf("\nComando (a=agregar, s=servir, f=finalizar): ");
        int res = scanf(" %c", &comando);

        if (res != 1) {
            // Limpiar buffer si hay errores
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Limpiar buffer de salto de línea
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (comando == 'f') break;

        if (comando != 'a' && comando != 's') {
            printf("Comando inválido. Solo a, s o f.\n");
            continue;
        }

        if (comando == 'a') {
            if (llena(&ordenes)) {
                printf("Cola llena, espere que se sirvan algunas órdenes.\n");
                continue;
            }
            p.id_mesa = id++;
            printf("Nombre del platillo: ");
            fgets(p.platillo, sizeof(p.platillo), stdin);
            // Eliminar salto de línea al final
            size_t len = strlen(p.platillo);
            if (len > 0 && p.platillo[len-1] == '\n') p.platillo[len-1] = '\0';
            enqueue(p, &ordenes);
            printf("Orden agregada: Mesa %d - %s\n", p.id_mesa, p.platillo);
        } else if (comando == 's') {
            if (vacia(&ordenes)) {
                printf("No hay órdenes para servir.\n");
                continue;
            }
            Pedido servido = dequeue(&ordenes);
            printf("Sirviendo mesa %d: %s\n", servido.id_mesa, servido.platillo);
        }
    }

    if (!vacia(&ordenes)) {
        printf("\nPedidos restantes en cola:\n");
        while (!vacia(&ordenes)) {
            Pedido ped = dequeue(&ordenes);
            printf("Mesa %d: %s\n", ped.id_mesa, ped.platillo);
        }
    } else {
        printf("\nNo hay pedidos pendientes.\n");
    }

    return 0;
}
