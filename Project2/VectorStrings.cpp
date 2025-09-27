#include "VectorStrings.h"

VectorStrings::VectorStrings()
{
    capacidad = 10;
    cantidad = 0;
    elementos = new std::string[capacidad];
    // No need to initialize std::string elements to nullptr; they are default constructed as empty strings
}

VectorStrings::~VectorStrings()
{
    if (elementos != nullptr) {
        delete[] elementos;
        elementos = nullptr;
    }
}

bool VectorStrings::buscarString(std::string s)
{
    for (int i = 0; i < cantidad; ++i) {
        if (elementos[i] == s) {
            return true;
        }
    }
    return false;
}

int VectorStrings::getCantidad()
{
    return cantidad;
}

bool VectorStrings::agregarString(std::string str)
{
    if (cantidad >= capacidad) return false;
    elementos[cantidad] = str;
    cantidad++;
    return true;
}

void VectorStrings::mostrarStrings()
{
    if (cantidad == 0) {
        std::cout << "No hay elementos en el vector." << std::endl;
        return;
    }
    std::cout << "=== LISTA DE STRINGS ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << elementos[i] << std::endl;
    }
}