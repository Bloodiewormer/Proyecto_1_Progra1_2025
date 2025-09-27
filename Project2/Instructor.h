#pragma once
#include <iostream>
#include <sstream>
#include "VectorStrings.h"

class Instructor
{
private:
    int idInstructor;
    std::string nombre;
    std::string correoElectronico;
    std::string telefono;
    std::string fechaNacimiento;
    VectorStrings especialidades;

public:
    Instructor();
    Instructor(int id, std::string& nombre, std::string& correo, std::string& telefono, std::string& fechaNac);
    ~Instructor();

    // Getters
    int getIdInstructor() const;
    std::string getNombre() const;

    // Especialidades
    bool agregarEspecialidad(std::string especialidad);
    void mostrarEspecialidades();
    bool tieneEspecialidad(std::string especialidad);

    std::string toString();
    std::string toStringDetalle();
};