# Super Trunfo em C

Implementação simples do jogo **Super Trunfo de cidades** em linguagem C.  
Este projeto começou com várias restrições (sem `structs`, funções, loops ou arrays) para treinar lógica e fundamentos.  
A ideia é evoluir o código conforme novos conceitos forem aprendidos.

---

## 🎮 Como funciona
- O jogador cadastra **duas cartas** (cidades) com atributos:
  - Estado e código da carta  
  - Nome da cidade  
  - População  
  - Área (km²)  
  - PIB (em bilhões de reais)  
  - Número de pontos turísticos  
- O programa calcula automaticamente:
  - PIB per capita  
  - Densidade demográfica  
  - Um "Super Poder" (combinação de atributos, penalizando densidade maior).  

Depois, o jogador escolhe **dois atributos** para comparar entre as cidades e o programa exibe a vencedora.

---

## ⚙️ Como compilar e executar
No terminal (Linux, macOS ou WSL no Windows):
```
# Compilar
gcc main.c -o supertrunfo

# Executar
./supertrunfo
```

No Windows (Prompt de Comando ou PowerShell):
```
# Compilar
gcc main.c -o supertrunfo.exe

# Executar
supertrunfo.exe
