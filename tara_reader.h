#ifndef TARA_READER_H
#define TARA_READER_H

#include <fstream>
#include <string>
#include <vector>
#include "continent.h"
#include "tara.h"

class TaraReader {
protected:
    virtual std::string citesteNumeTara(std::ifstream& fisier) = 0;
    virtual std::string citesteNumeCapitala(std::ifstream& fisier) = 0;

public:
    virtual ~TaraReader() = default;

    void citesteTara(std::ifstream& fisier, Continent& europa);

    virtual Tara* creazaTara(const std::string& nume_taraa, const std::string& nume_capitala, const std::vector<Oras>& orase, std::ifstream& fisier) = 0;
    virtual std::vector<Oras> citesteOrase(std::ifstream& fisier) = 0;
};

class TaraLockedReader : public TaraReader {
protected:
    std::string citesteNumeTara(std::ifstream& fisier) override;
    std::string citesteNumeCapitala(std::ifstream& fisier) override;

    Tara* creazaTara(const std::string& nume_taraa, const std::string& nume_capitala, const std::vector<Oras>& orase, std::ifstream& fisier) override;
    std::vector<Oras> citesteOrase(std::ifstream& fisier) override;
};

class TaraApaReader : public TaraReader {
protected:
    std::string citesteNumeTara(std::ifstream& fisier) override;
    std::string citesteNumeCapitala(std::ifstream& fisier) override;

    Tara* creazaTara(const std::string& nume_taraa, const std::string& nume_capitala, const std::vector<Oras>& orase, std::ifstream& fisier) override;
    std::vector<Oras> citesteOrase(std::ifstream& fisier) override;
};

#endif  // TARA_READER_H
