import random

class Personagem:
    def __init__(self, nome, hp_max):
        self.nome = nome
        self.hp_max = hp_max
        self.hp = hp_max
        self.vivo = True
        self.curas_restantes = 3
        self.especiais_restantes = 1

    def ataque_especial(self, alvo):
        if not self.vivo:
            print(f"{self.nome} não pode atacar porque está morto.")
            return

        if self.especiais_restantes <= 0:
            print(f"{self.nome} não tem ataques especiais restantes!")
            return

        dano = 20  #2x do ataque normal
        print(f"{self.nome} usa ATAQUE ESPECIAL! 💥")
        alvo.tomar_dano(dano)

        self.especiais_restantes -= 1
        print(f"Especiais restantes: {self.especiais_restantes}")

    def tomar_dano(self, dano):
        if not self.vivo:
            print(f"{self.nome} já está morto.")
            return
        
        self.hp -= dano

        if self.hp <= 0:
            self.hp = 0
            self.vivo = False
            print(f"{self.nome} morreu!")

    def curar(self, valor): 
        if not self.vivo:
            print(f"{self.nome} não pode ser curado porque está morto.")
            return
    
        if self.curas_restantes <= 0:
            print(f"{self.nome} não tem mais curas disponíveis!")
            return

        self.hp += valor

        if self.hp > self.hp_max:
            self.hp = self.hp_max

        self.curas_restantes -= 1

        print(f"{self.nome} se curou em {valor}.")
        print(f"Curas restantes: {self.curas_restantes}")

    def atacar(self, alvo):
        if not self.vivo:
            print(f"{self.nome} não pode atacar porque está morto.")
            return
        
        alvo.tomar_dano(10)

    def status(self):
        estado = "VIVO" if self.vivo else "MORTO"
        print(f"{self.nome} | HP: {self.hp}/{self.hp_max} | {estado} | Curas: {self.curas_restantes} | Especiais: {self.especiais_restantes}")


#ATAQUES
p1 = Personagem("Herói", 50)
p2 = Personagem("Monstro", 50)

while True:
    acao = input("\nDigite a (atacar), e (especial), c (curar) ou s (sair): ").lower()

    if acao == "a":
        p1.atacar(p2)

    elif acao == "e":
        p1.ataque_especial(p2)

    elif acao == "c":
        p1.curar(20)

    elif acao == "s":
        print("Saindo do jogo...")
        break

    else:
        print("Comando inválido!")

    
    p1.status()
    p2.status()

    #IA
    if p2.vivo:
        acao_monstro = random.choice(["atacar", "atacar", "curar"])
        if acao_monstro == "atacar":
            print("O monstro ataca!")
            p2.atacar(p1)
        else:
            print("O monstro se cura!")
            p2.curar(10)

    #FIM
    if not p1.vivo:
        print("Você morreu! 💀")
        break
    elif not p2.vivo:
        print("Você venceu! 🏆")
        break