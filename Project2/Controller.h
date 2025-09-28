// File: 'Project2/Controller.h'  (add new helpers)
#pragma once
#include "GymsPowerLab.h"
#include "UI.h"
#include "VectorEjercicio.h"

class Controller
{
private:
    GymsPowerLab gym;
    UI interfaz;
    VectorEjercicio bateriaEjercicios;

    void menuSucursales();
    void menuClientes();
    void menuInstructores();
    void menuClases();
    void menuMediciones();
    void menuInformes();
    void menuRutinas();

    void agregarSucursal();
    void agregarCliente();
    void agregarInstructor();
    void agregarClase();
    void agregarMedicion();
    void agregarEjercicio();

    void listarClientesPorSucursal();
    void listarInstructoresPorSucursal();
    void listarClasesPorSucursal();    
    void mostrarDetalleCliente();
    void mostrarDetalleInstructor();
    void mostrarDetalleClase();
    void mostrarHistorialMediciones();
    void reporteIMC();
    void matricularClienteEnClase();
    void generarRutina();

    void listarClientesPorInstructor();
    void listarInstructoresPorEspecialidad();

    bool validarEspecialidadInstructor(std::string especialidad);
    bool validarAreaEjercicio(std::string area);

    // helper: intenta extraer la especialidad base del texto de tipo de clase
    std::string obtenerEspecialidadDeTipo(std::string tipo);

    void cargarDatosPrueba();

public:
    Controller();
    ~Controller();
    void run();
};
