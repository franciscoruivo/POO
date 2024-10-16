
//
// Created by Ruivo on 16/10/2024.
//
/*

    1. **Abstração**: A classe `Pessoa` modela uma entidade do mundo real, destacando atributos e comportamentos essenciais (nome, idade, altura e gênero).

    2. **Encapsulamento**: Os atributos são declarados como `private`, permitindo acesso e modificação apenas por meio de métodos públicos. Isso protege os dados da classe contra acessos indevidos.

    3. **Ocultação de Dados**: Detalhes da implementação interna (como a validação do gênero) são escondidos dos usuários da classe, que interagem apenas através de uma interface limpa e controlada.

    4. **Desenho de Classes**: Os métodos têm responsabilidades claras, contribuindo para um código organizado, coeso e fácil de manter.
*/

#include <sstream>
#include <utility>
#include "Pessoa.h"

Pessoa::Pessoa(std::string nome, int idade, double altura, char genero)
        : nome(std::move(nome)), idade(idade), altura(altura), genero(genero) {
    // Lista de inicialização: inicializa os atributos diretamente com os parâmetros
    if (!Genero(genero)) {
        cout << "Genero invalido fornecido no construtor. Atribuindo 'M' como valor padrao." << endl;
        this->genero = 'M';  // Valor padrão caso o gênero seja inválido
    }
}

Pessoa::~Pessoa() {
    cout << "Pessoa destruida" << endl;
}

string Pessoa::exibeNome() const {
    return nome;
}

char Pessoa::getGenero() const {
    return genero;
}

double Pessoa::getAltura() const {
    return altura;
}


bool Pessoa::Genero(char genero) {
    if (genero == 'm' || genero == 'M' || genero == 'F' || genero == 'f') {
        this->genero = genero;  // Atualiza o atributo genero
        return true;            // Retorna true para indicar sucesso
    } else {
        cout << "Genero invalido. Use 'M' ou 'F'." << endl;
        return false;           // Retorna false para indicar falha
    }
}

void Pessoa::setIdade(int novaIdade) {
    if (novaIdade > 0) {
        idade = novaIdade;
    }
}
void Pessoa::setAltura(double novaAltura) {
    if (novaAltura > 0) {
        altura = novaAltura;
    }
}

string Pessoa::toString() const {
    ostringstream os;
    os << "Nome: " << nome << endl
       << "Idade: " << idade << endl
       << "Altura: " << altura << endl
       << "Genero: " << genero << endl;
    return os.str();
}