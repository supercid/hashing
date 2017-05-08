#ifndef HEAPMIN
#define HEAPMIN

class Bloco {
    public:
        int dado,
            prioridade,
            indice;
        Bloco *prox;

        Bloco(int, int, int);
};

Bloco::Bloco(int d, int p, int i) {
    dado = d;
    prioridade = p;
    indice = i;
    prox = NULL;
}

class HeapMin {
    public:
        Bloco *inicio,
              *final;

        HeapMin();
        ~HeapMin();

        bool vazia();
        void inserir(int, int);
        void shiftUP(Bloco *);
        void excluir();

        void imprimir();
};

HeapMin::HeapMin() {
    inicio = final = NULL;
}
HeapMin::~HeapMin() {
    while(!vazia())
        excluir();
}

bool HeapMin::vazia() {
    return inicio == NULL;
}
void HeapMin::inserir(int d, int p) {
    if(vazia())
        inicio = final = new Bloco(d,p,1);
    else {
        final->prox = new Bloco(d,p,final->indice+1);
        final = final->prox;

        shiftUP(final);
    }
}
void HeapMin::shiftUP(Bloco *filho) {
    Bloco *pai = inicio, *aux = NULL;
    int indicePai = filho->indice/2;

    while(pai->indice != indicePai)
        pai = pai->prox;

    cout << "pai=" << pai->dado << "," << pai->prioridade;
    system("pause>0");

    if(pai->prioridade > filho->prioridade) {
        aux = pai;
        pai = filho;
        filho = aux;
    }
}
void HeapMin::excluir() {
    if(!vazia()) {
        Bloco *aux = inicio;

        if(inicio == final)
            final = NULL;
        inicio = inicio->prox;
        delete aux;
    }
}

void HeapMin::imprimir() {
    cout << "[ ";
    if(!vazia()) {
        Bloco *aux = inicio;

        while(aux != NULL) {
            cout << "[" << aux->indice << "]( " << aux->dado << "," << aux->prioridade << " )";
            if(aux->prox != NULL)
                cout << ", ";
            aux = aux->prox;
        }
    }
    cout << " ]\n";
}

#endif
