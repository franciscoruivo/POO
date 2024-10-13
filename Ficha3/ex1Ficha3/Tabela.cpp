#include "Tabela.h"

// Construtor padrão que inicializa com zeros
Tabela::Tabela() {
    for (int& i : matriz) {
        i = 0;
    }
    std::cout << "Construido (Tabela padrao)\n";
}

// Construtor que inicializa com um valor específico
Tabela::Tabela(int valor) {
    for (int& i : matriz) {
        i = valor;
    }
    std::cout << "Construido (Tabela com valor " << valor << ")\n";
}

// Construtor que inicializa com uma sequência crescente de a com incremento de b
Tabela::Tabela(int a, int b) {
    for (int i = 0; i < nInt; ++i) {
        matriz[i] = a + (i * b);
    }
    std::cout << "Construido (Tabela com sequencia " << a << ", " << b << ")\n";
}

// Construtor que inicializa com uma lista de valores (std::initializer_list)
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

// Listar a matriz usando std::span
std::span<int> Tabela::lista() {
    return std::span<int>(matriz, nInt);
}

// Listar valores da matriz
int Tabela::lista(Tabela& t) {
    std::cout << "\n";
    for (int i : t.matriz) {
        std::cout << i << " | ";
    }
    std::cout << "\n";
    return 0;
}

// Modifica o valor numa posição específica
int Tabela::modificar(int pos, int valor) {
    if (pos < 0 || pos >= nInt) {
        throw std::out_of_range("Posicao invalida");
    }
    matriz[pos] = valor;
    return 0;
}

// Verifica se um valor existe na tabela
bool Tabela::existe(int valor) {
    for (int& i : matriz) {
        if (valor == i) {
            return true;
        }
    }
    return false;
}

// Verifica se dois objetos têm os mesmos valores
bool Tabela::mesmoConjunto(Tabela& other) {
    int copiaMatriz[nInt];
    int copia_other[nInt];

    // Copia para arrays temporários
    std::copy(std::begin(matriz), std::end(matriz), copiaMatriz);
    std::copy(std::begin(other.matriz), std::end(other.matriz), copia_other);

    // Ordena os arrays temporários
    std::sort(std::begin(copiaMatriz), std::end(copiaMatriz));
    std::sort(std::begin(copia_other), std::end(copia_other));

    // Compara os arrays temporários já ordenados
    for (int i = 0; i < nInt; ++i) {
        if (copiaMatriz[i] != copia_other[i]) {
            return false;
        }
    }

    return true;
}

// Metodo que recebe um objeto da classe
void Tabela::recebe(Tabela t) {
    std::cout << "Objeto recebido.\n";
}

// Retorna um objeto da classe por valor
Tabela Tabela::devolve() {
    std::cout << "Objeto devolvido.\n";
    return *this;  // Retorna uma cópia do objeto atual
}

// Inicializa objetos e demonstra atribuição
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

// Destrutor
Tabela::~Tabela() {
    std::cout << "Destruido\n";
}
