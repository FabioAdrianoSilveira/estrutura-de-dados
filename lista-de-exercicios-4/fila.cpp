#include <iostream>
using namespace std;

// Estrutura:
struct No
{
    int info;
    No *prox;
};

struct Fila
{
    No *inicio;
    No *fim;
};

Fila *cria()
{
    Fila *f = new Fila;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere(Fila *f, int valor)
{
    No *novo = new No;
    novo->info = valor;
    novo->prox = NULL;

    if (f->fim != NULL)
    {
        f->fim->prox = novo;
    }
    else
    {
        f->inicio = novo;
    }
    f->fim = novo;
}

int remove(Fila *f)
{
    if (f->inicio == NULL)
    {
        return -1;
    }

    No *temp = f->inicio;
    int valor = temp->info;
    f->inicio = temp->prox;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    delete temp;
    return valor;
}

bool vazia(Fila *f)
{
    return f->inicio == NULL;
}

void imprime(Fila *f)
{
    cout << "Fila: ";
    No *aux = f->inicio;
    while (aux != NULL)
    {
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}

// Função:
void excluiNegativos(Fila *f)
{
    Fila *temp = cria();

    while (!vazia(f))
    {
        int valor = remove(f);
        if (valor >= 0)
        {
            insere(temp, valor);
        }
    }

    f->inicio = temp->inicio;
    f->fim = temp->fim;
    delete temp;
}

// Exemplo:
int main()
{
    Fila *f = cria();

    insere(f, 10);
    insere(f, -5);
    insere(f, 20);
    insere(f, -3);
    insere(f, 30);
    insere(f, -8);
    insere(f, 40);

    cout << "Antes de excluir negativos:" << endl;
    imprime(f);

    excluiNegativos(f);

    cout << "Depois de excluir negativos:" << endl;
    imprime(f);

    return 0;
}