#include "threadrace.h"
#include "bicho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cont = 1;

    while (cont) {
        pthread_mutex_init(&mutex, NULL);
        srand(time(NULL));
        int ticket_number;
        
        printf("Bem-vindo ao jogo do bicho!\n\n");

        int qtd_tickets = 100;

        pthread_t threads[qtd_tickets];
        Ticket tickets[qtd_tickets];

        finished = 0;
        winner = -1;
    
        // Inicia o processo de apostas
        int acceptable = 0;
        while (acceptable == 0){

            printf("Escolha um numero para apostar (1 a %d) ", qtd_tickets);
            printf("\n(Cheque uma tabela para visualizar o bicho correspondente): \n");
            scanf("%d", &ticket_number);

            if (ticket_number < 1 || ticket_number > qtd_tickets) {
                printf("Numero inválido!");
            } else {
                acceptable = 1;
            }
        }
        
        int round = 0;
        int win = 0;
        int lost = 0;
        int victory_count[qtd_tickets];
        int winner_id;

        for (int i = 0; i < qtd_tickets; i++){
            victory_count[i] = 0;
        }

        while(win < 2 && lost < 2){
            winner = -1;
            finished = 0;
            // Inicia a corrida
            for (int i = 0; i < qtd_tickets; i++) {
                tickets[i].id = i + 1;
                tickets[i].position = 0;
            }

            for (int i = 0; i < qtd_tickets; i++) {
                pthread_create(&threads[i], NULL, correr, (void *)&tickets[i]);
            }

            // Aguarda todas as threads terminarem
            for (int i = 0; i < qtd_tickets; i++) {
                pthread_join(threads[i], NULL);
            }

            // Verifica o resultado das apostas
            if (winner == ticket_number) {
                printf(";)!\n");
                victory_count[winner]++;
                win++;
            } else {
                winner_id = winner-1;
                printf(";( \n", round, winner);
                victory_count[winner_id]++;
                lost = victory_count[winner_id];                
            }
            round++;
        }

        if (win < 2) {
            printf("Que pena! Você perdeu a aposta.\n Numero sorteado: %d.\n", winner);
        }

        // Bônus de vitórias consecutivas
        if (win == 2) {
            printf("Parabéns! Você venceu a aposta!\n Numero sorteado: %d.\n", winner);
        }
        
        checkBicho((winner), qtd_tickets);

        printf("\nJogar Novamente? 0 para não e 1 para reiniciar: ");
        scanf("%d", &cont);
        pthread_mutex_destroy(&mutex);
    }

    return 0;
}