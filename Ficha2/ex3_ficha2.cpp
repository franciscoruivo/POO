#include <iostream>
using namespace std;

/*
void multiplica() {
    cout << 1 << endl;
}

void multiplica(int numero) {
    cout << numero << endl;
}

void multiplica(int numero, int numero2) {
    cout << numero * numero2 << endl;
}

void multiplica(int numero, int numero2, int num3) {
    cout << (numero * numero2) * num3 << endl;
}

 c) mensagem de erro ambiguating new declaration of 'int multiplica(int, int, int)'
*/

int multiplica(int numero = 1, int numero2 = 1, int num3 = 1) {
    return numero * numero2 * num3; // Retorna o produto dos números
}

int main() {
    cout << "\n" << multiplica() << "\n";          // Usa os valores padrão: 1
    cout << multiplica(5) << "\n";                  // Usa 5, e valores padrão para os outros: 5 * 1 * 1 = 5
    cout << multiplica(2, 3) << "\n";                // Usa 2 e 3, e valor padrão para o último: 2 * 3 * 1 = 6
    cout << multiplica(2, 3, 4) << "\n";             // Usa 2, 3 e 4: 2 * 3 * 4 = 24
    return 0;
}
/*
Resumo:

1. **Parâmetros com Valor por Omissão**: Permitem que uma função seja chamada sem fornecer todos os argumentos. Se um argumento não for passado, um valor padrão é utilizado.

2. **Vantagens**:
   - Simplicidade na chamada de funções.
   - Flexibilidade ao lidar com múltiplos casos sem a necessidade de criar várias sobrecargas.

3. **Restrições**:
   - **Sintáticas**: Parâmetros com valor por omissão devem vir após os parâmetros obrigatórios na lista de parâmetros.
   - **Ambiguidade**: Pode ocorrer se houver sobrecargas de funções que têm assinaturas que podem ser resolvidas de mais de uma maneira.
   - **Ordem**: Todos os parâmetros com valores por omissão devem estar no final da lista de parâmetros.

Ao tentar compilar um programa que combina funções com sobrecarga e funções com parâmetros por omissão, o compilador pode gerar erros de ambiguidade, pois não consegue determinar qual versão da função chamar quando os argumentos fornecidos se aplicam a mais de uma função.
*/
