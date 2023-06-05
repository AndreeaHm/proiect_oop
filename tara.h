#ifndef PRJCT_OOP_TARA_H
#define PRJCT_OOP_TARA_H

#include <string>
#include <iostream>
#include <vector>
#include "entitate.h"
#include "oras.h"

class Tara {
protected:
    std::string nume_tara;
    std::string capitala;
    std::vector<Oras> orase;

public:
    Tara(std::string  nume_tara_, std::string  capitalatara_, const std::vector<Oras>& orase_);
    Tara(const Tara& other);

    Tara();

    Tara& operator = (const Tara& other);
    virtual ~Tara();
    friend std::ostream& operator<<(std::ostream& os, const Tara& tara);

    [[nodiscard]] const std::string& getNume() const;

    [[nodiscard]] const std::string& getCapitala() const;

    [[nodiscard]] const std::vector<Oras>& getOrase() const;

    [[nodiscard]] virtual Tara* clone() const = 0;

    void swap(Tara& other);
    virtual void afisare() = 0;
};

class Tara_locked: public Tara{
public:
    Tara_locked(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_);

    void afisare() override;

    [[nodiscard]] Tara_locked* clone() const override;
};

class Tara_apa: public Tara{
public:
    Tara_apa(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_);

    void afisare() override;

    [[nodiscard]] Tara_apa* clone() const override;
};

#endif // PRJCT_OOP_TARA_H