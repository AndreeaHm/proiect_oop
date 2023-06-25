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

int Oras::getPopulation() const {
    return population;
}

template <typename T>
T Oras::findCityWithHighestPopulation(const T& city1, const T& city2, const T& city3) {
    if (city1.getPopulation() >= city2.getPopulation() && city1.getPopulation() >= city3.getPopulation()) {
        return city1;
    } else if (city2.getPopulation() >= city1.getPopulation() && city2.getPopulation() >= city3.getPopulation()) {
        return city2;
    } else {
        return city3;
    }
}
