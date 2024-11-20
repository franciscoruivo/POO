#include <iostream>
#include "cofre.h"

using namespace std;

int main() {
    Cofre cofre("1234", "87654321");
    string opcao;

    cout << "Bem vindo ao cofre!" << endl;

    while (true) {
        cout << "\nEscolha uma opcao:" << endl;
        cout << "1. Abrir cofre" << endl;
        cout << "2. Fechar cofre" << endl;
        cout << "3. Adicionar item" << endl;
        cout << "4. Remover item" << endl;
        cout << "5. Listar itens" << endl;
        cout << "6. Mudar codigo" << endl;
        cout << "7. Desbloquear cofre" << endl;
        cout << "8. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            string codigoTentativa;
            cout << "Digite o codigo do cofre: ";
            cin >> codigoTentativa;
            cout << cofre.abrir(codigoTentativa) << endl;

        } else if (opcao == "2") {
            cout << cofre.fechar() << endl;

        } else if (opcao == "3") {
            string item;
            cout << "Digite o nome do item: ";
            cin.ignore(); // Ignorar quebra de linha pendente
            getline(cin, item);
            cout << cofre.adicionarItem(item) << endl;

        } else if (opcao == "4") {
            string item;
            cout << "Digite o nome do item: ";
            cin.ignore();
            getline(cin, item);
            cout << cofre.removerItem(item) << endl;

        } else if (opcao == "5") {
            cout << cofre.listarItens() << endl;

        } else if (opcao == "6") {
            string codigoAtual, novoCodigo;
            cout << "Digite o codigo atual: ";
            cin >> codigoAtual;
            cout << cofre.mudarCodigo(codigoAtual, novoCodigo) << endl;

            cout << "Digite o novo codigo novamente: ";
            cin >> novoCodigo;
            cout << cofre.mudarCodigo(codigoAtual, novoCodigo) << endl;

        } else if (opcao == "7") {
            string codigoDesbloqueio;
            cout << "Digite o codigo de desbloqueio: ";
            cin >> codigoDesbloqueio;
            cout << cofre.desbloquear(codigoDesbloqueio) << endl;

        } else if (opcao == "8") {
            cout << "Saindo. Ate logo!" << endl;
            break;

        } else {
            cout << "Opcao invalida. Tente de novo." << endl;
        }
    }

    return 0;
}
