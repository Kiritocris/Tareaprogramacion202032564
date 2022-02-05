#include <iostream>
#include <string>
#include "Header.h"
//#include <iomanip>

using namespace std;

int main()
{
	int num_est = 0;// Número del objeto en el vector
	int numero_objeto = 0;// Apuntador del número del objeto
	int opcion; // Opción del menú
	char nom[50]; // Arreglo de 50 caracteres para el nombre
	int i = 0;// Auxiliar
	int n = 0; // Opción en el menú
	int dim; // Dimensión del arreglo de objetos
	Alumno* p;
	int l = 0;// Crea un puntero a objeto alumno
	// Alumno* p = new Alumno[dim];

	cout << "Cuantos alumnos tiene la clase? ";
	cin >> dim; //Para cuantos objetos hay que reservar memoria?
	cout << "\n";
	p = new Alumno[dim]; /* Asigna memoria dinámicamente y se crea el arreglo de tipo
	Alumno*/

	if (p == 0)//Si p = O no hay memoria suficiente
	{
		cout << "Error no hay suficiente memoria";
		return 0;

		//Sale del programa
	};

	do //estructura do .. .while que mantiene en el ciclo principal
	{
		cout << " Menu" << endl;
		cout << " 1. Registrar datos alumno y asignatura." << endl;
		cout << " 2. Ver lista de estudiantes inscritos." << endl;
		cout << " 3. Reporte de un estudiante." << endl;
		cout << " 4. Salir." << endl;
		cout << "------------------------------------------------" << endl;
		fflush(stdin);
		cout << "\n Elija una opcion del menu (1-4): ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			if (l == dim) {
				cout << "Numero limite de estudiantes alcanzado" << endl;
				system("pause");
				system("cls");
				break;
			}
			else {
				l++;
				//Acabas de ingresar un valor int
				(p + numero_objeto)->ingresar(); //operador flecha en vez de operador punto numero_objeto++;
				numero_objeto = numero_objeto + 1;
				system("cls");
				break;
			}
		case 2:
			cout << "\n";
			cout << "------------------------------------------------------" << endl;
			cout << "LISTADO DE ESTUDIANTES INSCRITOS-----------------" << endl;
			for (i = 0; i < dim; i++)
			{
				cout << "Estudiante numero " << i + 1;
				cout << ": ";
				(p + i)->mostrar_nombre();
				cout << "\n";
			} cout << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Ingrese el numero de lista del estudiante a generar el reporte: ";
			cin >> n;
			if (n > 0)
			{
				cout << "------------------------------------------------------" << endl;
				cout << " ALUMNO:";

				(p + n - 1)->mostrar_nombre();
				cout << endl << endl;
				cout << " NOTAS DE LAS ASIGNATURAS OBTENIDAS";
				cout << "\n";
				(p + n - 1)->reporte();

				cout << "-----------------------------------------------------" << endl;
			}
			else
				cout << "Digite un codigo de alumno valido " << endl;

			cout << endl;
			system("pause");
			system("cls"); break;

		case 4:
			break;

		default:
			cout << "\n\n Ingrese una opcion valida del menu.\n";
			system("pause");
			system("cls");
		}
	} while (opcion != 4); //sale del programa

	delete[] p; //libera la memoria asignada a *p
	return 0;
}