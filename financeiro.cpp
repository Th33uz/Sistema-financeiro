#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Definição da estrutura para representar uma transação
struct Transacao {
    float valor;
    string descricao;
    string categoria;
};

// Função para exibir o histórico completo de transações
void exibirHistoricoTransacoes(const vector<Transacao>& transacoes) {
    cout << "---- Historico de Transacoes ----" << endl;
    for (const auto& transacao : transacoes) {
        cout << "Valor: " << transacao.valor << " | Descricao: " << transacao.descricao << " | Categoria: " << transacao.categoria << endl;
    }
    cout << endl;
}

// Função para calcular o valor total gasto em cada categoria e o valor total geral
void calcularTotais(const vector<Transacao>& transacoes) {
    map<string, float> totaisCategoria;
    float totalGeral = 0.0;

    for (const auto& transacao : transacoes) {
        totaisCategoria[transacao.categoria] += transacao.valor;
        totalGeral += transacao.valor;
    }

    cout << "---- Total por Categoria ----" << endl;
    for (const auto& par : totaisCategoria) {
        cout << "Categoria: " << par.first << " | Total: " << par.second << endl;
    }

    cout << "---- Total Geral ----" << endl;
    cout << "Total: " << totalGeral << endl;
}

// Função principal
int main() {
    vector<Transacao> transacoes;

    // Loop principal do programa
    int escolha;
    do {
        cout << "Selecione uma opcao:" << endl;
        cout << "1. Adicionar transacao" << endl;
        cout << "2. Exibir historico de transacoes" << endl;
        cout << "3. Calcular totais" << endl;
        cout << "4. Sair" << endl;
        cout << "Opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                Transacao novaTransacao;
                cout << "Digite o valor da transacao: ";
                cin >> novaTransacao.valor;
                cout << "Digite a descricao da transacao: ";
                cin.ignore(); // Limpa o buffer do teclado
                getline(cin, novaTransacao.descricao);
                cout << "Selecione a categoria da transacao: ";
                cin >> novaTransacao.categoria;
                transacoes.push_back(novaTransacao);
                break;
            }
            case 2:
                exibirHistoricoTransacoes(transacoes);
                break;
            case 3:
                calcularTotais(transacoes);
                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (escolha != 4);

    return 0;
}
// Função para gerar relatório por categoria
void gerarRelatorioPorCategoria(const vector<Transacao>& transacoes) {
    string categoria;
    cout << "Digite a categoria para gerar o relatorio: ";
    cin >> categoria;

    cout << "---- Relatorio para Categoria: " << categoria << " ----" << endl;
    for (const auto& transacao : transacoes) {
        if (transacao.categoria == categoria) {
            cout << "Valor: " << transacao.valor << " | Descricao: " << transacao.descricao << endl;
        }
    }
    cout << endl;
}
// Função para definir metas financeiras por categoria
void definirMetasFinanceiras(map<string, float>& metas) {
    string categoria;
    float meta;
    cout << "Digite a categoria para definir a meta financeira: ";
    cin >> categoria;
    cout << "Digite a meta financeira para a categoria " << categoria << ": ";
    cin >> meta;
    metas[categoria] = meta;
}
// Função para monitorar o progresso do usuário em relação às metas financeiras
void monitorarProgressoMetas(const vector<Transacao>& transacoes, const map<string, float>& metas) {
    cout << "---- Progresso em relacao as metas financeiras ----" << endl;
    for (const auto& par : metas) {
        float gastosCategoria = 0.0;
        for (const auto& transacao : transacoes) {
            if (transacao.categoria == par.first) {
                gastosCategoria += transacao.valor;
            }
        }
        cout << "Categoria: " << par.first << " | Meta: " << par.second << " | Gastos: " << gastosCategoria << endl;
        if (gastosCategoria <= par.second) {
            cout << "Você esta dentro da meta!" << endl;
        } else {
            cout << "Você ultrapassou a meta!" << endl;
        }
    }
}
