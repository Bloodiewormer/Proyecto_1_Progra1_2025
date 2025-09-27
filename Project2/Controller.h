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

    // Métodos privados para cada funcionalidad
    void menuSucursales();
    void menuClientes();
    void menuInstructores();
    void menuClases();
    void menuMediciones();
    void menuInformes();
    void menuRutinas();

    // Funcionalidades específicas
    void agregarSucursal();
    void agregarCliente();
    void agregarInstructor();
    void agregarClase();
    void agregarMedicion();
    void agregarEjercicio();

    void listarClientesPorSucursal();
    void listarInstructoresPorSucursal();
    void mostrarDetalleCliente();
    void mostrarDetalleInstructor();
    void mostrarDetalleClase();
    void mostrarHistorialMediciones();
    void reporteIMC();
    void matricularClienteEnClase();
    void generarRutina();

    // Informes adicionales
    void listarClientesPorInstructor(); //add
    void listarInstructoresPorEspecialidad(); //add

    // Validaciones
    bool validarEspecialidadInstructor(std::string especialidad); //add
    bool validarAreaEjercicio(std::string area); //add

    // Datos de prueba
    void cargarDatosPrueba();

public:
    Controller();
    ~Controller();
    void run();
};

