# ----------------------------------------
# FUNÇÃO PURA (IN MODE)
# ----------------------------------------

def calcular_salario(base, horas_extra, valor_hora):
    return base + (horas_extra * valor_hora)

# ----------------------------------------
# PROCEDIMENTO (RESPONSÁVEL PELA SAÍDA)
# ----------------------------------------

def imprimir_salario(nome, salario):
    print(f"{nome}: {salario}")

# ----------------------------------------
# FLUXO PRINCIPAL (MAIN)
# ----------------------------------------

def main():
    s1 = calcular_salario(2000, 10, 20)
    s2 = calcular_salario(3000, 5, 30)
    s3 = calcular_salario(2500, 8, 25)

    imprimir_salario("Funcionario 1", s1)
    imprimir_salario("Funcionario 2", s2)
    imprimir_salario("Funcionario 3", s3)

    print("Folha processada com sucesso")

main()