#ifndef THREADRACE_H
#define THREADRACE_H

#include <pthread.h>

// Constantes
#define DISTANCIA 100

// Estruturas
typedef struct {
    int id;
    int position;
} Ticket;

// Variáveis globais
extern int finished; // Apenas a declaração
extern pthread_mutex_t mutex;
extern int winner; // Apenas a declaração

// Funções
void *correr(void *arg);

#endif