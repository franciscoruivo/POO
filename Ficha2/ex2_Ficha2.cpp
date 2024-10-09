#include <iostream>
#include <string>

using namespace std;
void imprime(const string& mensagem) {
    cout << mensagem << endl;
}
void imprime(const string& mensagem, int numero) {
    cout << mensagem << numero << endl;
}
void imprime(int numero, const string& mensagem) {
    cout << numero << mensagem << endl;
}

int main() {
    imprime("programacao orientada a objetos"); // Chama a primeira função
    imprime("horas por aula teorica ", 2);      // Chama a segunda função
    imprime(3, " horas em cada aula pratica");   // Chama a terceira função
    return 0;
}
/*
 * Overloading (sobrecarga) é a capacidade de definir várias funções
 * com o mesmo nome, mas com diferentes tipos ou números de parâmetros.
 * Vantagens do Overloading:
 * - Legibilidade: Permite usar um nome descritivo para operações similares.
 * - Facilidade de Uso: Os usuários da função não precisam lembrar de nomes diferentes.
 * - Flexibilidade: Manipula diferentes tipos de dados de maneira uniforme.
 *
 * Restrições e Ambiguidade:
 * - Erros de compilação podem ocorrer se o compilador não conseguir
 *   determinar qual função deve ser chamada.
 * - As funções devem diferir no tipo ou número de parâmetros; mudar apenas
 *   o nome dos parâmetros não é suficiente.
 */