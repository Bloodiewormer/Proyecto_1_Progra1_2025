#pragma once
#include <iostream>
#include "Sucursal.h"
class VectorSucursales
{
private:
	Sucursal** sucursales;
	int capacidad;
	int cantidad;
public:
	VectorSucursales();
	~VectorSucursales();
	bool agregarSucursal(Sucursal* sucursal);
	bool eliminarSucursal(int idSucursal);
	Sucursal** buscarSucursal(int idSucursal);
	bool existeSucursal(int idSucursal);
	void mostrarSucursales();
};

