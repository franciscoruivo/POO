#include <iostream>

using namespace std;
namespace DataStore {
    bool dadosSaoValidos(string str) {
        if (str.length() < 5) {
            return false;
        }
        if (str.length() > 10) {
            return false;
        }
        return true;
    }
}
namespace UserInterface {
    bool dadosSaoValidos(string str) {
        if (str.empty()) {
            return false;
        }
        // isupper Verifica se o primeiro caractere é uma letra maiúscula e islower se for para ser minúsculo
        return isupper(str[0]);
    }
}

int main() {
    string a = "vamos";
    string b = "Teste";
    string c = "Valida";

    // DataStore
    cout << "DataStore: " << DataStore::dadosSaoValidos(a) << endl; // true (5 caracteres)

    //  UserInterface
    cout << "UserInterface: " << UserInterface::dadosSaoValidos(b) << endl; // true (começa com maiúscula)
    cout << "UserInterface: " << UserInterface::dadosSaoValidos(c) << endl; // false (não começa com maiúscula)

    // i) Sem usar declaração using namespace …
    cout << "Sem using namespace:" << endl;
    cout << "DataStore: " << DataStore::dadosSaoValidos(a) << endl; // true (mais de 5 caracteres)
    cout << "UserInterface: " << UserInterface::dadosSaoValidos(b) << endl; // false (não começa com maiúscula)
    cout << "UserInterface: " << UserInterface::dadosSaoValidos(c) << endl; // true (começa com maiúscula)

    // ii) Usando using mas não using namespace…
    using DataStore::dadosSaoValidos; // Usando a função de DataStore
    cout << "\nUsando 'using' para DataStore:" << endl;
    cout << "DataStore: " << dadosSaoValidos(a) << endl; // true (mais de 5 caracteres)
    cout << "UserInterface: " << UserInterface::dadosSaoValidos(b) << endl; // false (não começa com maiúscula)

    // iii)  um using namespace …
    using namespace UserInterface; // Usando o namespace UserInterface
    cout << "\nUsando 'using namespace' para UserInterface:" << endl;
    cout << "UserInterface: " << dadosSaoValidos(c) << endl; // true (começa com maiúscula)
    cout << "DataStore: " << DataStore::dadosSaoValidos(a) << endl; // true (mais de 5 caracteres)

    // iv)  dois using namespaces…
    using namespace DataStore; // Agora usando ambos os namespaces
    cout << "\nUsando 'using namespace' para DataStore e UserInterface:" << endl;
    cout << "DataStore: " << dadosSaoValidos(a) << endl; // true (mais de 5 caracteres)
    cout << "UserInterface: " << dadosSaoValidos(b) << endl; // false (não começa com maiúscula)

    return 0;
}
/*Namespaces são utilizados para organizar o código e evitar conflitos de nomes em projetos grandes.
utilizar namespaces aumenta a clareza e evita conflitos:
Usar o prefixo do namespace.
Usar using para funções específicas
Usar using namespace para permitir chamadas diretas.*/
