#ifndef OPENHASHING_H
#define OPENHASHING_H

#include <iostream>
using std::cout;

#include "Lista.h"

class OpenHashing {
    Lista *Hashing;
    int TH, fatorCarga;
    double fatorBalanceamento;

    public:
        OpenHashing(int);
        ~OpenHashing();

        bool vazia();
        int getTH();
        void calculoFC();
        int getFC();
        void calculoFB();
        double getFB();
        void inserir(int);
        void deletar(int);
        void exibir();
};

OpenHashing::OpenHashing(int tamHashing) {
    TH = tamHashing;
    fatorBalanceamento = fatorCarga = 0;
    Hashing = new Lista[TH];
}
OpenHashing::~OpenHashing() {
    for(int i=0; i<TH; i++)
        while(!Hashing[i].vazia())
            Hashing[i].deletar();
}

bool OpenHashing::vazia() {
    bool vazia = true;
    for(int i=0; i<TH; i++)
        if(!Hashing[i].vazia())
            vazia = false;
    return vazia;
}
int OpenHashing::getTH() {
    return TH;
}
void OpenHashing::calculoFC() {
    int FC = 0;
    for(int i=0; i<TH; i++)
        FC = (Hashing[i].tamLista() > FC) ? Hashing[i].tamLista() : FC;
    fatorCarga = FC;
}
int OpenHashing::getFC() {
    return fatorCarga;
}
void OpenHashing::calculoFB() {
    int somatorio = 0;
    for(int i=0; i<TH; i++)
        somatorio += Hashing[i].tamLista();
    fatorBalanceamento = (fatorCarga != 0) ? (double)100*somatorio/(TH*fatorCarga) : 0;
}
double OpenHashing::getFB() {
    return fatorBalanceamento;
}
void OpenHashing::inserir(int valor) {
    int indice = valor%TH;
    Hashing[indice].inserir(valor);
}
void OpenHashing::deletar(int valor) {
    if(!vazia()) {
        int indice = valor%TH;
        Hashing[indice].deletar(valor);
    }
}
void OpenHashing::exibir() {
    cout << "\n\nHashing: { ";
    for(int i=0; i<TH; i++) {
        Hashing[i].exibir();
        if(i < TH-1)
            cout << ", ";
    }
    cout << " }\n";
}

#endif
