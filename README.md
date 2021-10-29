# PECL1_EEDD
First project in Data Structures at the University of Alcala de Henares.


https://tutorias.co/poo-visual-c-aplicacion-clase-gps/


﻿/*
 6x04-Notacion_postfija_con_pilas
 07/02/2012
 
 Escribe un programa que lea de teclado una expresión en notación postfija y la evalúe,
 mostrando su resultado por pantalla. Para ello implementa y utiliza una pila.
*/
 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct NODO
{
 int valor;
 struct NODO *puntero;
};
 
 
 
// FUNCIÓN QUE PASA UNA CADENA CON NUMEROS A ENTERO:
int pasaCadenaAEntero( char cadena[20] )
{
 /*
 Precondición:
 Se ha de recibir una cadena de caracteres terminada en fin de linea que contenga solo un numero entero de máximo 20 dígitos.
 Poscondición:
 Se pasa esa cadena al tipo entero y se devuelve el valor.
 */
 
 
 int longCadena=strlen(cadena), numero=0, i;
 
 for( i=0; i<longCadena; i++ )
 {
 numero *= 10;
 numero += cadena[i]-48;
 };
 
 return numero;
};
 
 
 
// FUNCIÓN QUE INTRODUCE UN NUMERO EN UNA PILA:
void insertaDatoEnLaPila( struct NODO **pila, int num )
{
 /*
 Precondición:
 Se ha de recibir un doble puntero de tipo struct NODO para una pila, y un parámetro de tipo entero.
 Poscondición:
 Se introduce el numero recibido en la pila.
 */
 
 
 struct NODO *temp = (struct NODO *) malloc(sizeof(struct NODO));
 
 
 temp->valor = num;
 temp->puntero = *pila;
 *pila = temp;
 
};
 
 
 
// FUNCIÓN QUE EXTRAE EL PRIMER ELEMENTO DE LA PILA Y BORRA EL NODO VACIO:
int extraeDatoDeLaPila( struct NODO **pila )
{
 /*
 Precondición:
 Se ha de recibir un doble puntero de tipo struct NODO para una pila.
 Poscondición:
 Se devuelve el primer parámetro de tipo entero almacenado en la pila.
 */
 
 
 struct NODO *siguiente;
 int resp;
 
 // Se copia el valor a la variable que va a ser retornada por la función:
 resp = (*pila)->valor;
 
 
 // Se elimina el primer Nodo (el vaciado):
 siguiente = (*pila)->puntero;
 free(*pila);
 *pila = siguiente;
 
 
 return resp;
};
 
 
 
// FUNCIÓN QUE LIBERA LA MEMORIA USADA POR UNA LISTA:
void listaLiberaRam( struct NODO **lista )
{
 /*
 Precondición:
 Se ha de recibir un puntero de tipo struct NODO al primer nodo de la lista.
 Poscondición:
 Se borran todos los nodos de esa lista hasta llegar a NULL.
 */
 
 
 struct NODO *actual, *siguiente;
 actual = *lista;
 
 while(actual != NULL)
 {
 siguiente = actual->puntero;
 free(actual);
 actual = siguiente;
 };
 
 *lista = NULL;
 
};
 
 
 
main()
{
 
 struct NODO *pila;
 char cad[20];
 int val1, val2;
 
 
 printf( "Introduce una expresión en notación postfija para hallar el resultado.\n" );
 printf( "Introduzca un valor o operador y pulse intro para introducir el siguiente, escriba = para calcular el resultado\n" );
 printf( "  Ejemplo:\n\n   5\n   9\n   +\n   2\n   *\n   6\n   5\n   *\n   +\n\n" );
 printf( "Indique la expresion:\n\n" );
 
 
 do{
 
 // Se lee un valor o operador:
 scanf( "%s", cad );
 
 
 // Dependiendo de lo leido se hace una operacion u otra:
 switch( cad[0] )
 {
 case '+':
 // En el caso de la: '+', '-', '*' y '/', se sacan dos valores de la pila, se opera con ellos según el operador elegido y se guarda el resultado en la pila.
 
 val1 = extraeDatoDeLaPila( &pila );
 val2 = extraeDatoDeLaPila( &pila );
 insertaDatoEnLaPila( &pila, val1 + val2 );
 break;
 
 
 case '-':
 val1 = extraeDatoDeLaPila( &pila );
 val2 = extraeDatoDeLaPila( &pila );
 insertaDatoEnLaPila( &pila, val1 - val2 );
 break;
 
 
 case '*':
 val1 = extraeDatoDeLaPila( &pila );
 val2 = extraeDatoDeLaPila( &pila );
 insertaDatoEnLaPila( &pila, val1 * val2 );
 break;
 
 
 case '/':
 val1 = extraeDatoDeLaPila( &pila );
 val2 = extraeDatoDeLaPila( &pila );
 insertaDatoEnLaPila( &pila, val1 / val2 );
 break;
 
 
 case '=':
 // Se imprime por pantalla el ultimo y único elemento de la pila.
 printf( "\nEl resultado es: %i\n\n", extraeDatoDeLaPila( &pila ) /*pila->valor*/ );
 break;
 
 
 default:
 // Se introduce un nuevo dato en la pila:
 insertaDatoEnLaPila( &pila, pasaCadenaAEntero(cad) );
 break;
 };
 
 } while( cad[0] != '=' );
 
};
