//
// Created by Andreea on 13-May-23.
//

#include "entitate.h"

Entitate::Entitate(const std::string& nume_): nume(nume_) {}

Entitate::Entitate(const Entitate& other): nume(other.nume) {}

Entitate::~Entitate() {}

const std::string& Entitate::getNume() const {
    return nume;
}
