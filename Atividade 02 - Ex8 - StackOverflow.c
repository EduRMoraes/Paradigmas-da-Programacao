#include <stdio.h>

void contagem_regressiva(int n) {
    
    if (n < 0) {
        return;
    }

    printf("%d\n", n);
    contagem_regressiva(n - 1);
}

int main() {
    contagem_regressiva(5);
    return 0;
}