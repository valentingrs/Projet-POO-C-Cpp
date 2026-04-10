#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Items.h"
#include "Entity.h"

using namespace std;

Player::Player(string personnage, int maxHP) : Entity(personnage, maxHP) {
    this->items = {};
    this->nbVictoires = 0;
    this->monstresVaincus = {};
}

vector<Item> Player::getItems() { return this->items; }
int Player::getNbVictoires() { return nbVictoires; }
vector<Monster> Player::getMonstresVaincus() { return monstresVaincus; }
int Player::getNbKilled() { return nbKilled; }
int Player::getNbSpared() { return nbSpared; }

void Player::addVictory() { nbVictoires += 1; }
void Player::addMonstresVaincus(Monster monstre) {
    monstresVaincus.push_back(monstre);
}

void Player::useItem(int index) {}
