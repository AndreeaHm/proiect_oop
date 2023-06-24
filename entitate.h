#ifndef PRJCT_OOP_ENTITATE_H
#define PRJCT_OOP_ENTITATE_H

#include <string>

class Entitate {
protected:
    std::string nume;

public:
    explicit Entitate(std::string  nume_);
    virtual ~Entitate();

    [[maybe_unused]] virtual void afisare() const;

    [[nodiscard]] const std::string& getNume() const;
};

#endif //PRJCT_OOP_ENTITATE_H