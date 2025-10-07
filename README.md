# 🏙️ Fundamentos de Programação em C: Super Trunfo de Cidades

Este projeto foi um exercício fundamental para aprofundar o conhecimento nas estruturas básicas da linguagem C, com foco na manipulação de **variáveis**, entrada de **dados do usuário** e aplicação de **estruturas condicionais** para tomada de decisão.

O código simula um jogo de cartas do tipo Super Trunfo, onde o usuário insere os dados de duas "cartas-cidades" e, em seguida, escolhe dois atributos para comparação.

---

## 🚀 Tecnologias e Conceitos Aplicados

| Conceito | Aplicação no Código |
| :--- | :--- |
| **Declaração de Variáveis** | Uso de múltiplos tipos de dados (`char`, `int`, `unsigned long int`, `float`, `char[]`) para armazenar diferentes informações sobre as cidades. |
| **Entrada e Saída (I/O)** | Uso de `printf()` e `scanf()` para interação básica, incluindo técnicas de **limpeza de buffer** (`getchar()`) e leitura de strings com espaços (`fgets()`). |
| **Conversão de Tipo (Type Casting)** | Conversão de variáveis inteiras para `float` no cálculo de métricas como **PIB per Capita** e **Densidade Populacional**, garantindo a precisão dos resultados. |
| **Estruturas Condicionais** | Uso de `if/else if/else` para: **1)** Validar se o usuário escolheu atributos válidos; **2)** Determinar a cidade **vencedora** com base na soma dos atributos. |
| **Estrutura `switch`** | Utilizado para mapear a escolha numérica do usuário (1 a 6) para a **variável** correspondente da cidade e o **nome do atributo** (string). |
| **Manipulação de Strings** | Uso de funções da biblioteca `<string.h>` (`strcspn`) para garantir a correta formatação dos nomes das cidades. |

---

## 🎯 Objetivo de Aprendizagem

O principal objetivo deste projeto foi colocar em prática a manipulação completa de dados em C:

1.  **Entrada de Dados Complexa:** Aprender a lidar com diferentes tipos de *input* do usuário, incluindo números grandes (`unsigned long int`) e nomes compostos (`fgets`).
2.  **Lógica de Negócios:** Criar fórmulas e cálculos (como o do "Super Poder") e utilizar a lógica condicional para simular um cenário real de comparação de dados.
3.  **Estruturação de Código:** Organizar o programa em blocos claros: Declaração, Coleta de Dados, Cálculos e, finalmente, Comparação e Resultado.

---

## ⚙️ Como Compilar e Executar

1.  **Salve** o código em um arquivo chamado `super_trunfo_cidades.c` (ou outro nome de sua preferência).
2.  **Compile** usando um compilador C (como o GCC) no terminal:
    ```bash
    gcc super_trunfo_cidades.c -o super_trunfo
    ```
3.  **Execute** o programa:
    ```bash
    ./super_trunfo
    ```

O programa guiará você pela inserção dos dados das duas cidades e, por fim, pedirá que escolha dois atributos para o confronto.
