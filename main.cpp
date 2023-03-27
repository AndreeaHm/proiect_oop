#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <algorithm>

std::ifstream fin("tastatura.txt");

class Tara{
    std::string numetara;
    std::string capitalatara;
public:
    Tara(const std::string& numetara_, const std::string& capitalatara_): numetara(numetara_), capitalatara(capitalatara_){}
    Tara(const Tara& other): numetara(other.numetara), capitalatara(other.capitalatara) {
        //std::cout <<"constr de copiere\n";
    }
    Tara& operator=(const Tara& other) {
        //std::cout <<"op = tara\n";
        numetara = other.numetara;
        capitalatara = other.capitalatara;
        return *this;
    }

    ~Tara() {
        //std::cout<<"destr\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Tara &tara) {
        os << "nume: " << tara.numetara << " capitala: " << tara.capitalatara;
        return os;
    }

    const std::string &getNume() const {
        return numetara;
    }

    const std::string &getCapitala() const {
        return capitalatara;
    }
};

class Jucator{
    std::string numejuc;
    int scorjuc;
    int nr_rundejuc;
public:
    Jucator(const std::string& numejuc_, const int scorjuc_, const int nr_rundejuc_ = 0): numejuc(numejuc_), scorjuc(scorjuc_), nr_rundejuc(nr_rundejuc_){}
    Jucator(const Jucator& other): numejuc(other.numejuc), scorjuc(other.scorjuc), nr_rundejuc(other.nr_rundejuc) {}
    ~Jucator() {}

    friend std::ostream &operator<<(std::ostream &os, const Jucator &jucator) {
        os << "nume: " << jucator.numejuc << " scor: " << jucator.scorjuc << " nr_runde: " << jucator.nr_rundejuc;
        return os;
    }

    const std::string &getNume() const {
        return numejuc;
    }

    int getScor() const {
        return scorjuc;
    }

    void crestere_scor (int pnct) {
        scorjuc = scorjuc + pnct;
    }


    int getNrRunde() const {
        return nr_rundejuc;
    }
};

class Joc {
    std::vector<Tara> tarajuc;
    std::vector<Jucator> juc;

public:
    Joc() = default;

    Joc(const std::vector<Tara> &tarajuc_, const std::vector<Jucator> &juc_) :
            tarajuc(tarajuc_), juc(juc_) {}

    Joc(const Joc &other) :
            tarajuc(other.tarajuc), juc(other.juc) {}

    Joc(Joc &&other) noexcept:
            tarajuc(std::move(other.tarajuc)), juc(std::move(other.juc)) {}

    Joc &operator=(const Joc &other) {
        if (this != &other) {
            tarajuc = other.tarajuc;
            juc = other.juc;
        }
        return *this;
    }

    Joc &operator=(Joc &&other) noexcept {
        if (this != &other) {
            tarajuc = std::move(other.tarajuc);
            juc = std::move(other.juc);
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Joc &joc) {
        os << "tarijuc: " << std::endl;
        for (const auto &tr: joc.tarajuc) {
            os << tr << std::endl;
        }
        os << "juc:" << std::endl;
        for (const auto &juctr: joc.juc) {
            os << juctr << std::endl;
        }
        return os;
    }

    void adauga_jucator(const Jucator &jucator) {
        juc.push_back(jucator);
    }

    void joaca(Joc &joc) {
        for(auto juctr : joc.juc){
            int random_nr[20];
            for(int k=1; k<=tarajuc.size(); k++)
                random_nr[k] = 0;
            for(int k=1; k<=tarajuc.size(); k++)
                random_nr[k] = k;
            std::random_shuffle(&random_nr[1],&random_nr[tarajuc.size()]);
            std::string nume = juctr.getNume();
            std::cout << "Jucatorul " << nume << std::endl;
            int nrr = juctr.getNrRunde();
            for(int i=1; i<=nrr; i++) {
                int random_index = random_nr[i];
                std::string tara = joc.tarajuc[random_index].getNume();
                std::string capitala = joc.tarajuc[random_index].getCapitala();
                std::cout << "Tara este: " << tara << std::endl;
                std::cout << "Capitala este: ";
                std::string raspuns;
                fin >> raspuns;
                std::cout << raspuns << std::endl;
                if (raspuns == capitala) {
                    std::cout << "Felicitari, " << nume << "! Ai ghicit capitala tarii " << tara << "." << std::endl;
                    juctr.crestere_scor(10);}
                else {
                    std::cout << "Imi pare rau, " << nume << ", dar capitala tarii " << tara << " este " << capitala
                              << "."
                              << std::endl;
                    juctr.crestere_scor(-10);
                }
                std::cout << std::endl;
            }
            int scor = juctr.getScor();
            std::cout<< "Scorul lui " << nume << " este " << scor << std::endl;
        }
    }
};



int main(){
    std::srand(time(nullptr));


    Jucator p1("Ion", 0, 2);
    Jucator p2("Ana", 0,4);
    Jucator p3("Florica", 0,3);

    Tara t1("Spania", "Madrid");
    Tara t2("Slovacia", "Bratislava");
    Tara t3("Danemarca", "Copenhaga");
    Tara t4("Grecia", "Atena");
    Tara t5("Olanda", "Amsterdam");
    Tara t6("Finlanda", "Helsinki");
    Tara t7("Serbia", "Belgrad");
    Tara t8("Islanda", "Reykjavik");
    Tara t9("Liechtenstein", "Vaduz");
    Tara t10("Belarus", "Minsk");

    std::vector<Tara> tari;
    std::vector<Jucator> jucatori;

    tari.push_back(t7);
    tari.push_back(t3);
    tari.push_back(t10);
    tari.push_back(t8);
    tari.push_back(t4);


    Joc j1(tari, jucatori);
    j1.adauga_jucator(p3);
    j1.adauga_jucator(p1);

    j1.joaca(j1);

    fin.close();

    return 0;
}
