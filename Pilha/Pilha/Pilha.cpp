#include <iostream>
#include <cstdlib> // Necessário para usar malloc e free de forma padrão

using namespace std;

// Definição do tipo NO (Estrutura do Nó)
struct NO {
    int valor;
    NO* prox;
};

// Ponteiro global para o topo da pilha
NO* topo = NULL;

// Headers (Protótipos das funções)
void menu();
void inicializar();
void push();
void pop();
void exibir();

int main() {
    menu();
    return 0;
}

void menu() {
    int op = 0;
    while (op != 5) {
        system("cls"); // Somente no Windows
        cout << "=== Menu Pilha ===";
        cout << endl << endl;
        cout << "1 - Inicializar Pilha \n";
        cout << "2 - Inserir elemento (Push) \n";
        cout << "3 - Remover elemento (Pop) \n";
        cout << "4 - Exibir Pilha (Extra) \n";
        cout << "5 - Sair \n";
        cout << "\nOpcao: ";
        cin >> op;

        switch (op) {
        case 1: inicializar(); break;
        case 2: push(); break;
        case 3: pop(); break;
        case 4: exibir(); break;
        case 5: return;
        default: cout << "Opcao invalida!\n"; break;
        }
        system("pause"); // Somente no Windows
    }
}

// Inicializa ou limpa a pilha liberando a memória
void inicializar() {
    NO* aux = topo;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir); // Libera a memória de cada nó
    }
    topo = NULL;
    cout << "Pilha inicializada com sucesso!\n";
}

// CORRIGIDO: Removido o ';' que estava logo após 'void push()'
void push() {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        cout << "Erro: Memoria insuficiente!\n";
        return;
    }
    cout << "Digite o elemento: ";
    cin >> novo->valor;

    novo->prox = topo;
    topo = novo;

    cout << "Elemento " << novo->valor << " inserido no topo da pilha.\n";
}

// Remove o elemento que está no topo da pilha (Pop)
void pop() {
    if (topo == NULL) {
        cout << "Pilha vazia! Nao ha elementos para remover.\n";
        return;
    }
    NO* aux = topo;
    cout << "Elemento removido: " << aux->valor << "\n";
    topo = topo->prox;
    free(aux);
}

// Desafio Extra: Exibe todos os elementos da pilha do topo até a base
void exibir() {
    if (topo == NULL) {
        cout << "Pilha vazia!\n";
        return; // CORRIGIDO: Chaves adicionadas implicitamente para o return só rodar se topo for NULL
    }

    cout << "Conteudo da pilha (Topo -> Base):\n";
    NO* aux = topo;
    while (aux != NULL) {
        cout << aux->valor;
        if (aux->prox != NULL) {
            cout << " -> ";
        }
        aux = aux->prox;
    }
    cout << "\n";
}
