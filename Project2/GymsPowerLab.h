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
    GymsPowerLab();
    ~GymsPowerLab();

    std::string getNombreGym() const;
    void setNombreGym(const std::string& nombre);

    bool agregarSucursal(Sucursal* sucursal);
    Sucursal* buscarSucursal(int idSucursal);
    bool existeSucursal(int idSucursal);
    void mostrarSucursales();

    bool agregarClienteASucursal(int idSucursal, Cliente& cliente);
    bool agregarInstructorASucursal(int idSucursal, Instructor& instructor);
    bool agregarClaseASucursal(int idSucursal, Clase& clase);

    Cliente* buscarClienteEnTodasSucursales(int idCliente);
    Instructor* buscarInstructorEnTodasSucursales(int idInstructor);

    bool existeIDPersona(int id);

    bool matricularClienteEnClase(int idSucursal, int idCliente, int idClase);

    void mostrarClientesPorSucursal(int idSucursal);
    void mostrarInstructoresPorSucursal(int idSucursal);
    void reporteIMCPorSucursal(int idSucursal);

};