#include <iostream>
#include <cstdlib>
using namespace std;

#include "HeapMinMax.h"

#define INSERIR 1
#define EXCLUIR_MIN 2
#define EXCLUIR_MAX 3
#define EXIT 0

int main() {
    cout<<"\t\t Heap Min Max"<<endl;

    int tamHeap;

    cout << "Tamanho da Heap: ";
    cin >> tamHeap;

    HeapMinMax heap(tamHeap);

    /**Teste**/
   //int p[16] = {13,2,4,9,21,31,6,19,32,41,17,28,3,29,1,32};
   int p[11] = {3, 10, 21, 43, 56, 32, 11, 3, 4, 9, 64};
   bool a = true;
    /**Teste**/

    while(true) {
        /**Teste**/
        if(a) {
            for(int i=0; i<16; i++)
                heap.inserir(1,p[i]);
            a = false;
        }
        /**Teste**/

        system("clear");
        cout << "Tamanho do Array: " << heap.tamArray << endl
             << "Tamanho da Heap: " << heap.tamHeap << endl;

        heap.imprimir();
        int comando;

        L1:
        cout << endl << "1.Inserir";
        if(!heap.vazia())
            cout << endl << "2.Excluir Min"
        << endl << "3.Excluir Max";
        cout << endl << "0.Exit"
        << endl << ": ";
        cin >> comando;
        switch(comando) {
            case INSERIR:
            int dado, prioridade;

            cout << endl << "Digite um numero inteiro" << endl << ": ";
            cin >> dado;

            cout << endl << "Digite a prioridade" << endl << ": ";
            cin >> prioridade;
            
            heap.inserir(dado,prioridade);
            break;
            case EXCLUIR_MIN:
                heap.excluirMin();
                break;
            case EXCLUIR_MAX:
                heap.excluirMax();
                break;
            case EXIT:
                system("clear");
                exit(0);
                break;
            default:
                cout << endl << "Erro, opção inválida";
                system("clear");
                goto L1;
                exit(-1);
        }
    }
    return 0;
}
