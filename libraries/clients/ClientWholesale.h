#pragma once

#include <iostream>
#include "Client.h"
#include "../helpers/types.h"

using std::string;
using Cmp::clientType;

class ClientRetail : public Client {
public:
    explicit ClientRetail(const string& _name, unsigned int _money) {
        type = clientType::wholesale;
        name = "Клииент: " + _name;
        money = _money;
    }
};