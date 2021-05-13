#include "vendor.h"

Vendor::Vendor(string name, string cpf, string email, string password) : User(name, cpf, email, password), id(3){}
Vendor::~Vendor(){}

int Vendor::get_id() const { return id; }

int Vendor::interface(){

    int opcao;

    cout << " ________________________________________________\n";
    cout << "|                                                |\n";
    cout << "|  Vendedor                                      |\n";
    cout << "|                                                |\n";
    cout << "|  [01] Cadastrar cliente                        |\n";
    cout << "|  [02] Cadastrar veiculo                        |\n";
    cout << "|  [03] Gerar ordem de servico                   |\n";
    cout << "|  [04] Visualizar ordens de servico pendentes   |\n";
    cout << "|  [05] Visualizar ordens de servico executadas  |\n";
    cout << "|  [06] Confirmar ordem de servico               |\n";
    cout << "|  [07] Fechar ordem de servico                  |\n";
    cout << "|  [08] Mostrar cliente                          |\n";
    cout << "|  [09] Mostrar Historico                        |\n";
    cout << "|  [10] Mostrar servicos disponiveis na oficina  |\n";
    cout << "|  [00] Sair                                     |\n";
    cout << "|________________________________________________|\n\n";

    do
    {

        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 10))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    return opcao;
}