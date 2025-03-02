typedef int tipoitem; //forma de chamar o tipo de item
const int max_itens = 100; //tamanho máximo da pilha

class stack{
    private:
    tipoitem tamanho; //tamanho da pilha.
    tipoitem* estrutura; //vetor da pilha

    public:
    stack(); //construtor
    ~stack(); //destrutor
    bool is_empty(); // verifica se a pulha está vazia
    bool is_full(); // verifica se a pilha está cheio
    void push(tipoitem item); //colocar elementos na pilha
    tipoitem pop(); //remover o último adicionado
    void print(); //imprimir na tela
    tipoitem lenght(); //Tamanho da pilha

};