#pragma once

#include <iostream>
#include "Seller.h"
#include "../helpers/types.h"

using std::string;
using Cmp::dayTime;

class SellerShop : public Seller {
public:
    explicit SellerShop(string _name) {
        type = Cmp::sellerType::shop;
        name = "Магазин: " + _name;
    }

    unsigned int getMoney(dayTime dt) override {
        if(dt == dayTime::evening) {
            unsigned int temp = money;
            money = 0;
            return money;
        }
    }

    unsigned int event() override {

    }
};

