#pragma once
#include "IRewardRule.h"

class StandardRewardRule : public IRewardRule {
public:
    int calculateReward(int baseScore) override {
        return baseScore; // Sesuai modul: Awalnya reward sama dengan base score
    }
};