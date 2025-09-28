// C++
#include "Fecha.h"
#include <sstream>


Fecha::Fecha( ) {
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

Fecha::~Fecha() {
}

int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getAnio() {
    return anio;
}


bool Fecha::esValida( Fecha f)
{

    if (f.anio < 1900 || f.anio > 2100) return false;
    if (f.mes < 1 || f.mes > 12) return false;
    if (f.dia < 1) return false;

    int diasEnMes;
    switch (f.mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        diasEnMes = 31; break;
    case 4: case 6: case 9: case 11:
        diasEnMes = 30; break;
    case 2:
        // Verificar a�o bisiesto
        if ((f.anio % 4 == 0 && f.anio % 100 != 0) || (f.anio % 400 == 0))
            diasEnMes = 29;
        else
            diasEnMes = 28;
        break;
    default:
        return false; // Mes inv��lido
    }
    if (f.dia > diasEnMes) return false;
    return true;
}

std::string Fecha::toString() {
    std::ostringstream oss;
    if (dia < 10) oss << "0";
    oss << dia << "/";
    if (mes < 10) oss << "0";
    oss << mes << "/";
    oss << anio;
    return oss.str();
}






