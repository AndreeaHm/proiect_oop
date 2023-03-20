#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

//std::srand(time(NULL));

class Tara{
    std::string nume;
    std::string capitala;
public:
    Tara(const std::string& nume_, const std::string& capitala_): nume(nume_), capitala(capitala_){}
    Tara(const Tara& other): nume(other.nume), capitala(other.capitala) {
        //std::cout <<"constr de copiere\n";
    }
    Tara& operator=(const Tara& other) {
        //std::cout <<"op = tara\n";
        nume = other.nume;
        capitala = other.capitala;
        return *this;
    }

    ~Tara() {
        //std::cout<<"destr\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Tara &tara) {
        os << "nume: " << tara.nume << " capitala: " << tara.capitala;
        return os;
    }

    const std::string &getNume() const {
        return nume;
    }

    const std::string &getCapitala() const {
        return capitala;
    }
};

class Jucator{
    std::string nume;
    int scor;
    int nr_runde;
public:
    Jucator(const std::string& nume_, const int scor_, const int nr_runde_ = 0): nume(nume_), scor(scor_), nr_runde(nr_runde_){}
    Jucator(const Jucator& other): nume(other.nume), scor(other.scor), nr_runde(other.nr_runde) {}
    ~Jucator() {}

    friend std::ostream &operator<<(std::ostream &os, const Jucator &jucator) {
        os << "nume: " << jucator.nume << " scor: " << jucator.scor << " nr_runde: " << jucator.nr_runde;
        return os;
    }

    const std::string &getNume() const {
        return nume;
    }

    int getScor() const {
        return scor;
    }

    void crestere_scor () {
        scor = scor + 10;
    }


    int getNrRunde() const {
        return nr_runde;
    }
};

class Joc {
    std::vector<Tara> tarajuc;
    std::vector<Jucator> j;

public:
    Joc() = default;

    Joc(const std::vector<Tara> &tarajuc_, const std::vector<Jucator> &j_) :
            tarajuc(tarajuc_), j(j_) {}

    Joc(const Joc &other) :
            tarajuc(other.tarajuc), j(other.j) {}

    Joc(Joc &&other) noexcept:
            tarajuc(std::move(other.tarajuc)), j(std::move(other.j)) {}

    Joc &operator=(const Joc &other) {
        if (this != &other) {
            tarajuc = other.tarajuc;
            j = other.j;
        }
        return *this;
    }

    Joc &operator=(Joc &&other) noexcept {
        if (this != &other) {
            tarajuc = std::move(other.tarajuc);
            j = std::move(other.j);
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Joc &joc) {
        os << "tarijuc: " << std::endl;
        for (const auto &tr: joc.tarajuc) {
            os << tr << std::endl;
        }
        os << "juc:" << std::endl;
        for (const auto &juc: joc.j) {
            os << juc << std::endl;
        }
        return os;
    }

    void adauga_jucator(const Jucator &jucator) {
        j.push_back(jucator);
    }

    void joaca(Joc &joc) {
        for(auto &juc : joc.j){
            std::string nume = juc.getNume();
            std::cout << "Jucatorul " << nume << std::endl;
            int nrr = juc.getNrRunde();
            for(int i=1; i<=nrr; i++) {
                int random_index = std::rand() % joc.tarajuc.size();
                std::string tara = joc.tarajuc[random_index].getNume();
                std::string capitala = joc.tarajuc[random_index].getCapitala();
                std::cout << "Tara este: " << tara << std::endl;
                std::cout << "Capitala este: ";
                std::string raspuns;
                std::cin >> raspuns;
                if (raspuns == capitala) {
                    std::cout << "Felicitari, " << nume << "! Ai ghicit capitala tarii " << tara << "." << std::endl;
                    juc.crestere_scor();}
                else {
                    std::cout << "Imi pare rau, " << nume << ", dar capitala tarii " << tara << " este " << capitala
                              << "."
                              << std::endl;
                }
                std::cout << std::endl;
            }
            int scor = juc.getScor();
            std::cout<< "Scorul lui " << nume << " este " << scor << std::endl;
        }
    }
};

int main(){
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


    return 0;
}
