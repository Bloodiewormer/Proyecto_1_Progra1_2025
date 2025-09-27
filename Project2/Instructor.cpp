#include "Instructor.h"

Instructor::Instructor()
{
    idInstructor = 0;
    nombre = "";
    correoElectronico = "";
    telefono = "";
    fechaNacimiento = "";
}

Instructor::Instructor(int id, std::string& nombre, std::string& correo, std::string& telefono, std::string& fechaNac)
{
    idInstructor = id;
    this->nombre = nombre;
    correoElectronico = correo;
    this->telefono = telefono;
    fechaNacimiento = fechaNac;
}

Instructor::~Instructor()
{
}

int Instructor::getIdInstructor() const
{
    return idInstructor;
}

std::string Instructor::getNombre() const
{
    return nombre;
}

bool Instructor::agregarEspecialidad(std::string especialidad)
{
    return especialidades.agregarString(especialidad);
}

void Instructor::mostrarEspecialidades()
{
    especialidades.mostrarStrings();
}

bool Instructor::tieneEspecialidad(std::string especialidad)
{
	for (int i = 0; i < especialidades.getCantidad(); i++) {
		if (especialidades.buscarString(especialidad)) {
			return true;
		}
	}
	return false;
}

std::string Instructor::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idInstructor << "\n";
    oss << "Nombre: " << nombre << "\n";
    oss << "Correo: " << correoElectronico << "\n";
    oss << "Telefono: " << telefono << "\n";
    oss << "Fecha de Nacimiento: " << fechaNacimiento << "\n";
    return oss.str();
}

std::string Instructor::toStringDetalle()
{
    std::ostringstream oss;
    oss << toString();
    oss << "Especialidades:\n";
    especialidades.mostrarStrings();
    return oss.str();
}