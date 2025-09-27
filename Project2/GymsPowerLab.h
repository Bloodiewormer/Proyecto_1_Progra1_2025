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

    // Gestión de sucursales
    bool agregarSucursal(const Sucursal& sucursal);
    Sucursal* buscarSucursal(int idSucursal);
    bool existeSucursal(int idSucursal);
    void mostrarSucursales();

    // Métodos de agregación de las diferentes entidades
    bool agregarClienteASucursal(int idSucursal, Cliente& cliente);
    bool agregarInstructorASucursal(int idSucursal, Instructor& instructor);
    bool agregarClaseASucursal(int idSucursal, Clase& clase);

    // Métodos de búsqueda global
    Cliente* buscarClienteEnTodasSucursales(int idCliente);
    Instructor* buscarInstructorEnTodasSucursales(int idInstructor);

    // Métodos de comprobación de existencia
    bool existeIDPersona(int id); // método para comprobar si existe un ID de persona (cliente o instructor) en todas las sucursales

    // Gestión de matrículas
    bool matricularClienteEnClase(int idSucursal, int idCliente, int idClase);

    // Informes
    void mostrarClientesPorSucursal(int idSucursal);
    void mostrarInstructoresPorSucursal(int idSucursal);
    void reporteIMCPorSucursal(int idSucursal);
};