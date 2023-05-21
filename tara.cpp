//
// Created by Andreea on 13-May-23.
//

#include "tara.h"

Tara::Tara(const std::string& numetara_, const std::string& capitalatara_, const std::vector<Oras*>& orase_)
        : Entitate(numetara_), capitala(capitalatara_), orase(orase_) {}

Tara::Tara(const Tara& other)
        : Entitate(other), capitala(other.capitala) {
    for (const auto &oras: other.orase) {
        orase.push_back(new Oras(*oras));
    }
}

Tara& Tara::operator=(Tara other) {
    swap(other);
    return *this;
}

Tara::~Tara() {
    for (auto oras : orase) {
        delete oras;
    }
}

void Tara::afisare() const {
    Entitate::afisare();
    std::cout << "Capitala: " << capitala << std::endl;
}

const std::string& Tara::getCapitala() const {
    return capitala;
}

const std::vector<Oras*>& Tara::getOrase() const {
    return orase;
}

void Tara::adaugaOras(Oras* oras) {
    orase.push_back(oras);
}

Tara* Tara::clone() const {
    return new Tara(*this);
}

void Tara::swap(Tara& other) {
    using std::swap;
    swap(nume,other.nume);
    swap(capitala, other.capitala);
    swap(orase, other.orase);
}