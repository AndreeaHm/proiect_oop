#ifndef PRJCT_OOP_JUCATOR_H
#define PRJCT_OOP_JUCATOR_H

#include "entitate.h"
#include <iostream>
#include <string>

class Jucator : public Entitate {
    static int scor; // Static attribute
    int nr_runde;
    int nr_joc;
    int nivel_dific;

public:
    Jucator(const std::string& numejuc_, int nr_rundejuc_, int nr_joc_, int nivel_dific_);
    Jucator(const Jucator& other);
    ~Jucator() override;

    friend std::ostream& operator<<(std::ostream& os, const Jucator& jucator);

    static int getScor();
    static void crestere_scor(int pnct);
    [[nodiscard]] int getNrRunde() const;
    [[nodiscard]] int getNrJoc() const;
    [[nodiscard]] int getNivelDific() const;
};

#endif // PRJCT_OOP_JUCATOR_H
