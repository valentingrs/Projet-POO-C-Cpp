#include "Entity.h"

Entity::Entity(string name, int maxHP) {
    this->name = name;
    this->HP = maxHP;
    this->maxHP = maxHP;
}

bool Entity::isAlive() {
    return true;
}

string Entity::getName() {
    return this->name;
}

int Entity::getHP() {
    return this->HP;
}
int Entity::getMaxHP() {
    return this->maxHP;
}