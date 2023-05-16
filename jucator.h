//
// Created by Andreea on 13-May-23.
//

#ifndef PRJCT_OOP_JUCATOR_H
#define PRJCT_OOP_JUCATOR_H

#include "Entitate.h"
#include <iostream>
#include <string>

class Jucator : public Entitate {
    int scor;
    int nr_runde;
    int nivel_dific;

public:
    Jucator(const std::string& numejuc_, const int scorjuc_, const int nr_rundejuc_, const int nivel_dific_);

    Jucator(const Jucator& other);

    ~Jucator();

    friend std::ostream& operator<<(std::ostream& os, const Jucator& jucator);

    int getScor() const;

    void crestere_scor(int pnct);

    int getNrRunde() const;

    int getNivelDific() const;
};

#endif //PRJCT_OOP_JUCATOR_H
