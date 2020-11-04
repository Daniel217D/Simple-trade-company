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

        for (int i = productType::apple; i <= productType::carrot; i++) {
            products.emplace_back((productType) i, 30 + rand() % 30);
        }
    }

    int collectMoney(dayTime dt) override {
        event();

        if (dt == dayTime::evening) {
            int temp = money;
            money = 0;
            return temp;
        }
        return 0;
    }

    void restore() {
        int change;
        for (auto &product : products) {
            change = 10 + rand() % 10;
            if (change > product.get_max_amount() - product.get_amount()) {
                change = product.get_max_amount() - product.get_amount();
            }
            product.change_amount(change);
            unsigned int p = ProductManager::get_purchase_price(product.get_type());
            money -= change * p;
        }
    }
};

