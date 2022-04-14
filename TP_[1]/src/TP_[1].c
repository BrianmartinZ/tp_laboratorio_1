/*
 ============================================================================
 Alumno: Brian Martin Ortiz
 Div: 1C
 DNI:37806620
 Tarea: TP1
 1 Enunciado
	Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
	para ofrecerlos a sus clientes.
	Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
	El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"



int main(void) {

	setbuf(stdout,NULL);

	int opciones;
	int kmIngresado;

	float precioLatam;
	float bitcoinLatam;
	float costKmLatam;
	float precioDescuentoLatam;
	float precioInteresesLatam;

	float precioAerolineas;
	float bitcoinAero;
	float costKmAero;
	float precioDescuentoAero;
	float precioInteresesAero;
	float diferenciaPrecio;


	do
	{
		opciones=MostrarOpciones(opciones);

		switch(opciones)
		{

		case 1:

			system("cls");
			kmIngresado=PedirNumeroEntero("Ingrese los kilometros: ");
			kmIngresado=ValidarKm(kmIngresado);

			break;
		case 2:
			system("cls");
			precioAerolineas=PedirNumeroFlotante("Ingrese el precio de Aerolineas: ");
			precioLatam=PedirNumeroFlotante("Ingrese el precio de Latam: ");

			precioAerolineas=ValidarPrecio(precioAerolineas,"Error,Ingrese el precio Aerolineas nuevamente:");
			precioLatam=ValidarPrecio(precioLatam,"Error,Ingrese el precio Latam nuevamente:");

			break;
		case 3:
			system("cls");

			//CALCULA LATAM
			precioDescuentoLatam=CalcularDescuento(precioLatam);
			precioInteresesLatam=CalcularIntereses(precioLatam);
			bitcoinLatam=CalcularBitcoin(precioLatam);
			costKmLatam=CostoPorKm(precioLatam,kmIngresado);
			//CALCULA AEROLINEAS
			precioDescuentoAero=CalcularDescuento(precioAerolineas);
			precioInteresesAero=CalcularIntereses(precioAerolineas);
			bitcoinAero=CalcularBitcoin(precioAerolineas);
			costKmAero=CostoPorKm(precioAerolineas,kmIngresado);

			diferenciaPrecio=DiferenciaPrecio(precioAerolineas,precioLatam);

			break;
		case 4:
			system("cls");

			//IMPRIME LATAM:
			ImprimirResultadosLatam(kmIngresado,precioLatam,precioDescuentoLatam,precioInteresesLatam,bitcoinLatam,costKmLatam,diferenciaPrecio);

			//IMPRIME AEROLINEAS:
			ImprimirResultadosAero(kmIngresado,precioAerolineas,precioDescuentoAero,precioInteresesAero,bitcoinAero,costKmAero,diferenciaPrecio);

			break;
		case 5:

			CargaForzada(kmIngresado,precioAerolineas,precioLatam);

			break;
		case 6:
			printf("Gracias por utilizar la app.");
			break;
		}

	}while(opciones!=6);

	return EXIT_SUCCESS;
}//FIN DEL MAIN





