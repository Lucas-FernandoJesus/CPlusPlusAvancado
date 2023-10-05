#include <iostream>
#include <vector>
#include <map>
#include "letra_existe.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> chutes_errados;

void chuta (){
    std ::cout << "Seu chute : " <<std ::endl;
    char chute;
    std ::cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        std ::cout << "Voce acertou ! O seu chute esta na palavra !" <<std ::endl;
    }
    else {
        std ::cout << "Voce errou ! Seu chute nao esta na palavra !" <<std ::endl;
        chutes_errados.push_back(chute);
    }
    std ::cout <<std ::endl;
}