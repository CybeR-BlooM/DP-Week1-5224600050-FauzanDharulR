#pragma once
#include <iostream>

class ShopSystem {
public:
    void displayShop() {
        std::cout << "--- SHOP PHASE ---\n";
        std::cout << "1. Relic (Joker) - $5\n";
        std::cout << "2. Rune (Tarot)  - $3\n";
        std::cout << "------------------\n";
    }
};