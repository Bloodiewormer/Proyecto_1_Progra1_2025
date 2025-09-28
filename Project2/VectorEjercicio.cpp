#include "VectorEjercicio.h"

VectorEjercicio::VectorEjercicio()
{
    capacidad = 50; // Capacidad para ejercicios
    cantidad = 0;
    ejercicios = new Ejercicio * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        ejercicios[i] = nullptr;
    }
}

VectorEjercicio::~VectorEjercicio()
{
    delete[] ejercicios;
}

int VectorEjercicio::getCantidad()
{
    return cantidad;
}

Ejercicio* VectorEjercicio::getEjercicioPorIndice(int i)
{
    if (i < 0 || i >= cantidad) return nullptr;
    return ejercicios[i];
}

bool VectorEjercicio::agregarEjercicio(Ejercicio* ejercicio)
{
    if (cantidad >= capacidad) return false; // No hay espacio
    if (existeEjercicio(ejercicio->getIdEjercicio())) return false; // ID repetido

    ejercicios[cantidad] = ejercicio;
    cantidad++;
    return true;
}

bool VectorEjercicio::eliminarEjercicio(int idEjercicio)
{
    for (int i = 0; i < cantidad; i++) {
        if (ejercicios[i]->getIdEjercicio() == idEjercicio) {
            for (int j = i; j < cantidad - 1; j++) {
                ejercicios[j] = ejercicios[j + 1];
            }
            ejercicios[cantidad - 1] = nullptr;
            cantidad--;
            return true;
        }
    }
    return false; // No encontrado
}

Ejercicio** VectorEjercicio::buscarEjercicio(int idEjercicio)
{
    for (int i = 0; i < cantidad; i++) {
        if (ejercicios[i]->getIdEjercicio() == idEjercicio) {
            return &ejercicios[i];
        }
    }
    return nullptr; // No encontrado
}

bool VectorEjercicio::existeEjercicio(int idEjercicio)
{
    return buscarEjercicio(idEjercicio) != nullptr;
}

void VectorEjercicio::mostrarEjercicios()
{
    if (cantidad == 0) {
        std::cout << "No hay ejercicios registrados." << std::endl;
        return;
    }

    std::cout << "=== LISTA DE EJERCICIOS ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << ejercicios[i]->toString() << std::endl;
    }
}