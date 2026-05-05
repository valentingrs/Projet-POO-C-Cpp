#ifndef NORMAL_H
#define NORMAL_H

#include "Monster.h"
#include <iostream>

using namespace std;

class Normal : public Monster {
    public:
        Normal(string name, int maxHP, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts);
        virtual ~Normal() = default;

        int getActCount() override;
        void afficherMenuAct() override;
};

#endif
