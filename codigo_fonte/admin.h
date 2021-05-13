#ifndef ADMIN_H
#define ADMIN_H

using namespace std;
#include <iostream>
#include <string>
#include <limits.h>
#include <map>

#include "user.h"

class Admin : public User{

  int id;

public:

    /// Construtor da classe
    Admin(string="", string="", string="", string="");

    /// Destrutor da classe
    ~Admin();

    /// @return ID de Administrador = 1
    int get_id() const;

    /**
     * Interface contendo opções de todos os usuários
     * visto que o administrador deve ter acesso a tudo no sistema.
     * 
     * @return opção escolhida pelo usuário
    */
    int interface();

};

#endif