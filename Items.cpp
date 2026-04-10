#include <string>
#include "Items.h"

using namespace std;

Item::Item(string nom, string type, int valeur, int quantite) {
    this->nom = nom;
    this->type = type;
    this->valeur = valeur;
    this->quantite = quantite;
}

