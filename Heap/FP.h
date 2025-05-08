#ifndef FP_H
#define FP_H

#include "FilaFIFO.h"

#define MAX_HEAP_SIZE 100

typedef struct {
    int chave;
    FilaFIFO fila;
} TipoRegistro;

typedef struct {
    TipoRegistro heap[MAX_HEAP_SIZE];
    int tamanho;
} FP;

void FP_Iniciar(FP *fp);
void FP_Inserir(FP *fp, TipoRegistro registro);
TipoRegistro FP_Retirar(FP *fp);
int FP_Vazia(FP *fp);

#endif // FP_H