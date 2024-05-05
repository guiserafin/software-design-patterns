#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    vector<Observer*> observers;

public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};


class Notificador {
public:
    void enviarNotificacao(string mensagem) {
        cout << "Enviando notificação: " << mensagem << endl;
    }
};


class Loja : public Subject {
private:
    string nome;
    vector<string> produtos;
    vector<double> precos;

public:
    Loja(string nome) : nome(nome) {}

    void adicionarProduto(string produto, double preco) {
        produtos.push_back(produto);
        precos.push_back(preco);
        notifyObservers();
    }

    void alterarPreco(string produto, double novoPreco) {
        for (size_t i = 0; i < produtos.size(); ++i) {
            if (produtos[i] == produto) {
                precos[i] = novoPreco;
                notifyObservers();
                return;
            }
        }
        cout << "Produto não encontrado!" << endl;
    }

    const string& getNome() const {
        return nome;
    }

    const vector<string>& getProdutos() const {
        return produtos;
    }

    const vector<double>& getPrecos() const {
        return precos;
    }
};

class Usuario : public Observer {
private:
    string nome;
    Notificador* notificador;

public:
    Usuario(string nome, Notificador* notificador) : nome(nome), notificador(notificador) {}

    void update() override {
        notificador->enviarNotificacao("Olá " + nome + "! Um produto foi adicionado ou teve seu preço alterado na loja.");
    }

    void receberNotificacao(string mensagem) {
        cout << nome << " recebeu a notificação: " << mensagem << endl;
    }
};

int main() {
    Notificador notificador;

    Loja loja("Minha Loja");

    Usuario usuario1("Alice", &notificador);
    Usuario usuario2("Bob", &notificador);


    loja.registerObserver(&usuario1);
    loja.registerObserver(&usuario2);

    loja.adicionarProduto("Camisa", 29.99);
    loja.alterarPreco("Camisa", 25.99);

    return 0;
}
