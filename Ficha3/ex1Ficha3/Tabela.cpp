#include "Tabela.h"

Tabela::Tabela() {
    for (int& i : matriz) {
        i = 0;
    }
    std::cout << "Construido (Tabela padrao)\n";
}

Tabela::Tabela(int valor) {
    for (int& i : matriz) {
        i = valor;
    }
    std::cout << "Construido (Tabela com valor " << valor << ")\n";
}

Tabela::Tabela(int a, int b) {
    for (int i = 0; i < nInt; ++i) {
        matriz[i] = a + (i * b);
    }
    std::cout << "Construido (Tabela com sequencia " << a << ", " << b << ")\n";
}

Tabela::Tabela(std::initializer_list<int> lista) {
    int i = 0;
    for (int valor : lista) {
        if (i >= nInt) break;
        matriz[i++] = valor;
    }
    while (i < nInt) {
        matriz[i++] = 0;
    }
    std::cout << "Construido (Tabela com initializer_list)\n";
}

int Tabela::preenche(int valor) {
    for (int& i : matriz) {
        i = valor;
    }
    return 0;
}

std::span<int> Tabela::lista() {
    return std::span<int>(matriz, nInt);
}

int Tabela::lista(Tabela& t) {
    std::cout << "\n";
    for (int i : t.matriz) {
        std::cout << i << " | ";
    }
    std::cout << "\n";
    return 0;
}

int Tabela::modificar(int pos, int valor) {
    if (pos < 0 || pos >= nInt) {
        throw std::out_of_range("Posicao invalida");
    }
    matriz[pos] = valor;
    return 0;
}

bool Tabela::existe(int valor) {
    for (int& i : matriz) {
        if (valor == i) {
            return true;
        }
    }
    return false;
}

bool Tabela::mesmoConjunto(Tabela& other) {
    int copiaMatriz[nInt];
    int copia_other[nInt];

    std::copy(std::begin(matriz), std::end(matriz), copiaMatriz);
    std::copy(std::begin(other.matriz), std::end(other.matriz), copia_other);

    std::sort(std::begin(copiaMatriz), std::end(copiaMatriz));
    std::sort(std::begin(copia_other), std::end(copia_other));

    for (int i = 0; i < nInt; ++i) {
        if (copiaMatriz[i] != copia_other[i]) {
            return false;
        }
    }

    return true;
}

void Tabela::recebe(Tabela t) {
    std::cout << "Objeto recebido.\n";
}

Tabela Tabela::devolve() {
    std::cout << "Objeto devolvido.\n";
    return *this;  
}


void Tabela::inicializa() {
    Tabela t1(5, 2);  // Constrói um objeto t1
    Tabela t9 = t1;   // Atribui t1 a t9 (cópia)
    std::cout << "Objeto inicializado por atribuicao.\n";
    std::cout << "Tabela 9 apos inici: \n";
    for (int num : t9.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;
}

Tabela::~Tabela() {
    std::cout << "Destruido\n";
}
