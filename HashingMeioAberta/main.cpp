#include <iostream>
using namespace std;

#include <cstdlib>
#include <iomanip>

#include "Lista.h"
#include "HashingMeioAberta.h"

int main() {
    cout<< "\t\tHASHING MEIO ABERTA"<<endl;

    int tam, carga;
    cout << "Tamanho da Hashing: "; cin >> tam;
    cout << "\nFator maximo de carga: "; cin >> carga;

    HashingMeioAberta hashing(tam,carga);

    while(true) {
        system("clear");

        hashing.calculoFC();
        hashing.calculoFB();
        cout << "Tamanho da Hashing = " << hashing.getTH() << endl
             << "\nFator de Carga = " << hashing.getFC() << endl
             << "\nFator de Balanceamento = " << setiosflags( ios::fixed ) << setprecision(2) << hashing.getFB() << "%";
        hashing.exibir();

        int comando = 0, valor;
        if(hashing.vazia())
            cout << "\n1 - Inserir\n0 - Sair\n: ";
        else
            cout << "\n1 - Inserir\n2 - Deletar\n0 - Sair\n: ";
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
