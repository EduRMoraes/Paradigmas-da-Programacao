sistema_arquivos = {
    "documentos": {
        "curriculo.pdf": None,
        "projetos": {
            "codigo.py": None,
            "relatorio.docx": None
        }
    },
    "imagens": {
        "foto1.jpg": None,
        "foto2.png": None
    },
    "backup.zip": None
}

def buscar_arquivo(pasta, nome_arquivo):
    
    if nome_arquivo in pasta and pasta[nome_arquivo] is None:
        return True

    for item in pasta:
        if isinstance(pasta[item], dict):  # se for subpasta
            if buscar_arquivo(pasta[item], nome_arquivo):
                return True

    return False

def main():
    arquivo = "codigo.py"

    encontrado = buscar_arquivo(sistema_arquivos, arquivo)

    if encontrado:
        print(f"Arquivo '{arquivo}' encontrado!")
    else:
        print(f"Arquivo '{arquivo}' nao encontrado.")

main()