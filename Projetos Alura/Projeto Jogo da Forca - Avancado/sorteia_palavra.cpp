#include <ctime>
#include "le_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra(){
    std :: vector<std :: string> palavras = le_arquivo();

    srand(time(0));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}