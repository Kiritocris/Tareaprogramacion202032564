#pragma once
#include <iostream>
#include <string>
#define CAL 5 // Define constante para el numero de calificaciones a manejar
#define PERLAB 4
using namespace std;

class Alumno
{
private:
	string nombre;
	float asignaturas[CAL]{};
	float data[PERLAB]{};
	

public:
	Alumno() { };//Constructor
	~Alumno() { };//Destructor
	void ingresar();
	void mostrar_nombre();
	void reporte();
};
