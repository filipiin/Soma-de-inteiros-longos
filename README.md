# Soma-de-inteiros-longos

# Soma de Inteiros Longos Positivos em C

## 📖 Descrição

Este projeto implementa a **soma de números inteiros positivos de tamanho arbitrário** utilizando **listas ligadas circulares** na linguagem C.

Como os tipos primitivos da linguagem (`int`, `long`, `long long`) possuem limite de armazenamento, este programa permite realizar operações de soma com números muito maiores do que os suportados nativamente.

Cada número é dividido em blocos de **5 dígitos**, armazenados em nós de uma lista ligada circular. Durante a soma, o algoritmo realiza o tratamento do **carry (vai um)** entre os blocos, produzindo o resultado corretamente independentemente do tamanho dos números.

---

## 🚀 Funcionalidades

* Leitura de números inteiros positivos de até **250 dígitos**.
* Conversão dos números para listas ligadas circulares.
* Soma de números grandes sem utilizar bibliotecas externas.
* Tratamento automático do transporte ("carry").
* Impressão do resultado no formato correto.
* Possibilidade de realizar várias somas consecutivas.
* Liberação da memória utilizada ao final de cada operação.

---

## 🛠 Estrutura de Dados

O programa utiliza a seguinte estrutura:

```c
struct node
{
    struct node *next;
    long int info;
};
```

Cada nó contém:

* `info` → bloco de até **5 dígitos** do número;
* `next` → ponteiro para o próximo nó.

A lista é **circular** e utiliza um **nó sentinela**, identificado pelo valor `-1`.

---

## ⚙️ Funcionamento

### Entrada

O usuário informa dois números inteiros positivos.

Exemplo:

```
12345678901234567890
98765432109876543210
```

---

### Conversão

Os números são divididos em blocos de 5 dígitos.

Exemplo:

```
12345678901234567890

↓

67890
12345
89012
34567
1
```

Esses blocos são armazenados em uma lista ligada.

---

### Soma

A soma é realizada bloco a bloco:

```
Bloco 1 + Bloco 1
Bloco 2 + Bloco 2
Bloco 3 + Bloco 3
...
```

Sempre que o resultado ultrapassa **99999**, o excedente é propagado para o próximo bloco através do **carry**.

---

## ▶️ Exemplo de execução

```
=======================================================
        SOMA DE INTEIROS LONGOS POSITIVOS
=======================================================

--- PRIMEIRO NUMERO ---
INSIRA O VALOR INTEIRO:
12345678901234567890

--- SEGUNDO NUMERO ---
INSIRA O VALOR INTEIRO:
98765432109876543210

RESULTADO DA SOMA:
111111111011111111100

Deseja realizar outra soma?
[1] Sim
[0] Não, encerrar programa
```

---

## 📂 Organização do Código

| Função                 | Descrição                                                          |
| ---------------------- | ------------------------------------------------------------------ |
| `getnode()`            | Aloca um novo nó.                                                  |
| `firstin()`            | Cria a lista circular com nó sentinela.                            |
| `insafter()`           | Insere um novo nó após um determinado nó.                          |
| `convert()`            | Converte a entrada do usuário em uma lista de blocos de 5 dígitos. |
| `addint()`             | Realiza a soma entre duas listas.                                  |
| `imprimir_resultado()` | Exibe o número resultante.                                         |
| `liberar_lista()`      | Libera toda a memória alocada.                                     |
| `main()`               | Controla o fluxo do programa.                                      |

---

## 💻 Compilação

Utilizando o GCC:

```bash
gcc main.c -o soma
```

Executar:

```bash
./soma
```

No Windows (MinGW):

```bash
gcc main.c -o soma.exe
soma.exe
```

---

## 📌 Conceitos Aplicados

* Linguagem C
* Alocação dinâmica de memória
* Ponteiros
* Listas ligadas circulares
* Nó sentinela
* Manipulação de strings
* Conversão de dados
* Estruturas de dados
* Algoritmos de soma de grandes números
* Tratamento de carry

---

## 📈 Complexidade

### Conversão

* **Tempo:** O(n)
* **Espaço:** O(n)

### Soma

* **Tempo:** O(n)
* **Espaço:** O(n)

onde **n** representa a quantidade de blocos de 5 dígitos armazenados nas listas.

---

## 📚 Objetivo Acadêmico

Este projeto foi desenvolvido com fins educacionais para praticar conceitos fundamentais de:

* Estruturas de Dados;
* Manipulação de listas ligadas;
* Gerenciamento manual de memória em C;
* Implementação de algoritmos utilizando ponteiros;
* Representação de números inteiros de grande porte.

---

## 👨‍💻 Autor

Desenvolvido como projeto de estudo da disciplina de Estruturas de Dados utilizando a linguagem C.
