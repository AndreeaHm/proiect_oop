//
// Created by Andreea on 13-May-23.
//

#include "jucator.h"

int Jucator::scor = 0;

Jucator::Jucator(const std::string& numejuc_, int nr_rundejuc_, int nr_joc_, int nivel_dific_)
        : Entitate(numejuc_), nr_runde(nr_rundejuc_), nr_joc(nr_joc_), nivel_dific(nivel_dific_) {}

Jucator::Jucator(const Jucator& other)
        : Entitate(other.nume), nr_runde(other.nr_runde), nr_joc(other.nr_joc), nivel_dific(other.nivel_dific) {}

Jucator::~Jucator() = default;

std::ostream& operator<<(std::ostream& os, const Jucator& jucator) {
    os << "Nume jucator: " << jucator.nume << "\n";
    os << "Scor: " << Jucator::scor << "\n";
    os << "Numar runde jucate: " << jucator.nr_runde << "\n";
    os << "Numar joc: " << jucator.nr_joc << "\n";
    os << "Nivel dificultate: " << jucator.nivel_dific << "\n";
    return os;
}

int Jucator::getScor() {
    return scor;
}

void Jucator::update(int score) {
    scor = score;
}

int Jucator::getNrRunde() const {
    return nr_runde;
}

int Jucator::getNrJoc() const {
    return nr_joc;
}

int Jucator::getNivelDific() const {
    return nivel_dific;
}

int Jucator::cresteScor(int pnct) {
    scor += pnct;
    return scor;
}

Jucator& Jucator::operator=(const Jucator& other) {
    if (this != &other) {
        Entitate::operator=(other);
    }
    return *this;
}