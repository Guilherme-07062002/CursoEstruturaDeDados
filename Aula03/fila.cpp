#include <iostream>

using namespace std;

typedef int TipoItem;
const int max_itens = 10;

class Fila
{
private:
    int primeiro, ultimo;
    TipoItem *estrutura;

public:
    Fila()
    {
        this->primeiro = 0;
        this->ultimo = 0;
        estrutura = new TipoItem[max_itens];
    }
    ~Fila()
    {
        delete[] estrutura;
    }
    bool estaVazio()
    {
        return (this->ultimo == this->primeiro);
    }
    bool estaCheio()
    {
        return ((this->ultimo - this->primeiro) == max_itens);
    }
    void inserir(TipoItem item)
    {
        if (estaCheio())
        {
            cout << "Fila está cheia, não é possivel inserir." << endl;
        }
        else
        {
            estrutura[ultimo % max_itens] = item;
            this->ultimo++;
        }
    }
    TipoItem remover()
    {
        if (estaVazio())
        {
            cout << "Fila está vazia, não é possivel remover." << endl;
        }
        else
        {
            primeiro++;
            return estrutura[(primeiro - 1) % max_itens];
        }
    }
    void imprimir()
    {
        cout << "Pilha: [ ";
        for (int i = primeiro; i < ultimo; i++)
        {
            cout << estrutura[i % max_itens] << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    Fila fila;
    TipoItem item;
    int opcao;

    cout << "Programa gerador de filas" << endl;

    do
    {
        cout << "0 - Parar\n1 - Inserir\n2 - Remover\n3 - Imprimir" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            cout << "Digite o elemento a ser inserido: ";
            cin >> item;
            fila.inserir(item);
        }
        else if (opcao == 2)
        {
            fila.remover();
            cout << "Elemento removido." << endl;
        }
        else if (opcao == 3)
        {
            fila.imprimir();
        }
    } while (opcao != 0);
    return 0;
}