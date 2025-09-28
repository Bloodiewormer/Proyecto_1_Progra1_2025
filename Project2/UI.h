// C++
#pragma once
#include <string>
#include "Sucursal.h"
#include "Cliente.h"
#include "Instructor.h"
#include "Clase.h"
#include "ReporteMedicion.h"
#include "Fecha.h"

class UI
{
public:
    void mostrarBannerBienvenida();
    void mostrarBannerDespedida();
    void mostrarMensaje(std::string mensaje);
    void mostrarError(std::string mensaje);

    int mostrarMenuPrincipal();
    int mostrarMenuSucursales();
    int mostrarMenuClientes();
    int mostrarMenuInstructores();
    int mostrarMenuClases();
    int mostrarMenuMediciones();
    int mostrarMenuInformes();
    int mostrarMenuRutinas();

    Sucursal crearSucursal();
    Cliente crearCliente();
    Instructor crearInstructor();
    Clase crearClase(Instructor& instructor);
    ReporteMedicion crearReporteMedicion();

    int solicitarIdSucursal();
    int solicitarIdCliente();
    int solicitarIdInstructor();
    int solicitarIdClase();

    void mostrarTitulo(std::string titulo);
    void limpiarPantalla();
    void pausarPantalla();
    int solicitarEntero(std::string mensaje);
    float solicitarFloat(std::string mensaje);
    std::string solicitarCadena(std::string mensaje);
    char solicitarCaracter(std::string mensaje);

    Fecha solicitarFechaDDMMAAAA(std::string titulo);
};
