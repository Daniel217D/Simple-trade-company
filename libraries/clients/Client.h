#pragma once

#include <iostream>

#include "../helpers/types.h"

using std::string;
using Cmp::clientType;

class Client {
    string name;

    unsigned int money;

    clientType type;
};

