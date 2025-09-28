// C++
#include "UI.h"
#include <iostream>

void UI::mostrarBannerBienvenida() {
    limpiarPantalla();
    std::cout << "========================================\n";
    std::cout << "   Bienvenido al sistema PowerLab Gym   \n";
    std::cout << "========================================\n";
    pausarPantalla();
}

void UI::mostrarBannerDespedida() {
    limpiarPantalla();
    std::cout << "\n========================================\n";
    std::cout << "   Gracias por usar PowerLab Gym System \n";
    std::cout << "========================================\n";
    pausarPantalla();
}

void UI::mostrarMensaje(std::string mensaje) {
    limpiarPantalla();
    std::cout << mensaje << std::endl;
    pausarPantalla();
}

void UI::mostrarError(std::string mensaje) {
    limpiarPantalla();
    std::cout << "ERROR: " << mensaje << std::endl;
    pausarPantalla();
}

void UI::mostrarTitulo(std::string titulo) {
    std::cout << "\n--- " << titulo << " ---\n";
}

int UI::mostrarMenuPrincipal() {
    limpiarPantalla();
    mostrarTitulo("Menu Principal");
    std::cout << "1. Gestionar Sucursales\n";
    std::cout << "2. Gestionar Clientes\n";
    std::cout << "3. Gestionar Instructores\n";
    std::cout << "4. Gestionar Clases Grupales\n";
    std::cout << "5. Gestionar Mediciones\n";
    std::cout << "6. Informes\n";
    std::cout << "7. Rutinas y Ejercicios\n";
    std::cout << "0. Salir\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuSucursales() {
    limpiarPantalla();
    mostrarTitulo("Menu Sucursales");
    std::cout << "1. Agregar Sucursal\n";
    std::cout << "2. Listar Sucursales\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuClientes() {
    limpiarPantalla();
    mostrarTitulo("Menu Clientes");
    std::cout << "1. Agregar Cliente\n";
    std::cout << "2. Listar Clientes por Sucursal\n";
    std::cout << "3. Ver Detalle Cliente\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuInstructores() {
    limpiarPantalla();
    mostrarTitulo("Menu Instructores");
    std::cout << "1. Agregar Instructor\n";
    std::cout << "2. Listar Instructores por Sucursal\n";
    std::cout << "3. Ver Detalle Instructor\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuClases() {
    limpiarPantalla();
    mostrarTitulo("Menu Clases Grupales");
    std::cout << "1. Agregar Clase\n";
    std::cout << "2. Listar Clases por Sucursal\n";
    std::cout << "3. Ver Detalle Clase\n";
    std::cout << "4. Matricular Cliente en Clase\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuMediciones() {
    limpiarPantalla();
    mostrarTitulo("Menu Mediciones");
    std::cout << "1. Agregar Medicion\n";
    std::cout << "2. Ver Historial de Mediciones\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuInformes() {
    limpiarPantalla();
    mostrarTitulo("Menu Informes");
    std::cout << "1. Informe de Clientes por Sucursal\n";
    std::cout << "2. Informe de Instructores por Sucursal\n";
    std::cout << "3. Informe IMC por Sucursal\n";
    std::cout << "4. Lista de Clientes por Instructor\n";
    std::cout << "5. Lista de Instructores por Especialidad\n";
    std::cout << "6. Clases matriculadas por Cliente\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuRutinas() {
    limpiarPantalla();
    mostrarTitulo("Menu Rutinas y Ejercicios");
    std::cout << "1. Agregar Ejercicio\n";
    std::cout << "2. Generar Rutina\n";
    std::cout << "3. Mostrar Rutina de Cliente\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

Sucursal UI::crearSucursal() {
    limpiarPantalla();
    mostrarTitulo("Agregar Sucursal");
    int id = solicitarEntero("Codigo de sucursal: ");
    std::string provincia = solicitarCadena("Provincia: ");
    std::string canton = solicitarCadena("Canton: ");
    std::string correo = solicitarCadena("Correo electronico: ");
    std::string telefono = solicitarCadena("Telefono: ");
    return Sucursal(id, provincia, canton, correo, telefono);
}

Cliente UI::crearCliente() {
    limpiarPantalla();
    mostrarTitulo("Crear Nuevo Cliente");
    int id = solicitarEntero("ID del cliente: ");
    std::string nombre = solicitarCadena("Nombre completo: ");
    std::string correo = solicitarCadena("Correo electronico: ");
    std::string telefono = solicitarCadena("Telefono: ");
    Fecha fechaNac = solicitarFechaDDMMAAAA("Fecha de nacimiento");
    char genero = solicitarCaracter("Genero (M/F): ");
    Fecha fechaIns = solicitarFechaDDMMAAAA("Fecha de inscripcion");

    return Cliente(id, nombre, correo, telefono, fechaNac, genero, fechaIns);
}

Instructor UI::crearInstructor() {
    limpiarPantalla();
    mostrarTitulo("Crear Nuevo Instructor");
    int id = solicitarEntero("ID del instructor: ");
    std::string nombre = solicitarCadena("Nombre completo: ");
    std::string correo = solicitarCadena("Correo electronico: ");
    std::string telefono = solicitarCadena("Telefono: ");
    Fecha fechaNac = solicitarFechaDDMMAAAA("Fecha de nacimiento");

    Instructor nuevo(id, nombre, correo, telefono, fechaNac);

    mostrarMensaje("Agregue especialidades (CrossFit, HIIT, TRX, Pesas, Spinning, Cardio, Yoga, Zumba)\nEscriba 'fin' para terminar");
    std::string especialidad;
    while (true) {
        especialidad = solicitarCadena("Especialidad: ");
        if (especialidad == "fin") break;

        // Validacion simple aqui tambien para ayudar al usuario
        std::string esp[8] = { "CrossFit","HIIT","TRX","Pesas","Spinning","Cardio","Yoga","Zumba" };
        bool ok = false;
        for (int i = 0; i < 8; i++) if (especialidad == esp[i]) ok = true;
        if (!ok) {
            mostrarError("Especialidad invalida. Intente nuevamente.");
            continue;
        }

        if (!nuevo.agregarEspecialidad(especialidad)) {
            mostrarError("No se pudo agregar la especialidad (lista llena o invalida).");
        }
    }

    return nuevo;
}

Clase UI::crearClase(Instructor& instructor) {
    limpiarPantalla();
    mostrarTitulo("Crear Nueva Clase");
    int id = solicitarEntero("ID de la clase: ");
    std::string tipo = solicitarCadena("Tipo de clase: ");
    int capacidad = solicitarEntero("Capacidad maxima: ");
    std::string horario = solicitarCadena("Horario: ");

    return Clase(id, tipo, capacidad, horario, instructor);
}

ReporteMedicion UI::crearReporteMedicion() {
    limpiarPantalla();
    mostrarTitulo("Crear Nuevo Reporte de Medicion");
    int id = solicitarEntero("ID de medicion: ");
    Fecha fecha = solicitarFechaDDMMAAAA("Fecha de medicion");
    float peso = solicitarFloat("Peso (kg): ");
    float estatura = solicitarFloat("Estatura (cm): ");
    float porcentajeGrasa = solicitarFloat("Porcentaje de grasa (%): ");
    float porcentajeMusculo = solicitarFloat("Porcentaje de musculo (%): ");
    int edadMetabolica = solicitarEntero("Edad metabolica: ");
    float porcentajeGrasaVisceral = solicitarFloat("Porcentaje de grasa visceral (%): ");
    float cintura = solicitarFloat("Medida de cintura (cm): ");
    float cadera = solicitarFloat("Medida de cadera (cm): ");
    float pecho = solicitarFloat("Medida de pecho (cm): ");
    float muslo = solicitarFloat("Medida de muslo (cm): ");

    return ReporteMedicion(id, fecha, peso, estatura, porcentajeGrasa, porcentajeMusculo,
        edadMetabolica, porcentajeGrasaVisceral, cintura, cadera, pecho, muslo);
}

int UI::solicitarIdSucursal() { return solicitarEntero("Ingrese el codigo de la sucursal: "); }
int UI::solicitarIdCliente()  { return solicitarEntero("Ingrese el ID del cliente: "); }
int UI::solicitarIdInstructor(){ return solicitarEntero("Ingrese el ID del instructor: "); }
int UI::solicitarIdClase()    { return solicitarEntero("Ingrese el ID de la clase: "); }

float UI::solicitarFloat(std::string mensaje) {
    float valor;
    std::cout << mensaje;
    while (!(std::cin >> valor)) {
        std::cin.clear();
        std::cout << "Entrada invalida. Intente de nuevo: ";
    }
    return valor;
}

void UI::limpiarPantalla() { system("cls"); }
void UI::pausarPantalla()  { system("pause"); }

int UI::solicitarEntero(std::string mensaje) {
    int valor;
    std::cout << mensaje;
    while (!(std::cin >> valor)) {
        std::cin.clear();
        std::cout << "Entrada invalida. Intente de nuevo: ";
    }
    return valor;
}

std::string UI::solicitarCadena(std::string mensaje) {
    std::string valor;
    std::cout << mensaje;
    std::getline(std::cin, valor);
    if (valor.size() == 0) std::getline(std::cin, valor);
    return valor;
}

char UI::solicitarCaracter(std::string mensaje) {
    char valor;
    std::cout << mensaje;
    std::cin >> valor;
    return valor;
}

Fecha UI::solicitarFechaDDMMAAAA(std::string titulo) {
    while (true) {
        std::cout << titulo << " (DD/MM/AAAA)\n";
        int d = solicitarEntero("Dia: ");
        int m = solicitarEntero("Mes: ");
        int a = solicitarEntero("Anio: ");
        Fecha f(d, m, a);
        if (f.esValida(f)) {
            return  f;
        } else {
            mostrarError("Fecha invalida, intente de nuevo.");
        }
    }
}
