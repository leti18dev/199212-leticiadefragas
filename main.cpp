#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string nome, double preco) : nome(nome), preco(preco) {}

    virtual void exibirInformacoes() const = 0;

    string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }
};


class Oleo : public Produto {
public:
    Oleo(double preco) : Produto("Oleo para Cambio", preco) {}

    void exibirInformacoes() const override {
        cout << "Produto: " << nome << ", Preco: R$" << preco << endl;
    }
};

class KitEmbreagem : public Produto {
public:
    KitEmbreagem(double preco) : Produto("Kit de Embreagem", preco) {}

    void exibirInformacoes() const override {
        cout << "Produto: " << nome << ", Preco: R$" << preco << endl;
    }
};

class BombaDeDirecao : public Produto {
public:
    BombaDeDirecao(double preco) : Produto("Bomba de Direcao Hidraulica", preco) {}

    void exibirInformacoes() const override {
        cout << "Produto: " << nome << ", Preco: R$" << preco << endl;
    }
};

class ConversorDeTorque : public Produto {
public:
    ConversorDeTorque(double preco) : Produto("Conversor de Torque", preco) {}

    void exibirInformacoes() const override {
        cout << "Produto: " << nome << ", Preco: R$" << preco << endl;
    }
};

class CaixaDeDirecao : public Produto {
public:
    CaixaDeDirecao(double preco) : Produto("Caixa de Direcao", preco) {}

    void exibirInformacoes() const override {
        cout << "Produto: " << nome << ", Preco: R$" << preco << endl;
    }
};


class Estoque {
private:
    vector<pair<Produto*, int>> produtos;

public:
    void adicionarProduto(Produto* produto, int quantidade) {
        produtos.push_back(make_pair(produto, quantidade));
    }

    void listarProdutos() const {
        cout << "Estoque da Oficina:" << endl;
        for (const auto& item : produtos) {
            item.first->exibirInformacoes();
            cout << "Quantidade: " << item.second << endl;
        }
    }

    bool verificarDisponibilidade(Produto* produto, int quantidade) const {
        for (const auto& item : produtos) {
            if (item.first->getNome() == produto->getNome() && item.second >= quantidade) {
                return true;
            }
        }
        return false;
    }

    void atualizarEstoque(Produto* produto, int quantidade) {
        for (auto& item : produtos) {
            if (item.first->getNome() == produto->getNome()) {
                item.second -= quantidade;
                break;
            }
        }
    }
};


class Pedido {
private:
    Produto* produto;
    int quantidade;

public:
    Pedido(Produto* produto, int quantidade) : produto(produto), quantidade(quantidade) {}

    void exibirPedido() const {
        cout << "Pedido - Produto: " << produto->getNome() << ", Quantidade: " << quantidade << endl;
    }

    Produto* getProduto() const {
        return produto;
    }

    int getQuantidade() const {
        return quantidade;
    }
};


class Mecanica {
private:
    string nome;
    Estoque estoque;
    vector<Pedido> pedidos;

public:
    Mecanica(string nome) : nome(nome) {}

    void adicionarProdutoAoEstoque(Produto* produto, int quantidade) {
        estoque.adicionarProduto(produto, quantidade);
    }

    void listarEstoque() {
        estoque.listarProdutos();
    }

    void fazerPedido(Produto* produto, int quantidade) {
        if (estoque.verificarDisponibilidade(produto, quantidade)) {
            Pedido pedido(produto, quantidade);
            pedidos.push_back(pedido);
            estoque.atualizarEstoque(produto, quantidade);
            cout << "Pedido realizado com sucesso!" << endl;
        } else {
            cout << "Produto indisponível no estoque!" << endl;
        }
    }

    void listarPedidos() const {
        cout << "Pedidos realizados:" << endl;
        for (const auto& pedido : pedidos) {
            pedido.exibirPedido();
        }
    }
};


int main() {
    Mecanica oficina("Mecanica PortesCar");

    Produto* oleo = new Oleo(50.0);
    Produto* kitEmbreagem = new KitEmbreagem(300.0);
    Produto* bombaDeDirecao = new BombaDeDirecao(400.0);
    Produto* conversorDeTorque = new ConversorDeTorque(700.0);
    Produto* caixaDeDirecao = new CaixaDeDirecao(600.0);

    oficina.adicionarProdutoAoEstoque(oleo, 10);
    oficina.adicionarProdutoAoEstoque(kitEmbreagem, 5);
    oficina.adicionarProdutoAoEstoque(bombaDeDirecao, 3);
    oficina.adicionarProdutoAoEstoque(conversorDeTorque, 2);
    oficina.adicionarProdutoAoEstoque(caixaDeDirecao, 4);

    oficina.listarEstoque();

    oficina.fazerPedido(oleo, 3);
    oficina.fazerPedido(kitEmbreagem, 2);
    oficina.fazerPedido(bombaDeDirecao, 1);

    oficina.listarEstoque();
    oficina.listarPedidos();


    return 0;
}
