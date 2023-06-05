//
// Created by Andreea on 16-May-23.
//

#include "oras.h"

Oras::Oras(const std::string& nume_oras_, int population_)
        : nume_oras(nume_oras_), population(population_) {}

Oras::Oras(const Oras& other)
        : nume_oras(other.nume_oras), population(other.population) {}


Oras::~Oras() = default;

std::ostream& operator<<(std::ostream& os, const Oras& oras) {
    os << "Nume oras: " << oras.nume_oras << std::endl;
    os << "Populatie: " << oras.population << std::endl;
    return os;
}

const std::string& Oras::getNume() const {
    return nume_oras;
}

/*int Oras::getPopulation() const {
    return population;
}*/
