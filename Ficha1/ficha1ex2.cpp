#include <iostream>
#include <cstdio>
#include <limits>
//parte 2 Pretende-se um programa que peça o nome e a idade do utilizador e depois imprima essa informação.
using namespace std;

int main() {
    int x;
    char nome[100];
    cout << "\n Indique o nome  \n" ;
    cin.getline(nome,99); // cin >> nome ;
    do{
        cout << "\n Indique a idade  \n" ;
    cin >> x;
    }while(x<=0);
    cout << "\n A tua idade -> " << x << " | Nome: "<<nome;

    return 0;
   
}
