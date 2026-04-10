#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include "Entity.h"
#include "Act.h"

using namespace std;

class Monster : public Entity {
    private:
        string category;
        int atk;
        int dfc;
        int mercy;
        int mercyGoal;
        vector<ACT> acts;

    public:
        Monster(string personnage, int maxHP, string category, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts);

        string getCategory();
        int getAtk();
        int getDfc();
        int getMercy();
        vector<ACT> getActs();
        
        void setMercy(int amount);
        void setAct(ACT act);

        // Methods
        int getActCount();
        bool canMercy();
};

#endif
