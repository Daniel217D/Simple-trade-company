#pragma once

#include <vector>
#include "ClientRetail.h"
#include "ClientWholesale.h"

using std::vector;

class ClientsGenerator {
public:
    static vector<Client> generate(unsigned int length) {
        vector<Client> clients;
        for (unsigned int i = 0; i < length; ++i) {
            if(rand() % 2) {
                clients.emplace_back(ClientRetail(to_string(i), 50 + rand() % 50));
            } else {
                clients.emplace_back(ClientWholesale(to_string(i), 100 + rand() % 100));
            }
        }
        return clients;
    }
};