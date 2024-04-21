#include <iostream>
#include "joc.h"
class intro
{
public:
    virtual void afisare()
    {
        std::cout << "scrieti un caracter. Daca doriti sa schimbati miza scrieti 'miza' si dupa aceea numarul nou.\n";
    }
    void afisare2()
    {
        std::cout << "scrieti un caracter. Daca doriti sa schimbati miza scrieti 'miza' si dupa aceea numarul nou.\n";
        std::cout << "Pentru a opri jocul scrieti stop\n";
    }
};
class test : public intro
{
public:
    void afisare()
    {
        std::cout << "Pentru a juca introduceti 2 inturi (suma initiala de bani, si miza pe care jucati), si pentru a genera un tabel nou\n";
    }
};

class abstract
{
public:
    virtual void f() = 0;
};

class derivata : public abstract
{
public:
    void f()
    {
        std::cout << "Pentru a opri jocul scrieti stop\n";
    }
};

int main() {
    test s;
    intro *p = &s;
    p->afisare();
    p->afisare2();
    int suma2, miza2;
    std::cin >> suma2 >> miza2;
    Joc a(suma2, miza2);
    a.jocul();
    abstract *p2 = new derivata();
    p2->f();
    return 0;
}