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
using Cmp::clientType;

class Company {
private:
    int money;
    dayTime dt;
    vector<SellerShop> seller_shops;
    vector<SellerStorage> seller_storages;

    void collect_money() {
        for (auto & shop : seller_shops) {
            money += shop.collectMoney(dt);
        }

        for (auto & shop : seller_storages) {
            money += shop.collectMoney(dt);
        }
    }
public:
    explicit Company(int _money, unsigned int shops_amount, unsigned int storage_amount) {
        money = _money;

        for (unsigned int i = 0; i < shops_amount; ++i) {
            seller_shops.emplace_back(SellerShop(to_string(i + 1)));
        }
        
        for (unsigned int i = 0; i < storage_amount; ++i) {
            seller_storages.emplace_back(SellerStorage(to_string(i + 1)));
        }
    }

    unsigned int getMoney() {
        return money;
    }

    void trade(const vector<Client>& clients) {
        for (const auto & client : clients) {
            trade(client);
        }
    }

    void trade(Client client) {
        if(client.get_type() == clientType::wholesale) {
            seller_shops[random() % seller_shops.size()].buy(client);
        } else {
            seller_storages[random() % seller_storages.size()].buy(client);
        }
    }

    void restore() {
        for (auto & shop : seller_shops) {
            shop.restore();
        }

        for (auto & shop : seller_storages) {
            shop.restore();
        }
    }

    bool isBankrupt() {
        return money <= 0;
    }

    void cycle() {
        collect_money();

        if(dt == dayTime::morning) {
            dt = dayTime::day;
        } else if(dt == dayTime::day) {
            dt = dayTime::evening;
        } else if(dt == dayTime::evening) {
            dt = dayTime::morning;
        }
    }

    string toString() {
        string res;
        res += "Бюджет: " + to_string(money) + "\n";
        for (auto & shop : seller_shops) {
            res += shop.toString() + "\n";
        }

        for (auto & shop : seller_storages) {
            res += shop.toString() + "\n";
        }
        return res;
    }
};

