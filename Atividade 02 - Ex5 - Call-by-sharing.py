def aplicar_desconto(lista, desconto):
    for i in range(len(lista)):
        lista[i] -= desconto  

def main():
    estoque = [100.0, 200.0, 300.0]

    print("Estoque original:", estoque)
    aplicar_desconto(estoque, 10.0)
    print("Estoque apos desconto:", estoque)

main()