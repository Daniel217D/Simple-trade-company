#include <iostream>
#include "windows.h"

#include "libraries/Company.h"
#include "libraries/clients/ClientsGenerator.h"
#include "libraries/products/ProductManager.h"

using std::cout;

int main() {
    srand(time(0));
    auto company = new Company(1000, 3, 1);
//    while(!company->isBankrupt()) {
    for (int i = 0; i < 100; ++i) {
        ProductManager::setValues();
        auto clients = ClientsGenerator::generate(rand() % 10);
        company->trade(clients);

        cout << i << "\n";
//        Sleep(1000);
    }

    cout << "Банкрот!";
    return 0;
}
