#ifndef PRJCT_OOP_CONTINENT_H
#define PRJCT_OOP_CONTINENT_H

#include <string>
#include <vector>
#include <memory>
#include "tara.h"

class Continent {
    std::string nume;
    std::vector<std::unique_ptr<Tara>> tari;

public:
    Continent(const std::string& nume_, std::vector<std::unique_ptr<Tara>> tari_);

    ~Continent();

    void adaugaTara(std::unique_ptr<Tara> tara);

    [[nodiscard]] const std::string& getNumecont() const;
    [[nodiscard]] const std::vector<std::unique_ptr<Tara>>& getTari() const;
};

#endif //PRJCT_OOP_CONTINENT_H