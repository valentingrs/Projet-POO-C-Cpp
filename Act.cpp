#include <string>
#include "Act.h"

using namespace std;

ACT::ACT(int id, string name, string text, int impactMercy) {
    this->id = id;
    this->name = name;
    this->text = text;
    this->impactMercy = impactMercy;
}

string ACT::getName() { return name; }
string ACT::getText() { return text; }
int ACT::getImpactMercy() { return impactMercy; }