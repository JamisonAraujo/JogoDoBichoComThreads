#include "threadrace.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int finished = 0; 
int winner = -1;          
pthread_mutex_t mutex;

void *correr(void *arg) {
    Ticket *ticket = (Ticket *)arg;
    while (!finished) {
        ticket->position += rand() % 10 + 1;

        pthread_mutex_lock(&mutex);
        if (!finished) {
            printf("O ticket %d está na posição %d\n", ticket->id, ticket->position);
        }
        pthread_mutex_unlock(&mutex);

        if (ticket->position >= DISTANCIA && !finished) {
            finished = 1;
            winner = ticket->id;
            pthread_mutex_lock(&mutex);
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }

        usleep(100000);
    }
    return NULL;
}
