#pragma once
#include <string>
#include "Sucursal.h"
#include "Cliente.h"
#include "Instructor.h"
#include "Clase.h"
#include "ReporteMedicion.h"

class UI
{
public:
    // Banners y mensajes generales
    void mostrarBannerBienvenida();
    void mostrarBannerDespedida();
    void mostrarMensaje(std::string mensaje);
    void mostrarError(std::string mensaje);

    // Menús principales y secundarios
    int mostrarMenuPrincipal();
    int mostrarMenuSucursales();
    int mostrarMenuClientes();
    int mostrarMenuInstructores();
    int mostrarMenuClases();
    int mostrarMenuMediciones();
    int mostrarMenuInformes();
    int mostrarMenuRutinas();

    // Formularios de ingreso de datos - NUEVOS MÉTODOS
    Sucursal crearSucursal();
    Cliente crearCliente();
    Instructor crearInstructor();
    Clase crearClase(Instructor& instructor);
    ReporteMedicion crearReporteMedicion();

    // Métodos de solicitud de datos
    int solicitarIdSucursal();
    int solicitarIdCliente();
    int solicitarIdInstructor();
    int solicitarIdClase();

    // Utilidades
    void mostrarTitulo(std::string titulo);
    void limpiarPantalla();
    void pausarPantalla();
    int solicitarEntero(std::string mensaje);
    float solicitarFloat(std::string mensaje);
    std::string solicitarCadena(std::string mensaje);
    char solicitarCaracter(std::string mensaje);
};
