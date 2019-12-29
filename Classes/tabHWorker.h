#ifndef AEDA_UGHEATS_TABHWORKER_H
#define AEDA_UGHEATS_TABHWORKER_H

#include <unordered_set>
#include <cmath>

using namespace std;

class Worker;

class workerHash {
public:
    size_t operator() (const Worker* w) const;
};

class workerEq {
public:
    bool operator() (const Worker* w1, const Worker* w2) const;
};

typedef unordered_set<Worker*, workerHash, workerEq> tabHWorker;

#endif //AEDA_UGHEATS_TABHWORKER_H
