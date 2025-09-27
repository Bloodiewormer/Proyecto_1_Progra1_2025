#include "Ejercicio.h"

Ejercicio::Ejercicio()
{
    idEjercicio = 0;
    nombre = "";
    area = "";
    descripcion = "";
    series = 0;
    repeticiones = 0;
    peso = 0.0f;
}

Ejercicio::Ejercicio(int id, std::string& nombre, std::string& area, std::string& descripcion, int series, int repeticiones, float peso)
{
    idEjercicio = id;
    this->nombre = nombre;
    this->area = area;
    this->descripcion = descripcion;
    this->series = series;
    this->repeticiones = repeticiones;
    this->peso = peso;
}

Ejercicio::~Ejercicio()
{
}

int Ejercicio::getIdEjercicio() const
{
    return idEjercicio;
}

std::string Ejercicio::getNombre() const
{
    return nombre;
}

std::string Ejercicio::getArea() const
{
    return area;
}

std::string Ejercicio::getDescripcion() const
{
    return descripcion;
}

int Ejercicio::getSeries() const
{
    return series;
}

int Ejercicio::getRepeticiones() const
{
    return repeticiones;
}

float Ejercicio::getPeso() const
{
    return peso;
}

void Ejercicio::setIdEjercicio(int id)
{
    idEjercicio = id;
}

void Ejercicio::setNombre(std::string& nombre)
{
    this->nombre = nombre;
}

void Ejercicio::setArea(std::string& area)
{
    this->area = area;
}

void Ejercicio::setDescripcion(std::string& descripcion)
{
    this->descripcion = descripcion;
}

void Ejercicio::setSeries(int series)
{
    this->series = series;
}

void Ejercicio::setRepeticiones(int repeticiones)
{
    this->repeticiones = repeticiones;
}

void Ejercicio::setPeso(float peso)
{
    this->peso = peso;
}

std::string Ejercicio::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idEjercicio << " | ";
    oss << "Nombre: " << nombre << " | ";
    oss << "Area: " << area << "\n";
    return oss.str();
}

std::string Ejercicio::toStringDetalle()
{
    std::ostringstream oss;
    oss << "ID Ejercicio: " << idEjercicio << "\n";
    oss << "Nombre: " << nombre << "\n";
    oss << "Area: " << area << "\n";
    oss << "Descripcion: " << descripcion << "\n";
    oss << "Series: " << series << "\n";
    oss << "Repeticiones: " << repeticiones << "\n";
    oss << "Peso: " << peso << " kg\n";
    return oss.str();
}