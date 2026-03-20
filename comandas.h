/* Sugerencia de estructuras para el ejercicio 2 */
typedef struct {
    int id_mesa;
    char platillo[50];
    int prioridad; 
} Pedido;

struct nodo {
    Pedido info;
    struct nodo *siguiente;
};

typedef struct {
    struct nodo *frente;
    struct nodo *final;
} Cola;
