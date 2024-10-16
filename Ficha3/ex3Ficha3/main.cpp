#include <iostream>
#include "Pessoa.h"

using namespace std;

int main() {
    Pessoa a("Francisco Ruivo", 21,1.82, 'T');
    cout << a.toString();
    return 0;
}