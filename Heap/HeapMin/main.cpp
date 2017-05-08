#include <iostream>
#include <cstdlib>
using namespace std;

#include "HeapMin.h"

#define INSERIR 1
#define EXCLUIR 2
#define EXIT 0

int main() {
    cout<< "\t\tHeap Min"<<endl;

    int tamHeap;

    cout << "Tamanho da Heap: ";
    cin >> tamHeap;

    HeapMin heap(tamHeap);

    /**Teste**/
    int p[13] = {10,32,4,56,3,11,21,9,43,64,9,11,21};
    bool a = true;
    /**Teste**/

    while(true) {
        /**Teste**/
        if(a) {
            for(int i=0; i<13; i++)
                heap.inserir(1,p[i]);
            a = false;
        }
        /**Teste**/

        system("clear");
        cout << "Tamanho do Array: " << heap.tamArray << endl
             << "Tamanho da Heap: " << heap.tamHeap << endl;

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
    }
    return 0;
}
