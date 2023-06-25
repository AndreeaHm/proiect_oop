#include <vector>
#include <string>
#include "joc.h"
#include "jucator.h"
#include "tara.h"
#include "continent.h"
#include "tara_reader.h"
#include "gamesub.h"

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

    for (int i = 1; i <= 37; i++) {
        TaraReader* taraReader;
        int tip_tara;
        f >> tip_tara;

        if (tip_tara == 1) {
            taraReader = new TaraLockedReader();
        } else {
            taraReader = new TaraApaReader();
        }

        taraReader->citesteTara(f, europa);
        delete taraReader;

        std::string rasp;
        fin >> rasp;
        raspunsurile.push_back(rasp);
    }

    Joc j1(raspunsurile, continentele);

    j1.adauga_jucator(p1);
    j1.adauga_jucator(p3);
    j1.adaugaContinent(europa);

    GameSubject gameSubject;

    gameSubject.addObserver(&p1);
    gameSubject.addObserver(&p3);

    Joc::setGameSubject(&gameSubject);

    Joc::joaca(j1);

    fin.close();
    f.close();

    return 0;
}