#include <iostream>
#include <vector>

extern std :: vector<char>chutes_errados;

void erros (){
    std :: cout << "Chutes errados : ";
    for(char letra : chutes_errados){
        std :: cout << letra <<" ";
    }
    std :: cout <<std ::endl;
}