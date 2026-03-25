def gerar_logs():
    contador = 1

    while True:
        log = f"Log #{contador}: evento processado"
        
        # -------------------------------
        # GERA UM ITEM POR VEZ
        # -------------------------------
        yield log

        contador += 1

def main():
    stream_logs = gerar_logs()

    for _ in range(5):
        print(next(stream_logs))


main()