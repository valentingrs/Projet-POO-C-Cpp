#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Entity.h"
#include "Monster.h"
#include "Items.h"

class Monster;

class Player : public Entity {
    private:
        vector<Item> items; 
        int nbVictoires;
        int nbKilled;
        int nbSpared;
        vector<Monster*> monstresVaincus;

    public:
        Player(string personnage, int maxHP);

        vector<Item> getItems();
        int getNbVictoires();
        vector<Monster*> getMonstresVaincus();
        int getNbKilled();
        int getNbSpared();

        bool hasWon(); // true si victories == 10

        // Inventaire
        void addItem(const Item& item); // Référence pour éviter les copies de items
        bool useItem(int index);              // applique l'effet sur le joueur
        void displayItems();

        void addVictory(bool monsterKilled);
        void addMonstresVaincus(Monster* monster);

        // Formule d'attaque 
        int attack(Entity& target) override;

        void displayStats()     const;
        void displayInventory() const;

};

#endif