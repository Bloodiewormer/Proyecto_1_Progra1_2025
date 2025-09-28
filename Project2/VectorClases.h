#pragma once
#include <iostream>
#include "Clase.h"

class VectorClases
{
private:
	Clase** clases;
	int capacidad;
	int cantidad;

public:
	VectorClases();
	~VectorClases();
	Clase* getClasePorIndice(int i);
	int getCantidad() ;
	bool agregarClase(Clase* clase);
	Clase** buscarClase(int idClase);
	bool existeClase(int idClase);
	void mostrarClases();
};