#ifndef TABELA_H
#define TABELA_H

#include <iostream>
#include <span>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

const int nInt = 10;

class Tabela {
private:
    int matriz[nInt];

public:
    // Construtores
    Tabela();  // Construtor padrão
    Tabela(int valor);  // Construtor com valor específico
    Tabela(int a, int b);  // Construtor com sequência crescente
    Tabela(std::initializer_list<int> lista);  // Construtor com initializer_list

    // Métodos
    int preenche(int valor);
    std::span<int> lista();
    int lista(Tabela& t);
    int modificar(int pos, int valor);
    bool existe(int valor);
    bool mesmoConjunto(Tabela& other);
    void recebe(Tabela t);
    Tabela devolve();
    void inicializa();

    // Destrutor
    ~Tabela();
};

#endif // TABELA_H
