//
// Created by Ruivo on 16/10/2024.
//

#include <sstream>
#include <utility>
#include "Automovel.h"

Automovel::Automovel(string matricula, double combustivel, string marca, string modelo):marca(marca), modelo(modelo) {
    this->matricula = matricula;
    this->combustivel = combustivel;
    cout << "Automovel Construido" << endl;
}

Automovel::~Automovel() {
    cout << "Automovel destruido" << endl;
}

string Automovel::exibeMatricula() {
    return matricula;
}

string Automovel::getMarca() {
    return marca;
}

string Automovel::getmodelo() {
    return modelo;
}

double Automovel::getCombustivel() const {
    return combustivel;
}

bool Automovel::setMatricula(string novaMat) {
    // Remover hifens, caso existam
    string matriculaSemHifen = "";
    for (char c : novaMat) {
        if (c != '-') {
            matriculaSemHifen += c;
        }
    }

    // se tem exatamente 6 caracteres
    if (matriculaSemHifen.length() != 6) {
        return false;
    }

    // Verificar formato antigo (AA-00-00): letras, números, números
    bool formatoAntigo = isalpha(matriculaSemHifen[0]) && isalpha(matriculaSemHifen[1]) &&
                         isdigit(matriculaSemHifen[2]) && isdigit(matriculaSemHifen[3]) &&
                         isdigit(matriculaSemHifen[4]) && isdigit(matriculaSemHifen[5]);

    // Verificar formato de 2005 e atual (00-AA-00): números, letras, números
    bool formatoAtual = isdigit(matriculaSemHifen[0]) && isdigit(matriculaSemHifen[1]) &&
                        isalpha(matriculaSemHifen[2]) && isalpha(matriculaSemHifen[3]) &&
                        isdigit(matriculaSemHifen[4]) && isdigit(matriculaSemHifen[5]);

    // Se a matrícula for válida em qualquer um dos formatos, atribuímos
    if (formatoAntigo || formatoAtual) {
        matricula = novaMat; // Matricula mantém o formato original, inclusive com hifens
        return true;
    }

    // Se não for válida, retornamos false
    return false;
}

void Automovel::setCombustivel(double x) {
    if(x > 0)
        combustivel = x;
}

string Automovel::toString() const {
    ostringstream os;
    os << "Marca: " << marca << endl
       << "Modelo: " << modelo << endl
       << "Matricula: " << matricula << endl
       << "Combustivel: " << combustivel << " Litros"<< endl;
    return os.str();
}
