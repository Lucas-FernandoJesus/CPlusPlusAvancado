#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menu(){

    cout <<"...Seja bem vindo a :..."<<endl;
    cout <<".......BIBLIOTECA......."<<endl;
    cout <<"........................"<<endl;
}

struct livros{
    static int proximoID;
    int ID,Ano;
    string Titulo, Autor, Genero;
};

int livros::proximoID = 0;


int escolhas(){

    int opcao;

    cout << "Escolha o que voce quer fazer : "<<endl;
    cout << "1 - Cadastrar novos livros."<<endl;
    cout << "2 - Visualizar os livros."<<endl;
    cout << "3 - Excluir algum cadastro."<<endl;
    cout << "4 - Sair."<<endl;
    cin >> opcao;

    return opcao;
}

// Cadastro de livros :

livros cadastro(){

    livros ListBooks;

    cout <<"Vamos comecar cadastrando o titulo do livro : " <<endl;

    cout << "Digite o titulo do livro : " <<endl;
    cin.ignore();
    getline(cin, ListBooks.Titulo);

    cout <<"Insira o auto desse livro : " <<endl;
    getline(cin, ListBooks.Autor);

    cout <<"Insita o genero do livro : " <<endl;
    getline(cin, ListBooks.Genero);

    cout <<"Insira o ano de cadastro do livro : " <<endl;
    cin >> ListBooks.Ano;

    ListBooks.ID = livros::proximoID ++;

    cout << "livro cadastrado com sucesso ! "<<endl;

    return ListBooks;
}

//Visualização de livros : 

void visualizacao (const livros& ListBooks){

    cout <<"Informacoes dos livros cadastrados : " <<endl;
    cout <<"ID : "<<ListBooks.ID <<endl;
    cout <<"Titulo : "<<ListBooks.Titulo <<endl;
    cout <<"Autor : "<<ListBooks.Autor <<endl;
    cout <<"Genero : "<<ListBooks.Genero <<endl;
    cout <<"Ano : "<<ListBooks.Ano <<endl;
    cout << "-----------------------------" << endl;
}

void deleta(vector<livros>& ListBooks){

    if(ListBooks.empty()){
        cout <<"There are no books registered " <<endl;
        return;
    }

    cout <<"Informations register" <<endl;

    int i = 0;
    for(const auto& book : ListBooks){
        cout <<i++ <<" - "<<book.ID<<", "<<book.Titulo<<", "<<book.Autor <<", "<<book.Genero<< ", "<<book.Ano <<endl;
    }

    int bookDelete;

    cout <<"Enter ID of book wou want to delete" <<endl;
    cin >> bookDelete;

    if(bookDelete < 1){
        cout <<"Invalid number! Please enter a valid id." <<endl;
    }
    else{
        int bookIndex = -1;
        for(size_t i = 0; i < ListBooks.size(); i++){
            if(ListBooks[i].ID == bookDelete){
                bookIndex = i;
                break;
            }
        }
        if(bookIndex == -1){
            cout <<"This book does not exist!" <<endl;
        }
        else{
            ListBooks.erase(ListBooks.begin() + bookIndex);
            cout <<"The book was successfully deleted !" <<endl;
        }
    }
}
    

int main(){

    vector <livros> ListBooks;

    int opcao, continueRegister;
    bool running = true;
    livros books;

    menu();

    do{
        opcao = escolhas();

        switch (opcao){
            case 1 :
                books = cadastro();
                ListBooks.push_back(books);
                break;
            case 2 :
                for (const auto &book : ListBooks) {
                    visualizacao(book);
                }
                break;
            case 3 :
                deleta(ListBooks);
            case 4:
                cout <<"Goodbye ..." <<endl;
                running = false;
        }
        cout <<"Continue reister books ? " <<endl;
        cout <<"If yes then press 1" <<endl;
        cout <<"If not then press 2" <<endl;
        cin >> continueRegister;

        if(continueRegister != 1 ){
            cout <<"Goodbye!"<< endl;
            running = false;
        }

    } while (running);

    return 0;
}