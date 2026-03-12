#pragma once

class IRewardRule {
public:
    virtual ~IRewardRule() = default;

    // Menerima skor dasar, mengembalikan jumlah uang yang didapat
    virtual int calculateReward(int baseScore) = 0;
};