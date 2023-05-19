#ifndef PRJCT_OOP_TARA_H
#define PRJCT_OOP_TARA_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "entitate.h"
#include "oras.h"

class Tara : public Entitate {
    std::string capitala;
    std::vector<std::shared_ptr<Oras>> orase;

public:
    Tara(const std::string& numetara_, const std::string& capitalatara_, const std::vector<std::shared_ptr<Oras>> orase_);
    Tara(const Tara& other);
    Tara& operator=(Tara other);
    ~Tara();

    friend std::ostream& operator<<(std::ostream& os, const Tara& tara);

    const std::string& getCapitala() const;

    const std::vector<std::shared_ptr<Oras>>& getOrase() const;

    void adaugaOras(const std::shared_ptr<Oras>& oras);

    Tara* clone() const;

    void swap(Tara& other);
};

#endif // PRJCT_OOP_TARA_H
