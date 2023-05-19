//
// Created by Andreea on 13-May-23.
//

#include "entitate.h"

#include <utility>

Entitate::Entitate(std::string  nume_): nume(std::move(nume_)) {}

//Entitate::Entitate(const Entitate& other): nume(other.nume) {}

Entitate::~Entitate() {}

const std::string& Entitate::getNume() const {
    return nume;
}
