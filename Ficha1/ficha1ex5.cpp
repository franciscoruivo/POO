//Ex 5
#include <iostream>
#include <string>

using namespace std;
int main(){
    string input;

    string valores[10] = { "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez" };

    do {
        cout << "\nIndique o Nome:\n";
        getline(cin,input);

        string OutputFinal;
        for(int i = 0; i < 10; i++){
            string index = to_string(i+1);

            if(input == index){
                OutputFinal = valores[i];
                break;
            }

            if(input == valores[i]){
                OutputFinal = index;
                break;
            }
        }

        if(!OutputFinal.empty()){
            cout << "\nResposta: "<<OutputFinal<<"\nPressione Enter para prosseguir.";
        }else{
            cout << "\nNao encontramos esse numero! Indique um de 0 a 10.\nPressione Enter para prosseguir.";
        }
        if(input=="fim") {
            cout <<"\n FIM PROGAMA"<<endl;
        }

    }while(input!="fim");



    return 0;
}

