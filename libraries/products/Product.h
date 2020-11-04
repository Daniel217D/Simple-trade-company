#pragma once

#include "../helpers/types.h"
#include <iostream>

using std::string;
using std::to_string;
using Cmp::productType;
using Cmp::productTypesToString;

class Product {
private:
    unsigned int amount = 0;
    unsigned int max_amount;
    productType type;
public:
    Product(productType _type, unsigned int _max_amount) : type(_type), max_amount(_max_amount) {}

    void change_amount(int c) {
            amount += c;
    }

    unsigned int get_amount() {
        return amount;
    }

    unsigned get_max_amount() {
        return max_amount;
    }

    productType get_type() {
        return type;
    }

    string toString() {
        return productTypesToString[type] + ": " + to_string(amount) + " штук (max: " + to_string(max_amount) + ")";
    }
};