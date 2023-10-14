#include <iostream>
#include <sstream>

using namespace std;
int main(){
    string frase;
    cout<<"\n Indique uma frase \n ->";
    getline(cin,frase);
    for(char l : frase){
        cout <<l; // se nao tiveres a perceber comenta o que vem a seguir e testa para ver o que está a fazer
        if(isspace(l)){
            cout<<"\n";
        }
    }
    // alinea b que procura a palavra Fernado na string da frase e usa while para percorrer
    string nome;
    cout<<"\n Indique uma frase \n ->";
    getline(cin,nome);
    istringstream ss(nome);
    string word;
        while(ss >> word){
            cout << word<< "\n";
            if(word=="Fernando"){
                cout <<"\n Nome Conhecido!";
            }
        }

    return 0;
}
