#include <vector>
#include "Player.h"
#include "Items.cpp"
#include "Entity.cpp"

using namespace std;

Player::Player(string personnage, int maxHP) : Entity(personnage, maxHP) {
    this->items = {};
    this->nbVictoires = 0;
    this->monstresVaincus = {};
}

vector<Item> Player::getItems() { return this->items; }