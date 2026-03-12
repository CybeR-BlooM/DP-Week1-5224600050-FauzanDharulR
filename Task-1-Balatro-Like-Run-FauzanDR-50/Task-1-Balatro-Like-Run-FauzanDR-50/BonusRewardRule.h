#pragma once
#include "IRewardRule.h"

class BonusRewardRule : public IRewardRule {
public:
    int calculateReward(int baseScore) override {
        return baseScore + 2; // Perubahan logika reward
    }
};