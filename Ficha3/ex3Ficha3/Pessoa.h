//
// Created by Ruivo on 16/10/2024.
//

#ifndef EX3FICHA3_PESSOA_H
#define EX3FICHA3_PESSOA_H

#include <iostream>
#include <ostream>
using namespace  std;
class Pessoa {
public:
    //construtor
    Pessoa(string nome,int idade,double altura,char genero);
    ~Pessoa();

    string exibeNome() const;
    int getIdade() const;
    double getAltura() const;
    char getGenero() const;

    // Funções para modificar idade e altura
    void setIdade(int novaIdade);
    void setAltura(double novaAltura);
    bool Genero(char genero);
    string toString() const;
private:
    // Atributos privados (encapsulamento)
    string nome;
    int idade;
    double altura;
    char genero;


};
#endif //EX3FICHA3_PESSOA_H
