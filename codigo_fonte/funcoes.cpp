#include "funcoes.h"
#include <locale.h>

using namespace std;

void login(Oficina* oficina){

    int usuario = 0;
    string cpf;
    string senha;
    bool verificador_login;
    int opcao = 1;

    do{
        CLEAR();

        cout << "Qual o tipo de login?\n";

        cout << " ______________________\n";
        cout << "|                      |\n";
        cout << "|  [01] Administrador  |\n";
        cout << "|  [02] Mecanico       |\n";
        cout << "|  [03] Vendedor       |\n";
        cout << "|  [00] Sair           |\n";
        cout << "|______________________|\n\n";
        cout << "Digite sua opcao: ";
        cin >> usuario;

        if (usuario >= 1 && usuario <= 3){

            cout << "Digite seu CPF: ";
            cin >> cpf;
            cout << "Digite sua senha: ";
            cin >> senha;
        }

        switch (usuario)
        {
        case 1:

            verificador_login = oficina->confirm_adm(cpf, senha);

            if (verificador_login == true){

                do{
                    CLEAR();
                    Admin adm;
                    opcao = adm.interface();

                    adm_options(opcao, oficina, cpf);

                }while (opcao != 0);

            }
            else{
                cout <<"\nUsuario nao cadastrado!\n";
                char aux;
                do {
                    cout << "Digite 'S' para continuar ...";
                    cin >> aux;
                }while (aux != 'S' && aux != 's');
            }

            break;

        case 2:

            verificador_login = oficina->confirm_mechanic(cpf, senha);

            if (verificador_login == true){

                do{

                    CLEAR();
                    Mechanic mecanico;
                    opcao = mecanico.interface();
                    mechanic_options(opcao, oficina, cpf);

                }while (opcao != 0);

            }
            else{
                cout <<"\nUsuario nao cadastrado!\n";
                char aux;
                do {
                    cout << "Digite 'S' para continuar ...";
                    cin >> aux;
                }while (aux != 'S' && aux != 's');
            }

            break;

        case 3:

            verificador_login = oficina->confirm_vendor(cpf, senha);

            if (verificador_login == true){

                do{

                    CLEAR();
                    Vendor vendedor;
                    opcao = vendedor.interface();
                    vendor_options(opcao, oficina, cpf);

                }while (opcao != 0);

            }
            else{
                cout <<"\nUsuario nao cadastrado!\n";
                char aux;
                do {
                    cout << "Digite 'S' para continuar ...";
                    cin >> aux;
                }while (aux != 'S' && aux != 's');
            }

            break;

        default:
            break;
        }

    }while(usuario != 0);

    CLEAR();

}

void adm_options(int opcao, Oficina *oficina, string cpf){
    int opcaoM = 0;
    int opcaoV = 0;
    switch (opcao)
    {
    case 1:
        do
        {

            CLEAR();
            Mechanic mecanico;
            opcaoM = mecanico.interface();
            mechanic_options(opcaoM, oficina, cpf);

        } while (opcaoM != 0);
        break;

    case 2:
        do
        {

            CLEAR();
            Vendor vendedor;
            opcaoV = vendedor.interface();
            vendor_options(opcaoV, oficina, cpf);

        } while (opcaoV != 0);
        break;

    case 3://
        oficina->update_staff_display();
        break;

    case 4://
        oficina->hire_staff_display();
        break;

    case 5://
        oficina->fire_staff_display();
        break;

    case 6:
        oficina->register_available_service();
        break;

    case 7:
        oficina->register_available_automobile_part();
        break;

    case 8:
        oficina->display_interface();
        break;

    case 9:
        oficina->display_staff(cpf);
        break;
    }
}
void mechanic_options(int opcao, Oficina* oficina, string cpf){
    switch(opcao)
    {
        case 1:
            oficina->lookup_confirmed_services();
            break;

        case 2:
            oficina->register_service();
            break;

        case 3:
            oficina->execute_service_order();
            break;

        case 4:
            oficina->register_auto_part();
            break;

        case 5:
            oficina->display_staff(cpf);
            break;

        case 6:
            oficina->lookup_available_services();
            break;

        case 7:
            oficina->lookup_available_automobile_parts();
            break;

        default:
            break;
    }
}
void vendor_options(int opcao, Oficina* oficina, string cpf){

    switch (opcao)
    {
    case 1: // cadastrar cliente
        
        oficina->register_client();

        break;
    
    case 2: // cadastrar veiculo

        oficina->register_vehicle();

        break;

    case 3: // gerar ordem de servico

        oficina->register_service_order();

        break;

    case 4: // vizualizar pendentes

        oficina->lookup_pending_services();

        break;

    case 5: // vizualizar executadas

        oficina->lookup_executed_services();

        break;

    case 6: // confirmar ordem de servico aprovada pelo cliente

        oficina->confirm_service_order();

        break;

    case 7: // fechar ordem de servico

        oficina->close_service_order();

        break;

    case 8: // mostra clientes

        oficina->display_clients();

        break;

    case 9: // mostrar historico

        oficina->display_historic();

        break;

    case 10: // mostrar serviços disponiveis na oficina

        oficina->lookup_available_services();

        break;

    default:
        break;
    }

}
