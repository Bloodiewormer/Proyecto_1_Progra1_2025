#include "VectorClases.h"

VectorClases::VectorClases()
{
	capacidad = 10;
	cantidad = 0;
	clases = new Clase*[capacidad];
	for (int i = 0; i < capacidad; i++) {
		clases[i] = nullptr;
	}
}

VectorClases::~VectorClases()
{
	delete[] clases;
}

int VectorClases::getCantidad()
{
	return cantidad;
}

bool VectorClases::agregarClase( Clase* clase)
{
	if (cantidad >= capacidad) return false; // No hay espacio
	if (existeClase(clase->getIdClase())) return false; // ID repetido
	clases[cantidad] = clase;
	cantidad++;
	return true;

}


Clase** VectorClases::buscarClase(int idClase)
{
	for (int i = 0; i < cantidad; i++) {
		if (clases[i]->getIdClase() == idClase) {
			return &clases[i];
		}
	}
	return nullptr; // No encontrado

}

bool VectorClases::existeClase(int idClase)
{
	return buscarClase(idClase) != nullptr;
}

void VectorClases::mostrarClases()
{

}

