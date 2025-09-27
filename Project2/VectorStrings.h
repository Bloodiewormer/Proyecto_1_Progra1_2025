#pragma once
#include <iostream>
#include <string>
class VectorStrings
{
private:
	std::string* elementos;
	int capacidad;
	int cantidad;
public:
	VectorStrings();
	~VectorStrings();
	bool buscarString(std::string s);
	int getCantidad();
	bool agregarString( std::string str);
	void mostrarStrings();
};

