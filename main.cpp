#include <bits/stdc++.h>
#include <array>

using namespace std;
int miza;
class generaretablou{
private:
    int v[4][6];
public:
    int get2(int i, int j)
    {
        return v[i][j];
    }
    void generare()
    {

        v[1][1] = (rand()%9 + 1);
        v[2][1] = (rand()%9 + 1);
        v[3][1] = (rand()%9 + 1);
        for(int i = 1; i <= 3; i ++)
        {
            for(int j = 2; j <= 5; j ++)
            {
                int h = (rand()% 100  + 1);
                if(h <= 2)
                {
                    v[i][j] = v[i][j - 1];
                    if(v[i][j] == 10 && j == 5)
                        v[i][j] = (rand() % 9 + 1);
                }
                else {
                    int numar = 10;
                    if(j == 5)
                        numar = 9;
                    v[i][j] = (rand() % numar + 1);
                    if(v[i][j] == 10)
                    {
                        int b = rand() % 100 + 1;
                        if(b <= 1)
                            v[i][j] = rand() % numar + 1;
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
    pair <int, int> p[11][6];
public:
    pair<int, int> getnext(int a, int b)
    {
        return p[a][b];
    }
    void generarelinii()
    {
        for(int i = 1; i <= 3; i ++)
            for(int j = 1; j <= 5; j ++)
                p[i][j] = make_pair(i, j);
        p[4][1] = make_pair(1, 1);
        p[4][2] = make_pair(2, 2);
        p[4][3] = make_pair(3, 3);
        p[4][4] = make_pair(2, 4);
        p[4][5] = make_pair(1, 5);

        p[5][1] = make_pair(3, 1);
        p[5][2] = make_pair(2, 2);
        p[5][3] = make_pair(1, 3);
        p[5][4] = make_pair(2, 4);
        p[5][5] = make_pair(3, 5);

        p[6][1] = make_pair(1, 1);
        p[6][2] = make_pair(1, 2);
        p[6][3] = make_pair(2, 3);
        p[6][4] = make_pair(3, 4);
        p[6][5] = make_pair(4, 5);

        p[7][1] = make_pair(3, 1);
        p[7][2] = make_pair(3, 2);
        p[7][3] = make_pair(2, 3);
        p[7][4] = make_pair(1, 4);
        p[7][5] = make_pair(1, 5);

        p[8][1] = make_pair(2, 1);
        p[8][2] = make_pair(1, 2);
        p[8][3] = make_pair(1, 3);
        p[8][4] = make_pair(1, 4);
        p[8][5] = make_pair(2, 5);

        p[9][1] = make_pair(2, 1);
        p[9][2] = make_pair(3, 2);
        p[9][3] = make_pair(3, 3);
        p[9][4] = make_pair(3, 4);
        p[9][5] = make_pair(2, 5);

        p[10][1] = make_pair(1, 1);
        p[10][2] = make_pair(2, 2);
        p[10][3] = make_pair(2, 3);
        p[10][4] = make_pair(2, 4);
        p[10][5] = make_pair(1, 5);
    }
};
class Joc{
private:
    int suma;
public:
    Joc(int suma){
        this->suma = suma;
    }
    ~Joc()
    {
        suma = 0;
    }

    Joc& operator=(const Joc& a) {
        if (this != &a) {
            suma = a.suma;
        }
        return *this;
    }

    [[nodiscard]] int get() const{
        return suma;
    }
    friend ostream &operator << (ostream &o, Joc &x)
    {
        o << x.suma << '\n';
        return o;
    }
    friend istream &operator >> (istream &i, Joc &x)
    {
        i >> x.suma;
        return i;
    }

    Joc& operator+(Joc& a)
    {
        Joc *c = new Joc(a);
        a.suma += a.suma;
        return *c;
    }

    friend Joc& operator-(Joc& a, int b)
    {
        Joc *c = new Joc(a);
        a.suma -= b;
        return *c;
    }

    friend generaretablou;
    friend linii;
    void jocul(){
        linii p;
        p.generarelinii();
        while(suma >= miza)
        {
            string caracter;
            cin >> caracter;
            if(caracter == "miza")
            {
                int y;
                cin >> y;
                miza = y;
            }
            if(caracter == "stop")
                break;
            suma = suma - miza;
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
                    cout << " ";
                }
                std::cout << '\n';
            }
            int plata = 0;
            for(int l = 1; l <= 10; l ++)
            {
                pair <int, int> start = p.getnext(l, 1);
                int cnt = 1;
                int simbol = c.get2(start.first, start.second);
                for(int i = 2; i <= 5; i ++)
                {
                    int a = c.get2(start.first, start.second);
                    pair <int, int> urm = p.getnext(l, i);
                    int b = c.get2(urm.first, urm.second);
                    if(a == b || a == 10 || b == 10)
                        cnt ++;
                    else
                        break;
                }
                if(simbol >= 2 && simbol <= 5)
                {
                    if(cnt == 3)
                        plata = plata + miza;
                    if(cnt == 4)
                        plata = plata + 3 * miza;
                    if(cnt == 5)
                        plata = plata + 6 * miza;
                }
                if(simbol == 1)
                {
                    if(cnt == 3)
                        plata = plata + 2 * miza;
                    if(cnt == 4)
                        plata = plata + 4 * miza;
                    if(cnt == 5)
                        plata = plata + 10 * miza;
                }
                if(simbol == 6)
                {
                    if(cnt == 3)
                        plata = plata + 4 * miza;
                    if(cnt == 4)
                        plata = plata + 8 * miza;
                    if(cnt == 5)
                        plata = plata + 17 * miza;
                }
                if(simbol == 7)
                {
                    if(cnt == 2)
                        plata = plata + miza;
                    if(cnt == 3)
                        plata = plata + 5 * miza;
                    if(cnt == 4)
                        plata = plata + 15 * miza;
                    if(cnt == 5)
                        plata = plata + 20 * miza;
                }
                if(simbol == 8)
                {
                    if(cnt == 3)
                        plata = plata + 4 * miza;
                    if(cnt == 4)
                        plata = plata + 12 * miza;
                    if(cnt == 5)
                        plata = plata + 20 * miza;
                }
            }
            if(plata > 0)
            {
                cout << "Castig: " << plata << ". Dublezi ? (da/nu)\n";
                string s;
                std::cin >> s;
                if(s != "da") {
                    string s2;
                    s2 = s;
                }
                else
                {
                    int k = 5;
                    while(k > 0)
                    {
                        cout << "rosie sau neagra ? (r/n)\n";
                        char ch;
                        cin >> ch;
                        int raspuns = (rand() % 2);
                        if(raspuns) {
                            plata = plata * 2;
                            if(ch == 'r')
                                cout << "rosie\n";
                            else
                                cout << "neagra\n";
                        }
                        else
                        {
                            if(ch == 'r')
                                cout << "neagra\n";
                            else
                                cout << "rosie\n";
                            plata = 0;
                            break;
                        }
                        cout << "continui ? (da/nu)\n";
                        string s2;
                        cin >> s2;
                        if(s2 == "nu")
                            break;
                        else
                            k = k - 1;
                    }
                }
            }
            suma = suma + plata;
            cout << "Suma: " << suma << " " << "Castig " << plata << '\n';
            cout << '\n';
        }
    }
};
int main() {
    cout << "Pentru a juca introduceti 2 inturi (suma initiala de bani, si miza pe care jucati), si pentru a genera un tabel nou\n";
    cout << "scrieti un caracter. Daca doriti sa schimbati miza scrieti 'miza' si dupa aceea numarul nou.\n";
    cout << "Pentru a opri jocul scrieti stop\n";
    int suma2;
    cin >> suma2 >> miza;
    Joc a = suma2;
    srand(time(nullptr));
    a.jocul();
    return 0;
}
