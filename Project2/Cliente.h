#pragma once
#include <iostream>
#include "VectorMedicion.h"
#include "Instructor.h"
#include "Ejercicio.h"
#include <sstream>
class Cliente
{
private:
    int idCliente;
    std::string nombre;
    std::string correoElectronico;
    std::string telefono;
    Fecha fechaNacimiento;
    char genero; // 'M' o 'F'
    Fecha fechaInscripcion;
    VectorMedicion historicoMediciones;
    Instructor* instructorAsignado;
    Ejercicio* rutina[20];
    int cantRutina;
public:
    Cliente();
    Cliente(int id, std::string& nombre, std::string& correo, std::string& telefono, Fecha& fechaNac, char genero, Fecha& fechaIns);
    ~Cliente();

    // Getters
    int getIdCliente();
    void setIdCliente(int id);
    std::string getNombre();
    void setNombre(std::string& nombre);
    void setInstructorAsignado(Instructor* instr);
    Instructor* getInstructorAsignado();

    // Mediciones
    bool agregarMedicion(ReporteMedicion& medicion);
    bool eliminarMedicion(int idMedicion);
    ReporteMedicion* buscarMedicion(int idMedicion);
    bool existeMedicion(int idMedicion);
    void mostrarHistorialMediciones();
    int getCantidadMediciones();
    ReporteMedicion* getMedicionPorIndice(int i);
    void mostrarHistorialMedicionesOrdenado(); // orden por fecha asc
    ReporteMedicion* obtenerUltimaMedicion();
    void limpiarRutina();
    bool agregarEjercicioARutina(Ejercicio* e);
    void mostrarRutina();

    ReporteMedicion* getUltimaMedicion();

    std::string toString();
    std::string toStringDetalle();
};