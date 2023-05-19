//
// Created by Andreea on 13-May-23.
//

#include "tara.h"

Tara::Tara(const std::string& numetara_, const std::string& capitalatara_, const std::vector<std::shared_ptr<Oras>> orase_)
        : Entitate(numetara_), capitala(capitalatara_) {
    for (const auto& oras : orase_) {
        orase.push_back(std::make_shared<Oras>(*oras));
    }
}

Tara::Tara(const Tara& other)
        : Entitate(other.nume), capitala(other.capitala), orase(other.orase) {}

Tara& Tara::operator=(Tara other) {
    swap(other);
    return *this;
}

Tara::~Tara() {}

std::ostream& operator<<(std::ostream& os, const Tara& tara) {
    os << "Tara: " << tara.nume << ", Capitala: " << tara.capitala << std::endl;
    os << "Orase: " << std::endl;
    for (const auto& oras : tara.orase) {
        os << *oras << std::endl;
    }
    return os;
}

const std::string& Tara::getCapitala() const {
    return capitala;
}

const std::vector<std::shared_ptr<Oras>>& Tara::getOrase() const {
    return orase;
}

void Tara::adaugaOras(const std::shared_ptr<Oras>& oras) {
    orase.push_back(oras);
}

Tara* Tara::clone() const {
    return new Tara(*this);
}

void Tara::swap(Tara& other) {
    using std::swap;
    swap(nume, other.nume);
    swap(capitala, other.capitala);
    swap(orase, other.orase);
}
