//
// Created by Andreea on 13-May-23.
//

#include "entitate.h"
#include <iostream>

Entitate::Entitate(std::string nume_) : nume(std::move(nume_)) {}

Entitate::~Entitate() = default;

const std::string& Entitate::getNume() const {
    return nume;
}

void Entitate::afisare() const {
    std::cout << "Nume: " << nume << std::endl;
}


