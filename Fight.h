#ifndef FIGHT_H
#define FIGHT_H

#include <string>
#include "Player.h"
#include "Monster.h"
#include "Act.h"
#include "Item.h"

using namespace std;

class Fight {
    public:
        Player player;
        Monster monster;
        int tourActuel;
        string issue;
    
        Fight(Player player, Monster monster, int tourActuel, string issue);

        string playersTurn(); // retourne le choix du joueur pour son tour
        int fightAttack(); // FIGHT -> calcule les dégats et retourne les HP du monstre restants
        ACT act(); // ACT -> retourne l'action décidée par le joueur
        Item item(); // ITEM -> retourne l'item décidé par le joueur, si c'est possible
        void mercy(); // MERCY -> mettre à jour nbVicoires si épargné
};

#endif