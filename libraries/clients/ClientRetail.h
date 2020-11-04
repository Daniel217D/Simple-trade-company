#pragma once

#include <iostream>
#include "Client.h"
#include "../helpers/types.h"

using std::string;
using Cmp::clientType;

class ClientWholesale : public Client {
public:
    explicit ClientWholesale(const string& _name, unsigned int _money) {
        type = clientType::retail;
        name = "Клииент: " + _name;
        money = _money;
    }
};