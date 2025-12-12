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


| Requisito                | Onde está implementado                | Descrição                                                                                             |
|--------------------------|----------------------------------------|------------------------------------------------------------------------------------------------------|
| Entrada e saída          | `main`, `login()`, `jogar()`           | Leitura do nome/idade, da jogada e das opções de continuar.                                          |
| Estruturas de controle   | `jogar()`, `vencedor()`                | Loops `while` e estruturas `if/else` para validações e determinação do vencedor.                     |
| Ponteiros                | `login()`, `jogar()`                   | Passagem de `struct cadastro` e variáveis de placar por referência (`*p`, `*totalPartidas`, etc.).   |
| Alocação dinâmica        | `jogar()`                              | Uso de `realloc` para aumentar dinamicamente o vetor de histórico.                                   |
| Vetores e matrizes       | `jogar()`                              | O histórico é um vetor de strings (`char**`).                                                        |
| Strings                  | `login()`, `vencedor()`, `jogar()`, `salvarArquivo()` | Manipulação e comparação de strings (`strcmp`, `sprintf`).                            |
| Estruturas heterogêneas  | Globalmente (antes do login)           | Definição da `struct cadastro` para armazenar os dados do jogador.                                   |
| Arquivos                 | `mostrarDesenho()`, `salvarArquivo()`  | Operações de leitura (`fopen(..., "r")`, `fgets`) e escrita (`fopen(..., "w")`, `fprintf`).          |
| Modularização            | Divisão em funções                     | Projeto modularizado em funções dedicadas (`login()`, `jogadaComputador()`, `vencedor()`, etc.).     |

---
## 4. Descrição dos Módulos

### 4.1 main.c
- Inicializa o programa.
- Chama a função login() para cadastrar o jogador.
- Controla o fluxo principal do jogo.
- Gera número aleatório com srand(time(NULL)).
- Chama jogar() para executar as partidas.
- Chama salvarArquivo() para salvar o histórico.
- Libera a memória alocada dinamicamente.

### 4.2 funcoes.h
- Declara a estrutura: struct cadastro (nome e idade).
- Declara protótipos das funções: login(); mostrarDesenho();  
  jogadaComputador(); vencedor(); jogar(); salvarArquivo().

### 4.3 funcoes.c
- login(): Lê nome e idade do jogador.
- mostrarDesenho(): Abre o arquivo tipo “.txt” da pasta ”imagens” e imprime o desenho ASCII correspondente à jogada.
- jogadaComputador(): Gera jogada aleatória (pedra/papel/tesoura).
- vencedor(): Compara jogadas e retorna resultado (empate, jogador venceu, computador venceu).
- jogar(): Função recursiva que executa uma partida, atualiza placar, armazena histórico e pergunta se o jogador deseja continuar.
- salvarArquivo(): Grava histórico e placar final em um arquivo temporário “historico.txt”.

---
## 5. Dificuldades Encontradas

- Manipulação de ponteiros e passagem por referência em funções.
- Uso de malloc e realloc para armazenar histórico de jogadas.
- Validação de entrada do usuário (garantir apenas "pedra", "papel" ou "tesoura").
- Leitura e escrita em arquivos externos.
- Implementação de função recursiva para repetir partidas.

---

## 6. Materiais Utilizados

### WhatsApp
- Usado para discussões rápidas e alinhamentos informais.
- Facilitou a troca de mensagens instantâneas e decisões ágeis.

### Discord
- Utilizado para trabalho em grupo, reuniões virtuais e compartilhamento de tela.
- Permitiu organizar canais temáticos (ex.: código, documentação, dúvidas).

### Miro
- Ferramenta de planejamento visual.
- Usada para criar fluxogramas, mapas mentais e organizar ideias de forma colaborativa.

### CodeBlock
- Plataforma para desenvolver o programa utilizando a linguagem C.

---



