#include <stdio.h>
// -------------------------------
// FUNÇÃO RECURSIVA (INGÊNUA)
// -------------------------------
/*
ANÁLISE:
- Implementação direta da definição matemática de Fibonacci.
- PROBLEMA: recalcula os mesmos valores várias vezes.
- Exemplo: fib(5) chama fib(4) e fib(3), mas fib(3) já foi chamado dentro de fib(4).
- Isso gera crescimento exponencial de chamadas.

COMPLEXIDADE:
- Tempo: O(2^n) → exponencial
- Espaço: O(n) → profundidade da pilha (stack)

RISCO:
- Alto custo computacional
- Grande uso de Stack Frames (cada chamada cria um novo frame na pilha)
*/
long fib_recursivo(int n) {
    if (n <= 1)
        return n;
    return fib_recursivo(n - 1) + fib_recursivo(n - 2);
}
// -------------------------------
// FUNÇÃO ITERATIVA (PROCEDURAL)
// -------------------------------
/*
ANÁLISE:
- Utiliza laço (for) e variáveis locais.
- Evita recomputações.
- Não usa chamadas recursivas → sem crescimento da pilha.

COMPLEXIDADE:
- Tempo: O(n)
- Espaço: O(1)

VANTAGEM:
- Muito mais eficiente e previsível
*/
long fib_iterativo(int n) {
    if (n <= 1)
        return n;

    long anterior = 0;
    long atual = 1;
    long proximo;

    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return atual;
}
// -------------------------------
// FUNÇÃO PRINCIPAL
// -------------------------------
int main() {
    int n = 40;

    printf("Fibonacci Iterativo (%d): %ld\n", n, fib_iterativo(n));
    printf("Fibonacci Recursivo (%d): %ld\n", n, fib_recursivo(n));

    return 0;
}