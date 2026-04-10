#include <string>
#include "Fight.h"

using namespace std;

Fight::Fight(Player player, Monster monster, int tourActuel, string issue)
    : player(player),
      monster(monster),
      tourActuel(tourActuel),
      issue(issue)
{
}
