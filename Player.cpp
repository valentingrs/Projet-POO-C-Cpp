#include <vector>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Items.h"
#include "Entity.h"

using namespace std;

Player::Player(string personnage, int maxHP) : Entity(personnage, maxHP) {
    this->items = {};
    this->nbVictoires = 0;
    this->monstresVaincus = {};
    this->nbKilled = 0;
    this->nbSpared = 0;
}

vector<Item> Player::getItems() { return this->items; }
int Player::getNbVictoires() { return nbVictoires; }
vector<Monster> Player::getMonstresVaincus() { return monstresVaincus; }
int Player::getNbKilled() { return nbKilled; }
int Player::getNbSpared() { return nbSpared; }

void Player::addVictory(bool monsterKilled) { 
    nbVictoires++;
    if (monsterKilled) { nbKilled++; }
    else { nbSpared++; }
}

void Player::addMonstresVaincus(Monster& monstre) {
    monstresVaincus.push_back(monstre);
}

bool Player::hasWon() { return (nbVictoires == 10); }

void Player::addItem(const Item& item) {
    items.push_back(item);
}

bool Player::useItem(int index) {
    Item it = items[index];

    if (it.getQuantite() == 0) {
        cout << "Item épuise, vous n'en avez plus !" << endl;
        return false;
    }

    cout << "Vous utilisez " << it.getNom() << endl;
    it.applyEffect(*this); // application sur l'objet lui même
    it.use(1);
    return true;

}

void Player::displayItems() {
    int i = 1;
    for(Item& it : items) {
        cout << i << ". " << it << endl;
        i++;
    }
}

int Player::attack(Entity& target) {
    int dmg = 10; // Ou ta formule de dégâts
    target.takeDamage(dmg);
    return dmg;
}