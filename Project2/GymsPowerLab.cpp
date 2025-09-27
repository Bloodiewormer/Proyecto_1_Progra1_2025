#include "GymsPowerLab.h"

GymsPowerLab::GymsPowerLab()
{
    nombreGym = "PowerLab Gym";
}

GymsPowerLab::~GymsPowerLab()
{
}

bool GymsPowerLab::agregarSucursal(const Sucursal& sucursal)
{
	if (existeSucursal(sucursal.getIdSucursal())) {
		return false; 
	}
	Sucursal* nuevaSucursal = new Sucursal(sucursal);
	return sucursales.agregarSucursal(nuevaSucursal);
  

}

Sucursal* GymsPowerLab::buscarSucursal(int idSucursal)
{
	Sucursal** suc = sucursales.buscarSucursal(idSucursal);
	if (suc != nullptr) {
		return *suc;
	}
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
    // Verificar que no exista la cédula en ninguna sucursal
    if (existeIDPersona(cliente.getIdCliente())) {
        return false; // Cédula ya existe
    }

    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) {
        return false; // Sucursal no existe
    }

    return sucursal->agregarCliente(cliente);
}

bool GymsPowerLab::agregarInstructorASucursal(int idSucursal, Instructor& instructor)
{
    // Verificar que no exista la cédula en ninguna sucursal
    if (existeIDPersona(instructor.getIdInstructor())) {
        return false; // Cédula ya existe
    }

    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) {
        return false; // Sucursal no existe
    }

    return sucursal->agregarInstructor(instructor);
}

bool GymsPowerLab::agregarClaseASucursal(int idSucursal, Clase& clase)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) {
        return false; // Sucursal no existe
    }

    return sucursal->agregarClase(clase);
}

Cliente* GymsPowerLab::buscarClienteEnTodasSucursales(int idCliente)
{
	for (int i = 0; i < 30; i++) { // Máximo 30 sucursales
		Sucursal** sucursal = sucursales.buscarSucursal(i + 1);
		if (sucursal != nullptr) {
			Cliente* cliente = (*sucursal)->buscarCliente(idCliente);
			if (cliente != nullptr) {
				return cliente; // Cliente encontrado
			}
		}

	}
	return nullptr; // Cliente no encontrado




}

Instructor* GymsPowerLab::buscarInstructorEnTodasSucursales(int idInstructor)
{
	for (int i = 0; i < 30; i++) { // Máximo 30 sucursales
		Sucursal** sucursal = sucursales.buscarSucursal(i + 1);
		if (sucursal != nullptr) {
			Instructor* instructor = (*sucursal)->buscarInstructor(idInstructor);
			if (instructor != nullptr) {
				return instructor; // Instructor encontrado
			}
		}
	}
	return nullptr; // Instructor no encontrado

}

bool GymsPowerLab::matricularClienteEnClase(int idSucursal, int idCliente, int idClase)
{
	Sucursal* sucursal = buscarSucursal(idSucursal);
	if (sucursal == nullptr) {
		return false; // Sucursal no existe
	}
	Cliente* cliente = sucursal->buscarCliente(idCliente);
	if (cliente == nullptr) {
		return false; // Cliente no existe en la sucursal
	}
	Clase* clase = sucursal->buscarClase(idClase);
	if (clase == nullptr) {
		return false; // Clase no existe en la sucursal
	}
	return clase->agregarCliente(*cliente);
}

void GymsPowerLab::mostrarClientesPorSucursal(int idSucursal)
{
	Sucursal* sucursal = buscarSucursal(idSucursal);
	if (sucursal != nullptr) {
		sucursal->mostrarClientes();
	}
	else {
		std::cout << "Sucursal con ID " << idSucursal << " no encontrada." << std::endl;
	}
}

void GymsPowerLab::mostrarInstructoresPorSucursal(int idSucursal)
{
	Sucursal* sucursal = buscarSucursal(idSucursal);
	if (sucursal != nullptr) {
		sucursal->mostrarInstructores();
	}
	else {
		std::cout << "Sucursal con ID " << idSucursal << " no encontrada." << std::endl;
	}
}


void GymsPowerLab::reporteIMCPorSucursal(int idSucursal)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal != nullptr) {
        std::cout << "=== Reporte IMC - Sucursal " << idSucursal << " ===" << std::endl;
        // Implementation for IMC report - this would need specific logic
        // to iterate through clients and show their BMI information
        std::cout << "Funcionalidad de reporte IMC pendiente de implementar." << std::endl;
    }
    else {
        std::cout << "Sucursal no encontrada." << std::endl;
    }
}



bool GymsPowerLab::existeSucursal(int idSucursal)
{
    return sucursales.existeSucursal(idSucursal);
}

bool GymsPowerLab::existeIDPersona(int id)
{
    // Buscar en todas las sucursales si existe el ID (cliente o instructor)
    for (int i = 0; i < 30; i++) { // Máximo 30 sucursales
		Sucursal** sucursal = sucursales.buscarSucursal(i + 1);
		if (sucursal != nullptr) {
			if ((*sucursal)->buscarCliente(id) != nullptr) {
				return true; // ID encontrado como cliente
			}
			if ((*sucursal)->buscarInstructor(id) != nullptr) {
				return true; // ID encontrado como instructor
			}
		}
 
    }
    return false;
}