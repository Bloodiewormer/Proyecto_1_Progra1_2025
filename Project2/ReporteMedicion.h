#pragma once
#include <iostream>
#include <sstream>

#include "Fecha.h"

class ReporteMedicion
{
private:
    int idMedicion;
    Fecha fecha;
    float peso;
    float estatura;
    float porcentajeGrasa;
    float porcentajeMusculo;
    int edadMetabolica;
    float porcentajeGrasaVisceral;
    float cintura, cadera, pecho, muslo;
    float imc;

public:
    ReporteMedicion();
    ReporteMedicion(int id, Fecha& fecha, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo, int edadMetabolica, float porcentajeGrasaVisceral, float cintura, float cadera, float pecho, float muslo);
    ~ReporteMedicion();

    // Getters
    int getIdMedicion() const;
    float getIMC() const;
    float getPeso() const;
    Fecha getFecha() const;

    // M�todos de c�lculo
    std::string getClasificacionIMC() const;
    bool esAltoRiesgo() const;
    float calcularVasosAgua();

    std::string toString();
    std::string toStringDetalle();
};
