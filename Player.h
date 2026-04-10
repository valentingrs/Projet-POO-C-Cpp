#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Entity.h"
#include "Items.h"
#include "Monster.h"

class Player : public Entity {
    private:
        vector<Item> items; 
        int nbVictoires;
        int nbKilled;
        int nbSpared;
        vector<Monster> monstresVaincus;

    public:
        Player(string personnage, int maxHP);

        vector<Item> getItems();
        int getNbVictoires();
        vector<Monster> getMonstresVaincus();
        int getNbKilled();
        int getNbSpared();

        void addVictory();
        void addMonstresVaincus(Monster monster);

        void useItem(int index);
};

#endif