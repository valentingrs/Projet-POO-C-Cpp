#include "MiniBoss.h"

using namespace std;

MiniBoss::MiniBoss(string name, int maxHP, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts)
            : Monster(name, maxHP, "MINIBOSS", atk, dfc, mercy, mercyGoal, acts) {}

int MiniBoss::getActCount() { return 3; }

void MiniBoss::afficherMenuAct() {
    cout << "Actions disponibles (MINIBOSS) :" << endl;
    vector<ACT> acts = getActs();
    for (int i = 0; i < 3 && i < (int)acts.size(); i++) {
        cout << i + 1 << ". " << acts[i].getText() << endl;
    }
}