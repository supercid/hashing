#ifndef HEAPMAX
#define HEAPMAX

class HeapMax {
    public:
        int tamHeap,
            tamArray,
            *dados,
            *prioridade;

        HeapMax(int);
        ~HeapMax();

        bool vazia();
        bool cheia();

        void troca(int,int);
        void shiftUP(int);
        void shiftDOWN(int);

        void inserir(int, int);
        void excluir();

        void imprimir();
};

HeapMax::HeapMax(int tam) {
    tamHeap = 0;
    tamArray = tam;
    dados = new int[tamArray+1];
    prioridade = new int[tamArray+1];
}
HeapMax::~HeapMax() {
    delete dados;
    delete prioridade;
}

bool HeapMax::vazia() {
    return tamHeap == 0;
}
bool HeapMax::cheia() {
    return tamHeap == tamArray;
}

void HeapMax::troca(int filho, int pai) {
    int tempDado = dados[filho],
        tempPrioridade = prioridade[filho];

    dados[filho] = dados[pai];
    prioridade[filho] = prioridade[pai];

    dados[pai] = tempDado;
    prioridade[pai] = tempPrioridade;
}
void HeapMax::shiftUP(int filho) {
    int pai = filho/2;

    if(pai >= 1)
        if(prioridade[filho] > prioridade[pai]) {
            troca(filho,pai);
            shiftUP(pai);
        }
}
void HeapMax::shiftDOWN(int pai) {
    if(tamHeap > 1) {
        int filhoE = pai*2,
            filhoD = pai*2+1,
            filhoMaior;

        if(filhoE <= tamHeap) {
            filhoMaior = filhoE;
            if(filhoD <= tamHeap)
                filhoMaior = (prioridade[filhoE] >= prioridade[filhoD])? filhoE: filhoD;

            if(prioridade[filhoMaior] > prioridade[pai]) {
                troca(filhoMaior,pai);
                shiftDOWN(filhoMaior);
            }
        }
    }
}

void HeapMax::inserir(int d, int p) {
    if(!cheia()) {
        tamHeap++;
        dados[tamHeap] = d;
        prioridade[tamHeap] = p;

        shiftUP(tamHeap);
    }
}
void HeapMax::excluir() {
    if(!vazia()) {
        dados[1] = dados[tamHeap];
        prioridade[1] = prioridade[tamHeap];
        tamHeap--;

        shiftDOWN(1);
    }
}

void HeapMax::imprimir() {
    cout << "\n[ ";
    for(int i=1; i<=tamHeap; i++) {
        cout << "(" << dados[i] << "," << prioridade[i] << ")";
        if(i<tamHeap)
            cout << ", ";
    }
    cout << " ]\n";
}

#endif
