#include <string>
#include "Fight.h"
#include "Monster.h"

using namespace std;

Fight::Fight(Player player, Monster monster, int tourActuel, string issue)
    : player(player),
      monster(monster),
      tourActuel(tourActuel),
      issue(issue)
{
}

string Fight::getIssue() { return issue; }
Monster Fight::getMonster() { return monster; }