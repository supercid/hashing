#ifndef HEAPMIN
#define HEAPMIN

class HeapMin {
    public:
        int tamHeap,
            tamArray,
            *dados,
            *prioridade;

        HeapMin(int);
        ~HeapMin();

        bool vazia();
        bool cheia();

        void troca(int,int);
        void shiftUP(int);
        void shiftDOWN(int);

        void inserir(int, int);
        void excluir();

        void imprimir();
};

HeapMin::HeapMin(int tam) {
    tamHeap = 0;
    tamArray = tam;
    dados = new int[tamArray+1];
    prioridade = new int[tamArray+1];
}
HeapMin::~HeapMin() {
    delete dados;
    delete prioridade;
}

bool HeapMin::vazia() {
    return tamHeap == 0;
}
bool HeapMin::cheia() {
    return tamHeap == tamArray;
}

void HeapMin::troca(int filho, int pai) {
    int tempDado = dados[filho],
        tempPrioridade = prioridade[filho];

    dados[filho] = dados[pai];
    prioridade[filho] = prioridade[pai];

    dados[pai] = tempDado;
    prioridade[pai] = tempPrioridade;
}
void HeapMin::shiftUP(int filho) {
    int pai = filho/2;

    if(pai >= 1)
        if(prioridade[filho] < prioridade[pai]) {
            troca(filho,pai);
            shiftUP(pai);
        }
}
void HeapMin::shiftDOWN(int pai) {
    if(tamHeap > 1) {
        int filhoE = pai*2,
            filhoD = pai*2+1,
            filhoMenor;

        if(filhoE <= tamHeap) {
            filhoMenor = filhoE;
            if(filhoD <= tamHeap)
                filhoMenor = (prioridade[filhoE] <= prioridade[filhoD])? filhoE: filhoD;

            if(prioridade[filhoMenor] < prioridade[pai]) {
                troca(filhoMenor,pai);
                shiftDOWN(filhoMenor);
            }
        }
    }
}

void HeapMin::inserir(int d, int p) {
    if(!cheia()) {
        tamHeap++;
        dados[tamHeap] = d;
        prioridade[tamHeap] = p;

        shiftUP(tamHeap);
    }
}
void HeapMin::excluir() {
    if(!vazia()) {
        dados[1] = dados[tamHeap];
        prioridade[1] = prioridade[tamHeap];
        tamHeap--;

        shiftDOWN(1);
    }
}

void HeapMin::imprimir() {
    cout << "\n[ ";
    for(int i=1; i<=tamHeap; i++) {
        cout << "(" << dados[i] << "," << prioridade[i] << ")";
        if(i<tamHeap)
            cout << ", ";
    }
    cout << " ]\n";
}

#endif
