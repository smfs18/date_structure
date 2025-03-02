typedef int tipoitem;
const int max_itens = 100;

class queue{
        private:
        int primeiro, ultimo;
        tipoitem* estrutura;
        
        public:
        queue();
        ~queue();
        bool isempty();
        bool isfull();
        void enqueue(tipoitem item);
        tipoitem dequeue();
        void print();
};