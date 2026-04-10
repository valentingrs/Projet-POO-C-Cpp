#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity {
    public:
        string name;
        int HP;
        int maxHP;

        Entity(string name, int maxHP);

        string getName();
        int getHP();
        int getMaxHP();
        bool isAlive();
};

#endif