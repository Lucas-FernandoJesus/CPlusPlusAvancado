#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

/*ARQUIVOS INCLUSOS*/

#include "adiciona_palavra.hpp"
#include "chuta.hpp"
#include "erros.hpp"
#include "imprime_palavra.hpp"
#include "le_arquivo.hpp"
#include "letra_existe.hpp"
#include "menu.hpp"
#include "nao_acertou.hpp"
#include "nao_enforcou.hpp"
#include "salva_arquivo.hpp"
#include "sorteia_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char>chutes_errados;


int main (){

    menu();

    le_arquivo();
    sorteia_palavra();


    while (nao_acertou() && nao_enforcou()){

        erros();

        imprime_palavra();

        chuta();
    }
    cout <<"Fim de Jogo !" <<endl;
    cout <<"A palavra secreta era : " <<palavra_secreta <<endl;
    if (nao_acertou()){
        cout << "Tente novamente !" <<endl;
    }
    else{
        cout << "Voce acertou a palavra secreta !" <<endl;

        cout << "Voce deseja adicionar uma nova palavra ? (S/N)" <<endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
    return 0;
}