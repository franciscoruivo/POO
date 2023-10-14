#include <iostream>
using namespace std;
#include <cstdio>
int  main(){

    string Nome;
    int Idade;
    int numero;

    cout << "Indique o Nome:";
    getline(cin, Nome);

    do {
        cout << "\nIndique a Idade:";
        cin >> Idade;
        if(cin.fail()){
            cout << "\nIndique um numero!";
            Idade = -1;
            cin.clear();
        }

    }while(Idade <= 0);

   //e)
    cout<<"\nNome: "<< Nome << " | Idade: "<<Idade;

    cout<<"\n Numero de caracteres do nome "<<Nome<<" sao "<< Nome.length(); // funcao para contar caracteres
    for(int i=0;i<Nome.length();++i){
        cout<< "\n Letra ["<<i<<"]: "<<Nome[i];
    }
    cout <<"\n \n Metodo com For each";
     for(char x: Nome){
         cout<<"\n"<<x;
     }
    return 0;
}