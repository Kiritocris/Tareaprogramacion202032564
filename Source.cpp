#include<iostream>
#include<string>
#include "Header.h"


void Alumno::ingresar() //Ingresa los datos de un alumno
{
	//fflush(stdin);
	cin.ignore();//

	cout << "Ingrese el Nombre del estudiante : ";
	//gets(nombre);
	getline(cin, nombre);

	int i;
	int j;
	for (i = 0; i < CAL; i++)
	{
		system("cls");
		float prom = 0;
		cout << "Asignatura " << i + 1 << endl;
		for (j = 0; j < PERLAB-1; j++) {
			cout << "Introduzca la calificacion del periodo " << j + 1 << " :";
			cin>>data[j];
			if (j == 0){
				prom = prom+(data[j] *.30);
			}
			else{
				prom = prom+(data[j]*.35);
			}
			
		}
		cout << "Introduzca su nota de laboratorio final:";
		cin >> data[j];
		prom =((data[j])*.40)+(prom*.60);
		asignaturas[i] = prom;
	}
}

void Alumno::mostrar_nombre()
{
	cout << nombre; //Escribe el nombre del alumno en la pantalla
}

void Alumno::reporte()
{
	int i;

	//Genera reporte del estudiante seleccionado

	cout << " ------------------------------------------------------" << endl;

	// Se le da formato a la tabla.
	for (i = 0; i < CAL; i++)
	{
		cout << "ASIGNATURA " << i + 1 << " : "<<endl;
		cout << "NOTA FINAL : " << asignaturas[i] << "  ";
		if (asignaturas[i] >= 6) {
			cout << "APROBADO C:" << endl;
		}
		else {
			cout << "REPROBADO :C" << endl;
		}
		cout << "*******************" << endl;

	}
}