#pragma once

#include <iostream>
#include <vector>
#include "../helpers/types.h"
#include "../products/Product.h"

using std::string;
using std::vector;
using Cmp::dayTime;

class Seller {
protected:
    string name;

    unsigned int money = 0;

    vector<Product> products;

    Cmp::sellerType type;

public:
    virtual unsigned int getMoney(dayTime dt) = 0;
    virtual unsigned int event() = 0;
};

