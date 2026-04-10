#ifndef ITEMS_H
#define ITEMS_H

#include <string>

using namespace std;

class Item {
    public:
        string nom;
        string type;
        int valeur;
        int quantite;

        Item(string nom, string type, int valeur, int quantite);
};

#endif