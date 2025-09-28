// cpp
// File: 'Project2/GymsPowerLab.cpp'
#include "GymsPowerLab.h"

GymsPowerLab::GymsPowerLab()
{
    nombreGym = "PowerLab Gym";
}

GymsPowerLab::~GymsPowerLab()
{
}

bool GymsPowerLab::agregarSucursal(Sucursal* sucursal)
{
    if (sucursal == nullptr) return false;
    if (existeSucursal(sucursal->getIdSucursal())) return false;
    return sucursales.agregarSucursal(sucursal);
}

Sucursal* GymsPowerLab::buscarSucursal(int idSucursal)
{
    Sucursal** suc = sucursales.buscarSucursal(idSucursal);
    if (suc != nullptr) return *suc;
    return nullptr;
}

void GymsPowerLab::mostrarSucursales()
{
    sucursales.mostrarSucursales();
}

std::string GymsPowerLab::getNombreGym() const
{
    return nombreGym;
}

void GymsPowerLab::setNombreGym(const std::string& nombre)
{
    nombreGym = nombre;
}

bool GymsPowerLab::agregarClienteASucursal(int idSucursal, Cliente& cliente)
{
    if (existeIDPersona(cliente.getIdCliente())) return false;
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) return false;
    return sucursal->agregarCliente(cliente);
}

bool GymsPowerLab::agregarInstructorASucursal(int idSucursal, Instructor& instructor)
{
    if (existeIDPersona(instructor.getIdInstructor())) return false;
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) return false;
    return sucursal->agregarInstructor(instructor);
}

bool GymsPowerLab::agregarClaseASucursal(int idSucursal, Clase& clase)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) return false;
    return sucursal->agregarClase(clase);
}

Cliente* GymsPowerLab::buscarClienteEnTodasSucursales(int idCliente)
{
    for (int i = 0; i < 30; i++) {
        Sucursal** sucursal = sucursales.buscarSucursal(i + 1);
        if (sucursal != nullptr) {
            Cliente* cliente = (*sucursal)->buscarCliente(idCliente);
            if (cliente != nullptr) return cliente;
        }
    }
    return nullptr;
}

Instructor* GymsPowerLab::buscarInstructorEnTodasSucursales(int idInstructor)
{
    for (int i = 0; i < 30; i++) {
        Sucursal** sucursal = sucursales.buscarSucursal(i + 1);
        if (sucursal != nullptr) {
            Instructor* instructor = (*sucursal)->buscarInstructor(idInstructor);
            if (instructor != nullptr) return instructor;
        }
    }
    return nullptr;
}

bool GymsPowerLab::matricularClienteEnClase(int idSucursal, int idCliente, int idClase)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) return false;
    Cliente* cliente = sucursal->buscarCliente(idCliente);
    if (cliente == nullptr) return false;
    Clase* clase = sucursal->buscarClase(idClase);
    if (clase == nullptr) return false;
    return clase->agregarCliente(*cliente);
}

void GymsPowerLab::mostrarClientesPorSucursal(int idSucursal)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal != nullptr) sucursal->mostrarClientes();
    else std::cout << "Sucursal con ID " << idSucursal << " no encontrada." << std::endl;
}

void GymsPowerLab::mostrarInstructoresPorSucursal(int idSucursal)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal != nullptr) sucursal->mostrarInstructores();
    else std::cout << "Sucursal con ID " << idSucursal << " no encontrada." << std::endl;
}

void GymsPowerLab::reporteIMCPorSucursal(int idSucursal)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal != nullptr) {
        std::cout << "=== Reporte IMC - Sucursal " << idSucursal << " ===" << std::endl;
        std::cout << "Funcionalidad de reporte IMC pendiente de implementar." << std::endl;
    } else {
        std::cout << "Sucursal no encontrada." << std::endl;
    }
}

bool GymsPowerLab::existeSucursal(int idSucursal)
{
    return sucursales.existeSucursal(idSucursal);
}

bool GymsPowerLab::existeIDPersona(int id)
{
    for (int i = 0; i < 30; i++) {
        Sucursal** sucursal = sucursales.buscarSucursal(i + 1);
        if (sucursal != nullptr) {
            if ((*sucursal)->buscarCliente(id) != nullptr) return true;
            if ((*sucursal)->buscarInstructor(id) != nullptr) return true;
        }
    }
    return false;
}
