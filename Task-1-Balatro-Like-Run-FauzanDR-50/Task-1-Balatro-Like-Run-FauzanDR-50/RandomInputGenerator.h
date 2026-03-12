#pragma once
#include "IInputGenerator.h"
#include <cstdlib>
#include <ctime>

class RandomInputGenerator : public IInputGenerator {
public:
    RandomInputGenerator() {
        // Inisialisasi seed random
        srand(time(NULL));
    }

    TurnInput generateInput() override {
        // Menghasilkan angka acak antara 1 sampai 10
        int randomValue = (rand() % 10) + 1;
        return TurnInput{ randomValue };
    }
};