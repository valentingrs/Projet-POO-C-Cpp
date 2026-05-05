#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"
#include <iostream>

using namespace std;

class Boss : public Monster {
    public:
        Boss(string name, int maxHP, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts);

        int getActCount() override;
        void afficherMenuAct() override;
};

#endif
