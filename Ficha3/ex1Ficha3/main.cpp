#include "Tabela.h"

int main() {
    // Teste 1: Inicialização com zeros
    Tabela t1;
    std::cout << "Inicializado com zeros: ";
    for (int num : t1.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    // Teste 2: Inicialização com valor específico
    Tabela t2(5);
    std::cout << "Inicializado com valor 5: ";
    for (int num : t2.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    // Teste 3: Inicialização com sequência crescente (a = 3, b = 2)
    Tabela t3(3, 2);
    std::cout << "Inicializado com sequencia crescente (a = 3, b = 2): ";
    for (int num : t3.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    // Teste 4: Inicialização com initializer_list
    Tabela t4({ 1, 2, 3, 4, 5 });
    std::cout << "Inicializado com initializer_list (1, 2, 3, 4, 5): ";
    for (int num : t4.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;


    t4.preenche(7);
    std::cout << "Matriz apos preenche(7): ";
    t4.lista(t4);  // segunda versão


    try {
        t4.modificar(0, 10);  // Modifica o valor na posição 0 para 10
        std::cout << "Matriz apos modificar(0, 10): ";
        t4.lista(t4);  // Exibe a matriz
    } catch (const std::out_of_range& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // Verifica se um valor existe
    int valorParaVerificar = 7;
    if (t3.existe(valorParaVerificar)) {
        std::cout << "O valor " << valorParaVerificar << " existe na tabela t3." << std::endl;
    } else {
        std::cout << "O valor " << valorParaVerificar << " não existe na tabela t3." << std::endl;
    }

    // Verificação se tem o mesmo conjunto de números
    Tabela t5({ 1, 2, 3, 4, 5 });
    Tabela t6({ 5, 4, 3, 2, 1 });
    if (t5.mesmoConjunto(t6)) {
        std::cout << "Tabela 5 e Tabela 6 armazenam o mesmo conjunto de numeros.\n";
    } else {
        std::cout << "Tabela 5 e Tabela 6 NÃO armazenam o mesmo conjunto de numeros.\n";
    }

    // Teste receber um objeto
    t2.recebe(t3);

    // Teste 5: Devolve um objeto
    std::cout << "Tabela 5: \n";
    for (int num : t5.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    Tabela t8 = t5.devolve();
    std::cout << "Tabela devolvida: ";
    for (int num : t8.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    // Inicializa um novo objeto
    Tabela t9;
    std::cout << "Tabela 9: \n";
    for (int num : t9.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    t9.inicializa();
    std::cout << "Tabela 9 apos: \n";
    for (int num : t9.lista()) {
        std::cout << num << " | ";
    }
    std::cout << std::endl;

    return 0;
}
/**
 • std::initializer_list: espécie de array otimizado e imutável de carácter temporário. é usado
essencialmente para especificar valores, os quais não existem para além da linha onde são
especificados. Caso de uso: passagem de valores por parâmetro para serem copiados,
tipicamente em inicializações.

• std::span: espécie de array otimizado, que pode ser modificado. É usado essencialmente
para especificar valores que já existem (num array ou outra coleção), os quais devem
obrigatoriamente continuar a existir enquanto o span é usado. É usado como substituto
(melhor) onde normalmente teria que se usar um ponteiro para o primeiro elemento e uma
quantidade de elementos.

O construtor com initializer_list pode ser priorizado pelo compilador ao usar chaves {}
sso pode impedir a chamada de outros construtores com parâmetros semelhantes, como int ou int, int

std::copy : Copia os elementos de um array para outro, preservando o original.
std::sort: Ordena os elementos de um array para facilitar a comparação.**/