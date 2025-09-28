#pragma once
#include <iostream>
#include <sstream>

class Instructor
{
private:
    int idInstructor;
    std::string nombre;
    std::string correoElectronico;
    std::string telefono;
    std::string fechaNacimiento;
	std::string especialidades[10]; // Array to hold up to 10 specialties

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