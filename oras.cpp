//
// Created by Andreea on 16-May-23.
//

#include "oras.h"

Oras::Oras(const std::string& name_, int population_)
        : Entitate(name_), population(population_) {}

Oras::Oras(const Oras& other)
        : Entitate(other), population(other.population) {}

Oras::~Oras() = default;

std::ostream& operator<<(std::ostream& os, const Oras& oras) {
    os << "Nume oras: " << oras.getNume() << std::endl;
    os << "Populatie: " << oras.population << std::endl;
    return os;
}

/*int Oras::getPopulation() const {
    return population;
}*/
