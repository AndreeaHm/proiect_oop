//
// Created by Andreea on 13-May-23.
//
#include "jucator.h"

Jucator::Jucator(const std::string& numejuc_, const int scorjuc_, const int nr_rundejuc_, const int nivel_dific_)
        : Entitate(numejuc_), scor(scorjuc_), nr_runde(nr_rundejuc_), nivel_dific(nivel_dific_) {}

Jucator::Jucator(const Jucator& other)
        : Entitate(other), scor(other.scor), nr_runde(other.nr_runde), nivel_dific(other.nivel_dific) {}

Jucator::~Jucator() {}

std::ostream& operator<<(std::ostream& os, const Jucator& jucator) {
    os << "nume: " << jucator.nume << " scor: " << jucator.scor << " nr_runde: " << jucator.nr_runde << "nivel_dific: " << jucator.nivel_dific;
    return os;
}

int Jucator::getScor() const {
    return scor;
}

void Jucator::crestere_scor(int pnct) {
    scor += pnct;
}

int Jucator::getNrRunde() const {
    return nr_runde;
}

int Jucator::getNivelDific() const {
    return nivel_dific;
}
