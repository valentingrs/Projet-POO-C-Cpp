#include "Normal.h"

using namespace std;

Normal::Normal(string name, int maxHP, int atk, int dfc, int mercy, int mercyGoal, vector<ACT> acts)
            : Monster(name, maxHP, "NORMAL", atk, dfc, mercy, mercyGoal, acts) {}

int Normal::getActCount() { return 2; }

void Normal::afficherMenuAct() {
    cout << "Actions disponibles (NORMAL) :" << endl;
    vector<ACT> acts = getActs();
    for (int i = 0; i < 2 && i < (int)acts.size(); i++) {
        cout << i + 1 << ". " << acts[i].getText() << endl;
    }
}