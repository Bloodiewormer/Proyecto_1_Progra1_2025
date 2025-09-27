#include "Cliente.h"

Cliente::Cliente()
{
	idCliente = 0;
	nombre = "";
	correoElectronico = "";
	telefono = "";
	fechaNacimiento = "";
	genero = ' ';
	fechaInscripcion = "";

}

Cliente::Cliente(int id, std::string& nombre, std::string& correo, std::string& telefono, std::string& fechaNac, char genero, std::string& fechaIns)
{
	idCliente = id;
	this->nombre = nombre;
	correoElectronico = correo;
	this->telefono = telefono;
	fechaNacimiento = fechaNac;
	this->genero = genero;
	fechaInscripcion = fechaIns;
}

Cliente::~Cliente()
{
}

int Cliente::getIdCliente()
{
	return idCliente;
}

void Cliente::setIdCliente(int id)
{
	idCliente = id;
}

std::string Cliente::getNombre()
{
	return nombre;
}

void Cliente::setNombre(std::string& nombre)
{
	this->nombre = nombre;
}

std::string Cliente::getCorreoElectronico()
{
	return correoElectronico;
}

void Cliente::setCorreoElectronico(std::string& correo)
{
	correoElectronico = correo;
}

std::string Cliente::getTelefono()
{
	return telefono;
}

void Cliente::setTelefono(std::string& telefono)
{
	this->telefono = telefono;
}

std::string Cliente::getFechaNacimiento()
{
	return fechaNacimiento;
}

void Cliente::setFechaNacimiento(std::string& fecha)
{
	fechaNacimiento = fecha;
}

char Cliente::getGenero()
{
	return genero;
}

void Cliente::setGenero(char genero)
{
	this->genero = genero;
}

std::string Cliente::getFechaInscripcion()
{
	return fechaInscripcion;
}

void Cliente::setFechaInscripcion(std::string& fecha)
{
	fechaInscripcion = fecha;
}

bool Cliente::agregarMedicion(ReporteMedicion& medicion)
{
	return historicoMediciones.agregarMedicion(&medicion);
}

bool Cliente::eliminarMedicion(int idMedicion)
{
	return historicoMediciones.eliminarMedicion(idMedicion);
}

ReporteMedicion* Cliente::buscarMedicion(int idMedicion)
{
	ReporteMedicion** med = historicoMediciones.buscarMedicion(idMedicion);
	if (med != nullptr) {
		return *med;
	}
	return nullptr;

}

bool Cliente::existeMedicion(int idMedicion)
{
	return historicoMediciones.existeMedicion(idMedicion);
}

void Cliente::mostrarHistorialMediciones()
{
	historicoMediciones.mostrarMediciones();
}

std::string Cliente::toString()
{
	std::ostringstream oss;
	oss << "ID: " << idCliente << "\n";
	oss << "Nombre: " << nombre << "\n";
	oss << "Correo Electronico: " << correoElectronico << "\n";
	oss << "Telefono: " << telefono << "\n";
	oss << "Fecha de Nacimiento: " << fechaNacimiento << "\n";
	oss << "Genero: " << genero << "\n";
	oss << "Fecha de Inscripcion: " << fechaInscripcion << "\n";
	return oss.str();
}

std::string Cliente::toStringDetalle()
{
	std::ostringstream oss;
	oss << toString();
	oss << "Historial de Mediciones:\n";
	historicoMediciones.mostrarMediciones();
	return oss.str();
}


