#pragma once
#include <iostream>
#include <sstream>
#include "VectorSucursales.h"

class GymsPowerLab
{
private:
    std::string nombreGym;
    VectorSucursales sucursales;

public:
    // Constructores y destructor
    GymsPowerLab();
    ~GymsPowerLab();

    // Getters y setters
    std::string getNombreGym() const;
    void setNombreGym(const std::string& nombre);

    // Gesti�n de sucursales
    bool agregarSucursal(const Sucursal& sucursal);
    Sucursal* buscarSucursal(int idSucursal);
    bool existeSucursal(int idSucursal);
    void mostrarSucursales();

    // M�todos de agregaci�n de las diferentes entidades
    bool agregarClienteASucursal(int idSucursal, Cliente& cliente);
    bool agregarInstructorASucursal(int idSucursal, Instructor& instructor);
    bool agregarClaseASucursal(int idSucursal, Clase& clase);

    // M�todos de b�squeda global
    Cliente* buscarClienteEnTodasSucursales(int idCliente);
    Instructor* buscarInstructorEnTodasSucursales(int idInstructor);

    // M�todos de comprobaci�n de existencia
    bool existeIDPersona(int id); // m�todo para comprobar si existe un ID de persona (cliente o instructor) en todas las sucursales

    // Gesti�n de matr�culas
    bool matricularClienteEnClase(int idSucursal, int idCliente, int idClase);

    // Informes
    void mostrarClientesPorSucursal(int idSucursal);
    void mostrarInstructoresPorSucursal(int idSucursal);
    void reporteIMCPorSucursal(int idSucursal);
};