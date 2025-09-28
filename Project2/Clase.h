#pragma once
#include <iostream>
#include <sstream>
#include "Instructor.h"
#include "Cliente.h"
#include "VectorClientes.h"

class Clase
{
private:
    int idClase;
    std::string tipoClase;
    int capacidadMaxima;
    std::string horario;
    Instructor instructorAsignado;
    VectorClientes clientesInscritos;

public:
    Clase();
    Clase(int id, std::string& tipo, int capacidad, std::string& horario, Instructor& instructor);
    ~Clase();

    int getIdClase();
    std::string getTipoClase();
    int getCapacidadMaxima();
    int getCuposDisponibles();
    int getCantidadInscritos();
    Instructor getInstructor();

    bool agregarCliente(Cliente& cliente);
    Cliente* buscarCliente(int idCliente);
    void mostrarClientes();
    bool estaLlena();
    bool tieneCliente(int idCliente);


    Cliente* getClientePorIndice(int i);
    std::string toString();
    std::string toStringCorto();
    std::string toStringDetalle();
};
