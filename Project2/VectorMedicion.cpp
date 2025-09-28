#include "VectorMedicion.h"

VectorMedicion::VectorMedicion()
{
    capacidad = 10; // M�ximo 10 mediciones por cliente seg�n el proyecto
    cantidad = 0;
    mediciones = new ReporteMedicion * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        mediciones[i] = nullptr;
    }
}

VectorMedicion::~VectorMedicion()
{
    delete[] mediciones;
}

int VectorMedicion::getCantidad()
{
    return cantidad;
}

ReporteMedicion* VectorMedicion::getMedicionPorIndice(int i)
{
    if (i < 0 || i >= cantidad) return nullptr;
    return mediciones[i];
}

bool VectorMedicion::agregarMedicion(ReporteMedicion* medicion)
{
    if (cantidad >= capacidad) return false; // No hay espacio
    if (existeMedicion(medicion->getIdMedicion())) return false; // ID repetido

    mediciones[cantidad] = medicion;
    cantidad++;
    return true;
}

bool VectorMedicion::eliminarMedicion(int idMedicion)
{
    for (int i = 0; i < cantidad; i++) {
        if (mediciones[i]->getIdMedicion() == idMedicion) {
            // Mover elementos hacia la izquierda
            for (int j = i; j < cantidad - 1; j++) {
                mediciones[j] = mediciones[j + 1];
            }
            mediciones[cantidad - 1] = nullptr;
            cantidad--;
            return true;
        }
    }
    return false; // No encontrado
}

ReporteMedicion** VectorMedicion::buscarMedicion(int idMedicion)
{
    for (int i = 0; i < cantidad; i++) {
        if (mediciones[i]->getIdMedicion() == idMedicion) {
            return &mediciones[i];
        }
    }
    return nullptr; // No encontrado
}

bool VectorMedicion::existeMedicion(int idMedicion)
{
    return buscarMedicion(idMedicion) != nullptr;
}

void VectorMedicion::mostrarMediciones()
{
    if (cantidad == 0) {
        std::cout << "No hay mediciones registradas." << std::endl;
        return;
    }

    std::cout << "=== HISTORIAL DE MEDICIONES ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << mediciones[i]->toString() << std::endl;
    }
}