#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include "Entity.h"
#include "Act.h"

using namespace std;

class Monster : public Entity {
    public:
        string category;
        int atk;
        int dfc;
        int mercy;
        vector<ACT> acts;

        Monster(string personnage, int maxHP);
};

#endif
