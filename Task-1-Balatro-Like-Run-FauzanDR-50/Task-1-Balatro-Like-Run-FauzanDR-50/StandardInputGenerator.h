#pragma once
#include "IInputGenerator.h"

class StandardInputGenerator : public IInputGenerator {
public:
    TurnInput generateInput() override {
        // Memberikan kartu dengan nilai tetap (misal: 10)
        return TurnInput{ 10 };
    }
};