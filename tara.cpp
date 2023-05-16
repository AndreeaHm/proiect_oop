//
// Created by Andreea on 13-May-23.
//

#include "tara.h"

Tara::Tara(const std::string& numetara_, const std::string& capitalatara_)
        : Entitate(numetara_), capitala(capitalatara_) {}

Tara::Tara(const Tara& other)
        : Entitate(other.nume), capitala(other.capitala) {}

Tara::~Tara() {}

std::ostream &operator<<(std::ostream &os, const Tara &tara) {
    os << "nume: " << tara.nume << " capitala: " << tara.capitala;
    return os;
}

const std::string &Tara::getCapitala() const {
    return capitala;
}
