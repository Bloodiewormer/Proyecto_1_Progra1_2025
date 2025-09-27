#include "VectorEjercicio.h"

VectorEjercicio::VectorEjercicio()
{
    capacidad = 100; // Capacidad inicial para batería de ejercicios
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
            // Mover todos los elementos una posición hacia atrás
            for (int j = i; j < cantidad - 1; j++) {
                ejercicios[j] = ejercicios[j + 1];
            }
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
        std::cout << "No hay ejercicios registrados en la bateria." << std::endl;
        return;
    }

    std::cout << "=== BATERIA DE EJERCICIOS ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << ejercicios[i]->toString();
    }
}
