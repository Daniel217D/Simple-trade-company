#pragma once

#include "../helpers/types.h"
#include <map>

using std::map;
using Cmp::productType;

class ProductManager {
private:
    static map <unsigned int, unsigned int> purchase_price;
    static map <unsigned int, unsigned int> sale_price;
    static map <unsigned int, unsigned short int> demand;

public:
    static void setValues() {
        for (int i = productType::apple; i <= productType::carrot; i++) {
            demand[i] = rand() % 10 - 2;
            purchase_price[i] = 10;
            sale_price[i] = 10 + demand[i];
        }
    }

    static unsigned int get_purchase_price(productType type) {
        return purchase_price[type];
    }

    static unsigned int get_sale_price(productType type) {
        return sale_price[type];
    }

    static unsigned short int get_demand(productType type) {
        return demand[type];
    }
};

map <unsigned int, unsigned int> ProductManager::purchase_price = {};
map <unsigned int, unsigned int> ProductManager::sale_price = {};
map <unsigned int, unsigned short int> ProductManager::demand = {};