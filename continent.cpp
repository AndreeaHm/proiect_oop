//
// Created by Andreea on 13-May-23.
//

#include "continent.h"

Continent::Continent(const std::string& nume_, std::vector<std::unique_ptr<Tara>> tari_)
        : nume(nume_), tari(std::move(tari_)) {}

Continent::~Continent() = default;

void Continent::adaugaTara(std::unique_ptr<Tara> tara) {
    tari.push_back(std::move(tara));
}

const std::string& Continent::getNumecont() const {
    return nume;
}

const std::vector<std::unique_ptr<Tara>>& Continent::getTari() const {
    return tari;
}