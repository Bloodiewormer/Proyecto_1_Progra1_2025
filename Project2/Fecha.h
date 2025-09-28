#pragma once
#include <string>

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:

    Fecha();
    Fecha(int d, int m, int a);
    ~Fecha();
    int getDia();
    int getMes();
    int getAnio();

    bool esValida(Fecha f) ;
    std::string toString() ;
};
