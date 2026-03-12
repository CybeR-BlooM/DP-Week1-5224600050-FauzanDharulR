#pragma once
#include "TurnInput.h"

class IInputGenerator {
public:
    virtual ~IInputGenerator() = default;

    // Fungsi murni: Siapapun yang memakai interface ini WAJIB membuat logika generateInput-nya
    virtual TurnInput generateInput() = 0;
};