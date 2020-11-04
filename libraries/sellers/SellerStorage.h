#pragma once

#include <iostream>
#include "Seller.h"
#include "../helpers/types.h"

using std::string;
using Cmp::dayTime;

class SellerStorage : public Seller {
public:
    explicit SellerStorage(string _name) {
        type = Cmp::sellerType::storage;
        name = "Склад: " + _name;
    }

    unsigned int getMoney(dayTime dt) override {
        unsigned int temp = money;
        money = 0;
        return money;
    }

    unsigned int event() override {

    }
};

