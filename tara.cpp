//
// Created by Andreea on 13-May-23.
//

#include "tara.h"

#include <utility>

Tara::Tara(std::string  nume_tara_, std::string  capitalatara_, const std::vector<Oras>& orase_)
        : nume_tara(std::move(nume_tara_)), capitala(std::move(capitalatara_)), orase(orase_) {}

Tara::Tara(const Tara& other) = default;

Tara& Tara::operator=(const Tara& other) {
    swap(const_cast<Tara &>(other));
    return *this;
}

Tara::~Tara() = default;

std::ostream& operator<<(std::ostream& os, const Tara& tara) {
    os << "Tara: " << tara.nume_tara << ", Capitala: " << tara.capitala << std::endl;
    os << "Orase: " << std::endl;
    for (const auto& oras : tara.orase) {
        os << oras << std::endl;
    }
    return os;
}

const std::string& Tara::getNume() const {
    return nume_tara;
}

const std::string& Tara::getCapitala() const {
    return capitala;
}

const std::vector<Oras>& Tara::getOrase() const {
    return orase;
}

void Tara::swap(Tara& other) {
    using std::swap;
    swap(nume_tara,other.nume_tara);
    swap(capitala, other.capitala);
    orase.swap(other.orase);
}

Tara::Tara() = default;

void Tara::afisare() {
    std::cout << "Tara: " << nume_tara << ", Capitala: " << capitala << std::endl;
    std::cout << "Orase: " << std::endl;
    for (const auto& oras : orase) {
        std::cout << oras << std::endl;
    }
}

void Tara_locked::afisare() {
    Tara::afisare();
}

Tara_locked* Tara_locked::clone() const {
    return new Tara_locked(*this);
}

Tara_locked::Tara_locked(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_) : Tara(nt, nc, orase_) {}

void Tara_apa::afisare() {
    Tara::afisare();
}

Tara_apa* Tara_apa::clone() const {
    return new Tara_apa(*this);
}

Tara_apa::Tara_apa(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_): Tara(nt, nc, orase_){}
