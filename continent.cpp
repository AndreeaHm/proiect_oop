//
// Created by Andreea on 13-May-23.
//

#include "continent.h"

Continent::Continent(const std::string& nume_, const std::vector<Tara*>& tari_)
        : Entitate(nume_), tari(tari_) {}

Continent::~Continent() {
    for (auto tara : tari) {
        delete tara;
    }
}

void Continent::adaugaTara(Tara* tara) {
    tari.push_back(tara);
}

const std::string& Continent::getNumecont() const {
    return nume;
}

const std::vector<Tara*>& Continent::getTari() const {
    return tari;
}