#include <iostream>
#include <cstdlib>
using namespace std;

#include "HeapMin.h"

#define INSERIR 1
#define EXCLUIR 2
#define EXIT 0

int main() {
    system("TITLE Heap Min");

    HeapMin heap;

    while(true) {
        heap.imprimir();
        int comando;

        cout << endl << "1.Inserir";
        if(!heap.vazia())
            cout << endl << "2.Excluir";
        cout << endl << "0.Exit"
             << endl << ": ";
        cin >> comando;
        switch(comando) {
            case INSERIR:
                int dado, prioridade;

                cout << endl << "Digite um numero inteiro"
                     << endl << ": ";
                cin >> dado;
                cout << endl << "Digite a prioridade"
                     << endl << ": ";
                cin >> prioridade;
                heap.inserir(dado,prioridade);
            break;
            case EXCLUIR:
                heap.excluir();
            break;
            case EXIT:
                exit(0);
            break;
            default:
                cout << endl << "Erro";
                exit(-1);
        }
        system("CLS");
    }
    return 0;
}
