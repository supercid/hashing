#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;

class Bloco {
    public:
        int dado;
        Bloco *prox;

        Bloco(int);
};

class Lista {
    Bloco *inicio, *final;

    public:
        Lista();
        ~Lista();

        bool vazia();
        int tamLista();
        void inserir(int);
        void deletar();
        void deletar(int);
        void exibir();
};

Bloco::Bloco(int valor) {
    dado = valor;
    prox = NULL;
}

Lista::Lista() {
    inicio = final = NULL;
}
Lista::~Lista() {
    while(!vazia())
        deletar();
}

bool Lista::vazia() {
    return inicio == NULL;
}
int Lista::tamLista() {
    if(vazia())
        return 0;
    else {
        int tam = 0;
        Bloco *aux = inicio;
        while(aux != NULL) {
            aux = aux->prox;
            tam++;
        }
        return tam;
    }
}
void Lista::inserir(int valor) {
    if(vazia())
        inicio = final = new Bloco(valor);
    else {
        final->prox = new Bloco(valor);
        final = final->prox;
    }
}
void Lista::deletar() {
    if(!vazia()) {
        Bloco *aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }
}
void Lista::deletar(int dado) {
    if(!vazia()) {
        Bloco *ante = NULL;
        Bloco *aux = inicio;
        while(aux != NULL && aux->dado != dado) {
            ante = aux;
            aux = aux->prox;
        }
        if(aux != NULL) {
            if(aux == final)
                final = ante;
            if(aux == inicio)
                inicio = inicio->prox;
            else
                ante->prox = aux->prox;
            delete aux;
        }
    }
}
void Lista::exibir() {
    cout << "[ ";
    if(!vazia()) {
        Bloco *aux = inicio;
        while(aux != NULL) {
            cout << aux->dado;
            if(aux != final)
                cout << ", ";
            aux = aux->prox;
        }
    }
    cout << " ]";
}

#endif
