#include <vector>
#include <string>
#include <fstream>
#include "joc.h"
#include "jucator.h"
#include "tara.h"
#include "oras.h"
#include "continent.h"
#include <random>


int main() {
    std::ifstream fin("tastatura.txt");
    std::ifstream f("europa.in");
    std::random_device rd;
    [[maybe_unused]] std::mt19937 g(rd());
    Jucator p1("Ion", 3, 2, 1);
    Jucator p2("Ana", 4, 2, 1);
    Jucator p3("Florica", 3, 1, 1);

    std::vector<Tara*> tari;
    std::vector<Jucator> jucatori;
    std::vector<std::string> raspunsurile;
    std::vector<Continent> continentele;

    auto europa = Continent("Europa", tari);
    //creezi un vector de pointeri cu clone
    //pe care sa il pasezi ca atribut cand apelezi constructorul din continent
    Tara* taraPtr;

    for (int i = 1; i <= 37; i++) {
        std::string nume_maree;
        std::string nume_taraa;
        std::string nume_capitala;
        std::string oras;
        int oraspop;
        int tip_tara;
        std::string rasp;
        std::vector<Oras> orase;
        f >> tip_tara;
        if(tip_tara == 2)
            f >>nume_maree;
        f >>nume_taraa >> nume_capitala;
        for (int v = 1; v <= 3; v++) {
            f >> oras >> oraspop;
            auto o = Oras(oras, oraspop);
            orase.push_back(o);
        }
        fin >> rasp;
        //in vectorul europa se adauga tara a pointer de tip tara catre clasa derivata, cu ajutorul functiei clone
        if (tip_tara == 1) {
            taraPtr = new Tara_locked{ nume_taraa, nume_capitala, orase };
        } else {
            taraPtr = new Tara_apa{ nume_taraa, nume_capitala, orase, nume_maree };
        }

        europa.adaugaTara(taraPtr->clone());




        raspunsurile.push_back(rasp);
    }

    Joc j1(jucatori, raspunsurile, continentele);
    j1.adauga_jucator(p3);
    j1.adauga_jucator(p1);
    j1.adaugaContinent(europa);

    Joc::joaca(j1);

    delete taraPtr;

    fin.close();
    f.close();

    return 0;
}