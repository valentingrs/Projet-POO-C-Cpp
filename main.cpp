#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include "Player.cpp"

using namespace std;

// Lecture fichiers monsters.csv
int ReadMonsters() {
    cout << "Répertoire actuel : " << filesystem::current_path() << endl;
    ifstream file("monsters.csv");

    if(!file.is_open()) {
        cout << "Fichier introuvable !" << endl;
        return 1;
    }

    string line;

    while(getline(file, line)) {
        cout << "Ligne : " << line << endl;
    }

    file.close();
    return 1;
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
    
    int x = ReadMonsters();
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