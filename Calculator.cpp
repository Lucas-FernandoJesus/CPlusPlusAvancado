#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void menu(){
    
    cout << "************************************************************************"<<endl;
    cout << "**********         Ola, seja bem vindo a calculadora !        **********"<<endl;
    cout << "**********  A calculadora realiza as quatro operacoes basicas **********"<<endl;
    cout << "**********          Fique a vontade para a utilizar           **********"<<endl;
    cout << "************************************************************************"<<endl;
}

void recebeNumeros(int &numero1, int &numero2){

    cout << "Insira o primeiro numero para que o mesmo seja calculado : " <<endl;
    cin >> numero1;

    cout << "Insira o segundo numero : " <<endl;
    cin >> numero2;
}

int funcao(){

    int opcao;

    cout << "A calculadora faz as operacoes basicas de matematica sendo elas : " <<endl;
    cout << "1 - Soma" <<endl;
    cout << "2 - Subtracao" <<endl;
    cout << "3 - Multiplicacao" <<endl;
    cout << "4 - Divisao" <<endl;
    cout << "5 - Sair" <<endl;
    cin >> opcao;

    return opcao;
}

int main (){


    int numero1,numero2,escolha, continuaCalculando;

    menu();

    do{

        recebeNumeros(numero1,numero2);

        int soma = numero1 + numero2;
        int subtracao = numero1 - numero2;
        int mutliplicacao = numero1 * numero2;
        int divisao = numero1 / numero2;

        int escolha = funcao();

        switch (escolha){
            case 1 :
                cout << "O resultado da soma eh de : " << soma<< endl;
                break;
            case 2 :
                cout << "O resultado da subtracao eh de : " << subtracao<< endl;
                break;
            case 3 :
                cout << "O resultado da multiplicacao eh de : " << mutliplicacao<< endl;
                break;
            case 4 :
                if(numero2 != 0){
                    cout << "O resultado da divisao eh de : " << divisao<< endl;
                }
                else{
                    cout << "Erro : Divisao por zero ! "<< endl;
                }
                break;
            case 5 :
                cout << "Saindo do programa ..." <<endl;
                exit(0);
            }

            cout << "Deseja continuar calculando ? " <<endl;
            cout << "Se sim aperte : 1" <<endl;
            cout << "Se nao aperte : 2" <<endl;
            cin >> continuaCalculando;

            if(continuaCalculando != 1){
                cout << "Saindo do programa ..." <<endl;
                exit(0);
            }
        }while (continuaCalculando == 1);

    return 0;
}