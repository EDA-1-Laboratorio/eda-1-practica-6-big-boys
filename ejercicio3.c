/* playlist.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Nodo para canción */
typedef struct song {
    char nombre[50];
    struct song *prev;
    struct song *next;
} song;

/* Playlist */
typedef struct {
    song *head;
    song *tail;
} playlist;

/* Inicializar playlist */
void init_playlist(playlist *p) {
    p->head = p->tail = NULL;
}

/* Agregar canción al final */
void add_song_end(playlist *p, const char *nombre) {
    song *s = malloc(sizeof(song));
    strcpy(s->nombre, nombre);
    s->next = NULL;
    s->prev = p->tail;

    if (p->tail) 
        p->tail->next = s;
    else 
        p->head = s;

    p->tail = s;
}

/* Agregar canción al inicio */
void add_song_start(playlist *p, const char *nombre) {
    song *s = malloc(sizeof(song));
    strcpy(s->nombre, nombre);
    s->prev = NULL;
    s->next = p->head;

    if (p->head)
        p->head->prev = s;
    else
        p->tail = s;

    p->head = s;
}

/* Mostrar playlist */
void show_playlist(playlist *p) {
    song *s = p->head;
    int i = 1;
    printf("\n--- Playlist ---\n");
    while (s) {
        printf("%d. %s\n", i++, s->nombre);
        s = s->next;
    }
}

/* Main para probar */
int main(void) {
    playlist p;
    init_playlist(&p);

    int opcion;
    char nombre[50];

    while (1) {
        printf("\nMenu:\n1. Agregar canción al inicio\n2. Agregar canción al final\n3. Mostrar playlist\n4. Salir\nOpción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar salto de línea

        if (opcion == 4) break;

        switch(opcion) {
            case 1:
                printf("Nombre de la canción: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0; // quitar salto de línea
                add_song_start(&p, nombre);
                printf("Canción agregada al inicio.\n");
                break;
            case 2:
                printf("Nombre de la canción: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;
                add_song_end(&p, nombre);
                printf("Canción agregada al final.\n");
                break;
            case 3:
                show_playlist(&p);
                break;
            default:
                printf("Opción inválida.\n");
        }
    }

    printf("\nGracias por usar el sistema de playlist.\n");
    return 0;
}
