#ifndef OOP_GAMESUB_H
#define OOP_GAMESUB_H

#include "jucator.h"
#include <vector>

class GameSubject {
private:
    std::vector<Observer*> observers;

public:
    [[maybe_unused]] void addObserver(Observer* observer);
    void notifyObservers(int score);
};

#endif //OOP_GAMESUB_H
