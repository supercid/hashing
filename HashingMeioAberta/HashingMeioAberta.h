#ifndef HashingMeioAberta_H
#define HashingMeioAberta_H

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_HASH 60

#include "Lista.h"

class HashingMeioAberta {
    Lista *Hashing;
    int TH, fatorCarga, maxFCarga;
    double fatorBalanceamento;

    public:
        HashingMeioAberta(int,int);
        ~HashingMeioAberta();

        bool vazia();

        int getTH();
        void calculoFC();
        int getFC();
        void calculoFB();
        double getFB();

        void inserir(int);
        void deletar(int);
        void refazHashing();

        void exibir();
};

HashingMeioAberta::HashingMeioAberta(int tamHashing, int maxFC) {
    TH = tamHashing;
    maxFCarga = maxFC;
    fatorBalanceamento = fatorCarga;
    Hashing = new Lista[TH];
}
HashingMeioAberta::~HashingMeioAberta() {
    for(int i=0; i<TH; i++)
        while(!Hashing[i].vazia())
            Hashing[i].deletar();
}

bool HashingMeioAberta::vazia() {
    bool vazia = true;
    for(int i=0; i<TH; i++)
        if(!Hashing[i].vazia())
            vazia = false;
    return vazia;
}

int HashingMeioAberta::getTH() {
    return TH;
}
void HashingMeioAberta::calculoFC() {
    int FC = 0;
    for(int i=0; i<TH; i++)
        FC = (Hashing[i].tamLista() > FC) ? Hashing[i].tamLista() : FC;
    fatorCarga = FC;
}
int HashingMeioAberta::getFC() {
    return fatorCarga;
}
void HashingMeioAberta::calculoFB() {
    int somatorio = 0;
    for(int i=0; i<TH; i++)
        somatorio += Hashing[i].tamLista();
    fatorBalanceamento = (fatorCarga != 0) ? (double)100*somatorio/(TH*fatorCarga) : 0;
}
double HashingMeioAberta::getFB() {
    return fatorBalanceamento;
}

void HashingMeioAberta::inserir(int valor) {
    int indice;
    for(int i=0; i<TH; i++) {
        indice = (valor + i*i)%TH;

        if(!Hashing[indice].buscar(valor)) {
            
            Hashing[indice].inserir(valor);

            calculoFC();
            calculoFB();
            if(fatorBalanceamento > MAX_HASH) {
                cout << "Hashing muito cheia, fazer ReHashing"<<endl;
                refazHashing();
            }
            if(fatorCarga > maxFCarga) {
                cout << "Hashing excedeu o maximo do fator de carga, fazer ReHashing"<<endl;
                refazHashing();
            }
            return;
        }
    }
    cout << "Esse numero nao pode ser inserido, fazer ReHashing"<<endl;
    system("pause>NULL");
    refazHashing();
}

void HashingMeioAberta::deletar(int valor) {
    if(!vazia()) {
        int indice = valor%TH;
        Hashing[indice].deletar(valor);
    }
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
}
int primoMaisProx(int th) {
    int primo_ante = primoAnte(th),
        primo_prox = primoProx(th);

    return (th-primo_ante >= primo_prox-th)? primo_prox : primo_ante;
}
void HashingMeioAberta::refazHashing() {
    Lista *temp = new Lista;
    int th = TH;

    for(int i=0; i<TH; i++)
        while(!Hashing[i].vazia())
            temp->inserir(Hashing[i].deletar());

    TH = primoMaisProx(2*TH);
    Hashing = new Lista[TH];
    fatorBalanceamento = fatorCarga = 0;

    for(int i=0; i<TH; i++)
        while(!temp->vazia())
            inserir(temp->deletar());
}

void HashingMeioAberta::exibir() {
    cout << "\n\nHashing:\n{ ";
    for(int i=0; i<TH; i++) {
        Hashing[i].exibir();
        if(i < TH-1)
            cout << ", ";
    }
    cout << " }\n";
}

#endif
