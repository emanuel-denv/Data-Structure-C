#include <stdio.h>
#include <stdlib.h>
#include "FilaFIFO.h"

void FilaFIFO_Iniciar(FilaFIFO *fifo) {
    fifo->inicio = 0;
    fifo->fim = 0;
    fifo->tamanho = 0;
}

void FilaFIFO_Enfileirar(FilaFIFO *fifo, int valor) {
    if (fifo->tamanho >= MAX_FIFO_SIZE) {
        printf("Fila FIFO está cheia!\n");
        return;
    }

    fifo->dados[fifo->fim] = valor;
    fifo->fim = (fifo->fim + 1) % MAX_FIFO_SIZE;
    fifo->tamanho++;
}

int FilaFIFO_Desequipe(FilaFIFO *fifo) {
    if (fifo->tamanho == 0) {
        printf("Fila FIFO está vazia!\n");
        return -1; // Indicador de erro
    }

    int valor = fifo->dados[fifo->inicio];
    fifo->inicio = (fifo->inicio + 1) % MAX_FIFO_SIZE;
    fifo->tamanho--;
    return valor;
}

int FilaFIFO_Vazia(FilaFIFO *fifo) {
    return fifo->tamanho == 0;
}