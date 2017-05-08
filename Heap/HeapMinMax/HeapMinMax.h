#ifndef HEAPMINMAX
#define HEAPMINMAX

#include <cmath>

#define MIN 0
#define MAX 1

class HeapMinMax {
    public:
        int tamHeap,
            tamArray,
            *dado,
            *prioridade;

        HeapMinMax(int);
        ~HeapMinMax();

        bool vazia();
        bool cheia();

        int nivelHeap(int);
        int min_max(int);

        void troca(int,int);
        void shiftUP(int);
        void shiftDOWN(int);

        void inserir(int, int);
        void excluirMin();
        void excluirMax();

        void imprimir();
};

HeapMinMax::HeapMinMax(int tam) {
    tamHeap = 0;
    tamArray = tam;
    dado = new int[tamArray+1];
    prioridade = new int[tamArray+1];
}
HeapMinMax::~HeapMinMax() {
    delete dado;
    delete prioridade;
}

bool HeapMinMax::vazia() {
    return tamHeap == 0;
}
bool HeapMinMax::cheia() {
    return tamHeap == tamArray;
}

int HeapMinMax::nivelHeap(int filho) {
    int nivel = 0;

    while(true)
        if(filho <= pow(2,nivel+1)-1)
            return nivel;
        else
            nivel++;
}
int HeapMinMax::min_max(int nivel) {
    return nivel%2;
}

void HeapMinMax::troca(int filho, int pai_avo) {
    int tempDado = dado[filho],
        tempPrioridade = prioridade[filho];

    dado[filho] = dado[pai_avo];
    prioridade[filho] = prioridade[pai_avo];

    dado[pai_avo] = tempDado;
    prioridade[pai_avo] = tempPrioridade;
}
void HeapMinMax::shiftUP(int filho) {
    int pai = filho/2;

    if(pai >= 1) {
        int nivel = min_max(nivelHeap(filho));

        if(nivel == MIN) {
            if(prioridade[filho] > prioridade[pai]) {
                troca(filho,pai);
                shiftUP(pai);
            } else {
                int avo = pai/2;

                if(avo >= 1)
                    if(prioridade[filho] < prioridade[avo]) {
                        troca(filho,avo);
                        shiftUP(avo);
                    }
            }
        }
        if(nivel == MAX) {
            if(prioridade[filho] < prioridade[pai]) {
                troca(filho,pai);
                shiftUP(pai);
            } else {
                int avo = pai/2;

                if(avo >= 1)
                    if(prioridade[filho] > prioridade[avo]) {
                        troca(filho,avo);
                        shiftUP(avo);
                    }
            }
        }
    }
}
void HeapMinMax::shiftDOWN(int avo) {
    if(tamHeap > 1) {
        int nivel = nivelHeap(avo),
            netoMin = pow(2,nivel+2),
            netoMax = pow(2,nivel+3)-1,
            neto = netoMin;

        nivel = min_max(nivel);

        if(tamHeap >= netoMin) {
            if(tamHeap < netoMax)
                netoMax = tamHeap;
            for(int i=netoMin+1; i<=netoMax; i++) {
                if(nivel == MIN)
                    if(prioridade[i] < prioridade[neto])
                        neto = i;
                if(nivel == MAX)
                    if(prioridade[i] > prioridade[neto])
                        neto = i;
            }

            if(nivel == MIN)
                if(prioridade[avo] > prioridade[neto]) {
                    troca(avo,neto);
                    shiftDOWN(neto);
                }
            if(nivel == MAX)
                if(prioridade[avo] < prioridade[neto]) {
                    troca(avo,neto);
                    shiftDOWN(neto);
                }
        } else {
            int filhoE = avo*2,
                filhoD = avo*2+1;

            if(filhoE <= tamHeap) {
                int filho = filhoE;

                if(filhoD <= tamHeap) {
                    if(nivel == MIN)
                        filho = (prioridade[filhoE] <= prioridade[filhoD])? filhoE: filhoD;
                    if(nivel == MAX)
                        filho = (prioridade[filhoE] >= prioridade[filhoD])? filhoE: filhoD;
                }
                if(nivel == MIN)
                    if(prioridade[filho] < prioridade[avo]) {
                        troca(filho,avo);
                        shiftDOWN(filho);
                    }
                if(nivel == MAX)
                    if(prioridade[filho] > prioridade[avo]) {
                        troca(filho,avo);
                        shiftDOWN(filho);
                    }
            }
        }
    }
}

void HeapMinMax::inserir(int d, int p) {
    if(!cheia()) {
        tamHeap++;
        dado[tamHeap] = d;
        prioridade[tamHeap] = p;

        shiftUP(tamHeap);
    }
}
void HeapMinMax::excluirMin() {
    if(!vazia()) {
        dado[1] = dado[tamHeap];
        prioridade[1] = prioridade[tamHeap];
        tamHeap--;

        shiftDOWN(1);
    }
}
void HeapMinMax::excluirMax() {
    if(!vazia()) {
        int maior = 1;

        if(tamHeap >= 2) {
            maior = 2;
            if(tamHeap >= 3)
                maior = (prioridade[2] >= prioridade[3])?2 :3;
            dado[maior] = dado[tamHeap];
            prioridade[maior] = prioridade[tamHeap];
        }
        tamHeap--;

        shiftDOWN(maior);
    }
}

void HeapMinMax::imprimir() {
    cout << "\n[ ";
    for(int i=1; i<=tamHeap; i++) {
        cout << "(" << dado[i] << "," << prioridade[i] << ")";
        if(i<tamHeap)
            cout << ", ";
    }
    cout << " ]\n";
}

#endif
