#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

// Função auxiliar para trocar elementos no heap
static void trocar(FP *fp, int i, int j) {
    TipoRegistro temp = fp->heap[i];
    fp->heap[i] = fp->heap[j];
    fp->heap[j] = temp;
}

// Função auxiliar para ajustar o heap
static void ajustar(FP *fp, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < fp->tamanho && fp->heap[esq].chave > fp->heap[maior].chave) {
        maior = esq;
    }
    if (dir < fp->tamanho && fp->heap[dir].chave > fp->heap[maior].chave) {
        maior = dir;
    }
    if (maior != i) {
        trocar(fp, i, maior);
        ajustar(fp, maior);
    }
}

void FP_Iniciar(FP *fp) {
    fp->tamanho = 0;
}

void FP_Inserir(FP *fp, TipoRegistro registro) {
    if (fp->tamanho >= MAX_HEAP_SIZE) {
        printf("Heap está cheio!\n");
        return;
    }

    fp->heap[fp->tamanho] = registro;
    int i = fp->tamanho;
    fp->tamanho++;

    // Reordenar o heap
    while (i > 0 && fp->heap[(i - 1) / 2].chave < fp->heap[i].chave) {
        trocar(fp, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

TipoRegistro FP_Retirar(FP *fp) {
    if (fp->tamanho == 0) {
        printf("Heap está vazio!\n");
        TipoRegistro registro;
        registro.chave = -1;
        return registro;
    }

    TipoRegistro raiz = fp->heap[0];
    fp->heap[0] = fp->heap[--fp->tamanho];
    ajustar(fp, 0);

    return raiz;
}

int FP_Vazia(FP *fp) {
    return fp->tamanho == 0;
}