//
// Created by Andreea on 13-May-23.
//

#ifndef PRJCT_OOP_TARA_H
#define PRJCT_OOP_TARA_H

#include <string>
#include <iostream>
#include "entitate.h"

class Tara : public Entitate {
    std::string capitala;

public:
    Tara(const std::string& numetara_, const std::string& capitalatara_);
    Tara(const Tara& other);
    ~Tara();

    friend std::ostream &operator<<(std::ostream &os, const Tara &tara);

    const std::string &getCapitala() const;
};

#endif //PRJCT_OOP_TARA_H
