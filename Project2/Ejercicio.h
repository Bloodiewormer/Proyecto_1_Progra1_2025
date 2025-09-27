#pragma once
#include <iostream>
#include <sstream>

class Ejercicio
{
private:
    int idEjercicio;
    std::string nombre;
    std::string area; // pecho y triceps, biceps, piernas, espalda
    std::string descripcion;
    int series;
    int repeticiones;
    float peso;

public:
    Ejercicio();
    Ejercicio(int id, std::string& nombre, std::string& area, std::string& descripcion, int series, int repeticiones, float peso);
    ~Ejercicio();

    int getIdEjercicio() const;
    std::string getNombre() const;
    std::string getArea() const;
    std::string getDescripcion() const;
    int getSeries() const;
    int getRepeticiones() const;
    float getPeso() const;

    void setIdEjercicio(int id);
    void setNombre(std::string& nombre);
    void setArea(std::string& area);
    void setDescripcion(std::string& descripcion);
    void setSeries(int series);
    void setRepeticiones(int repeticiones);
    void setPeso(float peso);

    std::string toString();
    std::string toStringDetalle();
};