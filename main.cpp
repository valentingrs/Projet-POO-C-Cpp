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
#include "Player.h"

using namespace std;

// Lecture fichiers monsters.csv
vector<Monster> ReadMonsters() {
    vector<Monster> setMonstres;
    string line;
    cout << "Répertoire actuel : " << filesystem::current_path() << endl;
    ifstream file("monsters.csv");

    if(!file.is_open()) {
        cout << "Fichier introuvable !" << endl;
        return setMonstres;
    }

    while(getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string category, name, hp_str, atk_str, dfc_str, mercyGoal_str;

        getline(ss, category, ';');
        getline(ss, name, ';'); 
        getline(ss, hp_str, ';'); int hp = stoi(hp_str);
        getline(ss, atk_str, ';'); int atk = stoi(atk_str);
        getline(ss, dfc_str, ';'); int dfc = stoi(dfc_str);
        getline(ss, mercyGoal_str, ';');  int mercyGoal = stoi(mercyGoal_str);


        vector<ACT> monsterActs;
        Monster m(name, hp, category, atk, dfc, mercyGoal, monsterActs);
        setMonstres.push_back(m);
    }

    file.close();
    return setMonstres;
}

Player setup() {
    string pseudo;
    cout << "Démarron une partie...\nRentrer un pseudo : ";
    cin >> pseudo;

    Player player(pseudo, 100);

    cout << "\nChargement des fichiers...\nFichiers chargés !" << endl;
    cout << "\nNom du joueur : " << player.getName() << "\nHP : " << player.getHP() << "\nItems : " << " "<< endl;

    cout << "Passer à la suite ...";
    _getch(); // Attendre que le joueur appuie sur entrée
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran

    return player;
}

void AfficherBestiaire() {
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
    cout << "Bestiaire : " << endl;

    // Retour menu principal 
    _getch(); // Attendre que le joueur appuie sur entrée
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
}

void DemarrerUnCombat() {
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
    cout << "Combat : " << endl;
    
    vector<Monster> setMonstres = ReadMonsters();
    srand(time(0));
    int index = rand() % setMonstres.size();
    Monster monsterFight = setMonstres[index];

    cout << "Nom du monstre pioché pour le combat : " << monsterFight.getName() << endl;

    // Retour menu principal 
    _getch(); // Attendre que le joueur appuie sur entrée
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
}

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
    Player p = setup();

    while(true) {
        int choix = mainMenu();

        if (choix == 1) { AfficherBestiaire(); }
        if (choix == 2) { DemarrerUnCombat(); }
    }
    mainMenu();
}