#pragma once
#include <iostream>
#include <sstream>

class ReporteMedicion
{
private:
    int idMedicion;
    std::string fecha;
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
    ReporteMedicion(int id, std::string& fecha, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo, int edadMetabolica, float porcentajeGrasaVisceral, float cintura, float cadera, float pecho, float muslo);
    ~ReporteMedicion();

    // Getters
    int getIdMedicion() const;
    float getIMC() const;
    float getPeso() const;
    std::string getFecha() const;

    // Métodos de cálculo
    std::string getClasificacionIMC() const;
    bool esAltoRiesgo() const;
    float calcularVasosAgua() const;
    float calcularProteinaRequerida(char genero, bool haceEjercicio) const;

    std::string toString();
    std::string toStringDetalle();
};