# 🧬 Genome Block Counter

![C++](https://img.shields.io/badge/C++-17-blue)
![Platform](https://img.shields.io/badge/Platform-Linux%20|%20macOS%20|%20WSL-lightgrey)

## 📋 Descrição do Projeto

Projeto em C++ que implementa um contador de blocos genômicos utilizando tabela hash manual para análise de sequências de DNA. Processa entradas do usuário e gera relatórios de ocorrências de padrões de 6 bases nitrogenadas.

## 🛠️ Funcionalidades Principais

- **Contagem precisa** de blocos de 6 bases (A, T, C, G)
- **Validação rigorosa** de entrada
- **Tabela hash otimizada** com tratamento de colisões
- **Saída formatada** para fácil interpretação

## 📥 Entrada do Programa

### Formato Requerido
- 60 strings de exatamente 6 caracteres cada
- Caracteres válidos: `A`, `T`, `C`, `G` (maiúsculos)

### Exemplo de Entrada Válida
```text
ATTAAA
AGGTTT
CTACGT
...
TAGATC

## Fluxo de Interação

> Digite 60 blocos de 6 caracteres cada (A/T/C/G):
Bloco 1: ATTAAA
Bloco 2: AGGTTT
...
Bloco 60: TAGATC

### 📤 Saída do Programa

## Formato de Resultado

-----------------------------
Bloco      Ocorrências
-----------------------------
ATTAAA     3
AGGTTT     5
ATACCT     2
...
TAGATC     1
-----------------------------

## Características da Saída

-Listagem de todos os blocos únicos

-Contagem exata de ocorrências

-Ordenação por posição na tabela hash

### 🚀 Instalação e Execução

## Pré-requisitos

-Compilador C++17 (g++ ≥ 7 ou clang++)

-Sistema Unix-like (Linux/macOS/WSL)

## Compilação

make clean && make

## Execução

./genome_analysis


### 🏗️ Arquitetura do Projeto

GenomeAnalysis/
├── include/
│   ├── HashNode.h        # Estrutura do nó da hash
│   ├── GenomeHashTable.h # Implementação da tabela
│   ├── GenomeProcessor.h # Lógica principal
│   └── constants.h       # Constantes globais
├── src/
│   ├── HashNode.cpp
│   ├── GenomeHashTable.cpp
│   ├── GenomeProcessor.cpp
│   └── main.cpp          # Ponto de entrada
├── Makefile              # Script de build
└── README.md             # Documentação

### 📝 Exemplo Completo

## Entrada do Usuário

ATTAAA
AGGTTT
ATTAAA
CTACGT
...
AGGTTT

## Saída Gerada

-----------------------------
Bloco      Ocorrências
-----------------------------
ATTAAA     2
AGGTTT     3
CTACGT     1
-----------------------------
