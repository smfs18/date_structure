🧬 Genome Block Counter
Um projeto em C++ para análise de sequências de DNA, contando a ocorrência de blocos de 6 bases nitrogenadas (A, T, C, G) em entradas fornecidas pelo usuário.

📥 Entrada do Programa
O programa solicita 60 strings de 6 caracteres cada, representando blocos de DNA:

Formato de Entrada
Cada bloco deve conter exatamente 6 caracteres

Caracteres válidos: A, T, C, G (maiúsculos)

Exemplo de entrada válida:

Copy
Bloco 1: ATTAAA  
Bloco 2: AGGTTT  
Bloco 3: CTTAGG  
...  
Bloco 60: TAGATC  
Validação Automática
O programa rejeita entradas incorretas e solicita correção:

❌ Tamanho diferente de 6 caracteres (ex.: ATTA)

❌ Caracteres inválidos (ex.: ATTAAX).

📤 Saída do Programa
Após processar os 60 blocos, o programa exibe um relatório detalhado:

Formato de Saída
plaintext
Copy
-----------------------------
Bloco      Ocorrências
-----------------------------
ATTAAA     3
AGGTTT     5
ATACCT     2
...        ...
TAGATC     1
-----------------------------
Características da Saída
✔ Blocos únicos: Lista cada padrão distinto de 6 bases.
✔ Contagem precisa: Mostra quantas vezes cada bloco apareceu.
✔ Ordenação: Organizado pela posição na tabela hash (não alfabética).

🛠 Como Executar
Compilação
Certifique-se de ter make e g++ instalados.

No terminal, navegue até a pasta do projeto e execute:

make
./genome_analysis
Siga as instruções para inserir os 60 blocos.

Os resultados serão exibidos automaticamente no terminal.

📂 Estrutura do Projeto
plaintext
Copy
GenomeAnalysis/
├── include/          # Cabeçalhos (.h)
│   ├── HashNode.h
│   ├── GenomeHashTable.h
│   └── ...
├── src/             # Código-fonte (.cpp)
│   ├── HashNode.cpp
│   ├── GenomeHashTable.cpp
│   └── ...
├── Makefile         # Script de compilação
└── README.md        # Documentação
❓ Por Que Usar Este Projeto?
✅ Eficiência: Implementação manual de tabela hash para processamento rápido.

✅ Modularização: Código organizado em classes bem definidas.

✅ Validação Robustas: Garante entradas corretas para análise precisa.

✅ Portável: Funciona em Linux, macOS e WSL (Windows).

📄 Exemplo Completo
Entrada do Usuário
plaintext
Copy
Bloco 1: ATTAAA
Bloco 2: AGGTTT
Bloco 3: ATTAAA
...
Bloco 60: AGGTTT
Saída Gerada
plaintext
Copy
-----------------------------
Bloco      Ocorrências
-----------------------------
ATTAAA     2
AGGTTT     3
CTTGGC     1
...        ...
-----------------------------
🔍 Requisitos
Compilador C++17 (ex.: g++ versão 7+)

Sistema Unix-like (Linux/macOS/WSL)