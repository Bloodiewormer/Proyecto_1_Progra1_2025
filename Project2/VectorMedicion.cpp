#include "VectorMedicion.h"

VectorMedicion::VectorMedicion()
{
    capacidad = 10; // Máximo 10 mediciones según el proyecto
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

bool VectorMedicion::agregarMedicion(ReporteMedicion* medicion)
{
    if (cantidad >= capacidad) return false; // Máximo 10 mediciones
    if (existeMedicion(medicion->getIdMedicion())) return false; // ID repetido

    mediciones[cantidad] = medicion;
    cantidad++;
    return true;
}

bool VectorMedicion::eliminarMedicion(int idMedicion)
{
    for (int i = 0; i < cantidad; i++) {
        if (mediciones[i]->getIdMedicion() == idMedicion) {
            // Mover todos los elementos una posición hacia atrás
            for (int j = i; j < cantidad - 1; j++) {
                mediciones[j] = mediciones[j + 1];
            }
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
