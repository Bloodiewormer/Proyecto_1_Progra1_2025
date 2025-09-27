#include "VectorSucursales.h"

VectorSucursales::VectorSucursales()
{
    capacidad = 30; // Máximo 30 sucursales según el proyecto
    cantidad = 0;
    sucursales = new Sucursal * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        sucursales[i] = nullptr;
    }
}

VectorSucursales::~VectorSucursales()
{
    delete[] sucursales;
}

bool VectorSucursales::agregarSucursal(Sucursal* sucursal)
{
    if (cantidad >= capacidad) return false; // No hay espacio
    if (existeSucursal(sucursal->getIdSucursal())) return false; // ID repetido

    sucursales[cantidad] = sucursal;
    cantidad++;
    return true;
}

bool VectorSucursales::eliminarSucursal(int idSucursal)
{
    for (int i = 0; i < cantidad; i++) {
        if (sucursales[i]->getIdSucursal() == idSucursal) {
            // Mover todos los elementos una posición hacia atrás
            for (int j = i; j < cantidad - 1; j++) {
                sucursales[j] = sucursales[j + 1];
            }
            cantidad--;
            return true;
        }
    }
    return false; // No encontrado
}

Sucursal** VectorSucursales::buscarSucursal(int idSucursal)
{
    for (int i = 0; i < cantidad; i++) {
        if (sucursales[i]->getIdSucursal() == idSucursal) {
            return &sucursales[i];
        }
    }
    return nullptr; // No encontrado
}

bool VectorSucursales::existeSucursal(int idSucursal)
{
    return buscarSucursal(idSucursal) != nullptr;
}

void VectorSucursales::mostrarSucursales()
{
    if (cantidad == 0) {
        std::cout << "No hay sucursales registradas." << std::endl;
        return;
    }

    std::cout << "=== LISTA DE SUCURSALES ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << sucursales[i]->toString() << std::endl;
    }
}
