#pragma once

#include "helpers/types.h"
#include "sellers/Seller.h"
#include "sellers/SellerShop.h"
#include "sellers/SellerStorage.h"
#include <vector>
#include <string>

using std::vector;
using std::to_string;
using Cmp::dayTime;

class Company {
private:
    unsigned int money;
    dayTime dt;
    vector<Seller> sellers;
public:
    explicit Company(unsigned int _money, unsigned int shops_amount, unsigned int storage_amount) {
        money = _money;

        for (unsigned int i = 0; i < shops_amount; ++i) {
            sellers.push_back(SellerShop(to_string(i)));
        }
        
        for (unsigned int i = 0; i < storage_amount; ++i) {
            sellers.push_back(SellerStorage(to_string(i)));
        }
    }

    unsigned int getMoney() {
        return money;
    }

    void trade() {

    }

    void changeTime() {
        if(dt == dayTime::morning) {
            dt = dayTime::day;
        } else if(dt == dayTime::day) {
            dt = dayTime::evening;
        } else if(dt == dayTime::evening) {
            dt = dayTime::morning;
        }
    }
};

