//
// Created by Andreea on 13-May-23.
//

#ifndef PRJCT_OOP_CONTINENT_H
#define PRJCT_OOP_CONTINENT_H

#include <string>
#include <vector>
#include "Tara.h"

#include <string>
#include <vector>
#include "tara.h"

class Continent {
    std::string nume;
    std::vector<Tara*> tari;
    int niv_dif;

public:
    Continent(const std::string &nume_, std::vector<Tara *> vector, const int niv_dif_);
    ~Continent();

    void adaugaTara(Tara* tara);

    const std::string& getNumecont() const;
    const std::vector<Tara*>& getTari() const;
    const int getNivdif() const;
};

#endif //PRJCT_OOP_CONTINENT_H
