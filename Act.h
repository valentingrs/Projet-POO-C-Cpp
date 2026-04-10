#ifndef ACT_H
#define ACT_H

#include <string>

using namespace std;

class ACT {
    private:
        int id;
        string text;
        int impactMercy;

    public:
        ACT(int id, string text, int impactMercy);
        string getText();
        int getImpactMercy();
};

#endif