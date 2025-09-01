#include <iostream>
#include "cadastro.h"

bool cadastrarPessoa(Pessoa vetor[], int tamanho, string *nome, int idade, Sexo sexo, int *proximaPosicao)
{
    if (*proximaPosicao < tamanho)
    {
        vetor[*proximaPosicao].nome = *nome;
        vetor[*proximaPosicao].idade = idade;
        vetor[*proximaPosicao].sexo = sexo;

        (*proximaPosicao)++;
        return true;
    }
    else
    {
        return false;
    }
}

void listarPessoas(Pessoa vetor[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i].nome == "")
        {
            break;
        }
        else
        {
            cout << "\t PESSOA NUMERO " << i + 1 << endl;
            cout << "Nome: " << vetor[i].nome << endl;
            cout << "Idade: " << vetor[i].idade << endl;
            if (vetor[i].sexo == masculino)
            {
                cout << "Sexo: Masculino" << endl
                     << endl;
            }
            else if (vetor[i].sexo == feminino)
            {
                cout << "Sexo: Feminino" << endl
                     << endl;
            }
            else if (vetor[i].sexo == outro)
            {
                cout << "Sexo: Outro" << endl
                     << endl;
            }
        }
    }
}