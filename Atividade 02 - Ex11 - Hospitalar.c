#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    int internado;
} Paciente;

typedef struct {
    char nome[50];
    char especialidade[50];
} Medico;

typedef struct {
    Paciente pacientes[100];
    Medico medicos[50];
    int leitos_disponiveis;
    float caixa;
    int total_pacientes;
} SistemaHospitalar;

void realizar_internacao(SistemaHospitalar *sistema, char nome[], int idade) {

    if (sistema->leitos_disponiveis <= 0) {
        printf("Sem leitos disponíveis!\n");
        return;
    }

    int i = sistema->total_pacientes;

    strcpy(sistema->pacientes[i].nome, nome);
    sistema->pacientes[i].idade = idade;
    sistema->pacientes[i].internado = 1;

    sistema->total_pacientes++;
    sistema->leitos_disponiveis--;
    sistema->caixa += 500.0; // custo da internação

    printf("Paciente %s internado com sucesso!\n", nome);
}

int main() {
    SistemaHospitalar sistema;

    sistema.leitos_disponiveis = 2;
    sistema.caixa = 1000.0;
    sistema.total_pacientes = 0;

    realizar_internacao(&sistema, "Joao", 30);
    realizar_internacao(&sistema, "Maria", 25);
    realizar_internacao(&sistema, "Carlos", 40); // deve falhar

    printf("\nLeitos restantes: %d\n", sistema.leitos_disponiveis);
    printf("Caixa: %.2f\n", sistema.caixa);

    return 0;
}