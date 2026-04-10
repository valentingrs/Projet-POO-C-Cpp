#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity {
    protected:
        string name;
        int HP;
        int maxHP;

    public:
        Entity(string name, int maxHP);

        string getName();
        int getHP();
        int getMaxHP();
        int attack();
};

#endif