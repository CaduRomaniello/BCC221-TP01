#include "admin.h"

Admin::Admin(string name, string cpf, string email, string password) : User(name, cpf, email, password), id(1){}
Admin::~Admin(){}

int Admin::get_id() const { return id; }

int Admin::interface(){

    int opcao;

    cout << " _______________________________\n";
    cout << "|                               |\n";
    cout << "|  Administrador                |\n";
    cout << "|                               |\n";
    cout << "|  [01] Opcoes mecanicos        |\n";
    cout << "|  [02] Opcoes vendedores       |\n";
    cout << "|  [03] Editar funcionario      |\n";
    cout << "|  [04] Contratar funcionario   |\n";
    cout << "|  [05] Demitir funcionario     |\n";
    cout << "|  [06] Disponibilizar servico  |\n";
    cout << "|  [07] Disponibilizar peca     |\n";
    cout << "|  [08] Mostrar dados           |\n";
    cout << "|  [09] Mostrar dados da conta  |\n";
    cout << "|  [00] Sair                    |\n";
    cout << "|_______________________________|\n\n";

    do
    {

        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 9))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    return opcao;
}
