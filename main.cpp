#include <iostream>
#include <random>
#include <string>

class generaretablou{

public:
    int v[4][6];
    int get2(int i, int j)
    {
        return v[i][j];
    }
    void generare()
    {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 9);
        v[1][1] = dis(gen);
        v[2][1] = dis(gen);
        v[3][1] = dis(gen);
        for(int i = 1; i <= 3; i ++)
        {
            for(int j = 2; j <= 5; j ++)
            {
                int h = dis(gen);
                if(h <= 2)
                {
                    v[i][j] = v[i][j - 1];
                    if(v[i][j] == 10 && j == 5)
                        v[i][j] = dis(gen);
                }
                else {
                    v[i][j] = dis(gen);
                    if(v[i][j] == 10)
                    {
                        std::bernoulli_distribution bd(0.01);
                        if(bd(gen))
                            v[i][j] = dis(gen);
                    }
                }
            }
        }
        for(int i = 1; i <= 3; i ++)
        {
            for(int j = 1; j <= 5; j ++) {
                if (v[i][j] == 10)
                    v[1][j] = 10, v[2][j] = 10, v[3][j] = 10;
            }
        }
    }
};
class linii{
private:
    std::pair <int, int> p[11][6];
public:
    std::pair<int, int> getnext(int a, int b)
    {
        return p[a][b];
    }
    void generarelinii()
    {
        for(int i = 1; i <= 3; i ++)
            for(int j = 1; j <= 5; j ++)
                p[i][j] = std::make_pair(i, j);
        p[4][1] = std::make_pair(1, 1);
        p[4][2] = std::make_pair(2, 2);
        p[4][3] = std::make_pair(3, 3);
        p[4][4] = std::make_pair(2, 4);
        p[4][5] = std::make_pair(1, 5);

        p[5][1] = std::make_pair(3, 1);
        p[5][2] = std::make_pair(2, 2);
        p[5][3] = std::make_pair(1, 3);
        p[5][4] = std::make_pair(2, 4);
        p[5][5] = std::make_pair(3, 5);

        p[6][1] = std::make_pair(1, 1);
        p[6][2] = std::make_pair(1, 2);
        p[6][3] = std::make_pair(2, 3);
        p[6][4] = std::make_pair(3, 4);
        p[6][5] = std::make_pair(4, 5);

        p[7][1] = std::make_pair(3, 1);
        p[7][2] = std::make_pair(3, 2);
        p[7][3] = std::make_pair(2, 3);
        p[7][4] = std::make_pair(1, 4);
        p[7][5] = std::make_pair(1, 5);

        p[8][1] = std::make_pair(2, 1);
        p[8][2] = std::make_pair(1, 2);
        p[8][3] = std::make_pair(1, 3);
        p[8][4] = std::make_pair(1, 4);
        p[8][5] = std::make_pair(2, 5);

        p[9][1] = std::make_pair(2, 1);
        p[9][2] = std::make_pair(3, 2);
        p[9][3] = std::make_pair(3, 3);
        p[9][4] = std::make_pair(3, 4);
        p[9][5] = std::make_pair(2, 5);

        p[10][1] = std::make_pair(1, 1);
        p[10][2] = std::make_pair(2, 2);
        p[10][3] = std::make_pair(2, 3);
        p[10][4] = std::make_pair(2, 4);
        p[10][5] = std::make_pair(1, 5);
    }
};
class Joc{
private:
    int suma;
    int miza;
public:

    Joc(int suma, int miza){
        this->suma = suma;
        this->miza = miza;
    }
    ~Joc()
    {
        suma = 0;
        miza = 0;
    }

    Joc& operator=(const Joc& a) {
        if (this != &a) {
            suma = a.suma;
            miza = a.miza;
        }
        return *this;
    }

    friend std::ostream &operator << (std::ostream &o, const Joc &x)
    {
        o << x.suma << '\n';
        return o;
    }
    friend std::istream &operator >> (std::istream &i, Joc &x)
    {
        i >> x.suma;
        return i;
    }

//    Joc& operator+(Joc& a)
//    {
//        Joc *c = new Joc(a);
//        a.suma += a.suma;
//        return *c;
//    }
//
//    friend Joc& operator-(Joc& a, int b)
//    {
//        Joc *c = new Joc(a);
//        a.suma -= b;
//        return *c;
//    }

    friend generaretablou;
    friend linii;
    void jocul(){
        linii p;
        p.generarelinii();
        int miza3 = miza;
        while(suma >= miza3)
        {
            std::string caracter;
            std::cin >> caracter;
            if(caracter == "miza")
            {
                int y;
                std::cin >> y;
                miza3 = y;
            }
            if(caracter == "stop")
                break;
            suma = suma - miza3;
            generaretablou c;
            c.generare();
            for(int i = 1; i <= 3; i ++) {
                for (int j = 1; j <= 5; j++) {
                    int raspuns = c.get2(i, j);
                    if(raspuns <= 4)
                        std::cout << char(raspuns + 1);
                    if(raspuns == 5)
                        std::cout << char(12);
                    if(raspuns == 6)
                        std::cout << char(14);
                    if(raspuns == 7)
                        std::cout << "7";
                    if(raspuns == 8)
                        std::cout << char(21);
                    if(raspuns == 9)
                        std::cout << char(15);
                    if(raspuns == 10)
                        std::cout << char(127);
                    std::cout << " ";
                }
                std::cout << '\n';
            }
            int plata = 0;
            for(int l = 1; l <= 10; l ++)
            {
                std::pair <int, int> start = p.getnext(l, 1);
                int cnt = 1;
                int simbol = c.get2(start.first, start.second);
                for(int i = 2; i <= 5; i ++)
                {
                    int a = c.get2(start.first, start.second);
                    std::pair <int, int> urm = p.getnext(l, i);
                    int b = c.get2(urm.first, urm.second);
                    if(a == b || a == 10 || b == 10)
                        cnt ++;
                    else
                        break;
                }
                if(simbol >= 2 && simbol <= 5)
                {
                    if(cnt == 3)
                        plata = plata + miza3;
                    if(cnt == 4)
                        plata = plata + 3 * miza3;
                    if(cnt == 5)
                        plata = plata + 6 * miza3;
                }
                if(simbol == 1)
                {
                    if(cnt == 3)
                        plata = plata + 2 * miza3;
                    if(cnt == 4)
                        plata = plata + 4 * miza3;
                    if(cnt == 5)
                        plata = plata + 10 * miza3;
                }
                if(simbol == 6)
                {
                    if(cnt == 3)
                        plata = plata + 4 * miza3;
                    if(cnt == 4)
                        plata = plata + 8 * miza3;
                    if(cnt == 5)
                        plata = plata + 17 * miza3;
                }
                if(simbol == 7)
                {
                    if(cnt == 2)
                        plata = plata + miza3;
                    if(cnt == 3)
                        plata = plata + 5 * miza3;
                    if(cnt == 4)
                        plata = plata + 15 * miza3;
                    if(cnt == 5)
                        plata = plata + 20 * miza3;
                }
                if(simbol == 8)
                {
                    if(cnt == 3)
                        plata = plata + 4 * miza3;
                    if(cnt == 4)
                        plata = plata + 12 * miza3;
                    if(cnt == 5)
                        plata = plata + 20 * miza3;
                }
            }
            if(plata > 0)
            {
                std::cout << "Castig: " << plata << ". Dublezi ? (da/nu)\n";
                std::string s;
                std::cin >> s;
                if(s != "da") {
                    std::cout << "";
                }
                else
                {
                    int k = 5;
                    while(k > 0)
                    {
                        std::cout << "rosie sau neagra ? (r/n)\n";
                        char ch;
                        std::cin >> ch;
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<int> dis(0, 1);
                        int raspuns = dis(gen);
                        if(raspuns) {
                            plata = plata * 2;
                            if(ch == 'r')
                                std::cout << "rosie\n";
                            else
                                std::cout << "neagra\n";
                        }
                        else
                        {
                            if(ch == 'r')
                                std::cout << "neagra\n";
                            else
                                std::cout << "rosie\n";
                            plata = 0;
                            break;
                        }
                        std::cout << "continui ? (da/nu)\n";
                        std::string s2;
                        std::cin >> s2;
                        if(s2 == "nu")
                            break;
                        else
                            k = k - 1;
                    }
                }
            }
            suma = suma + plata;
            std::cout << "Suma: " << suma << " " << "Castig " << plata << '\n';
            std::cout << '\n';
        }
    }
};
int main() {
    std::cout << "Pentru a juca introduceti 2 inturi (suma initiala de bani, si miza pe care jucati), si pentru a genera un tabel nou\n";
    std::cout << "scrieti un caracter. Daca doriti sa schimbati miza scrieti 'miza' si dupa aceea numarul nou.\n";
    std::cout << "Pentru a opri jocul scrieti stop\n";
    int suma2, miza2;
    std::cin >> suma2 >> miza2;
    Joc a(suma2, miza2);
    a.jocul();
    return 0;
}