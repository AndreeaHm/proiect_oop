#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <algorithm>
#include "joc.h"


int main() {
    std::ifstream fin("tastatura.txt");
    std::ifstream f("europa.in");
    std::srand(time(nullptr));

    Jucator p1("Ion", 3, 2, 1);
    Jucator p2("Ana", 4, 2, 1);
    Jucator p3("Florica", 3, 1, 1);

    std::vector<Tara*> tari;
    std::vector<Jucator> jucatori;
    std::vector<std::string> raspunsurile;
    std::vector<Continent*> continentele;

    Continent *europa;
    europa = new Continent("Europa", tari);

    for (int i = 1; i <= 37; i++) {
        std::string nume_taraa;
        std::string nume_capitala;
        std::string oras;
        int oraspop;
        int tip_tara;
        std::string rasp;
        std::vector<Oras> orase;
        f >> tip_tara >> nume_taraa >> nume_capitala;
        for (int v = 1; v <= 3; v++) {
            f >> oras >> oraspop;
            auto o = new Oras(oras, oraspop);
            orase.push_back(*o);
        }
        fin >> rasp;
        if(tip_tara == 1)
            europa->adaugaTara(Tara_locked{nume_taraa,nume_capitala,orase}.clone());
        else
            europa->adaugaTara(Tara_apa{nume_taraa,nume_capitala,orase}.clone());
        raspunsurile.push_back(rasp);
    }

    Joc j1(jucatori, raspunsurile, continentele);
    j1.adauga_jucator(p3);
    j1.adauga_jucator(p1);
    j1.adaugaContinent(*europa);

    Joc::joaca(j1);

    fin.close();
    f.close();

    delete europa;

    return 0;
}