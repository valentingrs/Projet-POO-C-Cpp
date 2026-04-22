#ifndef FIGHT_H
#define FIGHT_H

#include <string>
#include "Player.h"
#include "Monster.h"
#include "Act.h"
#include "Items.h"

using namespace std;

class Fight {
    private:
        Player& player;
        Monster& monster;
        int tourActuel;
        string issue;
    
    public:
        Fight(Player& player, Monster& monster, int tourActuel, string issue); // Player& = référence player pour éviter les copies
        // Si player perd 20hp alors grace a Player& c'est bien player qui perd et pas une copie

        string playersTurn(); // retourne le choix du joueur pour son tour
        int fightAttack(); // FIGHT -> calcule les dégats et retourne les HP du monstre restants
        ACT act(); // ACT -> retourne l'action décidée par le joueur
        Item item(); // ITEM -> retourne l'item décidé par le joueur, si c'est possible
        void mercy(); // MERCY -> mettre à jour nbVicoires si épargné

        Monster& getMonster();
        string getIssue();
};

#endif