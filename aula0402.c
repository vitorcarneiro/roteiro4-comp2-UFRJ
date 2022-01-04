/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Programa de testes para funcao CalcularExponencial

$Author$
$Date$
$Log$

*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <math.h>

#include "aula0401.h"

#define OK                                  0
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ARGUMENTO_INVALIDO	                2
#define VALOR_DOUBLE_EXCEDIDO               3
#define VALOR_INT_EXCEDIDO			        4
#define BASE_ZERO_E_EXPOENTE_NEGATIVO		5

#define NUMERO_ARGUMENTOS			        3
#define END_OF_STRING				        '\0'

int
main (int argc, char *argv[])
{

/* \/ DECLARACAO DE VARIAVEIS \/ ------------------------------------------------------------------ */
	
	long double calculoExponencial;
	double base;
	long expoenteLongo;
	char *verificacao;
	int expoente;

/* /\ DECLARACAO DE VARIAVEIS /\ ------------------------------------------------------------------ */


/* \/ TRATAMENTO DE ERROS \/ ---------------------------------------------------------------------- */

	if (argc != NUMERO_ARGUMENTOS)		/* Erro se possuir mais de 3 argumento */
	{
		printf ("Uso: %s <real-dupla_precisao> <inteiro>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	base = strtod (argv[1], &verificacao);
	if (*verificacao != END_OF_STRING)	/* Erro se argumento 1 possuir caractere invalido */
	{
		printf ("Argumento 1 contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (errno == ERANGE)	/* Erro se base for maior ou menor que valor permitido para double */
	{
		printf ("Entrada excede o valor permitido para \"double\" [entre (%.0f) e (%.0f)]\n",DBL_MIN, DBL_MAX);
		exit (VALOR_DOUBLE_EXCEDIDO);
	}
	
	expoenteLongo = strtol (argv [2], &verificacao, 10);
	if (*verificacao != END_OF_STRING)	/* Erro se segundo argumento possuir caractere invalido */
	{
		printf ("Argumento 2 contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (expoenteLongo > INT_MAX || expoenteLongo < INT_MIN)	/* Erro se expoente for maior que valor permitido para int */
	{
		printf ("Entrada excede o valor permitido para \"inteiro\" [entre (%i) e (%i)]\n", INT_MIN, INT_MAX);
		exit (VALOR_INT_EXCEDIDO);
	}
	
/* /\ TRATAMENTO DE ERROS /\ ---------------------------------------------------------------------- */


/* \/ CHAMADA FUNCAO PRINCIPAL \/ ----------------------------------------------------------------- */

	expoente = (int) expoenteLongo;
	calculoExponencial = CalcularExponencial (base, expoente);
	
	if (calculoExponencial <= LDBL_MAX) /* Retorna erro se o calculo for maior que valor maximo para long double */
		printf ("\n%.10f ^ %i = %.10Lf\n", base, expoente, CalcularExponencial (base, expoente));	/*Imprime calculo sem erro */

	else
		printf ("Impossivel calcular (%.10f ^ %i), resultado excede valor maximo permitido para long double\n", base, expoente);

	return OK;

/* /\ CHAMADA FUNCAO PRINCIPAL /\ ----------------------------------------------------------------- */

}

/* $RCSfile$ */
