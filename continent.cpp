//
// Created by Andreea on 13-May-23.
//

#include "continent.h"

Continent::Continent(const std::string& nume_,  std::vector<Tara*>& tari_)
        : Entitate(nume_){
    for(auto tara : tari_) {
        tari.push_back(tara->clone());
    }
}

Continent::~Continent() {
}

void Continent::adaugaTara(Tara* tara) {
    tari.push_back(tara->clone());
}

const std::string& Continent::getNumecont() const {
    return nume;
}

const std::vector<Tara*>& Continent::getTari() const {
    return tari;
}
