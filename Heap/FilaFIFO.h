#ifndef FILAFIFO_H
#define FILAFIFO_H

#define MAX_FIFO_SIZE 100

typedef struct {
    int dados[MAX_FIFO_SIZE];
    int inicio;
    int fim;
    int tamanho;
} FilaFIFO;

void FilaFIFO_Iniciar(FilaFIFO *fifo);
void FilaFIFO_Enfileirar(FilaFIFO *fifo, int valor);
int FilaFIFO_Desequipe(FilaFIFO *fifo);
int FilaFIFO_Vazia(FilaFIFO *fifo);

#endif // FILAFIFO_H