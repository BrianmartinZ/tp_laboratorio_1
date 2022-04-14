#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

/// \brief Pide un numero entero al usuario.
/// \param mensaje.
/// \return Retorna un entero.
int PedirNumeroEntero(char mensaje[])
{
	int precio;

	printf("%s",mensaje);
	scanf("%d",&precio);

	return precio;

}

/// \brief Pide un numero flotante al usuario.
/// \param mensaje.
/// \return Retorna un flotante.
float PedirNumeroFlotante(char mensaje[])
{
	float precio;

	printf("%s",mensaje);
	scanf("%f",&precio);

	return precio;

}

/// \brief Valida los kilometros ingresados (no permite '0' o negativos).
/// \param kmIngresado
/// \return Retorna un entero.
int ValidarKm(int kmIngresado)
{
	while(kmIngresado<=0)
	{
		printf("Error,Ingrese nuevamente el kilometro: ");
		scanf("%d",&kmIngresado);
	}
	return kmIngresado;
}

/// \brief Valida el precio que el usuario ingreso (no permite 0 o negativos).
/// \param precioIndicado
/// \param mensaje
/// \return devuelve un flotante.
float ValidarPrecio(float precioIndicado,char mensaje[])
{
	while(precioIndicado<=0)
		{
			printf("%s",mensaje);
			scanf("%f",&precioIndicado);
		}
	return precioIndicado;
}

/// \brief Calcula el descuento del precio ingresado. (10% de descuento)
/// \param numero
/// \return retorna un flotante.
float CalcularDescuento (float numero)
{
	float descuento;

	descuento = numero * 0.1;
	numero = numero - descuento;

	return numero;
}

/// \brief Calcula los intereses del precio ingresado. (25% de interes)
/// \param numero
/// \return retorna un flotante.
float CalcularIntereses (float numero)
{
	float aumento;

	aumento = numero * 0.25;
	numero = numero + aumento;

	return numero;
}

/// \brief Calcula el precio que se paga en bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
/// \param numero
/// \return retorna un flotante.
float CalcularBitcoin (float numero)
{
	float unBitcoin;
	float resultado;
	unBitcoin = 4606954.55;
	resultado = numero / unBitcoin;

	return resultado;

}

/// \brief Calcula el precio por km ingresado.
/// \param precio del vuelo ingresado.
/// \param kmIngresado.
/// \return retorna un flotante.
float CostoPorKm (float precio,int kmIngresado)
{
	float costoKm;

	costoKm = precio / kmIngresado;

	return costoKm;
}

/// \brief Calcula La diferencia de precio entre los dos vuelos ingresados.
/// \param precioA (Aerolineas)
/// \param precioL (Latam)
/// \return retorna un flotante.
float DiferenciaPrecio (float precioA,float precioL)
{
	float diferencia;

	diferencia = precioL - precioA;

	return diferencia;
}

/// \brief Carga forzada con los datos hardcodeados.
/// \param kmIng = 7090
/// \param precioAero = 162965.00
/// \param precioLat = 159339.00
void CargaForzada(int kmIng,float precioAero,float precioLat)
{
	//DATOS HARDCODEADOS:
				 kmIng = 7090;
				 precioAero = 162965.00;
			     precioLat = 159339.00;

			     float bitcoinLatam;
			     float costKmLatam;
			     float precioDescuentoLatam;
			     float precioInteresesLatam;

			     float bitcoinAero;
			     float costKmAero;
			     float precioDescuentoAero;
			     float precioInteresesAero;
			     float diferenciaPrecio;

			     //CALCULA LATAM:
			     precioDescuentoLatam=CalcularDescuento(precioLat);
			     precioInteresesLatam=CalcularIntereses(precioLat);
			     bitcoinLatam=CalcularBitcoin(precioLat);
			     costKmLatam=CostoPorKm(precioLat,kmIng);

			     //CALCULA AEROLINEAS:
			     precioDescuentoAero=CalcularDescuento(precioAero);
			     precioInteresesAero=CalcularIntereses(precioAero);
			     bitcoinAero=CalcularBitcoin(precioAero);
			     costKmAero=CostoPorKm(precioAero,kmIng);


			     diferenciaPrecio=DiferenciaPrecio(precioAero,precioLat);

			     //IMPRIME LATAM:
			     printf("Km Ingresados: %d km\n\n",kmIng);
			     printf("LATAM: \n\n");
			     printf("a) Precio Latam: $ %.2f\n",precioLat);
			     printf("a) El precio con Tarjeta de débito: $ %.2f\n",precioDescuentoLatam);
			     printf("b) El Precio con tarjeta de crédito: $ %.2f\n",precioInteresesLatam);
			     printf("c) Precio pagando con bitcoin: %f BTC\n",bitcoinLatam);
			     printf("e) Precio unitario: $ %.2f\n\n",costKmLatam);

			     //IMPRIME AEROLINEAS:
			     printf("Km Ingresados: %d km\n\n",kmIng);
			     printf("AEROLINEAS: \n\n");
			     printf("a) Precio Aerolineas: $ %.2f\n",precioAero);
			     printf("a) El precio con Tarjeta de débito: %.2f\n",precioDescuentoAero);
			     printf("b) El Precio con tarjeta de crédito: $ %.2f\n",precioInteresesAero);
			     printf("c) Precio pagando con bitcoin: %f BTC\n",bitcoinAero);
			     printf("e) Precio unitario: $ %.2f\n\n",costKmAero);
			     printf("f) La diferencia de precios es: $ %.2f\n\n",diferenciaPrecio);


}

/// \brief Muestra las distintas opciones que puede seleccionar el usuario.
/// \param opcionesNumero
/// \return retorna un entero.
int MostrarOpciones(int opcionesNumero)
{
	printf("MENU DE OPCIONES\n\n");
	printf("1. Ingresar Kilómetros: \n");
	printf("2. Ingresar Precio de Vuelos: \n");
	printf("3. Calcular todos los costos: \n");
	printf("4. Informar Resultados \n");
	printf("5. Carga forzada de datos \n");
	printf("6. Salir \n\n");
	printf("Elija una opcion: ");
	scanf("%d",&opcionesNumero);

	return opcionesNumero;
}



