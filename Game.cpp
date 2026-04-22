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
#include "Fight.h"
#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game(string fileMonsters, string fileItems) {
    this->player = setup();
    this->monsters = loadMonsters(fileMonsters);
    this->victoires = 0;
    this->items = loadItems(fileItems);

}

Game::~Game() {
    delete player;
    player = nullptr;

    for(Monster* m : monsters) {
        delete m;
        m = nullptr;
    }
}

vector<Item> Game::loadItems(string filepath) {
    ifstream file(filepath);
    vector<Item> setItems;
    if (!file.is_open()) {
        cerr << "[ERREUR] Fichier introuvable : " << filepath << "\n";
        return setItems;
    }

    string line;
    int lineNum = 0;
    while (getline(file, line)) {
        lineNum++;
        if (line.empty()) continue;

        // Supprimer les espaces autour des champs
        istringstream ss(line);
        string nom, typeStr, valueStr, qtyStr;

        if (!getline(ss, nom, ';') || !getline(ss, typeStr, ';') ||
            !getline(ss, valueStr, ';') || !getline(ss, qtyStr, ';')) {
            cerr << "[AVERT.] Ligne " << lineNum << " mal formée, ignorée.\n";
            continue;
        }

        // Trim simple
        auto trim = [](string& s) {
            s.erase(0, s.find_first_not_of(" \t\r\n"));
            s.erase(s.find_last_not_of(" \t\r\n") + 1);
            };
        trim(nom); trim(typeStr); trim(valueStr); trim(qtyStr);

        try {
            Item item(nom, typeStr, stoi(valueStr), stoi(qtyStr));
            setItems.push_back(item);
        }
        catch (...) {
            std::cerr << "[AVERT.] Ligne " << lineNum << " : valeur invalide, ignorée.\n";
        }
    }
    return setItems;
}

Player* Game::setup() {
    string pseudo;
    cout << "Démarron une partie...\nRentrer un pseudo : ";
    cin >> pseudo;

    Player* player = new Player(pseudo, 100);

    cout << "\nChargement des fichiers...\nFichiers chargés !" << endl;
    cout << "\nNom du joueur : " << player->getName() << "\nHP : " << player->getHP() << "\nItems : " << " "<< endl;

    cout << "Passer à la suite ...";
    _getch(); // Attendre que le joueur appuie sur entrée
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran

    return player;
}

vector<Monster*> Game::loadMonsters(string fileName) {
    ifstream file(fileName);
    vector<Monster*> setMonstres;
    string line;
    cout << "Répertoire actuel : " << filesystem::current_path() << endl;

    if(!file.is_open()) {
        cout << "Fichier introuvable !" << endl;
        return setMonstres;
    }

    while(getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string category, name, hp_str, atk_str, dfc_str, mercy_str;

        // à alléger 
        getline(ss, category, ';');
        getline(ss, name, ';'); 
        getline(ss, hp_str, ';'); int hp = stoi(hp_str);
        getline(ss, atk_str, ';'); int atk = stoi(atk_str);
        getline(ss, dfc_str, ';'); int dfc = stoi(dfc_str);
        getline(ss, mercy_str, ';');  int mercy = stoi(mercy_str);


        vector<ACT> monsterActs;
        Monster* m = new Monster(name, hp, category, atk, dfc, mercy, 100, monsterActs);
        setMonstres.push_back(m);
    }

    file.close();
    return setMonstres;
}

int Game::mainMenu() { // à remettre en void
    cout << "1 - Bestiaire\n2 - Démarrer un combat\n3 - Statisitques du personnage\n4 - Items\n5 - Quitter" << endl;   
    int choix = -1;
    while (choix < 1 || choix  > 5) {
        cout << "Que souhaitez-vous faire (rentrer le nombre) : ";
        cin >> choix;
    } 
    
    return choix;
}

void Game::displayBestiary() {
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
    cout << "Bestiaire : " << endl;

    // Retour menu principal 
    _getch(); // Attendre que le joueur appuie sur entrée
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
}

void Game::displayStats() {
}

void Game::displayItems() {
}

Fight Game::startFight() {
    // Initialisation et retour d'un objet Fight
    // (Attention : nécessite que le constructeur de Fight soit défini)
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran
    cout << "Combat : " << endl;
    
    srand(time(0));
    int index = rand() % monsters.size();
    Monster* monsterFight = monsters[index]; // adresse mémoire d'un mopnstre

    cout << "Nom du monstre pioché pour le combat : " << monsterFight->getName() << endl;

    // Retour menu principal 
    _getch(); // Attendre que le joueur appuie sur entrée
    cout << "\x1b[2J\x1b[H"; // Nettoyer l'écran

    return Fight(*player, *monsterFight, 0, "Started");
}

void Game::quit() {
    // Logique de sortie du jeu
}

bool Game::checkEndingGame() {
    // Vérification des conditions de fin (victoire ou défaite totale)
    return false;
}