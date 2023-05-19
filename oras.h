//
// Created by Andreea on 16-May-23.
//

#ifndef PRJCT_OOP_ORAS_H
#define PRJCT_OOP_ORAS_H

#include <string>
#include <iostream>
#include "entitate.h"

class Oras : public Entitate {
    int population;

public:
    Oras(const std::string& name_, int population_);
    Oras(const Oras& other);
    ~Oras() override;

    friend std::ostream& operator<<(std::ostream& os, const Oras& oras);

    [[nodiscard]] int getPopulation() const;
};

#endif //PRJCT_OOP_ORAS_H
