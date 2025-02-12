#include "bicho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkBicho(int num, int size){
    int qt;
    Bicho bicho[25];
    startBicho(bicho);

    if(size < 25){
        qt = size;
        for(int i = 0; i < qt; i++){
            bicho[i].max_num = i+1;
            bicho[i].min_num = i+1;
        }
    } else {
        qt = 25;
        for(int i = 0; i < qt; i++){
            bicho[i].min_num = 1 + (i*(size/qt)) ;
            bicho[i].max_num = bicho[i].min_num - 1 + (size/qt);
        }
    }
    
    for (int i = 0; i < qt; i++){
        
        if (num <= bicho[i].max_num && bicho[i].min_num <= num){
            printf("O bicho vencedor é %s", bicho[i].animal);
        }
    }

    for (int i = 0; i < 25; i++){
        printf("\n%s [%d-%d]", bicho[i].animal, bicho[i].min_num, bicho[i].max_num);
    }
}

void startBicho(Bicho *bicho){
    strcpy(bicho[0].animal, "Avestruz");
    strcpy(bicho[1].animal, "Águia");  
    strcpy(bicho[2].animal, "Burro");
    strcpy(bicho[3].animal, "Borboleta");
    strcpy(bicho[4].animal, "Cachorro");
    strcpy(bicho[5].animal, "Cabra");
    strcpy(bicho[6].animal, "Carneiro");
    strcpy(bicho[7].animal, "Camelo");
    strcpy(bicho[8].animal, "Cobra");
    strcpy(bicho[9].animal, "Coelho");
    strcpy(bicho[10].animal, "Cavalo");
    strcpy(bicho[11].animal, "Elefante");
    strcpy(bicho[12].animal, "Galo");
    strcpy(bicho[13].animal, "Gato");
    strcpy(bicho[14].animal, "Jacaré");
    strcpy(bicho[15].animal, "Leão");
    strcpy(bicho[16].animal, "Macaco");
    strcpy(bicho[17].animal, "Porco");
    strcpy(bicho[18].animal, "Pavão");
    strcpy(bicho[19].animal, "Peru");
    strcpy(bicho[20].animal, "Touro");
    strcpy(bicho[21].animal, "Tigre");
    strcpy(bicho[22].animal, "Urso");
    strcpy(bicho[23].animal, "Veado");
    strcpy(bicho[24].animal, "Vaca");   
}