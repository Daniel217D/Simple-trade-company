#pragma once

#include "../helpers/types.h"
#include <map>

using std::map;
using Cmp::productType;
using Cmp::productTypesToString;

class ProductManager {
private:
    static map<unsigned int, unsigned int> purchase_price;
    static map<unsigned int, unsigned int> sale_price;
    static map<unsigned int, short int> demand;

public:
    static void setValues() {
        for (int i = productType::apple; i <= productType::carrot; i++) {
            demand[i] = rand() % 10 - 2;
            purchase_price[i] = 8 + rand() % 5;
            sale_price[i] = 8 + demand[i];
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

    static string toString() {
        string res = "Товары на рынке:\n";

        for (map<unsigned int, unsigned int>::iterator it = purchase_price.begin(); it != purchase_price.end(); it++) {
            res += productTypesToString[(productType)it->first] + ": закупка - " + to_string(it->second) + "у.е. | продажа - " + to_string(sale_price[it->first]) + "у.е. | популярность - " + to_string(demand[it->first]) + "\n";
        }

        return res;
    }
};

map<unsigned int, unsigned int> ProductManager::purchase_price = {};
map<unsigned int, unsigned int> ProductManager::sale_price = {};
map<unsigned int, short int> ProductManager::demand = {};