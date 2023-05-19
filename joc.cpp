//
// Created by Andreea on 13-May-23.
//

#include "joc.h"
#include "exceptii.h"
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

void Joc::joaca(Joc& joc) {
    try {
        std::random_device rd;
        std::mt19937 g(rd());

        for (auto& juctr : joc.juc) {
            int nivelul_de_dific = juctr.getNivelDific();
            Continent* cont_jucat = joc.continente.at(nivelul_de_dific - 1);
            std::vector<Tara*> tarajuc = cont_jucat->getTari();
            if (tarajuc.empty()) {
                throw exceptie1("Lista de tari este goala!");
            }
            for (int i = tarajuc.size() - 1; i > 0; --i) {
                std::uniform_int_distribution<int> dist(0, i);
                int j = dist(g);
                if (i != j) {
                    std::swap(tarajuc[i], tarajuc[j]);
                }
            }
            int random_rsp[50];
            for (unsigned long k = 0; k < joc.raspunsuri.size(); k++) {
                random_rsp[k] = k;
            }
            std::shuffle(&random_rsp[1], &random_rsp[joc.raspunsuri.size()], g);

            std::string nume = juctr.getNume();
            std::cout << "Jucatorul " << nume << std::endl;
            int jocul_ales = juctr.getNrJoc();
            int nrr = juctr.getNrRunde();
            if (jocul_ales == 1) {
                for (int i = 0; i < nrr; i++) {
                    int random_index = i;
                    int random_r = random_rsp[i];

                    if (random_index >= tarajuc.size()) {
                        throw exceptie2("Indexul aleator depaseste dimensiunea listei de tari!");
                    }

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
                        std::cout << "Imi pare rau, " << nume << ", dar capitala tarii " << tara << " este " << capitala
                                  << "." << std::endl;
                    }

                    std::cout << std::endl;
                }
            } else if (jocul_ales == 2) {
                for (int i = 0; i < nrr; i++) {
                    if (i >= tarajuc.size()) {
                        break;
                    }
                    int random_index = i;
                    Tara* tara_curenta = tarajuc[random_index]->clone();
                    std::string nume_tara_curenta = tara_curenta->getNume();
                    const std::vector<std::shared_ptr<Oras>>& orase_curente = tara_curenta->getOrase();
                    std::cout << "Orasele: ";
                    for (const auto& oras : orase_curente) {
                        std::cout << oras->getNume() << " ";
                    }
                    std::cout << "apartin carei tari?" << std::endl;
                    std::cout << "Raspuns: ";
                    std::string raspuns;
                    std::cin >> raspuns;
                    if (raspuns == nume_tara_curenta) {
                        std::cout << "Felicitari, " << nume << "! Ai nimerit tara " << nume_tara_curenta << "." << std::endl;
                        juctr.crestere_scor(10);
                    } else {
                        std::cout << "Imi pare rau, " << nume << ", dar tara corecta este " << nume_tara_curenta << "." << std::endl;
                    }
                    std::cout << std::endl;
                }
            }
            int scor = juctr.getScor();
            std::cout << "Scorul lui " << nume << " este " << scor << std::endl;
        }
    } catch (const exceptie1& e) {
        std::cout << "Eroare exceptie1: " << e.what() << std::endl;
    } catch (const exceptie2& e) {
        std::cout << "Eroare exceptie2: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << std::endl;
    }
}

Joc::~Joc() {}
