#include <string>
#include <iostream>
#include "Fight.h"
#include "Monster.h"

using namespace std;

Fight::Fight(Player& player, Monster& monster, int tourActuel, string issue)
    : player(player),
      monster(monster),
      tourActuel(tourActuel),
      issue(issue)
{
}

void Fight::run() {
    cout << "Un combat commence contre " << monster.getName() << " !" << endl;

    while(player.isAlive() && monster.isAlive() && issue == "Started") {
        tourActuel++;
        cout << "\n---TOUR " << tourActuel << " ---" << endl;

        // Tour du joueur
        string choix = playersTurn();
        
        if (choix == "MERCY") {
            this->mercy();
        }

        else if (choix == "ACT") {
            this->act();
        }

        else if (choix == "ITEM") {
            this->item();
        }

        else if (choix == "FIGHT") {
            this->fightAttack();
        }

        if (!monster.isAlive()) {
            issue = "Win";
            player.addVictory(true); // true = monstre tué
            player.addMonstresVaincus(monster);
            cout << "Le monstre a été tué !" << endl;
            break;
        }

        // Si le monstre est encore en vie ou pas epargné, c'est son tour
        monsterAttack();

        if (!player.isAlive()) {
            issue = "Loss";
            cout << "Vous avez perdu le combat...\n" << endl;
            break;
        }
    }
    
}

string Fight::playersTurn() {
    int choix = -1;
    cout << "\nPV : " << player.getHP() << "/" << player.getMaxHP() << endl;
    cout << "Monstre - PV : " << monster.getHP() << "/" << monster.getMaxHP() <<  " | MERCY : " << monster.getMercy() << "/100" << endl;
    while (choix < 1 || choix > 4) {
        cout << "1. FIGHT  2. ACT  3. ITEM  4. MERCY" << endl;
        cout << "Choix : ";
        cin >> choix;
    }

    if (choix == 1) return "FIGHT";
    if (choix == 2) return "ACT";
    if (choix == 3) return "ITEM";
    if (choix == 4) return "MERCY";
    return "";
}

void Fight::fightAttack() {
    // Calcul des dégâts 
    int dmg = rand() % (monster.getMaxHP() + 1);

    cout << "\n---VOUS ATTAQUEZ ---" << endl;

    if (dmg == 0) { cout << "Coup raté ! Le monstre n'a rien senti" << endl; }
    else {
        cout << "Vous infligez " << dmg << " points de dégâts" << endl;
        monster.takeDamage(dmg); // on retire les HP au monstre
    }

    cout << "PV restants du monstre : " << monster.getHP() << "/" << monster.getMaxHP() << endl;
}

void Fight::monsterAttack() {
    // Calcul des dégâts 
    int dmg = rand() % (player.getMaxHP() + 1);

    cout << "\n--- " << monster.getName() << " ATTAQUE ---" << endl;

    if (dmg == 0) {
        cout << monster.getName() << " a raté son attaque !" << endl;
    } else {
        cout << monster.getName() << " vous inflige " << dmg << " points de dégâts !" << endl;
        player.takeDamage(dmg);
    }
}

void Fight::act() {
    cout << "Utilisation d'un ACT" << endl;
}

void Fight::item() {
    cout << "\nUtilisation d'un Item. Voici les items disponibles : " << endl;
    player.displayItems();

    int choixItem = -1; // choix de l'Item par son numéro
    while (choixItem < 1 || choixItem > player.getItems().size()) {
        cout << "Quel Item voulez-vous utiliser ? ";
        cin >> choixItem;
        player.useItem(choixItem - 1);
    }

    cout << "\nItem utilisé !" << endl;
    cout << "\nPV : " << player.getHP() << "/" << player.getMaxHP() << "\n" << endl;
}

void Fight::mercy() {
    cout << "\n--- TENTATIVE D'EPARGNE ---" << endl;

    if (monster.getMercy() >= 100) {
        cout << monster.getName() << "a été épargné" << endl;
        cout << "Victoire pacifiste !" << endl;

        this->issue = "Epargne";

        player.addVictory(false);
        player.addMonstresVaincus(monster);
    }
    else {
        cout << monster.getName() << " ne veut pas être épargné..." << endl;
        cout << "Mercy actuelle : " << monster.getMercy() + "/100." << endl;
    }
}

string Fight::getIssue() { return issue; }
Monster& Fight::getMonster() { return monster; }