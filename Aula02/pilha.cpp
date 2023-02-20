#include <iostream>

using namespace std;
typedef int TipoItem;

const int max_itens = 100;

class Pilha
{
private:
    int tamanho;
    int *estrutura;

public:
    // construtora
    Pilha()
    {
        this->tamanho = 0;
        this->estrutura = new TipoItem[max_itens];
    }
    // destrutora
    ~Pilha()
    {
        delete[] estrutura;
    }
    bool estaCheia()
    {
        return (this->tamanho == max_itens);
    }
    bool estaVazia()
    {
        return (this->tamanho == 0);
    }
    void inserir(TipoItem item)
    {
        if (estaCheia())
        {
            cout << "A pilha está cheia." << endl;
        }
        else
        {
            estrutura[tamanho] = item;
            this->tamanho++;
        }
    }
    TipoItem remover()
    {
        if (estaVazia())
        {
            cout << "Pilha vazia, não é possivel remover." << endl;
        }
        else
        {
            tamanho--;
            return estrutura[tamanho - 1];
        }
    }
    void imprimir()
    {
        cout << "Pilha: [ ";
        for (int i = 0; i < tamanho; i++)
        {
            cout << estrutura[i] << " ";
        }
        cout << "]" << endl;
    }
    int exibirTamanho()
    {
        return this->tamanho;
    }
};
int main()
{
    Pilha pilha;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de pilhas" << endl;

    do
    {
        cout << "0 - Parar\n1 - Inserir\n2 - Remover\n3 - Imprimir" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            cout << "Digite o elemento a ser inserido: ";
            cin >> item;
            pilha.inserir(item);
        }
        else if (opcao == 2)
        {
            pilha.remover();
            cout << "Elemento removido." << endl;
        }
        else if (opcao == 3)
        {
            pilha.imprimir();
        }
    } while (opcao != 0);
    return 0;
}