// Project2/Instructor.h
#pragma once
#include <iostream>
#include <sstream>
#include "Fecha.h"

class Instructor
{
private:
    int idInstructor;
    std::string nombre;
    std::string correoElectronico;
    std::string telefono;
    Fecha fechaNacimiento;
    std::string especialidades[10];



public:
    Instructor();
    Instructor(int id, std::string& nombre, std::string& correo, std::string& telefono, Fecha& fechaNac);
    ~Instructor();

    int getIdInstructor() const;
    std::string getNombre() const;
    bool especialidadValida(std::string e);
    bool agregarEspecialidad(std::string especialidad);
    void mostrarEspecialidades();
    bool tieneEspecialidad(std::string especialidad);

    std::string toString();
    std::string toStringDetalle();
};
