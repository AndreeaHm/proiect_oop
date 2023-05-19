//
// Created by Andreea on 13-May-23.
//

#ifndef PRJCT_OOP_ENTITATE_H
#define PRJCT_OOP_ENTITATE_H

#include <string>

class Entitate {
protected:
    std::string nume;

public:
    explicit Entitate(std::string  nume_);
    Entitate(const Entitate& other);
    virtual ~Entitate();

    [[nodiscard]] const std::string& getNume() const;
};

#endif //PRJCT_OOP_ENTITATE_H
