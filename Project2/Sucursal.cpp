#include "Sucursal.h"

Sucursal::Sucursal()
{
    idSucursal = 0;
    provincia = "";
    canton = "";
    correoElectronico = "";
    telefono = "";
}

Sucursal::Sucursal(int id, std::string& provincia, std::string& canton, std::string& correo, std::string& telefono)
{
    idSucursal = id;
    this->provincia = provincia;
    this->canton = canton;
    correoElectronico = correo;
    this->telefono = telefono;
}

Sucursal::~Sucursal()
{
}

int Sucursal::getIdSucursal()
{
    return idSucursal;
}

int Sucursal::getCantidadClases()
{
    return clases.getCantidad();
}

bool Sucursal::agregarCliente(Cliente& cliente)
{
    return clientes.agregarCliente(&cliente);
}

Cliente* Sucursal::buscarCliente(int idCliente)
{
    Cliente** cli = clientes.buscarCliente(idCliente);
    if (cli != nullptr) return *cli;
    return nullptr;
}

void Sucursal::mostrarClientes()
{
    clientes.mostrarClientes();
}

bool Sucursal::agregarInstructor(Instructor& instructor)
{
    return instructores.agregarInstructor(&instructor);
}

Instructor* Sucursal::buscarInstructor(int idInstructor)
{
    Instructor** instr = instructores.buscarInstructor(idInstructor);
    if (instr != nullptr) return *instr;
    return nullptr;
}

void Sucursal::mostrarInstructores()
{
    instructores.mostrarInstructores();
}

bool Sucursal::agregarClase(Clase& clase)
{
    if (clases.getCantidad() >= 8) return false;
    return clases.agregarClase(&clase);
}

Clase* Sucursal::buscarClase(int idClase)
{
    Clase** cls = clases.buscarClase(idClase);
    if (cls != nullptr) return *cls;
    return nullptr;
}

void Sucursal::mostrarClases()
{
    clases.mostrarClases();
}

std::string Sucursal::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idSucursal << " | ";
    oss << "Ubicacion: " << provincia << ", " << canton << " | ";
    oss << "Telefono: " << telefono;
    return oss.str();
}

std::string Sucursal::toStringDetalle()
{
    std::ostringstream oss;
    oss << "=== DETALLE DE SUCURSAL ===" << std::endl;
    oss << "ID: " << idSucursal << std::endl;
    oss << "Provincia: " << provincia << std::endl;
    oss << "Canton: " << canton << std::endl;
    oss << "Correo: " << correoElectronico << std::endl;
    oss << "Telefono: " << telefono << std::endl;
    oss << "Clientes registrados: " << clientes.getCantidad() << std::endl;
    return oss.str();
}

// NEW
int Sucursal::getCantidadClientes()
{
    return clientes.getCantidad();
}
Cliente* Sucursal::getClientePorIndice(int i)
{
    return clientes.getClientePorIndice(i);
}
int Sucursal::getCantidadInstructores()
{
    return instructores.getCantidad();
}
Instructor* Sucursal::getInstructorPorIndice(int i)
{
    return instructores.getInstructorPorIndice(i);
}
Clase* Sucursal::getClasePorIndice(int i)
{
    return clases.getClasePorIndice(i);
}
