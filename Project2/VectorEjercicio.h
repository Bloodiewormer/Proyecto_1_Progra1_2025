#pragma once
#include <iostream>
#include "Ejercicio.h"

class VectorEjercicio
{
private:
	Ejercicio** ejercicios;
	int capacidad;
	int cantidad;

public:
	VectorEjercicio();
	~VectorEjercicio();
	bool agregarEjercicio(Ejercicio* ejercicio);
	bool eliminarEjercicio(int idEjercicio);
	Ejercicio** buscarEjercicio(int idEjercicio);
	bool existeEjercicio(int idEjercicio);
	void mostrarEjercicios();
};