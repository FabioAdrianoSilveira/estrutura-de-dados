#include <iostream>
#include <string>
using namespace std;

struct Produto
{
    string nome;
    int quantidade;
    double preco;
    Produto *prox;
};

Produto *Start()
{
    return nullptr;
}

Produto *AddProduto(Produto *p, string nome, int quantidade, double preco)
{
    Produto *atual = p;
    Produto *anterior = nullptr;

    while (atual != nullptr)
    {
        if (atual->nome == nome)
        {
            atual->quantidade += quantidade;
            atual->preco = preco;
            return p;
        }
        anterior = atual;
        atual = atual->prox;
    }
    Produto *novoProduto = new Produto;
    novoProduto->nome = nome;
    novoProduto->quantidade = quantidade;
    novoProduto->preco = preco;
    novoProduto->prox = nullptr;

    if (p == nullptr)
    {
        return novoProduto;
    }
    else
    {
        anterior->prox = novoProduto;
        return p;
    }
}

Produto *RemoveProduto(Produto *p, string nome)
{
    Produto *atual = p;
    Produto *anterior = nullptr;

    while (atual != nullptr && atual->nome != nome)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == nullptr)
    {
        return p;
    }

    if (anterior == nullptr)
    {
        p = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    delete atual;
    return p;
}

double *CalcValorTotal(Produto *p)
{
    double valorTotal = 0;
    Produto *atual = p;

    while (atual != nullptr)
    {
        valorTotal += atual->quantidade * atual->preco;
        atual = atual->prox;
    }

    return valorTotal;
}

void PrintEstoque(Produto *p)
{
    if (p == nullptr)
    {
        cout << "\n--- ESTOQUE VAZIO ---" << endl;
        return;
    }

    Produto *atual = p;
    while (atual != nullptr)
    {
        double valorTotalItem = *CalcValorTotal(atual);
        cout << "Nome: " << atual->nome << endl;
        cout << "Quantidade: " << atual->quantidade << endl;
        cout << "Preço: " << atual->preco << endl;
        cout << "Valor em estoque: " << valorTotalItem << endl
             << endl;
        atual = atual->prox;
    }
}

void LiberarEstoque(Produto *p)
{
    Produto *atual = p;
    while (atual != nullptr)
    {
        Produto *proximo = atual->prox;
        delete atual;
        atual = proximo;
    }
    cout << "\nMemoria do estoque liberada com sucesso." << endl;
}

int main()
{
    Produto *estoque = Start();
    int opcao;

    do
    {
        cout << "\n*** Menu ***" << endl;
        cout << "1. Adicionar/Atualizar Produto" << endl;
        cout << "2. Remover Produto" << endl;
        cout << "3. Listar Estoque Completo" << endl;
        cout << "4. Calcular Valor Total do Estoque" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";

        // Trata a entrada da opção
        if (!(cin >> opcao))
        {
            cout << "Entrada invalida. Por favor, digite um numero." << endl;
            main();
        }

        string nome;
        int quantidade;
        double preco;

        switch (opcao)
        {
        case 1:
            cout << "\n--- ADICIONAR PRODUTO ---" << endl;
            cout << "Nome do produto: ";
            getline(cin.ignore(), nome);
            cout << "Quantidade a adicionar: ";
            cin >> quantidade;
            cout << "Preco unitario (R$): ";
            cin >> preco;
            estoque = AddProduto(estoque, nome, quantidade, preco);
            break;

        case 2:
            cout << "\n--- REMOVER PRODUTO ---" << endl;
            cout << "Nome do produto a remover: ";
            getline(cin.ignore(), nome);
            estoque = RemoveProduto(estoque, nome);
            break;

        case 3:
            PrintEstoque(estoque);
            break;

        case 4:
        {
            double total = *CalcValorTotal(estoque);
            cout << "\nVALOR TOTAL DO ESTOQUE: R$" << total << endl;
        }
        break;

        case 5:
            cout << "\nEncerrando o programa..." << endl;
            LiberarEstoque(estoque);
            exit(1);

        default:
            cout << "Opcao invalida. Por favor, escolha um numero entre 1 e 5." << endl;
            main();
        }
    } while (opcao != 5);
    return 0;
}