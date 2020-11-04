#pragma once

#include <iostream>
#include "Seller.h"
#include "../helpers/types.h"
#include "../products/Product.h"
#include "../products/ProductManager.h"

using std::string;
using Cmp::dayTime;
using Cmp::productType;

class SellerShop : public Seller {
public:
    explicit SellerShop(string _name) {
        type = Cmp::sellerType::shop;
        name = "Магазин: " + _name;

        for (int i = productType::apple; i <= productType::carrot; i++) {
            products.emplace_back((productType) i, 15 + rand() % 15);
        }
    }

    unsigned int collectMoney(dayTime dt) override {
        unsigned int temp = money;
        money = 0;
        return temp;
    }

    unsigned int event() override {

    }

    void restore() {
        int change;
        for (auto & product : products) {
            change = 5 + rand() % 5;
            if(change > product.get_max_amount() - product.get_amount()) {
                change = product.get_max_amount() - product.get_amount();
            }
            product.change_amount(change);
            unsigned int p = ProductManager::get_purchase_price(product.get_type());
            money -= change * p;
        }
    }
};

