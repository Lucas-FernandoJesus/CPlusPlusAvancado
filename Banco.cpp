#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct contaCria{

    static int nextId;
    string nome,genero;
    int idade, numeroConta;
    double saldo,sacar;
};

vector<int> numerosContas;

void menu(){
    cout << "Seja bem-vindo ao : "<< endl;
    cout << "Banco do Brasil"<< endl;
}

int contaCria :: nextId = 0;

contaCria cadastro(){

    contaCria conta;
    cout << "Vamos comecar criando a sua conta entao : " << endl;
    
    cout << "Insira o seu nome : " << endl;
    cin.ignore();
    getline(cin, conta.nome);

    cout << "Insira a sua idade : " << endl;
    cin >> conta.idade;
    
    cout << "Insira o seu genero : " << endl;
    cin.ignore();
    getline(cin,conta.genero);
    
    bool numerosContasValidas;
    do{
        cout << "Insira o numero da conta desejada : " << endl;
        cin >> conta.numeroConta;
        numerosContasValidas = true;
        for(int numero : numerosContas){
            if(numero == conta.numeroConta){
                cout << "O numero da conta inserido ja existe. Por favor, insira outro numero !" <<endl;
                numerosContasValidas = false;
                break;
            }
        }
    }while(!numerosContasValidas);
    numerosContas.push_back(conta.numeroConta);

    conta.saldo = 0.0;
    conta.nextId = contaCria :: nextId ++;
    cout << "" << endl;

    return conta;
}



//Deposito
void deposito(contaCria &conta){

    cout << "Digite o valor que voce deseja depositar na conta : "<<endl;
    cin >> conta.saldo;
    while (conta.saldo <= 0) {
        cout << "Valor de deposito menor ou igual a zero! Tente novamente." << endl;
        cin >> conta.saldo;
        }
    cout << "O saldo apos o deposito e de : " << conta.saldo << endl;
}

//Sacar
void sacar(contaCria &conta){

    cout << "Digite o valor que você deseja sacar : " <<endl;
    double valor;
    cin >> valor;

    if(valor <= 0){
        cout << "Valor de saque menor ou igual a 0. Tente novamente !" <<endl;
        sacar(conta);
    }
    else if(valor > conta.saldo){
        cout << "Valor digitado e maior que o saldo na conta. Tente novamente !" <<endl;
    }
    else{
        conta.saldo -= valor;
        cout << "Saldo atualizado para : R$ " << conta.saldo << endl;
    }
}

int escolhas (){

    int opcao;

    cout << "O banco realiza as seguinte transacoes : "<<endl;
    cout << "0 - Criar conta"<< endl;
    cout << "1 - Depositar"<< endl;
    cout << "2 - Sacar"<< endl;
    cout << "3 - Consulta Saldo"<< endl;
    cout << "5 - Sair"<< endl;
    cin >> opcao;

    return opcao;
}
int main (){

    vector <contaCria> conta;
    int opcao;
    bool runing = true;

    menu();

    do{

        opcao = escolhas();
        switch (opcao){

        case 0:
            conta.push_back(cadastro());
            cout << "Conta criada com sucesso ! O seu ID de conta eh : " << conta.size() <<endl;
            break;

        case 1 :
            deposito(conta[conta.size()-1]);
            break;

        case 2:
            sacar(conta[conta.size()-1]);
            break;

        case 3:
            cout << "O saldo da conta eh : " << conta[conta.size()-1].saldo <<endl;
            break;
        case 5:
            runing = false;
            break;
        default:
            cout << "Opcao invalida. Tente novamente !" <<endl;
            break;
        }
    }while(runing);

    return 0;
}