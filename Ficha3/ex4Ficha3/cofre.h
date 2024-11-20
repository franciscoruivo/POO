#ifndef COFRE_H
#define COFRE_H

#include <string>
#include <vector>

using namespace std;

class Cofre {
private:
    string codigo;
    const string codigoDesbloqueio;
    bool aberto;
    bool bloqueado;
    int tentativasFalhas;
    vector<string> itens;
    string ultimoCodigoTentado;

    static const int MAX_ITENS = 20;

public:
    Cofre(const string& codigoInicial, const string& codigoDesbloqueioInicial);

    string abrir(const string& tentativaCodigo);
    string fechar();
    string desbloquear(const string& tentativaCodigoDesbloqueio);

    string adicionarItem(const string& item);
    string removerItem(const string& item);
    string listarItens() const;

    // Método para mudar o código
    string mudarCodigo(const string& codigoAntigo, const string& novoCodigo);
};

#endif // COFRE_H
