#include "oficina.h"

Oficina::Oficina() : adm("joao", "0123456", "joao@hotmail.com", "abc123") {}
Oficina::~Oficina(){}

bool Oficina::confirm_adm(string cpf, string senha){
    if (cpf == adm.get_cpf() && senha == adm.get_password()){
        return true;
    }
    else{
        return false;
    }
}

void Oficina::push_mechanics(string cpf, Mechanic mechanic){
    bool criou =  mechanics.insert(make_pair(cpf, mechanic)).second;
    if (criou == false){
        cout << "Mecânico já registrado!\n";
        cout << "CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_mechanics(string cpf){
    int removidos = mechanics.erase(cpf);
    if (removidos == 0){
        cout << "Não é possível realizar essa ação pois não existe mecânico cadastrado com o CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
bool Oficina::confirm_mechanic(string cpf, string senha){

    auto mecanico = mechanics.find(cpf);
    if (mecanico != mechanics.end() && mecanico->second.get_password() == senha){
        return true;
    }
    else{
        return false;
    }

}

void Oficina::push_vendors(string cpf, Vendor vendor){
    bool criou =  vendors.insert(make_pair(cpf, vendor)).second;
    if (criou == false){
        cout << "Vendedor já registrado!\n";
        cout << "CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_vendors(string cpf){
    int removidos = vendors.erase(cpf);
    if (removidos == 0){
        cout << "Não é possível realizar essa ação pois não existe vendedor cadastrado com o CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

bool Oficina::confirm_vendor(string cpf, string senha){

    auto vendor = vendors.find(cpf);
    if (vendor != vendors.end() && vendor->second.get_password() == senha){
        return true;
    }
    else{
        return false;
    }


}

void Oficina::push_clients(string cpf, Client client){
    bool criou =  clients.insert(make_pair(cpf, client)).second;
    if (criou == false){
        cout << "Cliente ja registrado!\n";
        cout << "CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_clients(string cpf){
    int removidos = clients.erase(cpf);
    if (removidos == 0){
        cout << "Nao foi possivel realizar essa acao pois nao existe cliente cadastrado com o CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

void Oficina::push_pending(int id, ServiceOrder service_order){
    bool criou =  pending_services.insert(make_pair(id, service_order)).second;
    if (criou == false){
        cout << "Ordem de servico pendente ja registrada!\n";
        cout << "ID: " << id << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_pending(int id){
    int removidos = pending_services.erase(id);
    if (removidos == 0){
        cout << "Nao foi possivel realizar essa acao pois nao existe ordem de servico pendente cadastrada com o ID: " << id << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

void Oficina::push_completed(int id, ServiceOrder service_order){
    bool criou =  completed_services.insert(make_pair(id, service_order)).second;
    if (criou == false){
        cout << "Ordem de servico completo ja registrada!\n";
        cout << "ID: " << id << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_completed(int id){
    int removidos = completed_services.erase(id);
    if (removidos == 0){
        cout << "Nao foi possivel realizar essa acao pois nao existe ordem de servico completa cadastrads com o ID: " << id << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

void Oficina::push_confirmed(int id, ServiceOrder service_order){
    bool criou =  confirmed_services.insert(make_pair(id, service_order)).second;
    if (criou == false){
        cout << "Ordem de servico completo ja registrada!\n";
        cout << "ID: " << id << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_confirmed(int id){
    int removidos = confirmed_services.erase(id);
    if (removidos == 0){
        cout << "Nao foi possivel realizar essa acao pois nao existe ordem de servico completa cadastrads com o ID: " << id << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

void Oficina::push_available_services(string service_name, Service service){
    bool criou =  available_services.insert(make_pair(service_name, service)).second;
    if (criou == false){
        cout << "Servico ja registrado!\n";
        cout << "Nome: " << service_name << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_available_services(string service_name){
    int removidos = available_services.erase(service_name);
    if (removidos == 0){
        cout << "Nao foi possivel realizar essa acao pois nao existe servico cadastrado com o nome: " << service_name << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

void Oficina::push_available_automobile_parts(string part_name, AutoPart part){
    bool criou = available_automobile_parts.insert(make_pair(part_name, part)).second;
    if (criou == false){
        cout << "Peca ja registrada!\n";
        cout << "Nome: " << part_name << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}
void Oficina::pop_available_automobile_parts(string part_name){
    int removidos = available_automobile_parts.erase(part_name);
    if (removidos == 0){
        cout << "Nao foi possivel realizar essa acao pois nao existe peca cadastrada com o nome: " << part_name << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }
}

// Register in Service Order

void Oficina::register_service(){

    int cod_service_order;
    string nome_servico;
    char opcao;

    cout << "Deseja ver todas as ordens de servicos aprovadas? (S/N) ";
    cin >> opcao;

    if (opcao == 'S' || opcao == 's')
    {
        lookup_confirmed_services();
    }

    cout << "Digite o ID da ordem de servico que sera alterada: ";
    cin >> cod_service_order;

    auto it = this->confirmed_services.find(cod_service_order);

    if (it == this->confirmed_services.end()){
        cout << "Ordem de servico nao cadastrada!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;
    }

    cout << "Digite o nome do servico que sera cadastrado: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, nome_servico);

    auto it_service = this->available_services.find(nome_servico);

    if (it_service == this->available_services.end()){
        cout << "Servico nao cadastrado!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;
    }

    it->second.push_service(it_service->second.get_service_name(), it_service->second);

    float old_cost = it->second.get_cost();
    float adding_cost = it_service->second.get_service_price();
    it->second.set_cost(old_cost + adding_cost);

    clients[it->second.get_owner_cpf()].vehicles[it->second.get_placa()].historic[cod_service_order].set_cost(old_cost + adding_cost);

}
void Oficina::register_auto_part(){

    int cod_service_order, qntd_pecas;
    string nome_peca;
    char opcao;

    cout << "Deseja ver todas as ordens de servicos aprovadas? (S/N) ";
    cin >> opcao;

    if (opcao == 'S' || opcao == 's')
    {
        lookup_confirmed_services();
    }

    cout << "\nDigite o ID da ordem de servico que sera alterada: ";
    cin >> cod_service_order;

    auto it = this->confirmed_services.find(cod_service_order);

    if (it == this->confirmed_services.end()){
        cout << "Ordem de servico nao cadastrada!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;
    }

    cout << "Digite o nome da peca que sera cadastrado: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, nome_peca);

    auto it_peca = this->available_automobile_parts.find(nome_peca);

    if (it_peca == this->available_automobile_parts.end()){
        cout << "Peca nao cadastrada!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;
    }

    AutoPart aux = it_peca->second;

    cout << "Digite quantas pecas serao utilizadas: ";
    cin >> qntd_pecas;
    aux.set_quantity(qntd_pecas);

    it->second.push_automobile_part(it_peca->second.get_part_name(), it_peca->second);

    float old_cost = it->second.get_cost();
    float adding_cost = it_peca->second.get_part_price() * qntd_pecas;
    it->second.set_cost(old_cost + adding_cost);

    clients[it->second.get_owner_cpf()].vehicles[it->second.get_placa()].historic[cod_service_order].set_cost(old_cost + adding_cost);

}

// Display Interface

void Oficina::display_interface(){
    int opcao;

    CLEAR();

    cout << " _____________________________________________\n";
    cout << "|                                             |\n";
    cout << "|  Mostrar dados                              |\n";
    cout << "|                                             |\n";
    cout << "|  [01] Mostar mecanicos                      |\n";
    cout << "|  [02] Mostar vendedores                     |\n";
    cout << "|  [03] Mostar clientes                       |\n";
    cout << "|  [04] Mostar ordens de servicos pendentes   |\n";
    cout << "|  [05] Mostar ordens de servicos aprovados   |\n";
    cout << "|  [06] Mostar ordens de servicos completos   |\n";
    cout << "|  [07] Mostar servicos disponiveis           |\n";
    cout << "|  [08] Mostar pecas disponiveis              |\n";
    cout << "|  [09] Mostar historico de veiculo           |\n";
    cout << "|  [10] Mostar dados de uma ordem de servico  |\n";
    cout << "|  [00] Sair                                  |\n";
    cout << "|_____________________________________________|\n\n";

    do
    {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 10))
        {
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    switch(opcao){
        case 1:
            display_mechanics();
            break;

        case 2:
            display_vendors();
            break;

        case 3:
            display_clients();
            break;

        case 4:
            lookup_pending_services();
            break;

        case 5:
            lookup_confirmed_services();
            break;

        case 6:
            lookup_completed_services();
            break;

        case 7:
            lookup_available_services();
            break;

        case 8:
            lookup_available_automobile_parts();
            break;

        case 9:
            display_historic();
            break;

        case 10:
            display_service_order();
            break;
    }
}
void Oficina::display_staff(string cpf)
{
    if (adm.get_cpf() == cpf)
        adm.display();
    else if (mechanics.find(cpf) != mechanics.end())
        mechanics.find(cpf)->second.display();
    else
        vendors.find(cpf)->second.display();
    char c;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> c;
    }while (c != 'S' && c != 's');
}

// Alter Staff

void Oficina::update_staff_display(){

    int opcao;
    string cpf;

    CLEAR();

    cout << " _______________________\n";
    cout << "|                       |\n";
    cout << "|  Editar funcionario   |\n";
    cout << "|                       |\n";
    cout << "|  [01] Email mecanico  |\n";
    cout << "|  [02] Email vendedor  |\n";
    cout << "|  [03] Senha mecanico  |\n";
    cout << "|  [04] Senha vendedor  |\n";
    cout << "|  [00] Sair            |\n";
    cout << "|_______________________|\n\n";

    do
    {

        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 4))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    switch(opcao){
        case 1:

            if (mechanics.size() > 0)
            {
                cout << "Digite o CPF do mecanico: ";
                cin >> cpf;
                update_staff_email(cpf, &mechanics);
            }
            else
            {
                cout << "Nenhum mecanico contratado!\n";
                char aux;
                do
                {
                    cout << "Digite 'S' para continuar ... ";
                    cin >> aux;
                } while (aux != 'S' && aux != 's');
            }
            
            break;

        case 2:

            if (vendors.size() > 0)
            {
                cout << "Digite o CPF do vendedor: ";
                cin >> cpf;
                update_staff_email(cpf, &vendors);
            }
            else
            {
                cout << "Nenhum vendedor contratado!\n";
                char aux;
                do
                {
                    cout << "Digite 'S' para continuar ... ";
                    cin >> aux;
                } while (aux != 'S' && aux != 's');
            }

            break;

        case 3:

            if (mechanics.size() > 0)
            {
                cout << "Digite o CPF do mecanico: ";
                cin >> cpf;
                update_staff_password(cpf, &mechanics);
            }
            else
            {
                cout << "Nenhum mecanico contratado!\n";
                char aux;
                do
                {
                    cout << "Digite 'S' para continuar ... ";
                    cin >> aux;
                } while (aux != 'S' && aux != 's');
            }

            break;

        case 4:

            if (vendors.size() > 0)
            {
                cout << "Digite o CPF do vendedor: ";
                cin >> cpf;
                update_staff_password(cpf, &vendors);
            }
            else
            {
                cout << "Nenhum vendedor contratado!\n";
                char aux;
                do
                {
                    cout << "Digite 'S' para continuar ... ";
                    cin >> aux;
                } while (aux != 'S' && aux != 's');
            }

            break;
    }
}
void Oficina::hire_staff_display()
{

    int opcao;
    string cpf;

    CLEAR();

    cout << " ___________________________\n";
    cout << "|                           |\n";
    cout << "|  Contratar funcionario    |\n";
    cout << "|                           |\n";
    cout << "|  [01] Contratar mecanico  |\n";
    cout << "|  [02] Contratar vendedor  |\n";
    cout << "|  [00] Sair                |\n";
    cout << "|___________________________|\n\n";

    do
    {

        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 2))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    switch(opcao){
        case 1:
            hire_staff(&mechanics);
            break;

        case 2:
            hire_staff(&vendors);
            break;
    }
}
void Oficina::fire_staff_display()
{

    int opcao;
    string cpf;

    CLEAR();

    cout << " _________________________\n";
    cout << "|                         |\n";
    cout << "|  Demitir funcionario    |\n";
    cout << "|                         |\n";
    cout << "|  [01] Demitir mecanico  |\n";
    cout << "|  [02] Demitir vendedor  |\n";
    cout << "|  [00] Sair              |\n";
    cout << "|_________________________|\n\n";

    do
    {

        cout << "Digite sua opcao: ";
        cin >> opcao;

        if (std::cin.fail() || (opcao < 0 && opcao > 2))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nOpcao invalida!\n\n";
            opcao = 1000;
        }

    } while (opcao == 1000);

    switch (opcao)
    {
        case 1:

            if (mechanics.size() > 0)
            {
                cout << "Digite o CPF do mecanico: ";
                cin >> cpf;
                fire_staff(cpf, &mechanics);
            } 
            else
            {
                cout << "Nenhum mecanico contratado, antes de demitir, contrate um!\n";
                char aux;
                do
                {
                    cout << "Digite 'S' para continuar ... ";
                    cin >> aux;
                } while (aux != 'S' && aux != 's');
            }

            break;

        case 2:

            if (vendors.size() > 0)
            {
                cout << "Digite o CPF do vendedor: ";
                cin >> cpf;
                fire_staff(cpf, &vendors);
            } 
            else
            {
                cout << "Nenhum vendedor contratado, antes de demitir, contrate um!\n";
                char aux;
                do
                {
                    cout << "Digite 'S' para continuar ... ";
                    cin >> aux;
                } while (aux != 'S' && aux != 's');
            }

            break;
    }
}

STAFF void Oficina::update_staff_email(string cpf, map<string, Staff>* staffs){

    string email;
    auto staff = staffs->find(cpf);

    if(staff != staffs->end())
    {
        cout << "Digite o novo email: ";
        cin >> email;

        staff->second.set_email(email);
    }

}
STAFF void Oficina::update_staff_password(string cpf, map<string, Staff>* staffs){

    string password;
    auto staff = staffs->find(cpf);

    if (staff != staffs->end())
    {
        cout << "Digite a nova senha: ";
        cin >> password;

        staff->second.set_password(password);
    }
}

STAFF void Oficina::hire_staff(map<string, Staff>* staffs){

    string name;
    string cpf;
    string email;
    string senha;

    cout << "Digite o nome do funcionario: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, name);
    cout << "Digite o CPF do funcionario: ";
    cin >> cpf;
    cout << "Digite o email do funcionario: ";
    cin >> email;
    cout << "Digite a senha do funcionario: ";
    cin >> senha;

    Staff staff(name, cpf, email, senha);

    bool criou = staffs->insert(make_pair(cpf, staff)).second;
    if (criou == false)
    {
        cout << "\nFuncionario ja registrado!\n";
        cout << "CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }

}
STAFF void Oficina::fire_staff(string cpf, map<string, Staff>* staffs){

    int removidos = staffs->erase(cpf);
    if (removidos == 0)
    {
        cout << "Nao foi possivel realizar essa acao pois nao existe funcionario cadastrado com o CPF: " << cpf << "\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
    }

}

void Oficina::register_available_service(){

    string service_name;
    float service_price;

    do
    {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\nDigite o nome do servico: ";
        getline(cin, service_name);

        cout << "Digite o preco do servico: R$ ";
        cin >> service_price;

        if (std::cin.fail() || service_price < 0)
        {
            cout << "\nOpcao invalida!\n\n";
            service_price = -1;
        }

    } while (service_price == -1);

    Service service(service_name, service_price);

    push_available_services(service_name, service);

}
void Oficina::register_available_automobile_part(){

    string part_name;
    float part_price;

    do
    {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\nDigite o nome da peca: ";
        getline(cin, part_name);

        cout << "Digite o preco da peca: R$ ";
        cin >> part_price;

        if (std::cin.fail() || part_price < 0)
        {
            cout << "\nOpcao invalida!\n\n";
            part_price = -1;
        }

    } while (part_price == -1);

    AutoPart part(part_name, 0, part_price);

    push_available_automobile_parts(part_name, part);

}

// Method to execute a specific service order

void Oficina::execute_service_order()
{

    char opcao;
    int id = -1;
    string cpf = "";
    string placa = "";

    cout << "Deseja ver todas as ordens de servicos aprovadas? (S/N) ";
    cin >> opcao;

    if (opcao == 'S' || opcao == 's')
    {
        lookup_confirmed_services();
    }

    cout << endl;

    cout << "Digite o ID da ordem de servico: ";
    cin >> id;

    auto service_order = confirmed_services.find(id);

    if (service_order != confirmed_services.end())
    {
        service_order->second.set_concluded(true);

        cpf = service_order->second.get_owner_cpf();
        placa = service_order->second.get_placa();

        clients[cpf].vehicles[placa].historic[id].set_concluded(true);
    } else{
        cout << "ID de ordem de servico não encontrado.";
        char c;
        do
        {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        } while (c != 'S' && c != 's');
        return;
    }
}

//Method to confirm an specific service order

void Oficina::confirm_service_order(){
    ServiceOrder aux;
    int id;
    string cpf, placa;

    cout << "Digite o ID da ordem de servico que sera confirmada: ";
    cin >> id;

    auto it = this->pending_services.find(id);
    if (it == this->pending_services.end()){

        cout << "\nOrdem de servico nao cadastrada!\n";
        char c;
        do
        {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        } while (c != 'S' && c != 's');
        return;

    }

    this->pending_services[id].set_approved(true);
    cpf = this->pending_services[id].get_owner_cpf();
    placa = this->pending_services[id].get_placa();
    this->clients[cpf].vehicles[placa].historic[id].set_approved(true);

    aux = this->pending_services[id];
    this->pending_services.erase(id);
    this->push_confirmed(id, aux);

}

//Method to close a servcice order

void Oficina::close_service_order(){

    ServiceOrder aux;
    int id;

    cout << "Digite o ID da ordem de servico que sera fechada: ";
    cin >> id;

    auto it = this->confirmed_services.find(id);

    if (it == this->confirmed_services.end()){

        cout << "\nOrdem de servico nao cadastrada!\n";
        char c;
        do
        {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        } while (c != 'S' && c != 's');
        return;

    }

    aux = this->confirmed_services[id];
    this->confirmed_services.erase(id);
    this->push_completed(id, aux);

}

// Register new client

void Oficina::register_client(){

    string cpf, name;

    cout << "Digite o CPF do cliente: ";
    cin >> cpf;

    auto it = this->clients.find(cpf);

    if (it != this->clients.end()){

        cout << "\nCliente ja cadastrado!\n";
        char c;
        do
        {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        } while (c != 'S' && c != 's');
        return;

    }

    cout << "Digite o nome do cliente: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, name);

    Client aux(name, cpf);
    this->push_clients(cpf, aux);

}
void Oficina::register_vehicle(){

    string cpf, placa, tipo;
    float km;

    cout << "Digite o CPF do dono: ";
    cin >> cpf;

    auto it = this->clients.find(cpf);

    if (it == this->clients.end()){

        cout << "\nCliente nao cadastrado!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;

    }

    cout << "Digite a placa do carro: ";
    cin >> placa;

    auto it2 = this->clients[cpf].vehicles.find(placa);

    if (it2 != this->clients[cpf].vehicles.end()){

        cout << "\nCarro ja cadastrado!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;

    }

    do{
        cout << "Digite a quilometragem do carro: ";
        cin >> km;

        if (km < 0){
            cout << "\nQuilometragem invalida!\n";
        }
    }while(km < 0);

    cout << "Digite o tipo do veiculo: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, tipo);

    Vehicle aux(tipo, placa, km, cpf);
    this->clients[cpf].push_vehicles(placa, aux);

}
void Oficina::register_service_order(){

    string cpf, placa, tipo, motivo;
    float km;

    cout << "Digite o CPF do dono do veiculo: ";
    cin >> cpf;

    auto it = this->clients.find(cpf);

    if (it == this->clients.end()){

        cout << "\nCliente nao cadastrado!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;

    }

    cout << "Digite a placa do veiculo: ";
    cin >> placa;

    auto it2 = this->clients[cpf].vehicles.find(placa);

    if (it2 == this->clients[cpf].vehicles.end()){

        cout << "\nCarro nao cadastrado!\n";
        char c;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> c;
        }while (c != 'S' && c != 's');
        return;

    }

    cout << "Digite o tipo da ordem de servico (orcamento/manutencao): ";
    cin >> tipo;

    cout << "Digite o motivo: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, motivo);

    km = it2->second.get_km();

    ServiceOrder aux(tipo, motivo, placa, km, false, false, 0.0, cpf);
    aux.set_id(aux.count);
    aux.count += 1;

    this->push_pending(aux.get_id(), aux);
    this->clients[cpf].vehicles[placa].push_historic(aux.get_id(), aux);

}

// Display interface methods -. printing maps

void Oficina::display_mechanics(){
    CLEAR();

    cout << "--------------- Mecanicos ---------------\n";
    for(auto mechanic : mechanics){
        cout << "Nome: " << mechanic.second.get_name() << endl;
        cout << "Email: " << mechanic.second.get_email() << endl;
        cout << "-----------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}
void Oficina::display_vendors(){
    CLEAR();

    cout << "--------------- Vendedores ---------------\n";
    for (auto vendor : vendors)
    {
        cout << "Nome: " << vendor.second.get_name() << endl;
        cout << "Email: " << vendor.second.get_email() << endl;
        cout << "------------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}

void Oficina::display_clients(){
    CLEAR();

    cout << "--------------- Clientes ---------------\n";
    for (auto client : clients)
    {
        cout << "Nome: " << client.second.get_name() << endl;

        int aux = 0;
        cout << "Veiculos: ";

        for (auto vehicle : client.second.vehicles){
            cout << vehicle.second.get_placa();
            aux += 1; 

            if (aux > 1)
                cout << " |";
        }

        cout << endl;
        cout << "----------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}
void Oficina::lookup_pending_services()
{
    cout << "\n---------- Ordens de servicos pendentes (em aberto) ----------" << endl;

    for (auto i : pending_services)
    {
        if (!(i.second.get_concluded()) && !(i.second.get_approved()))
        {
            cout << "ID da ordem de servico: " << i.first << endl;
            cout << "Placa do automovel: " << i.second.get_placa() << endl;
            cout << "Motivo: " << i.second.get_motivo() << endl;
            cout << "Preco total: R$ " << i.second.get_cost() << endl;
            cout << "--------------------------------------------------------------\n";
        }
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');

}
void Oficina::lookup_confirmed_services()
{
    cout << "\n---------- Ordens de servicos confirmadas (em aberto) ----------" << endl;

    for (auto service_order = confirmed_services.begin(); service_order != confirmed_services.end(); ++service_order)
    {
        if (!(service_order->second.get_concluded()) && service_order->second.get_approved())
        {
            cout << "ID da ordem de servico: " << service_order->second.get_id() << endl;
            cout << "Placa do automovel: " << service_order->second.get_placa() << endl;
            cout << "Preco total: R$ " << service_order->second.get_cost() << endl;
            cout << "----------------------------------------------------------------\n";
        }
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}
void Oficina::lookup_executed_services(){

    cout << "\n---------- Ordens de servicos executadas -----------------------" << endl;

    for (auto service_order = confirmed_services.begin(); service_order != confirmed_services.end(); ++service_order)
    {
        if (service_order->second.get_concluded() && service_order->second.get_approved())
        {
            cout << "ID da ordem de servico: " << service_order->second.get_id() << endl;
            cout << "Placa do automovel: " << service_order->second.get_placa() << endl;
            cout << "Preco total: R$ " << service_order->second.get_cost() << endl;
            cout << "----------------------------------------------------------------\n";
        }
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');

}
void Oficina::lookup_completed_services(){
    cout << "\n---------- Ordens de servicos feitas (fechadas) ----------" << endl;

    for (auto service_order = completed_services.begin(); service_order != completed_services.end(); ++service_order)
    {
        cout << "ID da ordem de servico: " << service_order->second.get_id() << endl;
        cout << "Placa do automovel: " << service_order->second.get_placa() << endl;
        cout << "Preco total: R$ " << service_order->second.get_cost() << endl;
        cout << "----------------------------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}
void Oficina::lookup_available_services(){
    cout << "\n---------- Servicos disponiveis na oficina ----------" << endl;

    for (auto service = available_services.begin(); service != available_services.end(); ++service)
    {
        cout << "Nome do servico: " << service->second.get_service_name() << endl;
        cout << "Preco do servico: R$ " << service->second.get_service_price() << endl;
        cout << "-----------------------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}
void Oficina::lookup_available_automobile_parts(){
    cout << "\n---------- Pecas disponiveis para reparo ----------" << endl;

    for (auto auto_part = available_automobile_parts.begin(); auto_part != available_automobile_parts.end(); ++auto_part)
    {
        cout << "Nome da peca: " << auto_part->second.get_part_name() << endl;
        cout << "Preco da peca: R$ " << auto_part->second.get_part_price() << endl;
        cout << "---------------------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');
}
void Oficina::display_service_order(){

    int id = -1;
    cout << "Digite o ID da ordem de servico: ";
    cin >> id;

    char opcao;
    cout << "A ordem ja foi fechada? (S/N) ";
    cin >> opcao;

    if (opcao == 's' || opcao == 'S'){
        auto service_order = completed_services.find(id);

        if (service_order != completed_services.end()){
            service_order->second.display();
        } 
        else{
            cout << "Ordem de servico nao encontrada!\n";
        }

    } 
    else{
        cout << "A ordem ja foi aprovada? (S/N) ";
        cin >> opcao;

        if (opcao == 's' || opcao == 'S')
        {
            auto service_order = confirmed_services.find(id);

            if (service_order != confirmed_services.end())
            {
                service_order->second.display();
            }
            else
            {
                cout << "Ordem de servico nao encontrada!\n";
            }

        } 
        else{
            auto service_order = pending_services.find(id);

            if (service_order != pending_services.end())
            {
                service_order->second.display();
            }
            else
            {
                cout << "Ordem de servico nao encontrada!\n";
            }
        }
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');

}

void Oficina::display_historic(){

    string cpf, placa;

    cout << "Digite o CPF do dono do veiculo: ";
    cin >> cpf;

    auto it = this->clients.find(cpf);
    if (it == this->clients.end()){
        cout << "\nCliente nao cadastrado!\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
        return;
    }

    cout << "Digite a placa do veiculo: ";
    cin >> placa;

    auto it2 = this->clients[cpf].vehicles.find(placa);
    if (it2 == this->clients[cpf].vehicles.end()){
        cout << "\nVehiculo nao cadastrado!\n";
        char aux;
        do {
            cout << "Digite 'S' para continuar ... ";
            cin >> aux;
        }while (aux != 'S' && aux != 's');
        return;
    }

    CLEAR();

    cout << "-------------------------- Historico ---------------------------\n";
    for (auto service_order = this->clients[cpf].vehicles[placa].historic.begin(); service_order != this->clients[cpf].vehicles[placa].historic.end(); ++service_order)
    {
        bool approved, concluded;
        approved = service_order->second.get_approved();
        concluded = service_order->second.get_concluded();

        cout << "ID: " << service_order->second.get_id() << endl;
        cout << "CPF do dono: " << service_order->second.get_owner_cpf() << endl;
        cout << "Placa do automovel: " << service_order->second.get_placa() << endl;
        cout << "Motivo: " << service_order->second.get_motivo() << endl;
        cout << "Status: ";
        if (approved == false && concluded == false){
            cout << "aguardadndo confirmacao do cliente!\n";
        }
        else if (approved == true && concluded == false){
            cout << "Aprovado e pronto para ser executado!\n";
        }
        else if (approved == true && concluded == true){
            cout << "Executado!\n";
        }
        else{
            cout << "\n";
        }
        cout << "Preco total: R$ " << service_order->second.get_cost() << endl;
        cout << "----------------------------------------------------------------\n";
    }

    char aux;
    do {
        cout << "Digite 'S' para continuar ... ";
        cin >> aux;
    }while (aux != 'S' && aux != 's');

}

void Oficina::set_adm(){

    string name, email, cpf, senha;

    cout << "AVISO!!!!\n";
    cout << "O programa nao possui um administrador, digite seus dados conforme indicado para registrar um adiministrador\n\n";

    cout << "Digite seu nome: ";
    getline(cin, name);

    cout << "Digite seu email: ";
    cin >> email;

    cout << "Digite seu CPF: ";
    cin >> cpf;

    cout << "Digite sua senha: ";
    cin >> senha;

    this->adm.set_name(name); 
    this->adm.set_cpf(cpf); 
    this->adm.set_email(email); 
    this->adm.set_password(senha); 

}