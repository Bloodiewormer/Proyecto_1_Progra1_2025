#include "UI.h"
#include <iostream>
#include <limits>

void UI::mostrarBannerBienvenida() {
    limpiarPantalla();
    std::cout << "========================================\n";
    std::cout << "   Bienvenido al sistema PowerLab Gym   \n";
    std::cout << "========================================\n";
}

void UI::mostrarBannerDespedida() {
    std::cout << "\n========================================\n";
    std::cout << "   Gracias por usar PowerLab Gym System \n";
    std::cout << "========================================\n";
}

void UI::mostrarMensaje(std::string mensaje) {
    std::cout << mensaje << std::endl;
}

void UI::mostrarError(std::string mensaje) {
    std::cout << "ERROR: " << mensaje << std::endl;
}

void UI::mostrarTitulo(std::string titulo) {
    std::cout << "\n--- " << titulo << " ---\n";
}

int UI::mostrarMenuPrincipal() {
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
    mostrarTitulo("Menu Sucursales");
    std::cout << "1. Agregar Sucursal\n";
    std::cout << "2. Listar Sucursales\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuClientes() {
    mostrarTitulo("Menu Clientes");
    std::cout << "1. Agregar Cliente\n";
    std::cout << "2. Listar Clientes por Sucursal\n";
    std::cout << "3. Ver Detalle Cliente\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuInstructores() {
    mostrarTitulo("Menu Instructores");
    std::cout << "1. Agregar Instructor\n";
    std::cout << "2. Listar Instructores por Sucursal\n";
    std::cout << "3. Ver Detalle Instructor\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuClases() {
    mostrarTitulo("Menu Clases Grupales");
    std::cout << "1. Agregar Clase\n";
    std::cout << "2. Listar Clases por Sucursal\n";
    std::cout << "3. Ver Detalle Clase\n";
    std::cout << "4. Matricular Cliente en Clase\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuMediciones() {
    mostrarTitulo("Menu Mediciones");
    std::cout << "1. Agregar Medicion\n";
    std::cout << "2. Ver Historial de Mediciones\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuInformes() {
    mostrarTitulo("Menu Informes");
    std::cout << "1. Informe de Clientes por Sucursal\n";
    std::cout << "2. Informe de Instructores por Sucursal\n";
    std::cout << "3. Informe IMC por Sucursal\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

int UI::mostrarMenuRutinas() {
    mostrarTitulo("Menu Rutinas y Ejercicios");
    std::cout << "1. Agregar Ejercicio\n";
    std::cout << "2. Generar Rutina\n";
    std::cout << "0. Volver\n";
    return solicitarEntero("Seleccione una opcion: ");
}

// Formularios de ingreso de datos
Sucursal UI::crearSucursal() {
    mostrarTitulo("Agregar Sucursal");
    int id = solicitarEntero("Codigo de sucursal: ");
    std::string provincia = solicitarCadena("Provincia: ");
    std::string canton = solicitarCadena("Canton: ");
    std::string correo = solicitarCadena("Correo electronico: ");
    std::string telefono = solicitarCadena("Telefono: ");
    return Sucursal(id, provincia, canton, correo, telefono);



}

Cliente UI::crearCliente() {
    mostrarTitulo("Crear Nuevo Cliente");
    int id = solicitarEntero("ID del cliente: ");
    std::string nombre = solicitarCadena("Nombre completo: ");
    std::string correo = solicitarCadena("Correo electronico: ");
    std::string telefono = solicitarCadena("Telefono: ");
    std::string fechaNac = solicitarCadena("Fecha de nacimiento (DD/MM/AAAA): ");
    char genero = solicitarCaracter("Genero (M/F): ");
    std::string fechaIns = solicitarCadena("Fecha de inscripcion (DD/MM/AAAA): ");

    return Cliente(id, nombre, correo, telefono, fechaNac, genero, fechaIns);
}

Instructor UI::crearInstructor() {
    mostrarTitulo("Crear Nuevo Instructor");
    int id = solicitarEntero("ID del instructor: ");
    std::string nombre = solicitarCadena("Nombre completo: ");
    std::string correo = solicitarCadena("Correo electronico: ");
    std::string telefono = solicitarCadena("Telefono: ");
    std::string fechaNac = solicitarCadena("Fecha de nacimiento (DD/MM/AAAA): ");

    Instructor nuevo(id, nombre, correo, telefono, fechaNac);

    // Agregar especialidades
    mostrarMensaje("Agregue especialidades (CrossFit, HIIT, TRX, Pesas, Spinning, Cardio, Yoga, Zumba)");
    mostrarMensaje("Escriba 'fin' para terminar");
    std::string especialidad;
    while (true) {
        especialidad = solicitarCadena("Especialidad: ");
        if (especialidad == "fin") break;
        nuevo.agregarEspecialidad(especialidad);
    }

    return nuevo;
}

Clase UI::crearClase(Instructor& instructor) {
    mostrarTitulo("Crear Nueva Clase");
    int id = solicitarEntero("ID de la clase: ");
    std::string tipo = solicitarCadena("Tipo de clase: ");
    int capacidad = solicitarEntero("Capacidad maxima: ");
    std::string horario = solicitarCadena("Horario: ");

    return Clase(id, tipo, capacidad, horario, instructor);
}

ReporteMedicion UI::crearReporteMedicion() {
    mostrarTitulo("Crear Nuevo Reporte de Medicion");
    int id = solicitarEntero("ID de medicion: ");
    std::string fecha = solicitarCadena("Fecha de medicion (DD/MM/AAAA): ");
    float peso = solicitarFloat("Peso (kg): ");
    float estatura = solicitarFloat("Estatura (m): ");
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

// Métodos de solicitud de datos
int UI::solicitarIdSucursal() {
    return solicitarEntero("Ingrese el codigo de la sucursal: ");
}

int UI::solicitarIdCliente() {
    return solicitarEntero("Ingrese el ID del cliente: ");
}

int UI::solicitarIdInstructor() {
    return solicitarEntero("Ingrese el ID del instructor: ");
}

int UI::solicitarIdClase() {
    return solicitarEntero("Ingrese el ID de la clase: ");
}

float UI::solicitarFloat(std::string mensaje) {
    float valor;
    std::cout << mensaje;
    while (!(std::cin >> valor)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Intente de nuevo: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

// Utilidades
void UI::limpiarPantalla() {
    system("cls");
}

void UI::pausarPantalla() {
    std::cout << "Presione ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int UI::solicitarEntero(std::string mensaje) {
    int valor;
    std::cout << mensaje;
    while (!(std::cin >> valor)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Intente de nuevo: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

std::string UI::solicitarCadena(std::string mensaje) {
    std::string valor;
    std::cout << mensaje;
    std::getline(std::cin, valor);
    return valor;
}

char UI::solicitarCaracter(std::string mensaje) {
    char valor;
    std::cout << mensaje;
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}
