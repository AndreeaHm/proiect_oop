#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "joc.h"
#include "tara.h"
#include "continent.h"
#include "jucator.h"


std::ifstream fin("tastatura.txt");
std::ifstream f("europa.in");

int main(){
    std::srand(time(nullptr));

    Jucator p1("Ion", 0, 2,1);
    Jucator p2("Ana", 0,4,1 );
    Jucator p3("Florica", 0,3,1 );

    std::vector<Tara*> tari;
    std::vector<Jucator> jucatori;
    std::vector<std::string> raspunsurile;
    std::vector<Continent *> continentele;

    Continent* europa = new Continent("Europa", {tari},1);

    for(int i=1; i<=44; i++){
        std::string sir1;
        std::string sir2;
        std::string rasp;
        f >> sir1 >> sir2;
        fin >> rasp;
        Tara *t;
        t = new Tara(sir1, sir2);
        europa->adaugaTara(t);
        raspunsurile.push_back(rasp);
    }

    Joc j1(jucatori,raspunsurile, continentele);
    j1.adauga_jucator(p3);
    j1.adauga_jucator(p1);
    j1.adaugaContinent(*europa);

    j1.joaca(j1);

    fin.close();
    f.close();

    return 0;
}
