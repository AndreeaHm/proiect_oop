//
// Created by Andreea on 13-May-23.
//

#ifndef PRJCT_OOP_CONTINENT_H
#define PRJCT_OOP_CONTINENT_H

#include <string>
#include <vector>
#include "tara.h"

class Continent {
    std::string nume;
    std::vector<Tara*> tari;
    //int niv_dif __attribute__((unused));

public:
    Continent(const std::string& nume_, std::vector<Tara*> tari_);

    ~Continent();

    void adaugaTara(Tara* tara);

    [[nodiscard]] const std::string& getNumecont() const;
    [[nodiscard]] const std::vector<Tara*>& getTari() const;
    //[[nodiscard]]  int getNivdif() const;
};

#endif //PRJCT_OOP_CONTINENT_H
