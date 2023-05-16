//
// Created by Andreea on 13-May-23.
//

#include "Continent.h"

Continent::Continent(const std::string &nume_, std::vector<Tara *> vector, const int niv_dif_) {
    nume = nume_;
    tari = vector;
    niv_dif = niv_dif_;
}

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

const int Continent::getNivdif() const {
    return niv_dif;
}
