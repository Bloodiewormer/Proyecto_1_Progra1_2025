#include "GymsPowerLab.h"

GymsPowerLab::GymsPowerLab()
{
    nombreGym = "PowerLab Gym";
}

GymsPowerLab::~GymsPowerLab() {}

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

void GymsPowerLab::mostrarSucursales() { sucursales.mostrarSucursales(); }

std::string GymsPowerLab::getNombreGym() const { return nombreGym; }
void GymsPowerLab::setNombreGym(const std::string& nombre) { nombreGym = nombre; }

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

bool GymsPowerLab::existeSucursal(int idSucursal) { return sucursales.existeSucursal(idSucursal); }

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

void GymsPowerLab::mostrarClasesPorSucursal(int idSucursal)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal != nullptr) sucursal->mostrarClases();
    else std::cout << "Sucursal con ID " << idSucursal << " no encontrada." << std::endl;
}

void GymsPowerLab::mostrarClientesPorInstructor(int idInstructor)
{
    std::cout << "=== Clientes del Instructor " << idInstructor << " ===\n";
    bool alguno = false;
    for (int s = 0; s < 30; s++) {
        Sucursal** ps = sucursales.buscarSucursal(s + 1);
        if (ps == nullptr) continue;
        Sucursal* suc = *ps;

        int n = suc->getCantidadClases();
        for (int i = 0; i < n; i++) {
            Clase* c = suc->getClasePorIndice(i);
            if (c == nullptr) continue;
            // Se asume que Clase expone getInstructor() y toStringDetalle()/mostrarClientes()
            if (c->getInstructor().getIdInstructor() == idInstructor) {
                std::cout << c->toStringDetalle() << "\n";
                c->mostrarClientes();
                alguno = true;
            }
        }
    }
    if (!alguno) std::cout << "(sin clientes)\n";
}

int GymsPowerLab::getCantidadClasesEnSucursal(int idSucursal)
{
    Sucursal* suc = buscarSucursal(idSucursal);
    if (suc == nullptr) return 0;
    return suc->getCantidadClases();
}

void GymsPowerLab::mostrarInstructoresPorEspecialidad(std::string especialidad)
{
    std::cout << "=== Instructores con especialidad: " << especialidad << " ===\n";
    bool alguno = false;
    for (int s = 0; s < 30; s++) {
        Sucursal** ps = sucursales.buscarSucursal(s + 1);
        if (ps == nullptr) continue;
        Sucursal* suc = *ps;

        int m = suc->getCantidadInstructores();
        for (int i = 0; i < m; i++) {
            Instructor* inst = suc->getInstructorPorIndice(i);
            if (inst != nullptr && inst->tieneEspecialidad(especialidad)) {
                std::cout << inst->toString() << "\n";
                alguno = true;
            }
        }
    }
    if (!alguno) std::cout << "(sin instructores)\n";
}

void GymsPowerLab::mostrarClasesDeCliente(int idCliente)
{
    std::cout << "=== Clases del Cliente " << idCliente << " ===\n";
    bool alguno = false;
    for (int s = 0; s < 30; s++) {
        Sucursal** ps = sucursales.buscarSucursal(s + 1);
        if (ps == nullptr) continue;
        Sucursal* suc = *ps;

        int n = suc->getCantidadClases();
        for (int i = 0; i < n; i++) {
            Clase* c = suc->getClasePorIndice(i);
            if (c == nullptr) continue;
            // Se asume que Clase expone buscarCliente(id)
            Cliente* cli = c->buscarCliente(idCliente);
            if (cli != nullptr) {
                std::cout << c->toStringDetalle() << "\n";
                alguno = true;
            }
        }
    }
    if (!alguno) std::cout << "(sin clases)\n";
}

void GymsPowerLab::reporteIMCPorSucursal(int idSucursal)
{
    Sucursal* sucursal = buscarSucursal(idSucursal);
    if (sucursal == nullptr) {
        std::cout << "Sucursal no encontrada.\n";
        return;
    }

    std::cout << "=== Reporte IMC - Sucursal " << idSucursal << " ===\n";
    int bajo = 0, normal = 0, sobre = 0, obes = 0;

    int c = sucursal->getCantidadClientes();
    for (int i = 0; i < c; i++) {
        Cliente* cli = sucursal->getClientePorIndice(i);
        if (cli == nullptr) continue;


         float imc = cli->getUltimaMedicion()->getIMC();
        // Clasificar
        if (imc >= 0.0f) {
            if (imc < 18.5f) bajo++;
            else if (imc < 25.0f) normal++;
            else if (imc < 30.0f) sobre++;
            else obes++;
        }
    }

    std::cout << "Bajo peso: " << bajo << "\n";
    std::cout << "Normal: " << normal << "\n";
    std::cout << "Sobrepeso: " << sobre << "\n";
    std::cout << "Obesidad: " << obes << "\n";
}
