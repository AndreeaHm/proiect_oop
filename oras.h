//
// Created by Andreea on 16-May-23.
//

#ifndef PRJCT_OOP_ORAS_H
#define PRJCT_OOP_ORAS_H

#include <string>
#include <iostream>
#include "entitate.h"

class Oras {
    std::string nume_oras;
    int population;

public:
    Oras(const std::string& nume_oras_, int population_);
    Oras(const Oras& other);
    ~Oras();
    friend std::ostream& operator<<(std::ostream& os, const Oras& oras);
    [[nodiscard]] const std::string& getNume() const;
    //[[nodiscard]] int getPopulation() const;
};

#endif //PRJCT_OOP_ORAS_H