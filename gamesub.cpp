#include "gamesub.h"

[[maybe_unused]] void GameSubject::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void GameSubject::notifyObservers(int score) {
    for (Observer* observer : observers) {
        observer->update(score);
    }
}

