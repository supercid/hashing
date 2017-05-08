#ifndef REHASHING_H
#define REHASHING_H

#include <iostream>
#include <cstdlib>
#include <cmath>
using std::cout;
using std::endl;

#define LINEAR 1
#define QUADRATICO 2
#define DUPLO_HASHING 3
#define MUITO_CHEIA 0.70

class ReHashing {
    int *Hashing;
    int TH;
    int tentativa;
    int FB;

    public:
        ReHashing(int,int);
        ~ReHashing();

        bool vazia();

        int getTH();
        void getTentativa();

        void inserir(int);
        void deletar(int);
        void refazHashing();

        void exibir();
};

#endif

ReHashing::ReHashing(int tam, int tent) {
    TH = tam;
    FB = 0;
    tentativa = tent;
    Hashing = new int[tam];
    for(int i=0; i<tam; i++)
        Hashing[i] = 0;
}
ReHashing::~ReHashing() {
    for(int i=0; i<TH; i++)
        Hashing[i] = 0;
}

bool ReHashing::vazia() {
    bool vazia = true;
    for(int i=0; i<TH; i++)
        if(Hashing[i] != 0)
            vazia = false;
    return vazia;
}

int ReHashing::getTH() {
    return TH;
}
void ReHashing::getTentativa() {
    if(tentativa == LINEAR)
        cout << "Linear" << endl;
    else if(tentativa == QUADRATICO)
        cout << "Quadratico" << endl;
    else if(tentativa == DUPLO_HASHING)
        cout << "Duplo Hashing" << endl;
}

bool primo(int valor) {
    int j=1;
    if(valor == 1)
        return false;
    for(int i=1; i<=sqrt(valor); i++)
        if(valor%i == 0)
            j++;
    if(j>2 || j==1)
        return false;
    else
        return true;
}
int primoProx(int th) {
    for(int i=th+1; ; i++) {
        if(primo(i))
            return i;
    }
}
int primoAnte(int th) {
    for(int i=th-1; i>=1; i--) {
        if(primo(i))
            return i;
    }
    return 2;
    /*if(valor == 1)
        return 1;
    else {
        for(int i=2; i<valor; i++) {
            if((valor%i) == 0) {
                valor = proxPrimo(--valor);
                break;
            }
        }
        return valor;
    }*/
}

void ReHashing::inserir(int valor) {
    int indice, th = TH;

    for(int i=0; i<TH; i++) {
        if(tentativa == LINEAR)
            indice = (valor + i)%TH;
        else if(tentativa == QUADRATICO)
            indice = (valor + i*i)%TH;
        else if(tentativa == DUPLO_HASHING) {
            indice = valor%th;
            th = primoAnte(th);
        }
        if(Hashing[indice] == 0) {
            Hashing[indice] = valor;
            if((float)(++FB)/TH > MUITO_CHEIA) {
                cout << "\nHashing muito cheia, fazer ReHashing";
                system("pause>NULL");
                refazHashing();
            }
            return;
        }
    }
    cout << "\nEsse numero nao pode ser inserido, fazer ReHashing";
    system("pause>NULL");
    refazHashing();
}
void ReHashing::deletar(int valor) {
    if(!vazia()) {
        int indice, th = TH;
        for(int i=0; i<TH; i++) {
            if(tentativa == LINEAR)
                indice = (valor + i)%TH;
            else if(tentativa == QUADRATICO)
                indice = (valor + i*i)%TH;
            else if(tentativa == DUPLO_HASHING) {
                indice = valor%th;
                th = primoAnte(th);
            }
            if(Hashing[indice] == valor) {
                Hashing[indice] = 0;
                FB--;
                return;
            }
        }
    }
}

int primoMaisProx(int th) {
    int primo_ante = primoAnte(th),
        primo_prox = primoProx(th);

    return (th-primo_ante >= primo_prox-th)? primo_prox : primo_ante;
}
void ReHashing::refazHashing() {
    FB = 0;
    int *temp = new int[TH], th = TH;

    for(int i=0; i<th; i++)
        temp[i] = Hashing[i];

    TH = primoMaisProx(2*TH);
    Hashing = new int[TH];
    for(int i=0; i<TH; i++)
        Hashing[i] = 0;

    for(int i=0; i<th; i++)
        inserir(temp[i]);
}

void ReHashing::exibir() {
    cout << "\nHashing: [ ";
    for(int i=0; i<TH; i++) {
        cout << Hashing[i];
        if(i < TH-1)
            cout << ", ";
    }
    cout << " ]\n";
}
