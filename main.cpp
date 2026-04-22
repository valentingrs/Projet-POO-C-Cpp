#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Act.h"

using namespace std;

int mainMenu() {
    cout << "1 - Bestiaire\n2 - Démarrer un combat\n3 - Statisitques du personnage\n4 - Items\n5 - Quitter" << endl;   
    int choix = -1;
    while (choix < 1 || choix  > 5) {
        cout << "Que souhaitez-vous faire (rentrer le nombre) : ";
        cin >> choix;
    } 
    
    return choix;
}

int main() {
    Game g("monsters.csv", "items.csv");

    while(true) {
        int choix = g.mainMenu();

        if (choix == 1) { g.displayBestiary(); }
        if (choix == 2) { g.startFight(); }
    }
}