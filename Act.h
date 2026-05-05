#ifndef ACT_H
#define ACT_H

#include <string>

using namespace std;

class ACT {
    private:
        int id;
        string name;
        string text;
        int impactMercy;

    public:
        ACT() : id(0), name(""), text(""), impactMercy(0) {} // constructeur par défaut
        ACT(int id, string name, string text, int impactMercy);
        string getName();
        string getText();
        int getImpactMercy();
};



#endif