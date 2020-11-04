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
    for (int i = 0; i < 2; ++i) {
        ProductManager::setValues();
        company->restore();
        auto clients = ClientsGenerator::generate(5 + rand() % 5);
        company->trade(clients);
        company->cycle();
        cout << company->toString() << "\n";
//        Sleep(1000);
    }

    cout << "Банкрот!";
    return 0;
}
