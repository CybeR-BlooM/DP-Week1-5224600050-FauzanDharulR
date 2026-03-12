#pragma once
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession {
private:
    // Pointers ke Mutable Components (Dependencies)
    IInputGenerator* inputGenerator;
    IScoringRule* scoringRule;
    IRewardRule* rewardRule;
    ShopSystem* shopSystem;

    // State dari Run
    int currentMoney;
    int currentRound;
    const int MAX_ROUNDS = 3;

public:
    // Constructor: Menerima "suntikan" dari luar
    RunSession(IInputGenerator* ig, IScoringRule* sr, IRewardRule* rr, ShopSystem* shop);

    // Fungsi utama untuk menjalankan core loop
    void run();
};