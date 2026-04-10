#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Entity.h"
#include "Items.h"
#include "Monster.h"

class Player : public Entity {
    public:
        vector<Item> items; 
        int nbVictoires;
        vector<Monster> monstresVaincus;

        Player(string personnage, int maxHP);

        vector<Item> getItems();
};

#endif