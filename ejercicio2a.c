#include <stdio.h>
#include <stdlib.h>
#include "queue.h" // Asegúrate de incluir tu header

// Definimos los platillos con un enum
typedef enum {
HAMBURGUESA = 1,
PIZZA = 2,
TACOS = 3,
ENCHILADAS = 4,
SOPA = 5
} Platillos;

// Función auxiliar para imprimir el texto del platillo
void imprimirPlatillo(data d) {
switch(d) {
case HAMBURGUESA: printf("Hamburguesa"); break;
case PIZZA: printf("Pizza"); break;
case TACOS: printf("Tacos"); break;
case ENCHILADAS: printf("Enchiladas"); break;
case SOPA: printf("Sopa"); break;
default: printf("Platillo desconocido");
}
}

int main() {
queue comandas;
initialize(&comandas); // Inicializamos la cola
int opcion;
unsigned int eleccionPlatillo;

printf("=== BIENVENIDO AL SISTEMA DE COMANDAS ===\n");

while(1) {
printf("\n1. Recibir comanda (Ingresar orden)\n");
printf("2. Servir platillo (Sacar orden)\n");
printf("3. Consultar siguiente platillo por servir\n");
printf("4. Consultar ultimo platillo anotado\n");
printf("5. Salir\n");
printf("Elige una opcion: ");
scanf("%d", &opcion);

switch(opcion) {
case 1:
printf("\nMenu:\n1. Hamburguesa\n2. Pizza\n3. Tacos\n4. Enchiladas\n5. Sopa\n");
printf("Ingrese el numero del platillo: ");
scanf("%u", &eleccionPlatillo);

// Encolamos el platillo
enqueue(eleccionPlatillo, &comandas);
printf("Comanda recibida: ");
imprimirPlatillo(eleccionPlatillo);
printf("\n");
break;

case 2:
if (!empty(&comandas)) {
data servido = deque(&comandas);
printf("\nPlatillo servido: ");
imprimirPlatillo(servido);
printf("\n");
} else {
printf("\nNo hay ordenes pendientes por servir.\n");
}
break;

case 3:
if (!empty(&comandas)) {
printf("\nEl siguiente platillo por servir es: ");
imprimirPlatillo(head(&comandas));
printf("\n");
} else {
printf("\nLa cola de comandas esta vacia.\n");
}
break;

case 4:
if (!empty(&comandas)) {
printf("\nEl ultimo platillo anotado es: ");
imprimirPlatillo(tail(&comandas));
printf("\n");
} else {
printf("\nLa cola de comandas esta vacia.\n");
}
break;

case 5:
printf("\nSaliendo del sistema...\n");
// Aquí idealmente deberías liberar la memoria de la cola antes de salir
return 0;

default:
printf("\nOpcion no valida. Intente de nuevo.\n");
}
}
return 0;
}
