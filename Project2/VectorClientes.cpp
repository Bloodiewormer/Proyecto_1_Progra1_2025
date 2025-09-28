#include "VectorClientes.h"

VectorClientes::VectorClientes()
{
    capacidad = 100; // Capacidad inicial generosa
    cantidad = 0;
    clientes = new Cliente * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        clientes[i] = nullptr;
    }
}

VectorClientes::~VectorClientes()
{
    delete[] clientes;
}

int VectorClientes::getCantidad()
{
    return cantidad;
}

bool VectorClientes::agregarCliente(Cliente* cliente)
{
    if (cantidad >= capacidad) return false; // No hay espacio
    if (existeCliente(cliente->getIdCliente())) return false; // ID repetido

    clientes[cantidad] = cliente;
    cantidad++;
    return true;
}


Cliente** VectorClientes::buscarCliente(int idCliente)
{
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getIdCliente() == idCliente) {
            return &clientes[i];
        }
    }
    return nullptr; // No encontrado
}

bool VectorClientes::existeCliente(int idCliente)
{
    return buscarCliente(idCliente) != nullptr;
}

void VectorClientes::mostrarClientes()
{
    if (cantidad == 0) {
        std::cout << "No hay clientes registrados." << std::endl;
        return;
    }

    std::cout << "=== LISTA DE CLIENTES ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        std::cout << i + 1 << ". " << clientes[i]->toString() << std::endl;
    }
}
