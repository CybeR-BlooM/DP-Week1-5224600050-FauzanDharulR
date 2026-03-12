#include <iostream>
#include "RunSession.h"
#include "StandardInputGenerator.h"
#include "RandomInputGenerator.h"
#include "StandardScoringRule.h"
#include "StandardRewardRule.h"
#include "BonusRewardRule.h"
#include "ShopSystem.h"

int main() {
    // 1. Buat instance dari ShopSystem (karena dia bukan interface di tugas ini)
    ShopSystem shop;

    // ==========================================
    // SKENARIO 1: SISTEM ORIGINAL
    // ==========================================
    std::cout << "\n[MENJALANKAN SISTEM ORIGINAL]\n";
    StandardInputGenerator originalInput;
    StandardScoringRule standardScoring;
    StandardRewardRule originalReward;

    // Inject ke RunSession
    RunSession originalRun(&originalInput, &standardScoring, &originalReward, &shop);
    originalRun.run();

    std::cout << "\n==========================================\n";

    // ==========================================
    // SKENARIO 2: SETELAH MODIFIKASI 1 & 2
    // ==========================================
    std::cout << "\n[MENJALANKAN SISTEM DENGAN MODIFIKASI]\n";

    // Kita gunakan kelas baru: RandomInputGenerator dan BonusRewardRule
    RandomInputGenerator modifiedInput;
    BonusRewardRule modifiedReward;

    // Inject komponen BARU ke RunSession (RunSession.cpp TIDAK DISENTUH SAMA SEKALI!)
    RunSession modifiedRun(&modifiedInput, &standardScoring, &modifiedReward, &shop);
    modifiedRun.run();

    return 0;
}