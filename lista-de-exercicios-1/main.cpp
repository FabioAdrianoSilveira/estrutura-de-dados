#include <iostream>
#include <string>
#include "cadastro.h"

using namespace std;

int main()
{
    Pessoa pessoas[10];
    int proximaPosicao = 0;
    int opcao, idade, sexoInt;
    string nome;
    Sexo sexo;
    bool cadastro;

    do
    {
        cout << "\t ===MENU===" << endl;
        cout << "1) Cadastrar pessoa" << endl;
        cout << "2) Listar pessoa" << endl;
        cout << "3) Sair" << endl;
        cout << endl
             << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o nome: ";
            getline(cin.ignore(), nome);
            cout << "Digite a idade: ";
            cin >> idade;
            cout << "Informe o sexo (0 = Masculino, 1 = Feminino, 2 = Outro): ";
            cin >> sexoInt;

            switch (sexoInt)
            {
            case 0:
                sexo = masculino;
                break;

            case 1:
                sexo = feminino;
                break;

            case 2:
                sexo= outro;
                break;

            default:
                cout << "Opcao invalida! Abortando cadastro";
                main();
                break;
            }

            cadastro = cadastrarPessoa(pessoas, 10, &nome, idade, sexo, &proximaPosicao);
            if (cadastro == true)
            {
                cout << "Cadastro realizado com sucesso!\n\n";
            }
            else
            {
                cout << "Armazenamento cheio! Nao e possivel cadastrar mais pessoas\n";
            }

            break;

        case 2:
            listarPessoas(pessoas, 10);
            break;

        case 3:
            cout << "Finalizando sistema";
            exit(1);

        default:
            cout << "Opcao invalida! Tente novamente\n";
            main();
            break;
        }
    } while (opcao != 3);

    return 0;
}