#include <stdio.h>

int calcular_nova_altitude(int altitude_atual, int variacao) {
    return altitude_atual + variacao;
}

void forcar_altitude(int *altitude, int variacao) {
    *altitude += variacao;
    printf("[Procedimento] Altitude alterada diretamente: %d\n", *altitude);
}

int main() {
    int altitude = 10000; 

    printf("Altitude inicial: %d\n\n", altitude);

    int nova_altitude = calcular_nova_altitude(altitude, 500);

    printf("[Funcao Pura] Nova altitude calculada: %d\n", nova_altitude);
    printf("Altitude original apos funcao pura: %d\n\n", altitude);
    forcar_altitude(&altitude, -200);

    printf("Altitude original apos procedimento: %d\n", altitude);

    return 0;
}