// C++
#include "Instructor.h"

Instructor::Instructor()
{
    idInstructor = 0;
    nombre = "";
    correoElectronico = "";
    telefono = "";
    fechaNacimiento = Fecha();
    for (int i = 0; i < 10; i++) especialidades[i] = "";
}

Instructor::Instructor(int id, std::string& nombre, std::string& correo, std::string& telefono, Fecha& fechaNac)
{
    idInstructor = id;
    this->nombre = nombre;
    correoElectronico = correo;
    this->telefono = telefono;
    fechaNacimiento = fechaNac;
    for (int i = 0; i < 10; i++) especialidades[i] = "";
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

bool Instructor::especialidadValida(std::string e)
{
    std::string esp[8] = { "CrossFit","HIIT","TRX","Pesas","Spinning","Cardio","Yoga","Zumba" };
    for (int i = 0; i < 8; i++) if (e == esp[i]) return true;
    return false;
}

bool Instructor::agregarEspecialidad(std::string especialidad)
{
    if (!especialidadValida(especialidad)) return false;
    for (int i = 0; i < 10; i++) {
        if (especialidades[i].empty()) {
            especialidades[i] = especialidad;
            return true;
        }
    }
    return false;
}



void Instructor::mostrarEspecialidades()
{
    for (int i = 0; i < 10; i++) {
        if (!especialidades[i].empty()) {
            std::cout << especialidades[i] << std::endl;
        }
    }
}

bool Instructor::tieneEspecialidad(std::string especialidad)
{
    for (int i = 0; i < 10; i++) {
        if (especialidades[i] == especialidad) return true;
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
    oss << "Fecha de Nacimiento: " << fechaNacimiento.toString() << "\n";
    return oss.str();
}

std::string Instructor::toStringDetalle()
{
    std::ostringstream oss;
    oss << toString();
    oss << "Especialidades:\n";
    for (int i = 0; i < 10; i++) {
        if (!especialidades[i].empty()) oss << " - " << especialidades[i] << "\n";
    }
    return oss.str();
}
