def calcular_valor_normalizado(valor, maximo, fator):
    base = valor / maximo
    return base + fator


def normalizar_dados(brutos, fator):
    maximo = max(brutos)
    resultado = []
    
    for valor in brutos:
        resultado.append(
            calcular_valor_normalizado(valor, maximo, fator)
        )
    
    return resultado


def main():
    brutos = [10.0, 20.0, 50.0]
    fator = 0.5
    
    normalizados = normalizar_dados(brutos, fator)
    
    print(f"IA Dados: {normalizados}")


main()