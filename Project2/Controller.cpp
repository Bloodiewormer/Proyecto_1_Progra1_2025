
#include "Controller.h"

Controller::Controller()
{
    cantRutinas = 0;
}
Controller::~Controller() {}

void Controller::run()
{
    cargarDatosPrueba();
    interfaz.mostrarBannerBienvenida();
    int opcion;
    do {
        opcion = interfaz.mostrarMenuPrincipal();
        switch (opcion) {
        case 1: menuSucursales(); break;
        case 2: menuClientes(); break;
        case 3: menuInstructores(); break;
        case 4: menuClases(); break;
        case 5: menuMediciones(); break;
        case 6: menuInformes(); break;
        case 7: menuRutinas(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
    interfaz.mostrarBannerDespedida();
}

void Controller::menuSucursales()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuSucursales();
        switch (opcion) {
        case 1: agregarSucursal(); break;
        case 2: gym.mostrarSucursales(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

void Controller::menuClientes()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuClientes();
        switch (opcion) {
        case 1: agregarCliente(); break;
        case 2: listarClientesPorSucursal(); break;
        case 3: mostrarDetalleCliente(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

void Controller::menuInstructores()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuInstructores();
        switch (opcion) {
        case 1: agregarInstructor(); break;
        case 2: listarInstructoresPorSucursal(); break;
        case 3: mostrarDetalleInstructor(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

void Controller::menuClases()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuClases();
        switch (opcion) {
        case 1: agregarClase(); break;
        case 2: listarClasesPorSucursal(); break;
        case 3: mostrarDetalleClase(); break;
        case 4: matricularClienteEnClase(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

void Controller::menuMediciones()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuMediciones();
        switch (opcion) {
        case 1: agregarMedicion(); break;
        case 2: mostrarHistorialMediciones(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

void Controller::menuInformes()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuInformes();
        switch (opcion) {
        case 1: gym.mostrarClientesPorSucursal(interfaz.solicitarIdSucursal()); break;
        case 2: gym.mostrarInstructoresPorSucursal(interfaz.solicitarIdSucursal()); break;
        case 3: reporteIMC(); break;
        case 4: listarClientesPorInstructor(); break;
        case 5: listarInstructoresPorEspecialidad(); break;
        case 6: verClasesDeCliente() ; break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

void Controller::menuRutinas()
{
    int opcion;
    do {
        opcion = interfaz.mostrarMenuRutinas();
        switch (opcion) {
        case 1: agregarEjercicio(); break;
        case 2: generarRutina(); break;
        case 3: mostrarRutinaDeCliente(); break;
        case 0: break;
        default: interfaz.mostrarError("Opcion invalida"); break;
        }
        if (opcion != 0) interfaz.pausarPantalla();
    } while (opcion != 0);
}

// ==== Funcionalidades ====

void Controller::agregarSucursal()
{
    int id = interfaz.solicitarEntero("ID de la sucursal: ");
    std::string provincia = interfaz.solicitarCadena("Provincia: ");
    std::string canton = interfaz.solicitarCadena("Canton: ");
    std::string correo = interfaz.solicitarCadena("Correo: ");
    std::string telefono = interfaz.solicitarCadena("Telefono: ");
    Sucursal* nueva = new Sucursal(id, provincia, canton, correo, telefono);
    if (gym.agregarSucursal(nueva)) interfaz.mostrarMensaje("Sucursal agregada exitosamente.");
    else interfaz.mostrarError("No se pudo agregar la sucursal.");
}

void Controller::agregarCliente()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    if (!gym.existeSucursal(idSucursal)) {
        interfaz.mostrarError("Sucursal no encontrada.");
        return;
    }

    int id = interfaz.solicitarEntero("ID del cliente: ");
    if (gym.existeIDPersona(id)) {
        interfaz.mostrarError("ID de cliente ya existe en el sistema.");
        return;
    }
    std::string nombre = interfaz.solicitarCadena("Nombre: ");
    std::string correo = interfaz.solicitarCadena("Correo: ");
    std::string telefono = interfaz.solicitarCadena("Telefono: ");
    Fecha fechaNac = interfaz.solicitarFechaDDMMAAAA("Fecha de nacimiento");
    std::string generoStr = interfaz.solicitarCadena("Genero (M/F): ");
    char genero = generoStr.empty() ? 'M' : generoStr[0];
    Fecha fechaIns = interfaz.solicitarFechaDDMMAAAA("Fecha de inscripcion");

    Cliente* nuevo = new Cliente(id, nombre, correo, telefono, fechaNac, genero, fechaIns);
    if (gym.agregarClienteASucursal(idSucursal, *nuevo)) interfaz.mostrarMensaje("Cliente agregado exitosamente.");
    else interfaz.mostrarError("No se pudo agregar el cliente.");
}

void Controller::agregarInstructor()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    if (!gym.existeSucursal(idSucursal)) { interfaz.mostrarError("Sucursal no encontrada."); return; }

    int id = interfaz.solicitarEntero("ID del instructor: ");
    if (gym.existeIDPersona(id)) { interfaz.mostrarError("ID de instructor ya existe en el sistema."); return; }
    std::string nombre = interfaz.solicitarCadena("Nombre: ");
    std::string correo = interfaz.solicitarCadena("Correo: ");
    std::string telefono = interfaz.solicitarCadena("Telefono: ");
    Fecha fechaNac = interfaz.solicitarFechaDDMMAAAA("Fecha de nacimiento");

    Instructor* nuevo = new Instructor(id, nombre, correo, telefono, fechaNac);

    std::string esp = interfaz.solicitarCadena("Especialidad (vacio para omitir): ");
    if (!esp.empty() && validarEspecialidadInstructor(esp)) nuevo->agregarEspecialidad(esp);
    std::string esp2 = interfaz.solicitarCadena("Otra especialidad (vacio para omitir): ");
    if (!esp2.empty() && validarEspecialidadInstructor(esp2)) nuevo->agregarEspecialidad(esp2);

    if (gym.agregarInstructorASucursal(idSucursal, *nuevo)) interfaz.mostrarMensaje("Instructor agregado exitosamente.");
    else interfaz.mostrarError("No se pudo agregar el instructor.");
}

void Controller::agregarClase()
{
    // mostrar ayuda
    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();
    Sucursal* suc = gym.buscarSucursal(idSucursal);
    if (suc == nullptr) {
        interfaz.mostrarError("Sucursal no encontrada.");
        return;
    }

    suc->mostrarInstructores();
    int idInstructor = interfaz.solicitarIdInstructor();
    Instructor* instructor = suc->buscarInstructor(idInstructor);
    if (instructor == nullptr) {
        interfaz.mostrarError("Instructor no encontrado.");
        return;
    }

    int idClase = interfaz.solicitarIdClase();
    std::string tipo = interfaz.solicitarCadena("Tipo de clase: ");
    int cupo = interfaz.solicitarEntero("Cupo: ");
    std::string horario = interfaz.solicitarCadena("Horario: ");


    std::string espBase = obtenerEspecialidadDeTipo(tipo);
    if (espBase != "" && !instructor->tieneEspecialidad(espBase)) {
        interfaz.mostrarError("El instructor no posee la especialidad requerida: " + espBase);
        return;
    }

    Clase* nueva = new Clase(idClase, tipo, cupo, horario, *instructor);
    if (gym.agregarClaseASucursal(idSucursal, *nueva)) interfaz.mostrarMensaje("Clase agregada exitosamente.");
    else interfaz.mostrarError("No se pudo agregar la clase.");
}

void Controller::agregarMedicion()
{
    interfaz.limpiarPantalla();
    interfaz.mostrarTitulo("Agregar Medicion a Cliente");

    // Ayuda visual para elegir
    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.mostrarClientesPorSucursal(idSucursal);

    int idCliente = interfaz.solicitarIdCliente();
    Cliente* cliente = gym.buscarClienteEnTodasSucursales(idCliente);
    if (cliente == nullptr) {
        interfaz.mostrarError("El cliente no existe.");
        return;
    }

    ReporteMedicion rep = interfaz.crearReporteMedicion();
    ReporteMedicion* p = new ReporteMedicion(rep);
    cliente->agregarMedicion(*p);

    interfaz.mostrarMensaje("Medicion agregada correctamente.");
}

void Controller::agregarEjercicio() {
    std::cout << "--- Agregar Ejercicio ---\n";
    int id = interfaz.solicitarEntero("ID del ejercicio: ");
    std::string nombre = interfaz.solicitarCadena("Nombre: ");
    std::string area = interfaz.solicitarCadena("Area (pecho y triceps, biceps, piernas, espalda): ");
    if (!validarAreaEjercicio(area)) {
        interfaz.mostrarError("Area invalida.");
        return;
    }
    std::string descripcion = interfaz.solicitarCadena("Descripcion: ");
    int series = interfaz.solicitarEntero("Series: ");
    int rep = interfaz.solicitarEntero("Repeticiones: ");
    float peso = interfaz.solicitarFloat("Peso (kg): ");

    Ejercicio* e = new Ejercicio(id, nombre, area, descripcion, series, rep, peso);
    if (bateriaEjercicios.agregarEjercicio(e)) {
        interfaz.mostrarMensaje("Ejercicio agregado a la bateria.");
    } else {
        delete e;
        interfaz.mostrarError("No se pudo agregar el ejercicio (id repetido o sin espacio).");
    }
}

void Controller::listarClientesPorSucursal()
{
    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.mostrarClientesPorSucursal(idSucursal);
}

void Controller::listarInstructoresPorSucursal()
{
    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.mostrarInstructoresPorSucursal(idSucursal);
}

void Controller::listarClasesPorSucursal()
{
    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.mostrarClasesPorSucursal(idSucursal);
}

void Controller::mostrarDetalleCliente() {
    int id = interfaz.solicitarIdCliente();

    // localizar sucursal y cliente
    Sucursal* sucEncontrada = 0;
    Cliente* cli = 0;
    for (int s = 0; s < 30; s++) {
        Sucursal* suc = gym.buscarSucursal(s + 1);
        if (suc == 0) continue;
        Cliente* c = suc->buscarCliente(id);
        if (c != 0) {
            sucEncontrada = suc;
            cli = c;
            break;
        }
    }

    if (cli == 0) {
        interfaz.mostrarError("Cliente no encontrado.");
        return;
    }

    std::cout << "=== DETALLE DEL CLIENTE ===\n";
        if (sucEncontrada != 0) {
        std::cout << "Sucursal: " << sucEncontrada->toString() << "\n";
    } else {
        std::cout << "Sucursal: (no encontrada)\n";
    }
    std::cout << cli->toStringDetalle() << "\n";
    cli->mostrarHistorialMediciones();


    interfaz.pausarPantalla();
}

void Controller::mostrarDetalleInstructor()
{
    int idInstructor = interfaz.solicitarIdInstructor();
    Instructor* instructor = gym.buscarInstructorEnTodasSucursales(idInstructor);
    if (instructor != nullptr) interfaz.mostrarMensaje(instructor->toStringDetalle());
    else interfaz.mostrarError("Instructor no encontrado.");
}

void Controller::mostrarDetalleClase()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    int idClase = interfaz.solicitarIdClase();

    Sucursal* suc = gym.buscarSucursal(idSucursal);
    if (suc == 0) {
        interfaz.mostrarError("Sucursal no encontrada.");
        return;
    }
    Clase* cls = suc->buscarClase(idClase);
    if (cls == 0) {
        interfaz.mostrarError("Clase no encontrada.");
        return;
    }

    interfaz.limpiarPantalla();
    std::cout << "=== DETALLE DE LA CLASE ===\n";

    // Mostrar info de la clase (usar toStringDetalle si existe, sino toString)
    std::string textoClase = cls->toString();
    std::cout << textoClase << "\n";

    // Instructor
    Instructor inst = cls->getInstructor();
    std::cout << "Instructor: " << inst.getIdInstructor() << " - " << inst.getNombre() << "\n";

    // Listar clientes inscritos
    std::cout << "Clientes inscritos:\n";
    int m = cls->getCantidadInscritos();
    if (m == 0) {
        std::cout << "(sin clientes)\n";
    } else {
        for (int i = 0; i < m; i++) {
            Cliente* c = cls->getClientePorIndice(i);
            if (c != 0) {
                std::cout << (i + 1) << ". " << c->toStringCorto() << "\n";
            }
        }
    }

    interfaz.pausarPantalla();
}

void Controller::mostrarHistorialMediciones() {
    int id = interfaz.solicitarIdCliente();

    Cliente* cli = gym.buscarClienteEnTodasSucursales(id);
    if (cli == 0) {
        interfaz.mostrarError("Cliente no encontrado.");
        return;
    }

    // Se asume que Cliente expone getCantidadMediciones() y getMedicionPorIndice(i)
    int n = cli->getCantidadMediciones();
    if (n == 0) {
        interfaz.mostrarMensaje("El cliente no tiene mediciones.");
        return;
    }

    // copiar punteros y ordenar por fecha descendente (burbuja simple)
    ReporteMedicion* arr[20];
    if (n > 20) n = 20; // seguridad sencilla
    for (int i = 0; i < n; i++) arr[i] = cli->getMedicionPorIndice(i);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            Fecha a = arr[j]->getFecha();
            Fecha b = arr[j + 1]->getFecha();
            bool menor = false;
            if (a.getAnio() < b.getAnio()) menor = true;
            else if (a.getAnio() == b.getAnio() && a.getMes() < b.getMes()) menor = true;
            else if (a.getAnio() == b.getAnio() && a.getMes() == b.getMes() && a.getDia() < b.getDia()) menor = true;
            if (menor) {
                ReporteMedicion* tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    std::cout << "=== HISTORIAL DE MEDICIONES (recientes primero) ===\n";
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". " << arr[i]->toString() << "\n";
    }

    int idMed = interfaz.solicitarEntero("Ingrese ID de medicion para ver detalle (0 = volver): ");
    if (idMed == 0) return;

    // buscar por id en el arreglo ordenado
    ReporteMedicion* sel = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i]->getIdMedicion() == idMed) {
            sel = arr[i];
            break;
        }
    }
    if (sel == 0) {
        interfaz.mostrarError("Medicion no encontrada.");
        return;
    }
    std::cout << sel->toStringDetalle() << "\n";
    interfaz.pausarPantalla();
}

void Controller::reporteIMC()
{
    interfaz.limpiarPantalla();
    interfaz.mostrarTitulo("Reporte IMC por Sucursal");

    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();
    Sucursal* suc = gym.buscarSucursal(idSucursal);
    if (suc == nullptr) {
        interfaz.mostrarError("Sucursal no encontrada.");
        return;
    }

    // Contadores y listado de clientes por rango
    int bajo = 0, normal = 0, sobre = 0, obes = 0;

    std::cout << "=== Detalle por cliente ===\n";
    int c = suc->getCantidadClientes();
    for (int i = 0; i < c; i++) {
        Cliente* cli = suc->getClientePorIndice(i);
        if (cli == nullptr) continue;

        ReporteMedicion* ult = cli->obtenerUltimaMedicion();
        if (ult == nullptr) continue;

        float imc = ult->getIMC();
        if (imc < 18.5f) { bajo++;  std::cout << "[Bajo]   " << cli->toString() << "\n"; }
        else if (imc < 25.0f) { normal++; std::cout << "[Normal] " << cli->toString() << "\n"; }
        else if (imc < 30.0f) { sobre++;  std::cout << "[Sobre]  " << cli->toString() << "\n"; }
        else { obes++;  std::cout << "[Obes]   " << cli->toString() << "\n"; }
    }

    std::cout << "\n=== Totales ===\n";
    std::cout << "Bajo peso: " << bajo << "\n";
    std::cout << "Normal: " << normal << "\n";
    std::cout << "Sobrepeso: " << sobre << "\n";
    std::cout << "Obesidad: " << obes << "\n";
    interfaz.pausarPantalla();
}


void Controller::matricularClienteEnClase()
{
    gym.mostrarSucursales();
    int idSucursal = interfaz.solicitarIdSucursal();

    Sucursal* suc = gym.buscarSucursal(idSucursal);
    if (suc == nullptr) { interfaz.mostrarError("Sucursal no encontrada."); return; }

    std::cout << "\nClientes en la sucursal:\n";
    suc->mostrarClientes();
    int idCliente = interfaz.solicitarIdCliente();

    std::cout << "\nClases en la sucursal:\n";
    suc->mostrarClases();
    int idClase = interfaz.solicitarIdClase();

    if (gym.matricularClienteEnClase(idSucursal, idCliente, idClase)) interfaz.mostrarMensaje("Cliente matriculado exitosamente.");
    else interfaz.mostrarError("No se pudo matricular el cliente.");
}

void Controller::generarRutina() {
    int id = interfaz.solicitarIdCliente();
    Cliente* cli = gym.buscarClienteEnTodasSucursales(id);
    if (cli == 0) {
        interfaz.mostrarError("Cliente no encontrado.");
        return;
    }

    std::string area = interfaz.solicitarCadena("Area (pecho y triceps, biceps, piernas, espalda): ");
    if (!validarAreaEjercicio(area)) {
        interfaz.mostrarError("Area invalida.");
        return;
    }

    // recolectar ejercicios por area desde la bateria
    Ejercicio* seleccion[10];
    int cant = 0;

    // Se asume que VectorEjercicio expone getCantidad() y getEjercicioPorIndice(i)
    int total = bateriaEjercicios.getCantidad();
    for (int i = 0; i < total; i++) {
        Ejercicio* e = bateriaEjercicios.getEjercicioPorIndice(i);
        if (e == 0) continue;
        if (e->getArea() == area) {
            if (cant < 10) {
                seleccion[cant] = e;
                cant++;
            }
        }
    }

    if (cant == 0) {
        interfaz.mostrarMensaje("No hay ejercicios en esa area.");
        return;
    }

    guardarRutinaParaCliente(id, seleccion, cant);

    std::cout << "=== RUTINA GENERADA PARA CLIENTE " << id << " ===\n";
    for (int i = 0; i < cant; i++) {
        std::cout << i + 1 << ". " << seleccion[i]->toStringDetalle() << "\n";
    }
    interfaz.pausarPantalla();
}


void Controller::listarClientesPorInstructor() {
    int idInst = interfaz.solicitarIdInstructor();
    gym.mostrarClientesPorInstructor(idInst);
    interfaz.pausarPantalla();
}

void Controller::listarInstructoresPorEspecialidad() {
    std::string esp = interfaz.solicitarCadena("Especialidad (CrossFit, HIIT, TRX, Pesas, Spinning, Cardio, Yoga, Zumba): ");
    if (!validarEspecialidadInstructor(esp)) {
        interfaz.mostrarError("Especialidad invalida.");
        return;
    }
    gym.mostrarInstructoresPorEspecialidad(esp);
    interfaz.pausarPantalla();
}

void Controller::mostrarRutinaDeCliente() {
    int id = interfaz.solicitarIdCliente();
    int pos = buscarIndiceRutinaPorCliente(id);
    if (pos == -1) {
        interfaz.mostrarMensaje("El cliente no tiene rutina generada.");
        return;
    }
    std::cout << "=== RUTINA DEL CLIENTE " << id << " ===\n";
    for (int i = 0; i < rutinas[pos].cantidad; i++) {
        Ejercicio* e = rutinas[pos].ejercicios[i];
        if (e != 0) std::cout << i + 1 << ". " << e->toStringDetalle() << "\n";
    }
    interfaz.pausarPantalla();
}

void Controller::verClasesDeCliente() {
    int id = interfaz.solicitarIdCliente();
    gym.mostrarClasesDeCliente(id);
    interfaz.pausarPantalla();
}


bool Controller::validarEspecialidadInstructor(std::string especialidad)
{
    return (especialidad == "CrossFit" || especialidad == "HIIT" || especialidad == "TRX" ||
            especialidad == "Pesas" || especialidad == "Spinning" || especialidad == "Cardio" ||
            especialidad == "Yoga" || especialidad == "Zumba");
}

bool Controller::validarAreaEjercicio(std::string area)
{
    return (area == "pecho y triceps" || area == "biceps" || area == "piernas" || area == "espalda");
}

std::string Controller::obtenerEspecialidadDeTipo(std::string tipo)
{
    // busca una palabra clave de especialidad dentro del tipo de clase
    std::string esp[] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
    for (int i = 0; i < 8; i++) {
        if (tipo == esp[i]) return esp[i];
    }
    return "";
}

int Controller::buscarIndiceRutinaPorCliente(int idCliente) {
    for (int i = 0; i < cantRutinas; i++) {
        if (rutinas[i].idCliente == idCliente) return i;
    }
    return -1;
}

void Controller::guardarRutinaParaCliente(int idCliente, Ejercicio** lista, int n) {
    int pos = buscarIndiceRutinaPorCliente(idCliente);
    if (pos == -1) {
        if (cantRutinas >= 100) return; // sin espacio
        pos = cantRutinas;
        rutinas[pos].idCliente = idCliente;
        rutinas[pos].cantidad = 0;
        cantRutinas++;
    }
    // copiar hasta 10
    if (n > 10) n = 10;
    rutinas[pos].cantidad = n;
    for (int i = 0; i < n; i++) rutinas[pos].ejercicios[i] = lista[i];
}
void Controller::cargarDatosPrueba()
{
    // Sucursales
    std::string prov1 = "San Jose";
    std::string cant1 = "San Pedro";
    std::string correo1 = "sanjose@powerlab.com";
    std::string tel1 = "2234-5678";
    Sucursal* sucursal1 = new Sucursal(1, prov1, cant1, correo1, tel1);

    std::string prov2 = "Cartago";
    std::string cant2 = "Cartago Centro";
    std::string correo2 = "cartago@powerlab.com";
    std::string tel2 = "2551-9876";
    Sucursal* sucursal2 = new Sucursal(2, prov2, cant2, correo2, tel2);

    gym.agregarSucursal(sucursal1);
    gym.agregarSucursal(sucursal2);

    // Instructores (Fecha)
    std::string nombre1 = "Carlos Rodriguez";
    std::string correoI1 = "carlos@powerlab.com";
    std::string telI1 = "8888-1111";
    Fecha* fechaNacI1 = new Fecha(15, 3, 1985);
    Instructor* instructor1 = new Instructor(101, nombre1, correoI1, telI1, *fechaNacI1);
    instructor1->agregarEspecialidad("CrossFit");
    instructor1->agregarEspecialidad("HIIT");

    std::string nombre2 = "Maria Gonzalez";
    std::string correoI2 = "maria@powerlab.com";
    std::string telI2 = "8888-2222";
    Fecha* fechaNacI2 = new Fecha(22, 7, 1990);
    Instructor* instructor2 = new Instructor(102, nombre2, correoI2, telI2, *fechaNacI2);
    instructor2->agregarEspecialidad("Yoga");
    instructor2->agregarEspecialidad("Spinning");

    std::string nombre3 = "Jose Ramirez";
    std::string correoI3 = "jose@powerlab.com";
    std::string telI3 = "8888-3333";
    Fecha* fechaNacI3 = new Fecha(10, 12, 1988);
    Instructor* instructor3 = new Instructor(103, nombre3, correoI3, telI3, *fechaNacI3);
    instructor3->agregarEspecialidad("Pesas");
    instructor3->agregarEspecialidad("TRX");

    gym.agregarInstructorASucursal(1, *instructor1);
    gym.agregarInstructorASucursal(1, *instructor2);
    gym.agregarInstructorASucursal(2, *instructor3);

    // Clientes (usar Fecha, no string)
    std::string nombreC1 = "Ana Soto";
    std::string correoC1 = "ana.soto@email.com";
    std::string telC1 = "8777-1111";
    Fecha* fechaNacC1 = new Fecha(25, 5, 1992);
    Fecha* fechaInsC1 = new Fecha(1, 1, 2024);
    Cliente* cliente1 = new Cliente(201, nombreC1, correoC1, telC1, *fechaNacC1, 'F', *fechaInsC1);

    std::string nombreC2 = "Pedro Morales";
    std::string correoC2 = "pedro.morales@email.com";
    std::string telC2 = "8777-2222";
    Fecha* fechaNacC2 = new Fecha(18, 9, 1987);
    Fecha* fechaInsC2 = new Fecha(15, 1, 2024);
    Cliente* cliente2 = new Cliente(202, nombreC2, correoC2, telC2, *fechaNacC2, 'M', *fechaInsC2);

    std::string nombreC3 = "Lucia Herrera";
    std::string correoC3 = "lucia.herrera@email.com";
    std::string telC3 = "8777-3333";
    Fecha* fechaNacC3 = new Fecha(30, 11, 1995);
    Fecha* fechaInsC3 = new Fecha(20, 2, 2024);
    Cliente* cliente3 = new Cliente(203, nombreC3, correoC3, telC3, *fechaNacC3, 'F', *fechaInsC3);

    std::string nombreC4 = "Roberto Castro";
    std::string correoC4 = "roberto.castro@email.com";
    std::string telC4 = "8777-4444";
    Fecha* fechaNacC4 = new Fecha(12, 4, 1983);
    Fecha* fechaInsC4 = new Fecha(5, 3, 2024);
    Cliente* cliente4 = new Cliente(204, nombreC4, correoC4, telC4, *fechaNacC4, 'M', *fechaInsC4);

    std::string nombreC5 = "Sofia Jimenez";
    std::string correoC5 = "sofia.jimenez@email.com";
    std::string telC5 = "8777-5555";
    Fecha* fechaNacC5 = new Fecha(8, 8, 1993);
    Fecha* fechaInsC5 = new Fecha(10, 3, 2024);
    Cliente* cliente5 = new Cliente(205, nombreC5, correoC5, telC5, *fechaNacC5, 'F', *fechaInsC5);

    gym.agregarClienteASucursal(1, *cliente1);
    gym.agregarClienteASucursal(1, *cliente2);
    gym.agregarClienteASucursal(1, *cliente3);
    gym.agregarClienteASucursal(2, *cliente4);
    gym.agregarClienteASucursal(2, *cliente5);

    // Clases
    std::string tipoClase1 = "CrossFit Matutino";
    std::string horario1 = "Lunes-Miercoles-Viernes 6:00-7:00 AM";
    Clase* clase1 = new Clase(301, tipoClase1, 15, horario1, *instructor1);

    std::string tipoClase2 = "Yoga Relajante";
    std::string horario2 = "Martes-Jueves 7:00-8:00 PM";
    Clase* clase2 = new Clase(302, tipoClase2, 20, horario2, *instructor2);

    std::string tipoClase3 = "Entrenamiento con Pesas";
    std::string horario3 = "Lunes-Miercoles-Viernes 4:00-5:30 PM";
    Clase* clase3 = new Clase(303, tipoClase3, 12, horario3, *instructor3);

    gym.agregarClaseASucursal(1, *clase1);
    gym.agregarClaseASucursal(1, *clase2);
    gym.agregarClaseASucursal(2, *clase3);

    // Matriculas
    gym.matricularClienteEnClase(1, 201, 301);
    gym.matricularClienteEnClase(1, 202, 301);
    gym.matricularClienteEnClase(1, 203, 302);
    gym.matricularClienteEnClase(2, 204, 303);
    gym.matricularClienteEnClase(2, 205, 303);

    // Ejercicios
    std::string nombreEj1 = "Press de Banca";
    std::string areaEj1 = "pecho y triceps";
    std::string descEj1 = "Ejercicio basico para pecho con barra";
    Ejercicio* ejercicio1 = new Ejercicio(1, nombreEj1, areaEj1, descEj1, 3, 12, 80.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio1);

    std::string nombreEj2 = "Flexiones";
    std::string areaEj2 = "pecho y triceps";
    std::string descEj2 = "Flexiones de pecho con peso corporal";
    Ejercicio* ejercicio2 = new Ejercicio(2, nombreEj2, areaEj2, descEj2, 3, 15, 0.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio2);

    std::string nombreEj3 = "Curl con Mancuernas";
    std::string areaEj3 = "biceps";
    std::string descEj3 = "Curl de biceps con mancuernas alterno";
    Ejercicio* ejercicio3 = new Ejercicio(3, nombreEj3, areaEj3, descEj3, 3, 12, 15.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio3);

    std::string nombreEj4 = "Curl con Barra";
    std::string areaEj4 = "biceps";
    std::string descEj4 = "Curl de biceps con barra recta";
    Ejercicio* ejercicio4 = new Ejercicio(4, nombreEj4, areaEj4, descEj4, 3, 10, 30.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio4);

    std::string nombreEj5 = "Sentadillas";
    std::string areaEj5 = "piernas";
    std::string descEj5 = "Sentadillas profundas con barra";
    Ejercicio* ejercicio5 = new Ejercicio(5, nombreEj5, areaEj5, descEj5, 4, 12, 100.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio5);

    std::string nombreEj6 = "Peso Muerto";
    std::string areaEj6 = "piernas";
    std::string descEj6 = "Levantamiento de peso muerto convencional";
    Ejercicio* ejercicio6 = new Ejercicio(6, nombreEj6, areaEj6, descEj6, 3, 8, 120.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio6);

    std::string nombreEj7 = "Dominadas";
    std::string areaEj7 = "espalda";
    std::string descEj7 = "Dominadas con peso corporal";
    Ejercicio* ejercicio7 = new Ejercicio(7, nombreEj7, areaEj7, descEj7, 3, 8, 0.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio7);

    std::string nombreEj8 = "Remo con Barra";
    std::string areaEj8 = "espalda";
    std::string descEj8 = "Remo inclinado con barra";
    Ejercicio* ejercicio8 = new Ejercicio(8, nombreEj8, areaEj8, descEj8, 3, 10, 70.0f);
    bateriaEjercicios.agregarEjercicio(ejercicio8);

    // Mediciones (usar Fecha, no string)
    Cliente* clienteAna = gym.buscarClienteEnTodasSucursales(201);
    Cliente* clientePedro = gym.buscarClienteEnTodasSucursales(202);
    Cliente* clienteLucia = gym.buscarClienteEnTodasSucursales(203);

    if (clienteAna != nullptr) {
        Fecha fechaMed1(1, 2, 2024);
        ReporteMedicion* medicion1 = new ReporteMedicion(1, fechaMed1, 65.5f, 165.0f, 24.1f, 35.2f, 28, 8.5f,
                                                         78.0f, 95.0f, 88.0f, 55.0f);
        clienteAna->agregarMedicion(*medicion1);

        Fecha fechaMed2(1, 3, 2024);
        ReporteMedicion* medicion2 = new ReporteMedicion(2, fechaMed2, 64.8f, 165.0f, 23.8f, 36.0f, 27, 8.2f,
                                                         77.0f, 94.5f, 87.5f, 54.5f);
        clienteAna->agregarMedicion(*medicion2);
    }

    if (clientePedro != nullptr) {
        Fecha fechaMed3(20, 2, 2024);
        ReporteMedicion* medicion3 = new ReporteMedicion(3, fechaMed3, 78.2f, 175.0f, 25.5f, 42.1f, 26, 9.2f,
                                                         100.0f, 88.0f, 96.0f, 36.0f);
        clientePedro->agregarMedicion(*medicion3);
    }

    if (clienteLucia != nullptr) {
        Fecha fechaMed4(25, 2, 2024);
        ReporteMedicion* medicion4 = new ReporteMedicion(4, fechaMed4, 58.3f, 162.0f, 22.2f, 33.8f, 29, 7.8f,
                                                         84.0f, 70.0f, 94.0f, 28.0f);
        clienteLucia->agregarMedicion(*medicion4);
    }

    interfaz.mostrarMensaje("Datos de prueba cargados exitosamente:\n- 2 Sucursales (San Jose y Cartago)\n- 5 Clientes\n- 3 Instructores\n- 3 Clases\n- 8 Ejercicios\n- Mediciones y Matriculas creadas");
}

