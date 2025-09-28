
#pragma once
#include <iostream>
#include "VectorClientes.h"
#include "VectorInstructores.h"
#include "VectorClases.h"

class Sucursal
{
private:
    int idSucursal;
    std::string provincia;
    std::string canton;
    std::string correoElectronico;
    std::string telefono;
    VectorClientes clientes;
    VectorInstructores instructores;
    VectorClases clases;
public:
    Sucursal();
    Sucursal(int id, std::string& provincia, std::string& canton, std::string& correo, std::string& telefono);
    ~Sucursal();
    int getCantidadClases();
    int getIdSucursal();
    bool agregarCliente(Cliente& cliente);
    Cliente* buscarCliente(int idCliente);
    void mostrarClientes();
    bool agregarInstructor(Instructor& instructor);
    Instructor* buscarInstructor(int idInstructor);
    void mostrarInstructores();
    bool agregarClase(Clase& clase);
    Clase* buscarClase(int idClase);
    void mostrarClases();
    std::string toString();
    std::string toStringDetalle();

    int getCantidadClientes();
    Cliente* getClientePorIndice(int i);
    int getCantidadInstructores();
    Instructor* getInstructorPorIndice(int i);
    Clase* getClasePorIndice(int i);
};
