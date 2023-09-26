#include <string>
#include <vector>

extern std :: string palavra_secreta;
extern std :: vector<char>chutes_errados;

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }

    return false;
}