//
// Created by Andreea on 13-May-23.
//

#include <utility>

#include "continent.h"

Continent::Continent(const std::string &nume_, std::vector<Tara *> tari_, const int niv_dif_) {
    nume = nume_;
    tari = std::move(tari_);
    niv_dif = niv_dif_;
}

Continent::~Continent() {
    for (auto tara : tari) {
        delete tara;
    }
}

void Continent::adaugaTara(Tara* tara) {
    if (Tara* t = dynamic_cast<Tara*>(tara)) {
        tari.push_back(t);
    } else {
        delete tara;
    }
}

const std::string& Continent::getNumecont() const {
    return nume;
}

const std::vector<Tara*>& Continent::getTari() const {
    return tari;
}

/*const int Continent::getNivdif() const {
    return niv_dif;
}*/
