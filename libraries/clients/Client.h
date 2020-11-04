#pragma once

#include <iostream>

#include "../helpers/types.h"

using std::string;
using Cmp::clientType;

class Client {
protected:
    string name;
    unsigned int money;
    clientType type;
public:
    string get_name() {
        return name;
    };

    unsigned int get_money() {
        return money;
    };

    unsigned int change_money(int _money) {
        money += _money;
    }

    clientType get_type() {
        return type;
    };
};

