#pragma once
#include "IScoringRule.h"

class StandardScoringRule : public IScoringRule {
public:
    int calculateBaseScore(const TurnInput& input) override {
        // Contoh sederhana: nilai kartu dikali 5
        return input.cardValue * 5;
    }
};