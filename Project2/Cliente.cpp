#include "Cliente.h"

Cliente::Cliente()
{
    idCliente = 0;
    nombre = "";
    correoElectronico = "";
    telefono = "";
    fechaNacimiento = Fecha();
    genero = ' ';
    fechaInscripcion = Fecha();
    instructorAsignado = nullptr;
    cantRutina = 0;
    for (int i = 0; i < 20; i++) rutina[i] = nullptr;
}

Cliente::Cliente(int id, std::string& nombre, std::string& correo, std::string& telefono, Fecha& fechaNac, char genero, Fecha& fechaIns)
{
    idCliente = id;
    this->nombre = nombre;
    correoElectronico = correo;
    this->telefono = telefono;
    fechaNacimiento = fechaNac;
    this->genero = genero;
    fechaInscripcion = fechaIns;
    instructorAsignado = nullptr;
    cantRutina = 0;
    for (int i = 0; i < 20; i++) rutina[i] = nullptr;
}

Cliente::~Cliente() {}

int Cliente::getIdCliente() { return idCliente; }
void Cliente::setIdCliente(int id) { idCliente = id; }
std::string Cliente::getNombre() { return nombre; }
void Cliente::setNombre(std::string& nombre) { this->nombre = nombre; }


void Cliente::setInstructorAsignado(Instructor* instr) { instructorAsignado = instr; }
Instructor* Cliente::getInstructorAsignado() { return instructorAsignado; }

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
    if (med != nullptr) return *med;
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

int Cliente::getCantidadMediciones()
{
    return historicoMediciones.getCantidad();
}

ReporteMedicion* Cliente::getMedicionPorIndice(int i)
{
    return historicoMediciones.getMedicionPorIndice(i);
}


void Cliente::mostrarHistorialMedicionesOrdenado()
{
    int n = getCantidadMediciones();
    if (n == 0) {
        std::cout << "(sin mediciones)\n";
        return;
    }
    ReporteMedicion* arr[100];
    for (int i = 0; i < n; i++) arr[i] = getMedicionPorIndice(i);
    // bubble sort por fecha ascendente
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {


        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i]->toString() << std::endl;
    }
}

ReporteMedicion* Cliente::obtenerUltimaMedicion()
{
return historicoMediciones.getMedicionPorIndice( getCantidadMediciones() - 1 );

}

void Cliente::limpiarRutina()
{
    for (int i = 0; i < 20; i++) rutina[i] = nullptr;
    cantRutina = 0;
}

bool Cliente::agregarEjercicioARutina(Ejercicio* e)
{
    if (e == nullptr) return false;
    if (cantRutina >= 20) return false;
    rutina[cantRutina++] = e;
    return true;
}

void Cliente::mostrarRutina()
{
    std::cout << "=== Rutina de " << nombre << " ===\n";
    if (cantRutina == 0) {
        std::cout << "(sin ejercicios)\n";
        return;
    }
    for (int i = 0; i < cantRutina; i++) {
        if (rutina[i] != nullptr) std::cout << "- " << rutina[i]->toStringDetalle();
    }
}




std::string Cliente::toString()
{
    std::ostringstream oss;
    oss << "ID: " << idCliente << "\n";
    oss << "Nombre: " << nombre << "\n";
    oss << "Correo Electronico: " << correoElectronico << "\n";
    oss << "Telefono: " << telefono << "\n";
    oss << "Fecha de Nacimiento: " << fechaNacimiento.toString() << "\n";
    oss << "Genero: " << genero << "\n";
    oss << "Fecha de Inscripcion: " << fechaInscripcion.toString() << "\n";
    oss << "Instructor asignado: " << (instructorAsignado == nullptr ? "N/A" : instructorAsignado->getNombre()) << "\n";
    return oss.str();
}



std::string Cliente::toStringDetalle()
{
    std::ostringstream oss;
    oss << toString();
    oss << "Historial de Mediciones (ordenadas por fecha):\n";





	return oss.str();
}

std::string Cliente::toStringCorto()
{
    std::ostringstream oss;
    oss << "ID: " << idCliente << " | " << nombre<<std::endl;
    return oss.str();
}
