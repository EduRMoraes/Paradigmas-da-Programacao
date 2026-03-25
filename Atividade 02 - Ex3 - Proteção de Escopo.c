#include <stdio.h>

void tentar_alterar_por_valor(int saldo) {
    saldo += 1000; // altera apenas a cópia
    printf("[Dentro da funcao - valor] Saldo alterado: %d\n", saldo);
}

void alterar_por_referencia(int *saldo) {
    *saldo += 1000; // altera o valor original
    printf("[Dentro da funcao - referencia] Saldo alterado: %d\n", *saldo);
}

int main() {
    int saldo_bancario = 5000;

    printf("Saldo inicial: %d\n\n", saldo_bancario);

    tentar_alterar_por_valor(saldo_bancario);
    printf("Saldo apos funcao por valor: %d\n\n", saldo_bancario);

    alterar_por_referencia(&saldo_bancario);
    printf("Saldo apos funcao por referencia: %d\n", saldo_bancario);

    return 0;
}