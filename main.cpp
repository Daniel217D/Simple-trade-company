#include <iostream>
#include "windows.h"

#include "libraries/Company.h"
#include "libraries/clients/ClientsGenerator.h"
#include "libraries/products/ProductManager.h"

using std::cin;
using std::cout;

int main() {
    srand(time(0));
    unsigned start;
    cin >> start;
    auto company = new Company(start, 3, 1);
    while(!company->isBankrupt()) {
//    for (int i = 0; i < 100; ++i) {
        ProductManager::setValues();
        company->restore();
        auto clients = ClientsGenerator::generate(5 + rand() % 5);
        company->trade(clients);
        cout << company->toString() << ProductManager::toString() << "\n";
        company->cycle();
        Sleep(5000);
    }

    cout << "Банкрот!";
    return 0;
}
