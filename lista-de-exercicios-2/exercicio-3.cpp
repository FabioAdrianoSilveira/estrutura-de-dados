#include <iostream>

using namespace std;

struct No
{
    int valor;
    No *prox;
};

No *criaLista()
{
    return nullptr;
}

No *InserirElemento(No *v, int i)
{
    No *novoNo = new No;
    novoNo->valor = i;
    novoNo->prox = v;

    return novoNo;
}

No *copia(No *l)
{
    if (l == nullptr)
        return nullptr;
    No *nova = nullptr;
    No *fim = nullptr;
    while (l != nullptr)
    {
        No *novo = new No{l->valor, nullptr};
        if (nova == nullptr)
        {
            nova = novo;
        }
        else
        {
            fim->prox = novo;
        }
        fim = novo;
        l = l->prox;
    }
    return nova;
}

void imprimeLista(No *v)
{
    No *novoNo;
    for (novoNo = v; novoNo != nullptr; novoNo = novoNo->prox)
    {
        cout << novoNo->valor << " ";
    }
    cout << endl;
}

int main()
{
    No *listaOriginal = criaLista();
    listaOriginal = InserirElemento(listaOriginal, 10);
    listaOriginal = InserirElemento(listaOriginal, 20);
    listaOriginal = InserirElemento(listaOriginal, 30);
    listaOriginal = InserirElemento(listaOriginal, 40);
    cout << "Lista original: ";
    imprimeLista(listaOriginal);
    No *listaCopia = copia(listaOriginal);
    cout << "Lista copiada: ";
    imprimeLista(listaCopia);
    return 0;
}