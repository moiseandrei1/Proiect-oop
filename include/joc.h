#include <iostream>
#include <random>
#include "generaretablou.h"
#include "linii.h"
class Joc : public generaretablou, public linii{
private:
    int suma;
    int miza;
public:
    Joc(int suma, int miza) : generaretablou(){
        this->suma = suma;
        this->miza = miza;
    }
    virtual ~Joc() = default;

    Joc& operator=(const Joc& a) {
        if (this != &a) {
            suma = a.suma;
            miza = a.miza;
        }
        return *this;
    }
    //Joc(const Joc &p) : linii(p)
    //{
    //    this->suma = suma;
    //    this->miza = miza;
    //}
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
            generaretablou c{};
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

        }
    }
};