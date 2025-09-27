#pragma once
#include <iostream>
#include "Instructor.h"
class VectorInstructores
{
private:
	Instructor** instructores;
	int capacidad;
	int cantidad;
public:
	VectorInstructores();
	~VectorInstructores();
	bool agregarInstructor(Instructor* instructor);
	bool eliminarInstructor(int idInstructor);
	Instructor** buscarInstructor(int idInstructor);
	bool existeInstructor(int idInstructor);
	void mostrarInstructores();
};

