// C++
// File: 'Project2/Controller.h'
#pragma once
#include "GymsPowerLab.h"
#include "UI.h"
#include "VectorEjercicio.h"

class RutinaCliente {
public:
    int idCliente;
    Ejercicio* ejercicios[10];
    int cantidad;
    RutinaCliente() {
        idCliente = 0;
        cantidad = 0;
        for (int i = 0; i < 10; i++) ejercicios[i] = 0;
    }
};

class Controller
{
private:
    GymsPowerLab gym;
    UI interfaz;
    VectorEjercicio bateriaEjercicios;
    RutinaCliente rutinas[100];
    int cantRutinas;
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
    void verClasesDeCliente();
    void mostrarRutinaDeCliente();

    bool validarEspecialidadInstructor(std::string especialidad);
    bool validarAreaEjercicio(std::string area);

    std::string obtenerEspecialidadDeTipo(std::string tipo);

    int buscarIndiceRutinaPorCliente(int idCliente);
    void guardarRutinaParaCliente(int idCliente, Ejercicio** lista, int n);

    void cargarDatosPrueba();

public:
    Controller();
    ~Controller();
    void run();
};


