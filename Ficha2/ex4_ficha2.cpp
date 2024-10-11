#include <iostream>
using std::cout;
using std::endl;
void trocacomponteiros(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void trocacomreferencias(int &a,int &b) {
    int aux=a;// Acessa diretamente o valor de a
    a=b;//Modifica diretamente o valor de a
    b=aux; //Modifica diretamente o valor de b
}
//b) Sem o uso de ponteiros, a função não seria capaz de alterar os valores das variáveis a e b do main.
/*Um ponteiro armazena o endereço de memória de uma variável.
 *Já as referências são uma maneira mais direta de manipular variáveis. Uma referência atua como um apelido para uma variável existente. */
void trocacomreferenciasconst(const int &a, const int &b) {
   //a = b; // Isso não vai compilar, pois a é uma referência constante.
}
int main() {
    int a = 5, b = 10;
    cout << "\na = " << a << "\nb = " << b;
    //trocacomponteiros(&a,&b);
    trocacomreferencias(a,b);
    cout << "\na = " << a << "\nb = " << b;
    //Impacto do uso de Valores Literais
   // trocacomreferencias(5,4); // Dá erro | Referências em C++ devem ser associadas a variáveis, e não a constantes ou valores literais.
   trocacomreferenciasconst(a,b);
    cout << "\na = " << a << "\nb = " << b;

    return 0;
}
/*Ponteiros oferecem maior flexibilidade, permitindo manipular diretamente endereços de memória, mas trazem riscos como erros de segmentação e podem ser nulos ou não inicializados.

Referências são mais simples e seguras, pois sempre devem referenciar algo válido e não podem ser nulas, mas têm menos flexibilidade em comparação com ponteiros.

Adicionar const a referências impede a modificação dos valores, além de permitir a passagem de literais, sendo útil quando queremos proteger o valor original de alterações.

Literais não podem ser passados para funções que esperam referências modificáveis, mas funcionam com referências constantes.*/