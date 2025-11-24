#include <iostream>
using namespace std;

struct Node
{
    Node *prox;
};

struct Nicho
{
    Node *prim;
    int qtdNodes;
    int capacidadeMaxima;
};

Nicho *start(int M)
{
    Nicho *n = new Nicho;
    n->prim = nullptr;
    n->qtdNodes = 0;
    n->capacidadeMaxima = M;

    return n;
}

bool insertNode(Nicho *n)
{
    if (n->qtdNodes == n->capacidadeMaxima)
    {
        return false;
    }

    Node *newNode = new Node;
    newNode->prox = n->prim;
    n->prim = newNode;
    n->qtdNodes++;

    return true;
}

bool removeNode(Nicho *n)
{
    if (n->qtdNodes == 0)
    {
        return false;
    }
    Node *aux = n->prim;
    n->prim = aux->prox;
    delete aux;
    aux = nullptr;
    n->qtdNodes--;

    return true;
}

void freeNicho(Nicho *n)
{
    Node *atual = n->prim;
    while (atual != nullptr)
    {
        Node *next = atual->prox;
        delete atual;
        atual = next;
    }
    n->prim == nullptr;
    n->qtdNodes = 0;
}

void showStatus(Nicho *n, int i)
{
    cout << "Nicho " << i + 1 << endl;
    cout << "Containers: " << n->qtdNodes;

    if (n->qtdNodes == 0)
    {
        cout << " (Vazio)";
    }
    else if (n->qtdNodes == n->capacidadeMaxima)
    {
        cout << " (Cheio)";
    }
    cout << endl;
}

void menu()
{
    cout << "\n--- Menu de Operações ---" << endl;
    cout << "1. Inserir contêiner (1 a 4)" << endl;
    cout << "2. Remover contêiner (1 a 4)" << endl;
    cout << "3. Exibir Status dos Nichos" << endl;
    cout << "4. Finalizar Programa" << endl;
    cout << "Escolha uma opção (1-4): ";
}

void insertIntoNicho(Nicho nicho[])
{
    int k;
    cout << "Digite qual em qual nicho será inserido o container: ";
    cin >> k;
    if (k < 1 || k > 4)
    {
        cout << "Erro! Selecione nicho de 1 a 4";
        main();
    }

    if (insertNode(&nicho[k - 1]))
    {
        cout << "OK: contêiner inserido em N" << k;
    }
    else
    {
        cout << "Erro: nicho N" << k << " cheio";
    }
}

void removeFromNicho(Nicho nicho[])
{
    int k;
    cout << "Digite de qual nicho será removido o container: ";
    cin >> k;
    if (k < 1 || k > 4)
    {
        cout << "Erro! Selecione nicho de 1 a 4";
        main();
    }

    if (removeNode(&nicho[k - 1]))
    {
        cout << "OK: contêiner removido de N" << k;
    }
    else
    {
        cout << "Erro: nicho N" << k << " vazio";
    }
}

int main()
{
    int MAXIMO;
    cout << "Digite a capacidade maxima dos nichos: ";
    cin >> MAXIMO;
    Nicho nicho[4];

    for (int i = 0; i < 4; i++)
    {
        nicho[i] = start(MAXIMO);
    }

    int opcao;
    bool continuar = true;

    while (continuar)
    {
        menu();
        cin >> opcao;
        if (opcao < 1 || opcao >> 4)
        {
            cout << "Erro! Escolha uma opcao de 1 a 4";
            main();
        }
        switch (opcao)
        {
        case 1: // Inserir
            insertIntoNicho(nicho);
            break;
        case 2: // Remover
            removeFromNicho(nicho);
            break;
        case 3:
        { // Exibir
            cout << "\n--- Status Resumido dos Nichos ---" << endl;
            for (int i = 0; i < 4; ++i)
            {
                showStatus(&nicho[i], i);
            }
            break;
        }
        case 4: // Finalizar
            cout << "Finalizando Programa. Liberando memória..." << endl;
            continuar = false;
            for (int i = 0; i < 4; ++i)
            {
                freeNicho(&nicho[i]);
            }
            cout << "Memória liberada com sucesso. Programa encerrado.";
            break;
        default:
            cout << "Erro: Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}