#include "Boss.h"

using namespace std;

Boss::Boss(string name, int maxHP, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts)
            : Monster(name, maxHP, "BOSS", atk, dfc, mercy, mercyGoal, acts) {}

int Boss::getActCount() { return 4; }

void Boss::afficherMenuAct() {
    cout << "Actions disponibles (BOSS) :" << endl;
    vector<ACT> acts = getActs();
    for (int i = 0; i < 4 && i < (int)acts.size(); i++) {
        cout << i + 1 << ". " << acts[i].getText() << endl;
    }
}