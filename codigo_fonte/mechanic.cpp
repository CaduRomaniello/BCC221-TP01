#include "mechanic.h"

Mechanic::Mechanic(string name, string cpf, string email, string password) : User(name, cpf, email, password), id(2){}
Mechanic::~Mechanic(){}

int Mechanic::get_id() const { return id; }

int Mechanic::interface(){

    int opcao;

    cout << " _____________________________________________\n";
    cout << "|                                             |\n";
    cout << "|  Mecanico                                   |\n";
    cout << "|                                             |\n";
    cout << "|  [01] Visualizar ordens de servico abertas  |\n";
    cout << "|  [02] Cadastrar servicos executados         |\n";
    cout << "|  [03] Executar ordem de servico             |\n";
    cout << "|  [04] Cadastrar pecas utilizadas            |\n";
    cout << "|  [05] Mostrar dados da conta                |\n";
    cout << "|  [06] Mostrar servicos disponiveis          |\n";
    cout << "|  [07] Mostrar pecas disponiveis             |\n";
    cout << "|  [00] Sair                                  |\n";
    cout << "|_____________________________________________|\n\n";

    do
    {

        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 7))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    return opcao;
}
