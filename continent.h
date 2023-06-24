#ifndef PRJCT_OOP_CONTINENT_H
#define PRJCT_OOP_CONTINENT_H

#include <string>
#include <vector>
#include "entitate.h"
#include "tara.h"

class Continent : public Entitate {
    std::vector<Tara*> tari;

public:
    Continent(const std::string& nume_, const std::vector<Tara*>& tari_);

    ~Continent() override;

    void adaugaTara(Tara* tara);

    [[nodiscard]] const std::string& getNumecont() const;
    [[nodiscard]] const std::vector<Tara*>& getTari() const;

};

#endif // PRJCT_OOP_CONTINENT_H