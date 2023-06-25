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
    Tara(std::string nume_tara_, std::string capitalatara_, const std::vector<Oras>& orase_);

    [[maybe_unused]] Tara(const Tara& other);

    Tara();

    Tara& operator=(const Tara& other);
    virtual ~Tara();
    friend std::ostream& operator<<(std::ostream& os, const Tara& tara);

    [[nodiscard]] const std::string& getNume() const;

    [[nodiscard]] const std::string& getCapitala() const;

    [[nodiscard]] const std::vector<Oras>& getOrase() const;

    [[nodiscard]] virtual Tara* clone() const = 0;

    [[maybe_unused]] [[maybe_unused]] void swap(Tara& other);
    virtual void afisare() = 0;
    [[nodiscard]] virtual bool isLocked() const = 0;
    [[nodiscard]] virtual bool hasAccesstoSea() const = 0;
};

class Tara_locked : public Tara {
public:
    Tara_locked(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_);

    void afisare() override;

    [[nodiscard]] bool isLocked() const override;

    [[nodiscard]] bool hasAccesstoSea() const override;

    [[nodiscard]] Tara_locked* clone() const override;

    ~Tara_locked() override = default;
};

class Tara_apa : public Tara {
    std::string nume_mare;
public:
    Tara_apa(const std::string& nt, const std::string& nc, const std::vector<Oras>& orase_, const std::string& nume_mare_);

    void afisare() override;

    [[nodiscard]] Tara_apa* clone() const override;

    [[nodiscard]] bool isLocked() const override;

    [[nodiscard]] bool hasAccesstoSea() const override;

    [[nodiscard]] const std::string& getNumeMare() const;

    ~Tara_apa() override = default;
};

#endif // PRJCT_OOP_TARA_H