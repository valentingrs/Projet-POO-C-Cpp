#include <string>
#include "Entity.cpp"
#include "Monster.h"

using namespace std;

Monster::Monster(string personnage, int maxHP) : Entity(personnage, maxHP) {
    this->category = category;
    this->atk = atk;
    this->dfc = dfc;
    this->mercy = mercy;
    this->acts = acts;
}
