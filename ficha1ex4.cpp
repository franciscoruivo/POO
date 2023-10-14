//Ex 4
#include <iostream>
#include <string>

using namespace std;
int main(){
    string word;
    do{
        do{
            cout << "Insira a palavra: ";
            cin >> word;
        }while (cin.fail());

        if (word == "fim") {
            cout << "Fim do programa!" << endl;
        }else{
            string iv_word= word;
            for (int i=0;i<word.length();i++){
                iv_word[i]=word[word.length()-i-1];
            }
            cout << "Palavra digitada \n-> "<< iv_word << "\n";
            if(word==iv_word){
                cout << "Palindromo !" <<endl;
            }else{
                cout << endl;
            }
            cin.ignore(1000, '\n');
            cout << "Carregue em enter para prosseguir" << endl;
            cin.ignore(1000, '\n');
        }
        }while(word!="fim");


    return 0;
}