#ifndef OFICINA_H
#define OFICINA_H

#define STAFF template <typename Staff>
#define CLEAR() system("cls") != 0 ? system("clear") : 0
using namespace std;

#include <iostream>
#include <locale.h>
#include <string>
#include <limits.h>
#include <map>

#include "user.h"
#include "vendor.h"
#include "mechanic.h"
#include "admin.h"
#include "service.h"
#include "automobile_part.h"
#include "service_order.h"
#include "vehicle.h"
#include "client.h"

class Oficina{

  Admin adm;
  std::map<string, Mechanic> mechanics;
  std::map<string, Vendor> vendors;
  std::map<string, Client> clients;
  std::map<int, ServiceOrder> pending_services;
  std::map<int, ServiceOrder> confirmed_services;
  std::map<int, ServiceOrder> completed_services;
  std::map<string, Service> available_services;
  std::map<string, AutoPart> available_automobile_parts;

public:

  Oficina();
  ~Oficina();

  /**
   *  Confirma se o dados inserido pelo usuário estão corretos.
   * 
   *  @return Bollean de confirmação.
  */
  bool confirm_adm(string cpf, string senha);

  /**
   * Insere no mapa de mecânicos um novo usuário
   * 
   * @param CPF serve como chave do mapa;
   * @param mechanic é o usuário cadastrado. 
  */
  void push_mechanics(string cpf, Mechanic mechanic);

  /// Deleta o usuário do CPF do sistema.
  void pop_mechanics(string cpf);

  /**
   *  Confirma se o dados inserido pelo usuário estão corretos.
   * 
   *  @return Bollean de confirmação.
  */
  bool confirm_mechanic(string cpf, string senha);

  /**
   * Insere no mapa de vendedores um novo usuário.
   * 
   * @param CPF serve como chave do mapa;
   * @param mechanic é o usuário cadastrado. 
  */
  void push_vendors(string cpf, Vendor vendor);

  /// Deleta o usuário do CPF do sistema.
  void pop_vendors(string cpf);

  /**
   *  Confirma se o dados inserido pelo usuário estão corretos.
   * 
   *  @return Bollean de confirmação.
  */
  bool confirm_vendor(string cpf, string senha);

  /**
   * Adiciona um novo usuário ao sistema.
   * 
   * @param CPF chave de identificação do cliente;
   * @param client Cliente sendo cadastrado.
  */
  void push_clients(string cpf, Client client);

  /// Remove o cliente de CPF passado do sistema.
  void pop_clients(string cpf);

  /**
   * Adiciona uma nova ordem de pedido ao sistema.
   * 
   * @param ID Chave de identificação da ordem;
   * @param service_order Ordem sendo adicionada ao mapa de ordem pendentes.
  */
  void push_pending(int id, ServiceOrder service_order);

  /// Retira a ordem do mapa de ordens pendentes.
  void pop_pending(int id);

  /**
   * Adiciona uma nova ordem de pedido ao sistema.
   * 
   * @param ID Chave de identificação da ordem;
   * @param service_order Ordem sendo adicionada ao mapa de ordem confirmadas.
  */
  void push_confirmed(int id, ServiceOrder service_order);

  /// Retira a ordem do mapa de ordens confirmadas.
  void pop_confirmed(int id);

  /**
   * Adiciona uma nova ordem de pedido ao sistema.
   * 
   * @param ID Chave de identificação da ordem;
   * @param service_order Ordem sendo adicionada ao mapa de ordem completas.
  */
  void push_completed(int id, ServiceOrder service_order);

  /// Retira a ordem do mapa de ordens confirmadas.
  void pop_completed(int id);

  /**
   * Adiciona um novo serviço ao sistema.
   * 
   * @param service_name Nome do serviço sendo disponibilzado. Ex: Calibragem;
   * @param service_price Preço do serviço ofertado.
  */
  void push_available_services(string service_name, Service service);

  /// Retira o serviço ofertado do sistema.
  void pop_available_services(string service_name);

  /**
   * Adiciona uma nova peça ao sistema.
   * 
   * @param part_name Nome da peça sendo disponibilzada. Ex: Pneu;
   * @param part_price Preço da peça ofertada.
  */
  void push_available_automobile_parts(string part_name, AutoPart part);
  void pop_available_automobile_parts(string part_name);

  // Display
  
  /// Método que mostra opções de imprimir dados na tela.
  void display_interface();

  /// Mostra dados do usuário logado.
  void display_staff(string cpf);

  /// Mostra opções de alterção de dados de um usuário, sendo esses, mecânicos ou vendedores.
  void update_staff_display();

  /**
   * Atualiza e-mail do usuário desejado.
   * 
   * @param CPF é o CPF do usuário que terá o dado alterado;
   * @param staffs é o mapa de usuários da classe do que será alterado. 
  */
  STAFF void update_staff_email(string cpf, map<string, Staff>* staffs);

  /**
   * Atualiza senha do usuário desejado.
   * 
   * @param CPF é o CPF do usuário que terá o dado alterado;
   * @param staffs é o mapa de usuários da classe do que será alterado. 
  */
  STAFF void update_staff_password(string cpf, map<string, Staff>* staffs);

  /// Mostra opções de contratar um tipo de funcionário, ou seja, vendedor ou mecânico. 
  void hire_staff_display();

  /// Mostra opções de demitir um tipo de funcionário, ou seja, vendedor ou mecânico. 
  void fire_staff_display();

  /**
   * Método responsável por pegar os dados de um funcionário contrato 
   * e cadastra-lo no mapa referente a sua classe.
   * 
   * @param staffs é o mapa da classe do usuário que será cadastrado.
  */
  STAFF void hire_staff(map<string, Staff>* staffs);

  /**
   * Método responsável por pegar os dados de um funcionário demetido 
   * e retirá-lo do mapa referente a sua classe.
   * 
   * @param CPF é o CPF do usuário que será demitido.
   * @param staffs é o mapa da classe do usuário que será demitido.
  */
  STAFF void fire_staff(string cpf, map<string, Staff>* staffs);

  // Register Available item

  /// Método que irá registrar um novo serviço a ser ofertado na oficina.
  void register_available_service();

  /// Método que irá registrar uma nova peça a ser ofertada na oficina.
  void register_available_automobile_part();

  //funcoes -> registram em ordem de serviço

  /// Função acessada por um mecânico para registrar um serviço necessário a uma ordem de serviço que ja foi aprovada.
  void register_service();

  /// Função acessada por um mecânico para registrar uma peça necessária a uma ordem de serviço que ja foi aprovada.
  void register_auto_part();

  // Method to execute a specific service order

  /// Método no qual uma ordem de serviço aprovada será marcada como executada.
  void execute_service_order();

  //Method to confirm an specific service order

  /** 
   * Método no qual um vendedor aprova uma ordem de serviço pendente,
   * e então retira esta ordem do mapa das ordens de serviço pendente
   * e passa para as confirmadas.
  */
  void confirm_service_order();

  //Method to close a servcice order

  /** 
   * Método no qual um vendedor fecha uma ordem de serviço confirmada,
   * e então retira esta ordem do mapa das ordens de serviço confirmada
   * e passa para as concluidas.
  */
  void close_service_order();

  // cadastra novo cliente

  /// Armazena dados de um novo cliente e caso esse não exista, adiciona ao mapa de clientes.
  void register_client();

  /// Armazena dados de um novo veículo e caso esse não exista, adiciona ao mapa de veículos dentro de um cliente.
  void register_vehicle();

  /// Armazena dados de uma nova ordem de serviço e caso essa não exista, adiciona ao mapa de ordem de serviços pendentes.
  void register_service_order();

  // Display interface methods -> print each map

  /// Mostra os dados dos mecânicos contratados.
  void display_mechanics();

  /// Mostra os dados dos vendedor contratados.
  void display_vendors();

  /// Mostra dados dos clientes da oficina.
  void display_clients();

  /// Mostra dados de todas as ordens de serviço pendentes.
  void lookup_pending_services();

  /// Mostra dados de todas as ordens de serviço aprovadas.
  void lookup_confirmed_services();

  /// Mostra dados de todas as ordens de serviço executadas (ainda abertas).
  void lookup_executed_services();

  /// Mostra dados de todas as ordens de serviço fechadas (completas).
  void lookup_completed_services();

  /// Imprime na tela os serviços ofertados pela oficina.
  void lookup_available_services();

  /// Imprime na tela as peças disponíveis na oficina.
  void lookup_available_automobile_parts();

  /// Mostra os dados de uma ordem de serviço específica.
  void display_service_order();

  /// Mostra o histórico de reparo de um veículo.
  void display_historic();

  // Adiciona um administrador ao sistema antes de iniciar o programa. -> Adicionada para facilitar a pessoa que estará testando o projeto.
  void set_adm();

};

#endif
