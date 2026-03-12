#pragma once
#include "TurnInput.h"

class IScoringRule {
public:
    virtual ~IScoringRule() = default;

    // Menerima input, mengembalikan skor dasar (base score)
    virtual int calculateBaseScore(const TurnInput& input) = 0;
};