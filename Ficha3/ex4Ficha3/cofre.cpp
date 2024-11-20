#include "cofre.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

Cofre::Cofre(const string& codigoInicial, const string& codigoDesbloqueioInicial)
        : codigo(codigoInicial), codigoDesbloqueio(codigoDesbloqueioInicial), aberto(false), bloqueado(false), tentativasFalhas(0), ultimoCodigoTentado("") {
    if (codigoInicial.size() != 4 || !all_of(codigoInicial.begin(), codigoInicial.end(), ::isdigit)) {
        throw invalid_argument("Codigo inicial deve ter 4 dígitos.");
    }
    if (codigoDesbloqueioInicial.size() != 8 || !all_of(codigoDesbloqueioInicial.begin(), codigoDesbloqueioInicial.end(), ::isdigit)) {
        throw invalid_argument("Codigo de desbloqueio deve ter 8 dígitos.");
    }
}

string Cofre::abrir(const string& tentativaCodigo) {
    ostringstream resposta;
    if (bloqueado) {
        resposta << "Falha: Cofre bloqueado.";
        return resposta.str();
    }
    if (aberto) {
        resposta << "Nenhuma alteracao: Cofre ja esta aberto.";
        return resposta.str();
    }
    if (tentativaCodigo == codigo) {
        aberto = true;
        tentativasFalhas = 0;
        resposta << "Sucesso: Cofre aberto.";
    } else {
        tentativasFalhas++;
        resposta << "Falha: Codigo incorreto. Tentativa " << tentativasFalhas << "/3.";
        if (tentativasFalhas >= 3) {
            bloqueado = true;
            resposta << " Cofre bloqueado.";
        }
    }
    return resposta.str();
}

string Cofre::fechar() {
    if (bloqueado) {
        return "Falha: Cofre bloqueado.";
    }
    if (!aberto) {
        return "Nenhuma alteracao: Cofre ja esta fechado.";
    }
    aberto = false;
    return "Sucesso: Cofre fechado.";
}

string Cofre::desbloquear(const string& tentativaCodigoDesbloqueio) {
    if (!bloqueado) {
        return "Nenhuma alteracao: Cofre nao esta bloqueado.";
    }
    if (tentativaCodigoDesbloqueio == codigoDesbloqueio) {
        bloqueado = false;
        tentativasFalhas = 0;
        return "Sucesso: Cofre desbloqueado.";
    }
    return "Falha: Codigo de desbloqueio incorreto.";
}

string Cofre::adicionarItem(const string& item) {
    if (!aberto) {
        return "Falha: Cofre fechado. Nao e possivel adicionar itens.";
    }
    if (item.empty()) {
        return "Falha: Nome do item nao pode ser vazio.";
    }
    if (itens.size() >= MAX_ITENS) {
        return "Falha: Cofre cheio. nao e possivel adicionar mais itens.";
    }
    itens.push_back(item);
    return "Sucesso: Item '" + item + "' adicionado.";
}

string Cofre::removerItem(const string& item) {
    if (!aberto) {
        return "Falha: Cofre fechado. Nao e possivel remover itens.";
    }
    auto it = find(itens.begin(), itens.end(), item);
    if (it != itens.end()) {
        itens.erase(it);
        return "Sucesso: Item '" + item + "' removido.";
    }
    return "Falha: Item '" + item + "' nao encontrado no cofre.";
}

string Cofre::listarItens() const {
    if (!aberto) {
        return "Falha: Cofre fechado. Nao e possivel listar itens.";
    }
    if (itens.empty()) {
        return "Cofre vazio.";
    }
    ostringstream resposta;
    resposta << "Itens no cofre:\n";
    for (const auto& item : itens) {
        resposta << "- " << item << "\n";
    }
    return resposta.str();
}

string Cofre::mudarCodigo(const string& codigoAntigo, const string& novoCodigo) {
    if (!aberto) {
        return "Falha: Cofre fechado. Nao e possível mudar o Codigo.";
    }
    if (ultimoCodigoTentado.empty() && codigoAntigo == codigo) {
        ultimoCodigoTentado = novoCodigo;
        return "Primeira etapa de mudanca de Codigo realizada. Insira novamente o novo codigo.";
    }
    if (!ultimoCodigoTentado.empty() && ultimoCodigoTentado == novoCodigo) {
        codigo = novoCodigo;
        ultimoCodigoTentado.clear();
        return "Sucesso: Codigo alterado.";
    }
    ultimoCodigoTentado.clear();
    return "Falha: Codigo antigo incorreto ou nova tentativa invalida.";
}
