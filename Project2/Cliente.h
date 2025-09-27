#pragma once
#include <iostream>
#include "VectorMedicion.h"
#include <sstream>
class Cliente
{
private:
    int idCliente;
    std::string nombre;
    std::string correoElectronico;
    std::string telefono;
    std::string fechaNacimiento;
    char genero; // 'M' o 'F'
    std::string fechaInscripcion;
    VectorMedicion historicoMediciones;
public:
    Cliente();
    Cliente(int id, std::string& nombre, std::string& correo, std::string& telefono, std::string& fechaNac, char genero, std::string& fechaIns);
    ~Cliente();

    // Getters
    int getIdCliente();
    void setIdCliente(int id);
    std::string getNombre();
    void setNombre(std::string& nombre);
    std::string getCorreoElectronico();
    void setCorreoElectronico(std::string& correo);
    std::string getTelefono();
    void setTelefono(std::string& telefono);
    std::string getFechaNacimiento();
    void setFechaNacimiento(std::string& fecha);
    char getGenero();
    void setGenero(char genero);
    std::string getFechaInscripcion();
    void setFechaInscripcion(std::string& fecha);

    // Mediciones
    bool agregarMedicion(ReporteMedicion& medicion);
    bool eliminarMedicion(int idMedicion);
    ReporteMedicion* buscarMedicion(int idMedicion);
    bool existeMedicion(int idMedicion);
    void mostrarHistorialMediciones();

    std::string toString();
    std::string toStringDetalle();
};