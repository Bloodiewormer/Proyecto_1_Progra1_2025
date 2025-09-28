#include "Clase.h"

Clase::Clase()
{
    idClase = 0;
    tipoClase = "";
    capacidadMaxima = 0;
    horario = "";
    // instructorAsignado se inicializa por defecto
    // clientesInscritos se inicializa por defecto
}

Clase::Clase(int id, std::string& tipo, int capacidad, std::string& horario, Instructor& instructor)
{
    idClase = id;
    tipoClase = tipo;
    capacidadMaxima = capacidad;
    this->horario = horario;
    instructorAsignado = instructor;
}

Clase::~Clase()
{
}

int Clase::getIdClase() 
{
    return idClase;
}

std::string Clase::getTipoClase() 
{
    return tipoClase;
}

int Clase::getCapacidadMaxima() 
{
    return capacidadMaxima;
}

int Clase::getCuposDisponibles() 
{
	return capacidadMaxima - clientesInscritos.getCantidad();
}

int Clase::getCantidadInscritos() 
{
    return clientesInscritos.getCantidad();
}

Instructor Clase::getInstructor() 
{
    return instructorAsignado;
}

bool Clase::agregarCliente(Cliente& cliente)
{
    if (estaLlena()) return false;
    Cliente* ya = buscarCliente(cliente.getIdCliente());
    if (ya != nullptr) return false;
    bool ok = clientesInscritos.agregarCliente(&cliente);
    if (ok) {
        // asignar instructor si el cliente no tiene
        if (cliente.getInstructorAsignado() == nullptr) {
            cliente.setInstructorAsignado(&instructorAsignado);
        }
    }
    return ok;
}

Cliente* Clase::buscarCliente(int idCliente)
{
    Cliente** c = clientesInscritos.buscarCliente(idCliente);
    if (c != nullptr) return *c;
    return nullptr;

}

void Clase::mostrarClientes()
{
    clientesInscritos.mostrarClientes();
}

bool Clase::estaLlena() 
{
    return clientesInscritos.getCantidad() >= capacidadMaxima;
}

bool Clase::tieneCliente(int idCliente)
{
    return buscarCliente(idCliente) != nullptr;
}

std::string Clase::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idClase << " | ";
    oss << "Tipo: " << tipoClase << " | ";
    oss << "Horario: " << horario << " | ";
    oss << "Instructor: " << instructorAsignado.getNombre() << " | ";
    oss << "Cupo: " << getCantidadInscritos() << "/" << capacidadMaxima;
    return oss.str();
}

std::string Clase::toStringDetalle()
{
    std::ostringstream oss;
    oss << "=== DETALLE DE CLASE ===\n";
    oss << "ID: " << idClase << "\n";
    oss << "Tipo: " << tipoClase << "\n";
    oss << "Horario: " << horario << "\n";
    oss << "Instructor: " << instructorAsignado.getNombre() << "\n";
    oss << "Capacidad max: " << capacidadMaxima << "\n";
    oss << "Matriculados: " << getCantidadInscritos() << "\n";
    oss << "Cupos disponibles: " << getCuposDisponibles() << "\n";
    oss << "--- Participantes ---\n";
    if (getCantidadInscritos() == 0) {
        oss << "(sin clientes)\n";
    } else {
        oss << "Clientes inscritos:\n";
        clientesInscritos.mostrarClientes();
    }
    return oss.str();
}