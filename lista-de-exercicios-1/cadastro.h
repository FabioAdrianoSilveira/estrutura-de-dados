#ifndef CADASTRO_H
#define CADASTRO_H

#include <string>

using namespace std;

union Sexo
{
    int masculino;
    int feminino;
    int outro;
};

struct Pessoa
{
    string nome;
    int idade;
    Sexo sexo;
};

bool cadastrarPessoa(Pessoa vetor[], int tamanho, string *nome, int idade, Sexo sexo, int *proximaPosicao);

void listarPessoas(Pessoa vetor[], int tamanho);

#endif