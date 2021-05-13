#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include "oficina.h"

#define CLEAR() system("cls") != 0 ? system("clear") : 0

void login(Oficina* oficina);
void adm_options(int opcao, Oficina* oficina, string cpf);
void mechanic_options(int opcao, Oficina* oficina, string cpf);
void vendor_options(int opcao, Oficina* oficina, string cpf);

#endif
