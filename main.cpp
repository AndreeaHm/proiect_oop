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

    if (!fin) {
        std::cerr << "Eroare la deschiderea fisierului tastatura.txt\n";
        return 1;
    }

    if (!f) {
        std::cerr << "Eroare la deschiderea fisierului europa.in\n";
        return 1;
    }

    std::vector<Tara*> tari;
    std::vector<Jucator> jucatori;
    std::vector<std::string> raspunsurile;
    std::vector<Continent*> continentele;

    Continent *europa;
    europa = new Continent("Europa", tari);

    for (int i = 1; i <= 37; i++) {
        std::string nume_tara;
        std::string nume_capitala;
        std::string oras;
        int oraspop;
        std::string rasp;
        f >> nume_tara >> nume_capitala;
        auto t = new Tara(nume_tara, nume_capitala, std::vector<Oras*>{});
        for (int v = 1; v <= 3; v++) {
            f >> oras >> oraspop;
            auto o = new Oras(oras, oraspop);
            t->adaugaOras(o);
        }
        fin >> rasp;
        europa->adaugaTara(t);
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