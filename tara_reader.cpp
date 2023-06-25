#include "tara_reader.h"

void TaraReader::citesteTara(std::ifstream& fisier, Continent& cont) {
    std::string nume_taraa = citesteNumeTara(fisier);
    std::string nume_capitala = citesteNumeCapitala(fisier);
    std::vector<Oras> orase = citesteOrase(fisier);
    Tara* taraPtr = creazaTara(nume_taraa, nume_capitala, orase, fisier);
    cont.adaugaTara(taraPtr->clone());
}

std::string TaraLockedReader::citesteNumeTara(std::ifstream& fisier) {
    std::string nume_taraa;
    fisier >> nume_taraa;
    return nume_taraa;
}

std::string TaraLockedReader::citesteNumeCapitala(std::ifstream& fisier) {
    std::string nume_capitala;
    fisier >> nume_capitala;
    return nume_capitala;
}

Tara* TaraLockedReader::creazaTara(const std::string& nume_taraa, const std::string& nume_capitala, const std::vector<Oras>& orase, std::ifstream& fisier) {
    std::string nada;
    fisier >> nada;
    return new Tara_locked(nume_taraa, nume_capitala, orase);
}

std::vector<Oras> TaraLockedReader::citesteOrase(std::ifstream& fisier) {
    std::vector<Oras> orase;
    for (int i = 0; i < 3; i++) {
        std::string nume_oras;
        int populatie;
        fisier >> nume_oras >> populatie;
        Oras oras(nume_oras, populatie);
        orase.push_back(oras);
    }
    return orase;
}

std::string TaraApaReader::citesteNumeTara(std::ifstream& fisier) {
    std::string nume_taraa;
    fisier >> nume_taraa;
    return nume_taraa;
}

std::string TaraApaReader::citesteNumeCapitala(std::ifstream& fisier) {
    std::string nume_capitala;
    fisier >> nume_capitala;
    return nume_capitala;
}

Tara* TaraApaReader::creazaTara(const std::string& nume_taraa, const std::string& nume_capitala, const std::vector<Oras>& orase, std::ifstream& fisier) {
    std::string nume_mar;
    fisier >> nume_mar;
    return new Tara_apa(nume_taraa, nume_capitala, orase, nume_mar);
}

std::vector<Oras> TaraApaReader::citesteOrase(std::ifstream& fisier) {
    std::vector<Oras> orase;
    for (int i = 0; i < 3; i++) {
        std::string nume_oras;
        int populatie;
        fisier >> nume_oras >> populatie;
        Oras oras(nume_oras, populatie);
        orase.push_back(oras);
    }
    return orase;
}
