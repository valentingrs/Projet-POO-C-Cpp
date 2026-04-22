#include <vector>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Items.h"
#include "Fight.h"

using namespace std;

class Game {
    private:
        Player* player;
        vector<Monster*> monsters;
        vector<Item> items;
        int victoires;

    public:
        Game(string fileMonsters, string fileItems);
        ~Game();

        vector<Item> loadItems(string filepath); // chatGPT l'a mis en pointeur
        vector<Monster*> loadMonsters(string file);

        int mainMenu(); // à remettre en void
        void displayBestiary();
        void displayStats();
        void displayItems();

        Fight startFight();

        void quit();
        Player* setup();

        bool checkEndingGame();
};