//
// Created by Andreea on 13-May-23.
//

#include "tara.h"

#include <utility>

Tara::Tara(std::string  nume_tara_, std::string  capitalatara_, const std::vector<Oras>& orase_)
        : nume_tara(std::move(nume_tara_)), capitala(std::move(capitalatara_)), orase(orase_) {}

Tara::Tara(const Tara& other)
        : nume_tara(other.nume_tara), capitala(other.capitala) {
    for (const auto &oras: other.orase)
        orase.emplace_back(oras);

}

Tara& Tara::operator=(const Tara& other) {
    if (this != &other) {
        nume_tara = other.nume_tara;
        capitala = other.capitala;
        orase = other.orase;
    }
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

[[maybe_unused]] void Tara::swap(Tara& other) {
    using std::swap;
    swap(nume_tara, other.nume_tara);
    swap(capitala, other.capitala);
    swap(orase, other.orase);
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
    std::vector<Oras> clonedOrase;
    for (const auto& oras : orase) {
        clonedOrase.push_back(oras);
    }
    return new Tara_locked(getNume(), getCapitala(), clonedOrase);
}


Tara_locked::Tara_locked(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_) : Tara(nt, nc, orase_) {}

bool Tara_locked::isLocked() const {
    return true;
}

bool Tara_locked::hasAccesstoSea() const {
    return false;
}

bool Tara_apa::isLocked() const {
    return false;
}

bool Tara_apa::hasAccesstoSea() const {
    return true;
}


void Tara_apa::afisare() {
    Tara::afisare();
    std::cout << "Nume mare: " << nume_mare << std::endl;
}

Tara_apa* Tara_apa::clone() const{
    return new Tara_apa(*this);
}

Tara_apa::Tara_apa(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_, const std::string& nume_mare_) : Tara(nt, nc, orase_), nume_mare(nume_mare_) {}

const std::string& Tara_apa::getNumeMare() const {
    return nume_mare;
}