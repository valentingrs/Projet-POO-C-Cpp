#ifndef ITEMS_H
#define ITEMS_H

#include "Entity.h"
#include <string>

using namespace std;

class Item {
    private:
        string nom;
        string type;
        int valeur;
        int quantite;

    public:
        Item(string nom, string type, int valeur, int quantite);
        string getNom();
        string getType();
        int getValeur();
        int getQuantite();

        friend ostream& operator<<(std::ostream& os, const Item& item); // pour faire cout << item << endl;
        
        void use(int amount);
        void applyEffect(Entity& target);
};

#endif