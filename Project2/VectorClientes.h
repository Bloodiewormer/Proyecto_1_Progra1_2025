#pragma once
#include <iostream>
#include "Cliente.h"
class VectorClientes
{
private:
	Cliente** clientes;
	int capacidad;
	int cantidad;
public:
	VectorClientes();
	~VectorClientes();
	int getCantidad();
	bool agregarCliente( Cliente* cliente);
	Cliente** buscarCliente(int idCliente);
	bool existeCliente(int idCliente);
	void mostrarClientes();
};

