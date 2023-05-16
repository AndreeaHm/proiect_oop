//
// Created by Andreea on 13-May-23.
//

#include "joc.h"
#include <random>
#include <algorithm>
#include <iostream>

Joc::Joc() = default;

Joc::Joc(const std::vector<Jucator>& juc_, const std::vector<std::string>& raspunsuri_, const std::vector<Continent*>& continente_)
        : juc(juc_), raspunsuri(raspunsuri_), continente(continente_) {}

Joc::Joc(const Joc& other)
        : juc(other.juc), raspunsuri(other.raspunsuri), continente(other.continente) {}

Joc::Joc(Joc&& other) noexcept
        : juc(std::move(other.juc)), raspunsuri(std::move(other.raspunsuri)), continente(std::move(other.continente)) {}

Joc& Joc::operator=(const Joc& other) {
    if (this != &other) {
        juc = other.juc;
        raspunsuri = other.raspunsuri;
        continente = other.continente;
    }
    return *this;
}

Joc& Joc::operator=(Joc&& other) noexcept {
    juc = std::move(other.juc);
    raspunsuri = std::move(other.raspunsuri);
    continente = std::move(other.continente);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Joc& joc) {
    os << "Jucatori: ";
    for (const auto& jucator : joc.juc) {
        os << jucator.getNume() << ", ";
    }
    os << std::endl;
    os << "Continente: ";
    for (const auto& cont : joc.continente) {
        os << cont->getNumecont() << ", ";
    }
    os << std::endl;
    return os;
}

void Joc::adauga_jucator(const Jucator &jucator) {
    juc.push_back(jucator);
}

void Joc::adaugaContinent(const Continent& continentu) {
    continente.push_back(new Continent(continentu));
}

void Joc::joaca(Joc &joc) {
    std::random_device rd;
    std::mt19937 g(rd());

    for (auto& juctr : joc.juc) {
        int nivelul_de_dific = juctr.getNivelDific();
        Continent* cont_jucat = joc.continente[nivelul_de_dific-1];
        std::vector<Tara*> tarajuc = cont_jucat->getTari();
        int random_nr[50];
        for(unsigned long k=1; k<=tarajuc.size(); k++){
            random_nr[k] = 0;}
        for(unsigned long k=1; k<=tarajuc.size(); k++){
            random_nr[k] = k;}
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(random_nr + 1, random_nr + tarajuc.size(), g);
        int random_rsp[50];
        for(unsigned long k=1; k<=raspunsuri.size(); k++)
            random_rsp[k] = 0;
        for(unsigned long k=1; k<=raspunsuri.size(); k++)
            random_rsp[k] = k;
        std::shuffle(&random_rsp[1],&random_rsp[raspunsuri.size()], g);

        std::string nume = juctr.getNume();
        std::cout << "Jucatorul " << nume << std::endl;

        int nrr = juctr.getNrRunde();
        for (int i = 0; i < nrr; i++) {

            int random_index = random_nr[i];
            int random_r = random_rsp[i];

            std::string tara = tarajuc[random_index]->getNume();
            std::string capitala = tarajuc[random_index]->getCapitala();


            std::cout << "Tara este: " << tara << std::endl;
            std::cout << "Capitala este: ";

            std::string raspuns = joc.raspunsuri[random_r];
            std::cout << raspuns << std::endl;

            if (raspuns == capitala) {
                std::cout << "Felicitari, " << nume << "! Ai ghicit capitala tarii " << tara << "." << std::endl;
                juctr.crestere_scor(10);
            } else {
                std::cout << "Imi pare rau, " << nume << ", dar capitala tarii " << tara << " este " << capitala << "." << std::endl;
                juctr.crestere_scor(-10);
            }

            std::cout << std::endl;
        }

        int scor = juctr.getScor();
        std::cout << "Scorul lui " << nume << " este " << scor << std::endl;
    }
}

Joc::~Joc() {}
