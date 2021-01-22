// Codigo principal del proyecto "Autolavado' Cruz Martinez Jesus Alberto grupo: 37 fundamentos de programacion:
#include <stdio.h>
#include "Funciones.h"
// codigo prueba
int main(){
	// DECLARACIÓN VARIABLES
    int opcionTamano = 0;
    int localCerrado = 1;
    int clienteNumero = 1;
    float precio = 0.0;
	float costoTamano = 0.0;
	float costoTipo = 0.0;
	float costoTipoTotal = 0.0;
    int opcionTipo = 0;	
	int gananciasTotales = 0;
	int seguir = 1;
    FILE *fichero;
	FILE *ficheroEmpleado;
	
	// INICIO DE FUNCIONALIDAD
    printf("***************************************** \n");
    printf("Bienvenidos al autolavado 'Performancewash' \n");
    printf("***************************************** \n");

    while(localCerrado == 1){
		
		// Se abre archivo con a, que significa que si no existe lo crea y si existe continua escribiendo en el
        fichero = fopen("Tickets.txt", "a");
		ficheroEmpleado = fopen("Empleado.txt", "a");
		
        // fputs escribe una cadena en el archivo
        fputs("************************************** \n", fichero);
		fputs("************************************** \n", ficheroEmpleado);
		
        // fprintf permite escribir en el archivo pero usando variables
        fprintf (fichero, "** Ticket del cliente número %i ** \n", clienteNumero);
		fprintf (ficheroEmpleado, "** Trabajo para el cliente número %i ** \n", clienteNumero);
		
		opcionTamano = SeleccionDeTamano(fichero);
		costoTamano = PrecioPorTamano(opcionTamano, fichero);		
		do{
			opcionTipo = SeleccionDeTipoDeLavado(fichero);
			costoTipo = PrecioPorTipoDeLavado(opcionTipo, fichero, ficheroEmpleado);
			costoTipoTotal = costoTipoTotal = costoTamano; //  Se suma el costo de la opción seleccionado mas lo que ya se llevaba
			seguir = RequiereOtroTipoDeLavado();
        } while (seguir == 1);

        precio = costoTamano + costoTipoTotal; // Se suma el total de todos los tipos seleccionados mas el costo del tamaño seleccionado dando como resultado precio final
        
		fputs("************************************** \n", fichero);
        fputs("\n", fichero);
        fprintf (fichero, "- TOTAL: .................... $%f \n", precio);
        fputs("----------------------------------- \n", fichero);
        fputs("\n", fichero);
        fputs("\n", fichero);
        fclose(fichero);
        
        printf("Tu precio a pagar es %f: \n", precio);
        printf("No olvides revisar tu ticket para ver el desglose de tu compra \n");		
		
		fputs("************************************** \n", ficheroEmpleado);
		gananciasTotales = gananciasTotales + precio;
		fprintf (ficheroEmpleado, "- GANANCIA TOTAL: ...................  $%d \n", gananciasTotales);
		fprintf (ficheroEmpleado, "- Llevas un total de %i clientes atendidos. \n", clienteNumero);
		fputs("--------------- \n", ficheroEmpleado);
		fputs("\n", ficheroEmpleado);
		fputs("\n", ficheroEmpleado);
		fclose(ficheroEmpleado);
	
	
	 
        printf("¿Deseas atender a otro cliente? (1 - si, 0 - no)");
        scanf("%i", &localCerrado);
        clienteNumero++;
    }

    printf("Local Cerrado");

    return 0;
}
// Aqui empieza el codigo Funciones.h  que es nuestra libreria personalizada 

// Codigo funciones .h de proyecto "Autolavado"
/**Función que devuelve el tamaño */
int SeleccionDeTamano(FILE *fichero){
	int opcionTamano = 1;
	
	printf("¿De que tamano es el auto? \n");
    printf("1 - Chico hatchback $80 \n");
    printf("2 - Mediano sedan $120\n");
    printf("3 - Grande  camionera mediana $150\n");        
    printf("4 - Camioneta $300\n");
    scanf("%i", &opcionTamano);
	
	return opcionTamano;
}

/**Función que devuelve el tipo de lavado seleccionado */
int SeleccionDeTipoDeLavado(FILE *fichero){
	int opcionTipo = 1;
	
	printf("¿Que tipo de lavado quieres? \n");
    printf("1 - Basico (solo carroseria) - $30\n");
    printf("2 - Basico + interiores  - $60 \n");
    printf("3 - Basico + interiores + vestiduras - $90 \n");
    printf("4 - Basico + interiores + vestiduras + motor - $150 \n");
    printf("5 - Basico + interiores + vestiduras + motor + encerado - $180 \n");
    printf("6 - Abolladuras y rayones - $300 \n");
	printf("7 - Solo encerado - $50 \n");
	printf("8 - Solo vestiduras - $40 \n");
	printf("9 - Solo interiores - $40 \n");
	printf("10 - Solo lavado de motor $60 \n");
    scanf("%i", &opcionTipo);
	
	return opcionTipo;
}


/**Función que devuelve el costo dependiendo el tamaño */
float PrecioPorTamano(int opcionTamano, FILE *fichero){
	float costoTamano = 0.0;

    /*funcionalidad*/
    switch (opcionTamano){
        case 1: // chico
            costoTamano = 50.0;
            fputs("- Coche chicho hatchback ............... $80.0 \n", fichero);
            break;
        case 2: // mediano
            costoTamano = 80.0;
            fputs("- Coche mediano sedan ............. $120.0 \n", fichero);
            break;
        case 3: // grande
            costoTamano = 100.0;
            fputs("- Coche grande camioneta mediana.............. $100.0 \n", fichero);
            break;

        case 4: // muy grande
            costoTamano = 300.0;
            fputs("- Coche grande camioneta.......... $300.0 \n", fichero);
            break;
        default://Todo
            printf("Vuelve a ingresar los valores.");
            break;
    }
	return costoTamano;
}

/**Función que devuelve el costo dependiendo el tipo de lavado */
float PrecioPorTipoDeLavado(int opcionTipo, FILE *fichero, FILE *ficheroEmpleado){
    /*declaracion de variables*/
    float costoTipo = 0.0;
	switch (opcionTipo){
		case 1: // basico
			fputs("- Basico (solo carroseria) ............. $30.0 \n", fichero);
			fputs("- Basico (solo carroseria) \n", ficheroEmpleado);
			costoTipo = 30.0;
			break;
		case 2: // Interiores
			fputs("- Basico + interiores .......... $60.0 \n", fichero);
			fputs("- Basico + interiores \n", ficheroEmpleado);
			costoTipo = 60.0;
			break;
		case 3: // Vestiduras
			fputs("- Basico + interiores + vestiduras .......... $90.0 \n", fichero);
			fputs("- Basico + interiores + vestiduras \n", ficheroEmpleado);
			costoTipo = 90.0;
			break;
		case 4: // Motor
			fputs("- Basico + interiores + vestiduras + Motor ............ $120.0 \n", fichero);
			fputs("- Basico + interiores + vestiduras + Motor \n", ficheroEmpleado);
			costoTipo = 120.0;
			break;
		case 5: // Enceradi
			fputs("- Basico + interiores + vestiduras + motros + encerado .................... $150.0 \n", fichero);
			fputs("- Basico + interiores + vestiduras + motros + encerado \n", ficheroEmpleado);
			costoTipo = 150.0;
			break;
		case 6: // Abolladuras y rayones
			fputs("- Abolladuras y rayones........ $300.0 \n", fichero);
			fputs("- Abolladuras y rayones \n", ficheroEmpleado);
			costoTipo = 300.0;
			break;
		case 7: // Solo encerado
			fputs("- Solo encerado ............ $40 \n", fichero);
			fputs("- Solo encerado \n", ficheroEmpleado);
			costoTipo = 50.0;
			break;
		case 8: // Solo vestiduras
			fputs("- Solo vestiduras ............... $40 \n", fichero);
			fputs("- Solo vestiduras \n", ficheroEmpleado);
			costoTipo = 40.0;
			break;
		case 9: // Solo interiores
			fputs("- Solo interiores ............. $40 \n", fichero);
			fputs("- Solo interiores \n", ficheroEmpleado);
			costoTipo = 40;
			break;
		case 10: // Solo lavado de motor
			fputs("- Solo lavado de motor ............. $60 \n", fichero);
			fputs("- Solo lavado de motor \n", ficheroEmpleado);
			costoTipo = 60;
			break;
		default://Todo
			printf("Vuelve a ingresar los valores.");
			break;
	}

    return costoTipo;
}
		
		
// Pregunta si desea agregar otro tipo de lavado
int RequiereOtroTipoDeLavado(){
	int seguir = 1;
	printf("¿Quieres agregar otro tipo de lavado? \n");
    printf("1 - si \n");
    printf("2 - no \n");
    scanf("%i", &seguir);
	return seguir;
}
