## 1. Resumo do Projeto

Neste projeto, o objetivo é criar um programa em C que traga à vida o famoso jogo Pedra, Papel e Tesoura (ou Jokenpô). O programa permitirá que qualquer pessoa crie uma conta informando nome e idade, dispute rodadas contra o próprio computador, acompanhe a pontuação em tempo real e, ao concluir, registre um relatório completo dos jogos e o resultado final em um arquivo. 
Para construir este sistema, foram empregadas técnicas de programação C, como:ponteiros, alocação dinâmica, struct, arquivos e funções.

---

## 2. Estrutura do Código

```text
/oficial
   /bin/Debug
      oficial.exe
   /imagens
      papel.txt
      pedra.txt
      tesoura.txt
   /obj/Debug
      main.o
   main.c
```

---
## 3. Requisitos Atendidos e Onde Estão no Código


| Requisito                | Onde está implementado                | Descrição                                                                                           |
|--------------------------|----------------------------------------|-------------------------------------------------------------------------------------------------------|
| Entrada e saída          | `main`, `login()`, `jogar()`           | Leitura do nome/idade, da jogada e das opções de continuar.                                          |
| Estruturas de controle   | `jogar()`, `vencedor()`                | Loops `while` e estruturas `if/else` para validações e determinação do vencedor.                    |
| Ponteiros                | `login()`, `jogar()`                   | Passagem de `struct cadastro` e variáveis de placar por referência (`*p`, `*totalPartidas`, etc.).   |
| Alocação dinâmica        | `jogar()`                              | Uso de `realloc` para aumentar dinamicamente o vetor de histórico.                                   |
| Vetores e matrizes       | `jogar()`                              | O histórico é um vetor de strings (`char**`).                                                        |
| Strings                  | `login()`, `vencedor()`, `jogar()`, `salvarArquivo()` | Manipulação e comparação de strings (`strcmp`, `sprintf`).                                           |
| Estruturas heterogêneas  | Globalmente (antes do login)           | Definição da `struct cadastro` para armazenar os dados do jogador.                                  |
| Arquivos                 | `mostrarDesenho()`, `salvarArquivo()`  | Operações de leitura (`fopen(..., "r")`, `fgets`) e escrita (`fopen(..., "w")`, `fprintf`).         |
| Modularização            | Divisão em funções                     | Projeto modularizado em funções dedicadas (`login()`, `jogadaComputador()`, `vencedor()`, etc.).     |
