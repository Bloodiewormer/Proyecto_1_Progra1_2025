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
    // clientesInscritos se inicializa por defecto
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
    if (estaLlena()) {
        return false; // Clase llena
    }

    if (clientesInscritos.existeCliente(cliente.getIdCliente())) {
        return false; // Cliente ya inscrito
    }

    return clientesInscritos.agregarCliente(&cliente);
}

Cliente* Clase::buscarCliente(int idCliente)
{
	Cliente** ptr = clientesInscritos.buscarCliente(idCliente);
	if (ptr != nullptr) {
		return *ptr;
	}
	return nullptr;

}

void Clase::mostrarClientes()
{
    std::cout << "Clientes inscritos en " << tipoClase << ":" << std::endl;
    clientesInscritos.mostrarClientes();
}

bool Clase::estaLlena() 
{
    return clientesInscritos.getCantidad() >= capacidadMaxima;
}

std::string Clase::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idClase << " | ";
    oss << "Tipo: " << tipoClase << " | ";
    oss << "Cupos: " << getCantidadInscritos() << "/" << capacidadMaxima << " | ";
    oss << "Horario: " << horario;
    return oss.str();
}

std::string Clase::toStringDetalle()
{
    std::ostringstream oss;
    oss << "=== DETALLE DE CLASE ===" << std::endl;
    oss << "ID Clase: " << idClase << std::endl;
    oss << "Tipo: " << tipoClase << std::endl;
    oss << "Capacidad Maxima: " << capacidadMaxima << std::endl;
    oss << "Cupos Disponibles: " << getCuposDisponibles() << std::endl;
    oss << "Cantidad Matriculados: " << getCantidadInscritos() << std::endl;
    oss << "Horario: " << horario << std::endl;
    oss << "Instructor: " << instructorAsignado.getNombre() << std::endl;
    return oss.str();
}