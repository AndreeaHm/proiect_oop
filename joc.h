//
// Created by Andreea on 13-May-23.
//

#ifndef PRJCT_OOP_JOC_H
#define PRJCT_OOP_JOC_H

#pragma once

#include <vector>
#include <string>
#include <random>
#include "tara.h"
#include "jucator.h"
#include "continent.h"
#include "gamesub.h"
#include "oras.h"

class Joc {
    std::vector<Jucator> juc;
    std::vector<std::string> raspunsuri;
    std::vector<Continent> continente;
    static GameSubject* gameSubject;

public:
    Joc();

    Joc(const std::vector<std::string> &raspunsuri_, const std::vector<Continent> &continente_);

    [[maybe_unused]] Joc(const Joc &other);

    [[maybe_unused]] Joc(Joc &&other) noexcept;

    Joc &operator=(const Joc &other);

    Joc &operator=(Joc &&other) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Joc &joc);

    void adauga_jucator(const Jucator &jucator);

    void adaugaContinent(const Continent& continentu);

    static void setGameSubject(GameSubject* subject);

    static std::string bonus(Continent& continent);

    static void joaca(Joc &joc);

    ~Joc();
};

#endif //PRJCT_OOP_JOC_H