#ifndef FICHA3_2_AUTOMOVEL_H
#define FICHA3_2_AUTOMOVEL_H

#include <iostream>
#include <ostream>

using namespace std;

class Automovel {
public:
    Automovel(string matricula, double combustivel, string marca, string modelo);
    ~Automovel();

    string exibeMatricula();
    string getMarca();
    string getmodelo();
    double getCombustivel() const;

    bool setMatricula(string novaMat);
    void setCombustivel(double x);

    bool acelera();
    bool travar();
    bool piscas();

    string toString() const;
private:
    string matricula;
    double combustivel;
    const string marca;
    const string modelo;
};


#endif //FICHA3_2_AUTOMOVEL_H
