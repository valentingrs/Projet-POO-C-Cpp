#include <string>
#include <iostream>
#include "Items.h"
#include "Entity.h"

using namespace std;

Item::Item(string nom, string type, int valeur, int quantite) {
    this->nom = nom;
    this->type = type;
    this->valeur = valeur;
    this->quantite = quantite;
}

string Item::getNom() { return nom; }
string Item::getType() { return type; }
int Item::getValeur() { return valeur; }
int Item::getQuantite() { return quantite; }

ostream& operator<<(ostream& os, const Item& item) {
    os << item.nom << " (x" << item.quantite << ") - [Effet: " << item.valeur << "]";
    return os;
}

void Item::use(int qte) {
    quantite = quantite - qte;
}

void Item::applyEffect(Entity& target) {
    if (type == "HEAL") {
        target.heal(valeur);
    }
}