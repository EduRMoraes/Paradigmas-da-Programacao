def linha_de_montagem(total_pecas):
    pecas_processadas = 0

    while pecas_processadas < total_pecas:
        pecas_processadas += 1

        print(f"Processando peça {pecas_processadas}")
        yield f"Peça {pecas_processadas} pronta"

    print("Linha de montagem finalizada")

def main():
    maquina = linha_de_montagem(3)

    print(next(maquina)) 
    print(next(maquina))  
    print(next(maquina))  

    try:
        print(next(maquina))
    except StopIteration:
        print("Produção encerrada")


main()