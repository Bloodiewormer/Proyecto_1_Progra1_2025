#pragma once
#include <iostream>
#include "ReporteMedicion.h"
class VectorMedicion
{
private:
    ReporteMedicion** mediciones;
    int capacidad;
    int cantidad;
public:
    VectorMedicion();
    ~VectorMedicion();
    bool agregarMedicion(ReporteMedicion* medicion);
    bool eliminarMedicion(int idMedicion);
    ReporteMedicion** buscarMedicion(int idMedicion);
    bool existeMedicion(int idMedicion);
    void mostrarMediciones();
};
