#include <iostream>
#include <string>

using namespace std;


// a) e b)
const int nInt = 10;

typedef struct t Tabela;
struct t{
    int matriz[nInt];
};


int preenche(Tabela &t, int num){
    for(int & i : t.matriz)
        i = num;
    return 0;

}

int lista(Tabela t)
{
    cout <<"\n";
    for(int &i : t.matriz)
        cout << i << " | ";

    return 0;
}

// Ex 6 b)

int obtem_valor(Tabela t, int pos)
{
    if(pos < 0 || pos > 9)
    {
        cout << "Erro de pos invalida";
        return 0;
    }
    return t.matriz[pos];
}

bool preencheValor(Tabela& t, int pos, int valor)
{
    if(pos < 0 || pos > 9)
    {
        cout << "\n Posicao invalida";
        return false;
    }
    t.matriz[pos] = valor;

    return true;
}



void juncao(Tabela &t, int pos, int valor, int flag)
{
    // obtem_valor
    if(flag == 0)
    {
        cout << "\n Pretende mostrar um elemento";
        cout << "\n Valor da posicao " << pos << " : " << obtem_valor(t,pos);
        lista(t);
    }
    // preencheValor
    else if(flag == 1)
    {
        cout << "\n Pretende atualizar";
        t.matriz[pos] = valor;
        lista(t);
    }
}

// Com Excessões

int juncao_v2(Tabela &t,int pos, int valor,int flag = 3) {

    try {
        if (flag == 1) {
            cout << "\n Pretende atualizar";
            t.matriz[pos] = valor;
            lista(t);
        } else if (flag == 2) {
            cout << "\n Pretende mostrar um elemento";
            cout << t.matriz[pos];
            lista(t);
        } else {
            throw invalid_argument("Flag invalida: " + (flag));
        }

    } catch (const invalid_argument& e) {
        cout << "\nErro capturado: " << e.what();
        throw;  // Repropaga a exceção
    }

    return 0;
}


void teste(Tabela &t, int pos, int valor, int flag = -1)
{
    try {
        juncao_v2(t, pos, valor, flag);
    } catch (const invalid_argument& e) {
        // Captura exceção específica em 'teste' e lida com ela
        cout << "\nErro capturado em 'teste()': " << e.what();
        throw;
    }
}
int main() {
    Tabela t;
    int valor = 5;
    int pos = 0;
    // Ex 6 b)
    preenche(t,valor);
    lista(t);
    cout << "\n Valor da posicao " << pos << " : " << obtem_valor(t,pos);

    valor = 3;
    pos = 0;

    if(preencheValor(t,pos,valor))
        cout << "\n Alteracao feita com sucesso";
    else{
        cout << "\n Houve um erro na alteracao";}
   lista(t);



    pos = 0;
    valor = 1;
    //d)
    juncao(t,pos,valor,1);
    juncao_v2(t,pos,valor,2);
    lista(t);
    //e)


    cout << "\n Teste com acesso invalido:";
    try {
        teste(t, 3, 3, 3); // valores inválidos
    }
    catch (const invalid_argument& e) {
        cout << "\n Erro capturado no 'main()': " << e.what();
    }
    lista(t);
    return 0;
}
// atencao , ex feito com bases de resolução de outras pessoas