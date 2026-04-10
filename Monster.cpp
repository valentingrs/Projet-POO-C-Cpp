#include <string>
#include <vector>
#include "Entity.h"
#include "Monster.h"
#include "Act.h"

using namespace std;

Monster::Monster(string personnage, int maxHP, string category, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts) 
: Entity(personnage, maxHP) {
    this->category = category;
    this->atk = atk;
    this->dfc = dfc;
    this->mercy = mercy;
    this->mercyGoal = mercyGoal;
    this->acts = acts;
}

string Monster::getCategory() { return category; }
int Monster::getAtk() { return atk; }
int Monster::getDfc() { return dfc; }
int Monster::getMercy() { return mercy; }
vector<ACT> Monster::getActs() { return acts; }

void Monster::setMercy(int amount) {
    mercy += amount;
    if (mercy < 0) { mercy = 0; }
}

void Monster::setAct(ACT action) {
    acts.push_back(action);
}

int Monster::getActCount() { return 0; } // à modifier
bool Monster::canMercy() { return true; } // à modifier