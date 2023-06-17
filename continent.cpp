//
// Created by Andreea on 13-May-23.
//

#include "continent.h"

Continent::Continent(const std::string& nume_,  std::vector<Tara*>& tari_)
        : Entitate(nume_), tari(std::move(tari_)) {}

Continent::~Continent() = default;

void Continent::adaugaTara(Tara* tara) {
    tari.push_back(tara);
}

const std::string& Continent::getNumecont() const {
    return nume;
}

const std::vector<Tara*>& Continent::getTari() const {
    return tari;
}
