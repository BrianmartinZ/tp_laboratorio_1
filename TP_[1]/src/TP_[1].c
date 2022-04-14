/*
 ============================================================================
 Alumno: Brian Martin Ortiz
 Div: 1C
 DNI:37806620
 Tarea: TP1

 1 Enunciado
	Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
	para ofrecerlos a sus clientes.
	Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
	El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.

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

			//LATAM
			precioDescuentoLatam=CalcularDescuento(precioLatam);
			precioInteresesLatam=CalcularIntereses(precioLatam);
			bitcoinLatam=CalcularBitcoin(precioLatam);
			costKmLatam=CostoPorKm(precioLatam,kmIngresado);


			//AEROLINEAS
			precioDescuentoAero=CalcularDescuento(precioAerolineas);
			precioInteresesAero=CalcularIntereses(precioAerolineas);
			bitcoinAero=CalcularBitcoin(precioAerolineas);
			costKmAero=CostoPorKm(precioAerolineas,kmIngresado);


			diferenciaPrecio=DiferenciaPrecio(precioAerolineas,precioLatam);



			break;
		case 4:
			system("cls");

				//IMPRIME LATAM:
				printf("Km Ingresados: %d km\n\n",kmIngresado);
				printf("LATAM: \n\n");
				printf("Precio Latam: $ %.2f\n",precioLatam);
				printf("a) El precio con Tarjeta de d�bito: $ %.2f\n",precioDescuentoLatam);
				printf("b) El Precio con tarjeta de cr�dito: $ %.2f\n",precioInteresesLatam);
				printf("c) Precio pagando con bitcoin: %f BTC\n",bitcoinLatam);
				printf("d) Precio unitario: $ %.2f\n\n",costKmLatam);

				//IMPRIME AEROLINEAS:
				printf("Km Ingresados: %d km\n\n",kmIngresado);
				printf("AEROLINEAS: \n\n");
				printf("Precio Aerolineas: $ %.2f\n",precioAerolineas);
				printf("a) El precio con Tarjeta de d�bito: %.2f\n",precioDescuentoAero);
				printf("b) El Precio con tarjeta de cr�dito: $ %.2f\n",precioInteresesAero);
				printf("c) Precio pagando con bitcoin: %f BTC\n",bitcoinAero);
				printf("d) Precio unitario: $ %.2f\n\n",costKmAero);
				printf("e) La diferencia de precios es: $ %.2f\n\n",diferenciaPrecio);


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





