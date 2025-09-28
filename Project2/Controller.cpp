// cpp
// File: 'Project2/Controller.cpp'
#include "Controller.h"

Controller::Controller() {}
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
        case 2: listarClientesPorSucursal(); break;
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
    std::string fechaNac = interfaz.solicitarCadena("Fecha nacimiento (dd/mm/aaaa): ");
    std::string generoStr = interfaz.solicitarCadena("Genero (M/F): ");
    char genero = generoStr.empty() ? 'M' : generoStr[0];
    std::string fechaIns = interfaz.solicitarCadena("Fecha inscripcion (dd/mm/aaaa): ");

    Cliente* nuevo = new Cliente(id, nombre, correo, telefono, fechaNac, genero, fechaIns);
    if (gym.agregarClienteASucursal(idSucursal, *nuevo)) interfaz.mostrarMensaje("Cliente agregado exitosamente.");
    else interfaz.mostrarError("No se pudo agregar el cliente.");
}

void Controller::agregarInstructor()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    if (!gym.existeSucursal(idSucursal)) {
        interfaz.mostrarError("Sucursal no encontrada.");
        return;
    }

    int id = interfaz.solicitarEntero("ID del instructor: ");
    if (gym.existeIDPersona(id)) {
        interfaz.mostrarError("ID de instructor ya existe en el sistema.");
        return;
    }
    std::string nombre = interfaz.solicitarCadena("Nombre: ");
    std::string correo = interfaz.solicitarCadena("Correo: ");
    std::string telefono = interfaz.solicitarCadena("Telefono: ");
    std::string fechaNac = interfaz.solicitarCadena("Fecha nacimiento (dd/mm/aaaa): ");

    Instructor* nuevo = new Instructor(id, nombre, correo, telefono, fechaNac);

    // Especialidades (opcional, hasta 2)
    std::string esp = interfaz.solicitarCadena("Especialidad (vacío para omitir): ");
    if (!esp.empty() && validarEspecialidadInstructor(esp)) nuevo->agregarEspecialidad(esp);
    std::string esp2 = interfaz.solicitarCadena("Otra especialidad (vacío para omitir): ");
    if (!esp2.empty() && validarEspecialidadInstructor(esp2)) nuevo->agregarEspecialidad(esp2);

    if (gym.agregarInstructorASucursal(idSucursal, *nuevo)) interfaz.mostrarMensaje("Instructor agregado exitosamente.");
    else interfaz.mostrarError("No se pudo agregar el instructor.");
}

void Controller::agregarClase()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    Sucursal* suc = gym.buscarSucursal(idSucursal);
    if (suc == nullptr) {
        interfaz.mostrarError("Sucursal no encontrada.");
        return;
    }

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

    Clase* nueva = new Clase(idClase, tipo, cupo, horario, *instructor);
    if (gym.agregarClaseASucursal(idSucursal, *nueva)) interfaz.mostrarMensaje("Clase agregada exitosamente.");
    else interfaz.mostrarError("No se pudo agregar la clase.");
}

void Controller::agregarMedicion()
{
    int idCliente = interfaz.solicitarIdCliente();
    Cliente* cliente = gym.buscarClienteEnTodasSucursales(idCliente);
    if (cliente == nullptr) {
        interfaz.mostrarError("Cliente no encontrado.");
        return;
    }

    int idRep = interfaz.solicitarEntero("ID del reporte: ");
    std::string fecha = interfaz.solicitarCadena("Fecha (dd/mm/aaaa): ");
    float peso = interfaz.solicitarFloat("Peso (kg): ");
    float alturaCm = interfaz.solicitarFloat("Altura (cm): ");
    float imc = interfaz.solicitarFloat("IMC: ");
    float musculo = interfaz.solicitarFloat("% Musculo: ");
    int edadMet = interfaz.solicitarEntero("Edad metabolica: ");
    float grasaVis = interfaz.solicitarFloat("Grasa visceral: ");
    float pecho = interfaz.solicitarFloat("Pecho (cm): ");
    float cintura = interfaz.solicitarFloat("Cintura (cm): ");
    float cadera = interfaz.solicitarFloat("Cadera (cm): ");
    float brazo = interfaz.solicitarFloat("Brazo (cm): ");

    ReporteMedicion* nueva = new ReporteMedicion(idRep, fecha, peso, alturaCm, imc, musculo, edadMet,
                                                 grasaVis, pecho, cintura, cadera, brazo);

    if (cliente->agregarMedicion(*nueva)) interfaz.mostrarMensaje("Medicion agregada exitosamente.");
    else interfaz.mostrarError("No se pudo agregar la medicion.");
}

void Controller::agregarEjercicio()
{
    interfaz.mostrarTitulo("Agregar Ejercicio");
    int id = interfaz.solicitarEntero("ID del ejercicio: ");
    std::string nombre = interfaz.solicitarCadena("Nombre del ejercicio: ");
    std::string area = interfaz.solicitarCadena("Area (pecho y triceps/biceps/piernas/espalda): ");
    if (!validarAreaEjercicio(area)) { interfaz.mostrarError("Area invalida."); return; }
    std::string descripcion = interfaz.solicitarCadena("Descripcion: ");
    int series = interfaz.solicitarEntero("Series: ");
    int repeticiones = interfaz.solicitarEntero("Repeticiones: ");
    float peso = interfaz.solicitarFloat("Peso (kg): ");

    Ejercicio* nuevo = new Ejercicio(id, nombre, area, descripcion, series, repeticiones, peso);
    if (bateriaEjercicios.agregarEjercicio(nuevo)) interfaz.mostrarMensaje("Ejercicio agregado exitosamente.");
    else interfaz.mostrarError("No se pudo agregar el ejercicio.");
}

void Controller::listarClientesPorSucursal()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.mostrarClientesPorSucursal(idSucursal);
}

void Controller::listarInstructoresPorSucursal()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.mostrarInstructoresPorSucursal(idSucursal);
}

void Controller::mostrarDetalleCliente()
{
    int idCliente = interfaz.solicitarIdCliente();
    Cliente* cliente = gym.buscarClienteEnTodasSucursales(idCliente);
    if (cliente != nullptr) interfaz.mostrarMensaje(cliente->toStringDetalle());
    else interfaz.mostrarError("Cliente no encontrado.");
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
    if (suc != nullptr) {
        Clase* clase = suc->buscarClase(idClase);
        if (clase != nullptr) interfaz.mostrarMensaje(clase->toStringDetalle());
        else interfaz.mostrarError("Clase no encontrada.");
    } else {
        interfaz.mostrarError("Sucursal no encontrada.");
    }
}

void Controller::mostrarHistorialMediciones()
{
    int idCliente = interfaz.solicitarIdCliente();
    Cliente* cliente = gym.buscarClienteEnTodasSucursales(idCliente);
    if (cliente != nullptr) cliente->mostrarHistorialMediciones();
    else interfaz.mostrarError("Cliente no encontrado.");
}

void Controller::reporteIMC()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    gym.reporteIMCPorSucursal(idSucursal);
}

void Controller::matricularClienteEnClase()
{
    int idSucursal = interfaz.solicitarIdSucursal();
    int idCliente = interfaz.solicitarIdCliente();
    int idClase = interfaz.solicitarIdClase();
    if (gym.matricularClienteEnClase(idSucursal, idCliente, idClase)) interfaz.mostrarMensaje("Cliente matriculado exitosamente.");
    else interfaz.mostrarError("No se pudo matricular el cliente.");
}

void Controller::generarRutina()
{
    interfaz.mostrarTitulo("Generar Rutina");
    bateriaEjercicios.mostrarEjercicios();
    interfaz.mostrarMensaje("Seleccione ejercicios por area para crear la rutina.");
}

// Pendientes
void Controller::listarClientesPorInstructor()
{
    interfaz.mostrarTitulo("Listar Clientes por Instructor");
    int idInstructor = interfaz.solicitarIdInstructor();
    interfaz.mostrarMensaje("Funcionalidad pendiente de implementar.");
}

void Controller::listarInstructoresPorEspecialidad()
{
    interfaz.mostrarTitulo("Listar Instructores por Especialidad");
    std::string especialidad = interfaz.solicitarCadena("Especialidad: ");
    interfaz.mostrarMensaje("Funcionalidad pendiente de implementar.");
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

void Controller::cargarDatosPrueba()
{
    // Sucursales en heap (sin copias)
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

    // Instructores
    std::string nombre1 = "Carlos Rodriguez";
    std::string correoI1 = "carlos@powerlab.com";
    std::string telI1 = "8888-1111";
    std::string fechaNacI1 = "15/03/1985";
    Instructor* instructor1 = new Instructor(101, nombre1, correoI1, telI1, fechaNacI1);
    std::string esp1 = "CrossFit"; std::string esp2 = "HIIT";
    instructor1->agregarEspecialidad(esp1);
    instructor1->agregarEspecialidad(esp2);

    std::string nombre2 = "Maria Gonzalez";
    std::string correoI2 = "maria@powerlab.com";
    std::string telI2 = "8888-2222";
    std::string fechaNacI2 = "22/07/1990";
    Instructor* instructor2 = new Instructor(102, nombre2, correoI2, telI2, fechaNacI2);
    std::string esp3 = "Yoga"; std::string esp4 = "Spinning";
    instructor2->agregarEspecialidad(esp3);
    instructor2->agregarEspecialidad(esp4);

    std::string nombre3 = "Jose Ramirez";
    std::string correoI3 = "jose@powerlab.com";
    std::string telI3 = "8888-3333";
    std::string fechaNacI3 = "10/12/1988";
    Instructor* instructor3 = new Instructor(103, nombre3, correoI3, telI3, fechaNacI3);
    std::string esp5 = "Pesas"; std::string esp6 = "TRX";
    instructor3->agregarEspecialidad(esp5);
    instructor3->agregarEspecialidad(esp6);

    gym.agregarInstructorASucursal(1, *instructor1);
    gym.agregarInstructorASucursal(1, *instructor2);
    gym.agregarInstructorASucursal(2, *instructor3);

    // Clientes
    std::string nombreC1 = "Ana Soto";
    std::string correoC1 = "ana.soto@email.com";
    std::string telC1 = "8777-1111";
    std::string fechaNacC1 = "25/05/1992";
    std::string fechaInsC1 = "01/01/2024";
    Cliente* cliente1 = new Cliente(201, nombreC1, correoC1, telC1, fechaNacC1, 'F', fechaInsC1);

    std::string nombreC2 = "Pedro Morales";
    std::string correoC2 = "pedro.morales@email.com";
    std::string telC2 = "8777-2222";
    std::string fechaNacC2 = "18/09/1987";
    std::string fechaInsC2 = "15/01/2024";
    Cliente* cliente2 = new Cliente(202, nombreC2, correoC2, telC2, fechaNacC2, 'M', fechaInsC2);

    std::string nombreC3 = "Lucia Herrera";
    std::string correoC3 = "lucia.herrera@email.com";
    std::string telC3 = "8777-3333";
    std::string fechaNacC3 = "30/11/1995";
    std::string fechaInsC3 = "20/02/2024";
    Cliente* cliente3 = new Cliente(203, nombreC3, correoC3, telC3, fechaNacC3, 'F', fechaInsC3);

    std::string nombreC4 = "Roberto Castro";
    std::string correoC4 = "roberto.castro@email.com";
    std::string telC4 = "8777-4444";
    std::string fechaNacC4 = "12/04/1983";
    std::string fechaInsC4 = "05/03/2024";
    Cliente* cliente4 = new Cliente(204, nombreC4, correoC4, telC4, fechaNacC4, 'M', fechaInsC4);

    std::string nombreC5 = "Sofia Jimenez";
    std::string correoC5 = "sofia.jimenez@email.com";
    std::string telC5 = "8777-5555";
    std::string fechaNacC5 = "08/08/1993";
    std::string fechaInsC5 = "10/03/2024";
    Cliente* cliente5 = new Cliente(205, nombreC5, correoC5, telC5, fechaNacC5, 'F', fechaInsC5);

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

    // Mediciones
    Cliente* clienteAna = gym.buscarClienteEnTodasSucursales(201);
    Cliente* clientePedro = gym.buscarClienteEnTodasSucursales(202);
    Cliente* clienteLucia = gym.buscarClienteEnTodasSucursales(203);

    if (clienteAna != nullptr) {
        std::string fechaMed1 = "01/02/2024";
        ReporteMedicion* medicion1 = new ReporteMedicion(1, fechaMed1, 65.5f, 165.0f, 24.1f, 35.2f, 28, 8.5f,
                                                         78.0f, 95.0f, 88.0f, 55.0f);
        clienteAna->agregarMedicion(*medicion1);

        std::string fechaMed2 = "01/03/2024";
        ReporteMedicion* medicion2 = new ReporteMedicion(2, fechaMed2, 64.8f, 165.0f, 23.8f, 36.0f, 27, 8.2f,
                                                         77.0f, 94.5f, 87.5f, 54.5f);
        clienteAna->agregarMedicion(*medicion2);
    }

    if (clientePedro != nullptr) {
        std::string fechaMed3 = "20/02/2024";
        ReporteMedicion* medicion3 = new ReporteMedicion(3, fechaMed3, 78.2f, 175.0f, 25.5f, 42.1f, 26, 9.2f,
                                                         100.0f, 88.0f, 96.0f, 36.0f);
        clientePedro->agregarMedicion(*medicion3);
    }

    if (clienteLucia != nullptr) {
        std::string fechaMed4 = "25/02/2024";
        ReporteMedicion* medicion4 = new ReporteMedicion(4, fechaMed4, 58.3f, 162.0f, 22.2f, 33.8f, 29, 7.8f,
                                                         84.0f, 70.0f, 94.0f, 28.0f);
        clienteLucia->agregarMedicion(*medicion4);
    }

    interfaz.mostrarMensaje("Datos de prueba cargados exitosamente:");
    interfaz.mostrarMensaje("- 2 Sucursales (San Jose y Cartago)");
    interfaz.mostrarMensaje("- 5 Clientes distribuidos en ambas sucursales");
    interfaz.mostrarMensaje("- 3 Instructores con especialidades variadas");
    interfaz.mostrarMensaje("- 3 Clases grupales activas");
    interfaz.mostrarMensaje("- 8 Ejercicios de diferentes areas corporales");
    interfaz.mostrarMensaje("- Reportes de mediciones para algunos clientes");
    interfaz.mostrarMensaje("- Matriculas de clientes en clases");
}
