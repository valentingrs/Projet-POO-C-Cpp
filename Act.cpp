#include <string>
#include "Act.h"

using namespace std;

ACT::ACT(int id, string text, int impactMercy) {
    this->id = id;
    this->text = text;
    this->impactMercy = impactMercy;
}

string ACT::getText() { return text; }
int ACT::getImpactMercy() { return impactMercy; }