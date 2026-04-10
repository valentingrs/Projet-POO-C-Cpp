#ifndef ACT_H
#define ACT_H

#include <string>

using namespace std;

class ACT {
    public:
        int id;
        string text;
        int impactMercy;

        ACT(int id, string text, int impactMercy);
};

#endif