#include <iostream>
#include <locale>
#include <typeinfo>
#include <string>
#include <map>

#define CLEAR() system("cls") != 0 ? system("clear") : 0

#include "user.h"
#include "vendor.h"
#include "mechanic.h"
#include "admin.h"
#include "service.h"
#include "automobile_part.h"
#include "service_order.h"
#include "vehicle.h"
#include "client.h"
#include "oficina.h"
#include "funcoes.h"

int ServiceOrder::count = 1;

/**
 * PS: Este programa foi feito como um trabalho para o curso de Programação Orientada a Objetos.
 * 
 * Esta entrega não possui uma interface gráfica, e apesar de simular um ambiente real de ge
 * renciamento de uma oficina, algumas verificações que devem ser feitas em um software real
 * não foram feitas, como por exemplo verificação de e-mail, CPF e de redefinição de senhas.
 * 
 * 
 * Objetivos principais do projeto:
 *  - Criar um sistema de Login (para administrador, vendedores e mecânicos) e Logout;
 *  - Permitir ao administrador editar dados dos vendedores e dos mecânicos;
 *  - Permitir aos vendedores cadastrar clientes, veiculos e gerar ordens de serviços;
 *  - Permitir ao mecânico estabelecer um ordem de serviço aprovada como executada, e cadastrar serviços executados e peças utilizadas.
 * 
 * 
 * O UML relativo ao projeto se encontra no PDF 'POO - TP1.pd' 
 * 
 * 
 * Alunos: 
 * - Vinicius Gabriel Angelozzi Verona de Resende | 19.1.4005;
 * - Carlos Eduardo Gonzaga Romaniello de Souza | 19.1.4003.
 * 
*/
int main(){

    CLEAR();

    Oficina oficina;

    oficina.set_adm();
    login(&oficina);

    return 0;

}