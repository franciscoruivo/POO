#include <iostream>
using std::cout;
using std::endl;
int & seleciona(int &a,int &b,char tipo) {
    if(tipo=='m') {
        cout<<"\n Menor"<< endl;
        return (a < b) ? a : b;
    }
    else if(tipo=='M') {
        cout<<"\n Maior"<< endl;
        return (a > b) ? a : b;
    }
    else if(tipo=='p') {
        cout<<"\n primeira"<< endl;
        return a;
    }
    else if(tipo=='u') {
        cout<<"\n ultima"<< endl;
        return b;
    }
    else {
        cout<<"\n Erro de paramentros"<< endl;
        throw std::invalid_argument("Erro: Codigo de selecao invalido.");
    }
}



int main() {
        try {
        int a = 5, b = 10;
            cout << "a = " << a << ", b = " << b << endl;
        // Selecionar a menor das variáveis e atribuir-lhe o valor 0
        seleciona(a, b, 'm') = 0; // Atribui 0 ao menor valor entre a e b
        cout << "a = " << a << ", b = " << b << endl; // Saída: a = 0, b = 10

        // Selecionar a maior das variáveis e diminuir seu valor em 3
        seleciona(a, b, 'M') -= 3; // Subtrai 3 do maior valor entre a e b
        cout << "a = " << a << ", b = " << b << endl; // Saída: a = 0, b = 7

        // Testar um código inválido
        seleciona(a, b, 'x'); // uma exceção

    } catch (const std::invalid_argument &e) {
        cout << e.what() << endl; // Captura e imprime a exceção se o código for inválido
    }

    return 0;
}
