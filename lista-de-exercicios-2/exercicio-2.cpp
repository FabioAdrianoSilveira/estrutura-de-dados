#include <iostream>
using namespace std;

// Estrutura:
struct No
{
    int info;
    No *prox;
};

struct Lista
{
    No *inicio;
};

Lista *cria()
{
    Lista *l = new Lista;
    l->inicio = NULL;
    return l;
}

void insere(Lista *l, int valor)
{
    No *novo = new No;
    novo->info = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
}

// Função:
int igual(Lista *l1, Lista *l2)
{
    No *aux1 = l1->inicio;
    No *aux2 = l2->inicio;

    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->info != aux2->info)
        {
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    if (aux1 == NULL && aux2 == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Exemplo:
int main()
{
    Lista *l1 = cria();
    Lista *l2 = cria();

    insere(l1, 30);
    insere(l1, 20);
    insere(l1, 10);

    insere(l2, 30);
    insere(l2, 20);
    insere(l2, 10);

    if (igual(l1, l2))
    {
        cout << "Listas iguais" << endl;
    }
    else
    {
        cout << "Listas diferentes" << endl;
    }

    return 0;
}