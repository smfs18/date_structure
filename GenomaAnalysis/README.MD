# 🧬 Genome Block Counter - Análise de Sequências de DNA

![C++](https://img.shields.io/badge/C++-17-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Platform](https://img.shields.io/badge/Platform-Linux%20|%20macOS%20|%20WSL-lightgrey)

## 📋 Descrição

Programa em C++ para contagem de padrões em sequências de DNA, implementando:

- Tabela hash manual para contagem eficiente
- Processamento de blocos de 6 bases nitrogenadas (A, T, C, G)
- Validação de entrada rigorosa

## 🚀 Como Usar

### Pré-requisitos

- Compilador C++17 (g++ ≥ 7 ou clang++)
- Sistema Unix-like (Linux/macOS/WSL)

### Compilação e Execução

```bash
# Compilar
make clean && make

# Executar
./genome_analysis
```

## 📥 Entrada

**Formato:**

- 60 strings de 6 caracteres cada
- Caracteres válidos: A, T, C, G

**Exemplo:**
```text
ATTAAA
AGGTTT
CTACGT
...
TAGATC
```

### Fluxo Interativo:

```text
> Digite 60 blocos de 6 caracteres:
Bloco 1: ATTAAA
Bloco 2: AGGTTT
...
Bloco 60: TAGATC
```

## 📤 Saída

**Formato:**
```text
-----------------------------
Bloco      Ocorrências
-----------------------------
ATTAAA     3
AGGTTT     5
ATACCT     2
...
TAGATC     1
-----------------------------
```

### Características:

- Lista todos os blocos únicos
- Exibe contagem precisa
- Ordenação por posição na tabela hash

## 🏗️ Estrutura do Código

```text
GenomeAnalysis/
├── include/
│   ├── HashNode.h        # Estrutura do nó
│   ├── GenomeHashTable.h # Tabela hash
│   └── ...
├── src/
│   ├── HashNode.cpp      # Implementação do nó
│   ├── GenomeHashTable.cpp # Lógica da hash
│   └── ...
├── Makefile              # Build automation
└── README.md             # Documentação
```

## 📝 Exemplo Completo

### Entrada:
```text
ATTAAA
AGGTTT
ATTAAA
CTACGT
...
AGGTTT
```

### Saída:
```text
-----------------------------
Bloco      Ocorrências
-----------------------------
ATTAAA     2
AGGTTT     3
CTACGT     1
-----------------------------
