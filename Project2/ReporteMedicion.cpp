#include "ReporteMedicion.h"
#include <cmath>

ReporteMedicion::ReporteMedicion()
{
    idMedicion = 0;
    fecha = "";
    peso = 0.0f;
    estatura = 0.0f;
    porcentajeGrasa = 0.0f;
    porcentajeMusculo = 0.0f;
    edadMetabolica = 0;
    porcentajeGrasaVisceral = 0.0f;
    cintura = 0.0f;
    cadera = 0.0f;
    pecho = 0.0f;
    muslo = 0.0f;
    imc = 0.0f;
}

ReporteMedicion::ReporteMedicion(int id, std::string& fecha, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo, int edadMetabolica, float porcentajeGrasaVisceral, float cintura, float cadera, float pecho, float muslo)
{
    idMedicion = id;
    this->fecha = fecha;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcentajeGrasa;
    this->porcentajeMusculo = porcentajeMusculo;
    this->edadMetabolica = edadMetabolica;
    this->porcentajeGrasaVisceral = porcentajeGrasaVisceral;
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;

    // Calcular IMC
    if (estatura > 0) {
        float estaturaEnMetros = estatura / 100.0f; // Convertir cm a metros
        this->imc = peso / (estaturaEnMetros * estaturaEnMetros);
    }
    else {
        this->imc = 0.0f;
    }
}

ReporteMedicion::~ReporteMedicion()
{


}

int ReporteMedicion::getIdMedicion() const
{
    return idMedicion;
}

float ReporteMedicion::getIMC() const
{
    return imc;
}

float ReporteMedicion::getPeso() const
{
    return peso;
}

std::string ReporteMedicion::getFecha() const
{
    return fecha;
}

std::string ReporteMedicion::getClasificacionIMC() const
{
    if (imc < 16.00f) return "Delgadez severa";
    if (imc <= 16.99f) return "Delgadez moderada";
    if (imc <= 18.49f) return "Delgadez leve";
    if (imc <= 24.99f) return "Normal";
    if (imc <= 29.99f) return "Pre-obesidad";
    if (imc <= 34.99f) return "Obesidad leve";
    if (imc <= 39.99f) return "Obesidad media";
    return "Obesidad morbida";
}

bool ReporteMedicion::esAltoRiesgo() const
{
    return (imc >= 30.0f); // Obesidad leve, media o mórbida
}

float ReporteMedicion::calcularVasosAgua() const
{
    return peso / 7.0f;
}

float ReporteMedicion::calcularProteinaRequerida(char genero, bool haceEjercicio) const
{
    if (!haceEjercicio) {
        return peso * 0.8f; // Base de 0.8g por kg
    }

    if (genero == 'M' || genero == 'm') {
        return peso * 2.1f; // Promedio entre 1.7-2.5 para hombres
    }
    else {
        return peso * 1.7f; // Promedio entre 1.6-1.8 para mujeres
    }
}

std::string ReporteMedicion::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idMedicion << " | Fecha: " << fecha << " | IMC: " << imc << " (" << getClasificacionIMC() << ")";
    return oss.str();
}

std::string ReporteMedicion::toStringDetalle()
{
    std::ostringstream oss;
    oss << "=== REPORTE DE MEDICION ===" << std::endl;
    oss << "ID Medicion: " << idMedicion << std::endl;
    oss << "Fecha: " << fecha << std::endl;
    oss << "Peso: " << peso << " kg" << std::endl;
    oss << "Estatura: " << estatura << " cm" << std::endl;
    oss << "IMC: " << imc << " - " << getClasificacionIMC() << std::endl;
    oss << "Porcentaje de Grasa: " << porcentajeGrasa << "%" << std::endl;
    oss << "Porcentaje de Musculo: " << porcentajeMusculo << "%" << std::endl;
    oss << "Edad Metabolica: " << edadMetabolica << " años" << std::endl;
    oss << "Grasa Visceral: " << porcentajeGrasaVisceral << "%" << std::endl;
    oss << "Medidas Corporales:" << std::endl;
    oss << "  - Cintura: " << cintura << " cm" << std::endl;
    oss << "  - Cadera: " << cadera << " cm" << std::endl;
    oss << "  - Pecho: " << pecho << " cm" << std::endl;
    oss << "  - Muslo: " << muslo << " cm" << std::endl;
    oss << "Vasos de agua recomendados: " << calcularVasosAgua() << " vasos de 250ml" << std::endl;
    if (esAltoRiesgo()) {
        oss << "*** PACIENTE DE ALTO RIESGO ***" << std::endl;
    }
    return oss.str();
}