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
        virtual ~Entity() = default;

        // Getters 
        string getName();
        int getHP();
        int getMaxHP();

        // Agissent comme des setters
        void takeDamage(int dmg);
        void heal(int amount);

        // Méthode virtuelle pure : chaque entité attaque différemment
        virtual int attack(Entity& target) = 0;

        bool isAlive();
};

#endif