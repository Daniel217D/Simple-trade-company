#pragma once

#include "helpers/types.h"
#include "sellers/SellerShop.h"
#include "sellers/SellerStorage.h"
#include "clients/Client.h"

#include <vector>
#include <string>

using std::vector;
using std::to_string;
using Cmp::dayTime;

class Company {
private:
    int money;
    dayTime dt;
    vector<SellerShop> seller_shops;
    vector<SellerStorage> seller_storages;
public:
    explicit Company(int _money, unsigned int shops_amount, unsigned int storage_amount) {
        money = _money;

        for (unsigned int i = 0; i < shops_amount; ++i) {
            seller_shops.emplace_back(to_string(i));
        }
        
        for (unsigned int i = 0; i < storage_amount; ++i) {
            seller_storages.emplace_back(to_string(i));
        }
    }

    unsigned int getMoney() {
        return money;
    }

    void trade(vector<Client> clients) {
        for (const auto & client : clients) {
            trade(client);
        }
    }

    void trade(Client client) {

    }

    bool isBankrupt() {
        return money <= 0;
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

