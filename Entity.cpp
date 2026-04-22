#include <algorithm>
#include "Entity.h"

Entity::Entity(string name, int maxHP) {
    this->name = name;
    this->HP = maxHP;
    this->maxHP = maxHP;
}

string Entity::getName() { return this->name; }
int Entity::getHP() { return this->HP;}
int Entity::getMaxHP() { return this->maxHP; }
bool Entity::isAlive() { return this->HP > 0; }

void Entity::takeDamage(int dmg) {
    HP = max(0, HP - dmg);
}
void Entity::heal(int amount) {
    HP = min(maxHP, HP + amount);
}


