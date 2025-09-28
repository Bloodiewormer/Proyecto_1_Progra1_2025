#include "ReporteMedicion.h"
#include <cmath>

ReporteMedicion::ReporteMedicion()
{
    idMedicion = 0;
    fecha = Fecha();
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

ReporteMedicion::ReporteMedicion(int id, Fecha& fecha, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo, int edadMetabolica, float porcentajeGrasaVisceral, float cintura, float cadera, float pecho, float muslo)
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

Fecha ReporteMedicion::getFecha() const
{
    return fecha;
}

std::string ReporteMedicion::getClasificacionIMC() const
{
    if (imc < 16.00) return "Delgadez severa";
    if (imc <= 16.99) return "Delgadez moderada";
    if (imc <= 18.49) return "Delgadez leve";
    if (imc <= 24.99) return "Normal";
    if (imc <= 29.99) return "Pre-obesidad";
    if (imc <= 34.99) return "Obesidad leve";
    if (imc <= 39.99) return "Obesidad media";
    return "Obesidad morbida";
}

bool ReporteMedicion::esAltoRiesgo() const
{
    return (imc >= 30); // Obesidad leve, media o m�rbida
}

float ReporteMedicion::calcularVasosAgua()
{
    return peso / 7;
}



std::string ReporteMedicion::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idMedicion << " | Fecha: " << fecha.toString() << " | IMC: " << imc << " (" << getClasificacionIMC() << ")";
    return oss.str();
}

std::string ReporteMedicion::toStringDetalle()
{
    std::ostringstream oss;
    oss << "=== REPORTE DE MEDICION ===" << std::endl;
    oss << "ID Medicion: " << idMedicion << std::endl;
    oss << "Fecha: " << fecha.toString() << std::endl;
    oss << "Peso: " << peso << " kg" << std::endl;
    oss << "Estatura: " << estatura << " cm" << std::endl;
    oss << "IMC: " << imc << " - " << getClasificacionIMC() << std::endl;
    oss << "Porcentaje de Grasa: " << porcentajeGrasa << "%" << std::endl;
    oss << "Porcentaje de Musculo: " << porcentajeMusculo << "%" << std::endl;
    oss << "Edad Metabolica: " << edadMetabolica << " a�os" << std::endl;
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