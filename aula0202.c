/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Programa de testes para funcao CalcularTermoSerieFibonacci

$Author$
$Date$
$Log$

*/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "aula0201.h"

#define OK					                0
#define NUMERO_ARGUMENTOS_INVALIDO		    1
#define ARGUMENTO_INVALIDO			        2
#define VALOR_MAXIMO_US_EXCEDIDO		    3
#define VALOR_MAXIMO_ULL_EXCEDIDO		    4

#define NUMERO_ARGUMENTOS			        2
#define END_OF_STRING                       '\0'

int
main (int argc, char *argv[])
{

/* \/ DECLARACAO DE VARIAVEIS \/ ------------------------------------------------------------------ */

	unsigned long indiceTermoFibonacci;
	unsigned short indiceLacoRepeticao;
	char *verificacao;

/* /\ DECLARACAO DE VARIAVEIS /\ ------------------------------------------------------------------ */


/* \/ TRATAMENTO DE ERROS \/ ---------------------------------------------------------------------- */

	if (argc != NUMERO_ARGUMENTOS)		/* Erro se possuir mais de 2 argumentos */
	{
		printf ("Uso: %s <inteiro-nao-negativo-curto>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (argv[1][0] == '-')			/* Erro se primeiro caractere for hifen */
	{	
		printf ("Caractere invalido: '-'\n");
		printf ("Uso: %s <inteiro-nao-negativo-curto>\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	
	indiceTermoFibonacci = strtoul (argv [1], &verificacao, 10);
	if (*verificacao != END_OF_STRING)	/* Erro se possuir caractere invalido */
	{
		printf ("Argumento contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (indiceTermoFibonacci > USHRT_MAX)	/* Erro se variavel for maior que valor maximo para unsigned short */
	{
		printf ("Entrada excede o valor maximo permitido para \"unsigned short\" (%u)\n", USHRT_MAX);
		exit (VALOR_MAXIMO_US_EXCEDIDO);
	}

/* /\ TRATAMENTO DE ERROS /\ ---------------------------------------------------------------------- */


/* \/ CHAMADA FUNCAO PRINCIPAL \/ ----------------------------------------------------------------- */
	
	if (indiceTermoFibonacci > 92)
		for (indiceLacoRepeticao = 0; indiceLacoRepeticao <= 93; indiceLacoRepeticao++)
		{
			if (indiceLacoRepeticao > 92)
			{
				printf ("Valor maximo permitido pela funcao foi excedido \"unsigned long long\" (%llu). \n", ULLONG_MAX);
				exit (VALOR_MAXIMO_ULL_EXCEDIDO);
			}
			printf ("F (%hu) = %llu\n", indiceLacoRepeticao, CalcularTermoSerieFibonacci (indiceLacoRepeticao));
		}

	for (indiceLacoRepeticao = 0; indiceLacoRepeticao <= indiceTermoFibonacci; indiceLacoRepeticao++)	
		printf ("F (%hu) = %llu\n", indiceLacoRepeticao, CalcularTermoSerieFibonacci (indiceLacoRepeticao));
	
	return OK;

/* /\ CHAMADA FUNCAO PRINCIPAL /\ ----------------------------------------------------------------- */

}

/* $RCSfile */