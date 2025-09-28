#include "VectorInstructores.h"

VectorInstructores::VectorInstructores()
{
    capacidad = 50; // Capacidad para instructores
    cantidad = 0;
    instructores = new Instructor * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        instructores[i] = nullptr;
    }
}

VectorInstructores::~VectorInstructores()
{
    delete[] instructores;
}

int VectorInstructores::getCantidad()
{
    return cantidad;
}

Instructor* VectorInstructores::getInstructorPorIndice(int i)
{
    if (i < 0 || i >= cantidad) return nullptr;
    return instructores[i];
}

bool VectorInstructores::agregarInstructor(Instructor* instructor)
{
    if (cantidad >= capacidad) return false; // No hay espacio
    if (existeInstructor(instructor->getIdInstructor())) return false; // ID repetido

    instructores[cantidad] = instructor;
    cantidad++;
    return true;
}

bool VectorInstructores::eliminarInstructor(int idInstructor)
{
    for (int i = 0; i < cantidad; i++) {
        if (instructores[i]->getIdInstructor() == idInstructor) {
            // Mover elementos hacia la izquierda
            for (int j = i; j < cantidad - 1; j++) {
                instructores[j] = instructores[j + 1];
            }
            instructores[cantidad - 1] = nullptr;
            cantidad--;
            return true;
        }
    }
    return false; // No encontrado
}

Instructor** VectorInstructores::buscarInstructor(int idInstructor)
{
    for (int i = 0; i < cantidad; i++) {
        if (instructores[i]->getIdInstructor() == idInstructor) {
            return &instructores[i];
        }
    }
    return nullptr; // No encontrado
}

bool VectorInstructores::existeInstructor(int idInstructor)
{
    return buscarInstructor(idInstructor) != nullptr;
}

void VectorInstructores::mostrarInstructores()
{
    if (cantidad == 0) {
        std::cout << "No hay instructores registrados." << std::endl;
        return;
    }

    std::cout << "=== LISTA DE INSTRUCTORES ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << instructores[i]->toString() << std::endl;
    }
}