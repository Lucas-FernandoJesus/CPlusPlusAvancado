#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Aluno
{
    string nome;
    double idade;
    int nota;
};

void menu()
{

    cout << "Escola Corleone" << endl;
    cout << "Cadastro de alunos" << endl;
}

// Cadastro
Aluno cadastro()
{

    Aluno aluno;

    cout << "Insira o nome do Aluno : " << endl;
    cin >> aluno.nome;

    cout << "Insira a idade do Aluno : " << endl;
    cin >> aluno.idade;

    cout << "Insira a nota do Aluno : " << endl;
    cin >> aluno.nota;

    return aluno;
}

// Visualização
void visualizacao(const Aluno &aluno)
{
    cout << "" << endl;
    cout << "Nome do Aluno : " << aluno.nome << endl;
    cout << "Idade do Aluno : " << aluno.idade << endl;
    cout << "Nota do Aluno : " << aluno.nota << endl;
}

int escolha()
{
    int opcao;

    cout << "" << endl;
    cout << "Escolha o que voce deseja fazer : " << endl;
    cout << "1 - Cadastrar um novo aluno." << endl;
    cout << "2 - Visualizar cadastros." << endl;
    cout << "3 - Sair." << endl;
    cout << "------------------------------------------" << endl;
    cin >> opcao;

    return opcao;
}

int main()
{

    vector<Aluno> alunos;
    Aluno aluno;

    int continuarLancamento;
    bool running = true;

    menu();

    do
    {
        int opcao = escolha();
        switch (opcao)
        {
        case 1:
            aluno = cadastro();
            alunos.push_back(aluno);
            break;
        case 2:
            for (const auto &aluno : alunos)
            {
                visualizacao(aluno);
            }
            break;
        case 3:
            cout << "Saindo do programa..." << endl;
            running = false;
        }
        cout << "Voce deseja voltar ao menu para cadastrar mais alunos ?" << endl;
        cout << "Se sim pressione 1." << endl;
        cout << "Se nao pressione 2." << endl;
        cin >> continuarLancamento;

        if (continuarLancamento != 1)
        {
            cout << "Saindo do programa !" << endl;
            running = false;
        }
    } while (running);

    return 0;
}