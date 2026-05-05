#ifndef MINIBOSS_H
#define MINIBOSS_H

#include "Monster.h"
#include <iostream>

using namespace std;

class MiniBoss : public Monster {
    public:
        MiniBoss(string name, int maxHP, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts);
        virtual ~MiniBoss() = default;

        int getActCount() override;
        void afficherMenuAct() override;
};

#endif
