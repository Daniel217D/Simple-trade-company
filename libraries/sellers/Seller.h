#pragma once

#include <iostream>
#include <vector>
#include "../helpers/types.h"
#include "../products/Product.h"
#include "../products/ProductManager.h"
#include "../clients/Client.h"

using std::string;
using std::to_string;
using std::vector;
using Cmp::dayTime;

class Seller {
protected:
    string name;

    int money = 0;

    vector<Product> products;

    Cmp::sellerType type;

public:
    virtual unsigned int collectMoney(dayTime dt) = 0;
    virtual unsigned int event() = 0;
    virtual void restore() = 0;

    string get_name() {
        return name;
    }

    void buy (Client client) {
        Product &buyProduct = products[rand() % products.size()];
        if(buyProduct.get_amount() == 0) {
            return;
        }

        unsigned int price = ProductManager::get_purchase_price(buyProduct.get_type());
        unsigned int amount = 1 + (buyProduct.get_amount() > 1 ? rand() % (buyProduct.get_amount() - 1) : 0);
        unsigned int clientMoney = client.get_money();

        if(amount * price < clientMoney) {
            amount = clientMoney / price;
        }

        buyProduct.change_amount(-amount);
        client.change_money(-(amount * price));
        money += amount * price;
    }

    string toString() {
        string res;

        res += name + ": " + to_string(money) + "у.е.\n";

        for (auto & product : products) {
            res += product.toString() + "\n";
        }

        return res;
    }
};

