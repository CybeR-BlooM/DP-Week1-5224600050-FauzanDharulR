#include "RunSession.h"
#include <iostream>

// Inisialisasi constructor
RunSession::RunSession(IInputGenerator* ig, IScoringRule* sr, IRewardRule* rr, ShopSystem* shop)
    : inputGenerator(ig), scoringRule(sr), rewardRule(rr), shopSystem(shop),
    currentMoney(0), currentRound(1) {
}

void RunSession::run() {
    std::cout << "=== STARTING BALATRO-LIKE RUN ===\n\n";

    while (currentRound <= MAX_ROUNDS) {
        std::cout << ">>> ROUND " << currentRound << " <<<\n";

        // Fase 1: Generate input
        TurnInput input = inputGenerator->generateInput();
        std::cout << "[Phase 1] Input generated (Card Value: " << input.cardValue << ")\n";

        // Fase 2: Compute base score
        int baseScore = scoringRule->calculateBaseScore(input);
        std::cout << "[Phase 2] Base score computed: " << baseScore << "\n";

        // Fase 3: Compute reward
        int reward = rewardRule->calculateReward(baseScore);
        std::cout << "[Phase 3] Reward computed: $" << reward << "\n";

        // Fase 4: Update money
        currentMoney += reward;
        std::cout << "[Phase 4] Money updated. Total Money: $" << currentMoney << "\n";

        // Fase 5: Shop phase
        std::cout << "[Phase 5] ";
        shopSystem->displayShop();

        // Fase 6: Advance round
        std::cout << "[Phase 6] Advancing round...\n\n";
        currentRound++;
    }

    std::cout << "=== RUN FINISHED! Final Money: $" << currentMoney << " ===\n";
}