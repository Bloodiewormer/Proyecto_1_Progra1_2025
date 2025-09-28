// C++
// File: 'Project2/VectorClientes.h' (add getter by index)
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
	Cliente* getClientePorIndice(int i);
	int getCantidad();
	bool agregarCliente( Cliente* cliente);
	Cliente** buscarCliente(int idCliente);
	bool existeCliente(int idCliente);
	void mostrarClientes();

	void toString();


};
