#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


#define LINEAR 1
#define QUADRATICO 2
#define DUPLO_HASHING 3


class ClosedHashing {
    int *Hashing;
    int TH;
    int tentativa;

    public:
        ClosedHashing(int,int);
        ~ClosedHashing();

        bool vazia();
        int getTH();
        void getTentativa();
        void inserir(int);
        void deletar(int);
        void exibir();
};

ClosedHashing::ClosedHashing(int tam, int tent) {
    TH = tam;
    tentativa = tent;
    Hashing = new int[tam];

    for(int i=0; i<tam; i++){
        Hashing[i] = NULL;
    }
}
ClosedHashing::~ClosedHashing() {
    for(int i=0; i<TH; i++)
        Hashing[i] = NULL;
}

bool ClosedHashing::vazia() {
    bool vazia = true;
    for(int i=0; i<TH; i++)
        if(Hashing[i] != NULL)
            vazia = false;
    return vazia;
}
int ClosedHashing::getTH() {
    return TH;
}
void ClosedHashing::getTentativa() {
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
int proxPrimo(int th) {
    for(int i=th-1; i>=1; i--) {
        if(primo(i))
            return i;
    }
    return 2;
}
void ClosedHashing::inserir(int valor) {
    int indice, th = TH;
    for(int i=0; i<TH; i++) {
        if(tentativa == LINEAR)
            indice = (valor + i)%TH;
        else if(tentativa == QUADRATICO)
            indice = (valor + i*i)%TH;
        else if(tentativa == DUPLO_HASHING) {
            indice = valor%th;
            th = proxPrimo(th);
        }
        if(Hashing[indice] == NULL) {
            Hashing[indice] = valor;
            return;
        }
    }
    cout << "\nEsse numero nao pode ser inserido";
    system("pause>NULL");


}


void ClosedHashing::deletar(int valor) {
    if(!vazia()) {
        int indice, th = TH;
        for(int i=0; i<TH; i++) {
            if(tentativa == LINEAR)
                indice = (valor + i)%TH;
            else if(tentativa == QUADRATICO)
                indice = (valor + i*i)%TH;
            else if(tentativa == DUPLO_HASHING) {
                indice = valor%th;
                th = proxPrimo(th);
            }
            if(Hashing[indice] == valor) {
                Hashing[indice] = NULL;
                cout << "Este número não está na hashing"<<endl;
                return;
            }
        }
    }
}

void ClosedHashing::exibir() {
    cout << "\n\t\tHashing:\n { [ ";
    for(int i=0; i<TH; i++) { 
        cout << Hashing[i];
        if(i < TH-1)
            cout << ", ";
    }
    cout << " ] }\n";
}
