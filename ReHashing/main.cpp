#include <iostream>
#include <cstdlib>
using namespace std;

#include "ReHashing.h"

#define LINEAR 1
#define QUADRATICO 2
#define DUPLO_HASHING 3

int main() {

    int tam, tent;
    cout << "Tamanho da Hashing: "; cin >> tam;
    cout << "\nTentativas\n1-Linear\n2-Quadratica\n3-Duplo Hashing\n: "; cin >> tent;
    ReHashing hashing(tam,tent);

    while(true) {
        system("clear");

        cout << "Tamanho da Hashing = " << hashing.getTH() << endl
             << "\nTentativa: "; hashing.getTentativa();
        hashing.exibir();

        int comando = 0, valor;
        if(hashing.vazia())
            cout << "\n1-Inserir\n0-Exit\n: ";
        else
            cout << "\n1-Inserir\n2-Deletar\n0-Exit\n: ";
        cin >> comando;
        if(comando == 0)
            exit(-1);
        else if(comando == 1) {
            cout << "\nDigite um valor inteiro\n: "; cin >> valor;
            hashing.inserir(valor);
        } else if(comando == 2) {
            cout << "\nDigite um valor inteiro a ser deletado\n: "; cin >> valor;
            hashing.deletar(valor);
        }
    }
    return 0;
}
