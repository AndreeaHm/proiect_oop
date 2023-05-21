#ifndef PRJCT_OOP_TARA_H
#define PRJCT_OOP_TARA_H

#include <string>
#include <iostream>
#include <vector>
#include "entitate.h"
#include "oras.h"

class Tara : public Entitate {
    std::string capitala;
    std::vector<Oras*> orase;

public:
    Tara(const std::string& numetara_, const std::string& capitalatara_, const std::vector<Oras*>& orase_);
    Tara(const Tara& other);
    Tara& operator=(Tara other);
    ~Tara() override;

    void afisare() const override;

    [[nodiscard]] const std::string& getCapitala() const;

    [[nodiscard]] const std::vector<Oras*>& getOrase() const;

    void adaugaOras(Oras* oras);

    [[nodiscard]] Tara* clone() const;

    void swap(Tara& other);
};

#endif // PRJCT_OOP_TARA_H