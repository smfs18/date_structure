#include<iostream>
using namespace std;

struct No{
    int data;
    No* proximo;

    No(int d) : data(d), proximo(nullptr){}
};
class list{
    private:
    No* cabeca;
    No* rabo;
    int tamanho;
    
    public:
    //Construtor:
    list() : cabeca(nullptr), rabo(nullptr), tamanho(0){}
    //Destrutor:
    ~list(){
        No* atual = cabeca;
        while (atual != nullptr)
        {
            No* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }
    //Checa se está vazio. 
    bool vazio(){
        return cabeca == nullptr;
    }
    //Informa o tamanho da lista.
    int gettamanho(){
        return tamanho;
    }
    //Inserir um elemento no ínicio.
    void inseririnicio(int valor){
        No* novoNo = new No(valor); //Instancio um novo nó chamado de novo nó;
        if(vazio()){ //Verifica se a lista está vazia;
            cabeca = rabo = novoNo; //Se estiver vazio, a cabeça, o rabo rececem o mesmo valor do nó criado(novoNo)
        }else{//caso a lista não esteja vazia, ele vai pegar o ponteiro do novoNo que aponta para Null e aponta para a antiga cabeça.
            novoNo->proximo = cabeca;
            cabeca = novoNo; //O novo nó se torna a cabeça.
        }
        tamanho++; //Aumenta mais um no tamanho da lista.
    }
    //Inserir um elemento no fim.
    void inserirfim(int valor){
        No* novoNo = new No(valor);//Criando um novo nó que vai receber o valor que vai ser passado pelo usuário.
        if(vazio()){//Verifica se a lista está vazia
            cabeca = rabo = novoNo;
        }else{
            novoNo->proximo = rabo;
            rabo = novoNo;
        }
        tamanho++;
    }
    //Remover um elemento do Início.
    void removerinicio(){
        if (vazio()){//Verifica se está vazio a lista
            cout<<"A lista está vazia"<<endl; //Mostra ao usuário;
        }
        No* temp = cabeca; //Adiciona a cabeça em um nó temporário.
        cabeca = cabeca->proximo; //atualizo a cabeça, nesse caso a cabeça se torna o próximo elemento da lista;
        if (cabeca == nullptr){ //Verifica se a cabeça é nula.
            rabo == nullptr;// Se sim, coloca o rabo como nulo também
        }
        delete temp; //deleta o ponteiro temporário.
        tamanho--; //decrementa o tamanho.
    }
    //Remover um elemento dfo final.
    void removerfinal(){
        if (vazio()){ //Verifica se a lista está vazia.
            cout<<"A lista está vazia"<<endl; //Se a lista está vazia, então imprime na tela do usuário.
        }
        if(cabeca == rabo){ //Se a cabeça for igual ao rabo da lista
            cabeca = rabo = nullptr; //Os dois viram nulos, porque o único valor da lista nós removemos.
        }else{
            No* atual = cabeca; //Criei um nó temporário e coloquei a cabeça nele.
            while (atual->proximo != rabo) //Enquanto esse nó temporário não tiver o ponteiro que aponta para o rabo, ele vai fazer
            {
               atual = atual->proximo; //atualizar o nó temporário com o próximo nó.
            }
            delete rabo; //Excluo o rabo, quando sair do nó;
            rabo = atual; //O rabo passa a ser agora o nó anterior a ele.
            rabo->proximo= nullptr; //O ponteiro para o próximo nó fica nulo, porque não tem mais nenhum elemento.           
        }
        tamanho--; //Decrementa o tamanho da lista;
    }
    //Buscar um valor na lista:
    bool buscar(int valor){
        No* atual = cabeca; //Mais uma vez criamos um nó temporário para armazenar o valor da cabeça.
        while(atual != nullptr){//Enquanto esse nó temporário for diferente de nulo, ele vai procurar o elemento.
            if(atual->data = valor){//Verifica se o valor buscado está no nó atual;
                return true; //Se sim, retorna true, o valor foi achado.
            }
            atual = atual->proximo;//Caso não, ele passa para o próximo.
        }
        return false;//Se sair do while significa que pecorreu a lista toda e não achou, retorna falso.

    }

        
};