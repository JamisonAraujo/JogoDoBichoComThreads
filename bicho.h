#ifndef BICHO_H
#define BICHO_H

typedef struct Bicho{
    char animal[10];
    int max_num;
    int min_num;
} Bicho;

void checkBicho(int num, int size);
void startBicho(Bicho *bicho);

#endif