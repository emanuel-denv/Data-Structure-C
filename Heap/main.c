#include <stdio.h>
#include "FP.h"
#include "FilaFIFO.h"

int main() {
    FP fp;
    FP_Iniciar(&fp);

    // Inserindo registros na fila de prioridade
    TipoRegistro r1 = {10};
    FilaFIFO_Iniciar(&r1.fila);
    FilaFIFO_Enfileirar(&r1.fila, 1);
    FilaFIFO_Enfileirar(&r1.fila, 2);
    FP_Inserir(&fp, r1);

    TipoRegistro r2 = {20};
    FilaFIFO_Iniciar(&r2.fila);
    FilaFIFO_Enfileirar(&r2.fila, 3);
    FilaFIFO_Enfileirar(&r2.fila, 4);
    FP_Inserir(&fp, r2);

    // Retirando registros da fila de prioridade e mostrando as chaves
    while (!FP_Vazia(&fp)) {
        TipoRegistro reg = FP_Retirar(&fp);
        printf("Chave: %d\n", reg.chave);
        
        // Imprimindo os elementos na FilaFIFO
        while (!FilaFIFO_Vazia(&reg.fila)) {
            printf("  Valor: %d\n", FilaFIFO_Desequipe(&reg.fila));
        }
    }

    return 0;
}