#pragma once

#include <map>
#include <string>

namespace Cmp {
    enum dayTime {
        morning, day, evening
    };

    enum sellerType {
        storage, shop
    };

    enum clientType {
        wholesale, retail
    };

    enum productType {
        apple = 0, pear = 1, carrot = 2
    };

    std::map<productType, std::string> productTypesToString = {
            {apple, "Яблоки"},
            {pear, "Груши"},
            {carrot, "Морковь"},
    };
}