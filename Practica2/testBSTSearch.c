/*
Implementación Práctica 02: Análisis temporal y notación de orden (Algoritmos de búsqueda)
Por: Git Gud (Equipo Arbol)
Versión: 1.0

Descripción: Programa que buscará por medio de un Árbol Binario de Búsqueda

Observaciones:

Compilación:

	gcc -o testBSTSearch testBSTSearch.c

	./testBSTSearch < UnsortedNumbers.txt >> BST.txt
*/


//LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "time.h"
#include "imprimeTiempos.h"

//VARIABLES GLOBALES
bool found = false;
int* Data;
int nSize = 10000000, keyNumber = 0;

#include "AuxBSTFunctions.h"
arbol_bin mainTree;

#include "BSTSearch.h"



// FUNCIÓN PRINCIPAL

/*
Variables usadas en el programa:
	bool found: variable que indicará si se encontró el número en la búsqueda
	int* Data: apuntador de entero que será inicializado como arreglo para los datos donde se buscará
	int nSize: variable que tomará el tamaño de la línea de comando
	int keyNumber: variable que indicará el número a buscar
	arbol_bin mainTree: estructura que simulará el ABB usado
	double utime0: variable que medirá el tiempo de inicio de ejecución del usuario
	double stime0: variable que medirá el tiempo de inicio de ejecución del sistema
	double wtime0: variable que medirá el tiempo de inicio de ejecución real
	double utime1: variable que medirá el tiempo de finalización de ejecución del usuario
	double stime1: variable que medirá el tiempo de finalización de ejecución del sistema
	double wtime1: variable que medirá el tiempo de finalización de ejecución real
	
*/
int main(int argc,char **argv){
	
	int aSizes[] = {100, 1000, 5000, 10000, 50000, 100000, 200000, 400000, 
			600000, 800000, 1000000, 2000000, 3000000, 4000000, 5000000, 
			6000000, 7000000, 8000000, 9000000, 10000000};

	int aNumbers[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 
			1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 
			214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};

	double utime0, stime0, wtime0; 	// Tiempos de inicio
	double utime1, stime1, wtime1;	// Tiempos de finalización

	Data = (int*)calloc(nSize,sizeof(int));	// Inicialización del arreglo para los números

	for (int i = 0; i < nSize; ++i){
		scanf("%d", Data+i);			// Insertamos los números en el arreglo
	}

	for (int i = 0; i < 20; ++i)
	{
		nSize = aSizes[i];

		Initialize(&mainTree);	// Iniciamos nuestro ABB para usarlo

		for(int k = 0; k < nSize; ++k){
			Insert(&mainTree, Data[k]);	// Insertamos los datos en el ABB
		}

		for (int j = 0; j < 20; ++j)
		{
			keyNumber = aNumbers[j];

			found = false;

			uswtime(&utime0, &stime0, &wtime0);		// Iniciamos los contadores de tiempo
			
			BSTSearch();	// Función que realiza la búsqueda
		
			uswtime(&utime1, &stime1, &wtime1);		// Finalizamos los contadores de tiempo
			
			double RealTime = wtime1 - wtime0;	// Asignamos el tiempo real del proceso desde su inicio hasta su finalización
			double UserTime = utime1 - utime0;	// Asignamos el tiempo que la CPU se ha dedicado exclusivamente a la computación del programa
			double SysTime  = stime1 - stime0;	// Asignamos el tiempo que la CPU se ha dedicado a dar servicio al sistema operativo por necesidades del programa
		
			imprimeTiempos(found, keyNumber, nSize, RealTime, UserTime, SysTime); // Función que mostrará los resultados
			
		}

		Destroy(&mainTree);
	}

	free(Data);	// Liberamos el arreglo de números

}