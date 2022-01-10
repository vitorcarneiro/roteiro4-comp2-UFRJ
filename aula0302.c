/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Programa de testes funcao CalcularMaximoDivisorComum

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
#include <errno.h>

#include "aula0301.h"

#define OK					            0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define ZERO_DUPLO				        2
#define ARGUMENTO_INVALIDO			    3
#define VALOR_MAXIMO_ULL_EXCEDIDO		4

#define NUMERO_ARGUMENTOS			3
#define END_OF_STRING				'\0'

int
main (int argc, char *argv[])
{

/* \/ DECLARACAO DE VARIAVEIS \/ ------------------------------------------------------------------ */

	unsigned long long termo1, termo2;
	char *verificacao;

/* /\ DECLARACAO DE VARIAVEIS /\ ------------------------------------------------------------------ */


/* \/ TRATAMENTO DE ERROS \/ ---------------------------------------------------------------------- */

	if (argc != NUMERO_ARGUMENTOS)		/* Erro se possuir mais de 3 argumento */
	{
		printf ("Este programa devera receber dois numeros inteiros nao negativos atraves de dois argumentos\n");
		printf ("Uso: %s <inteiro-nao-negativo-longo-longo> <inteiro-nao-negativo-longo-longo>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (argv[1] == 0 && argv[2] == 0)	
	{	
		printf ("Entrada deve possuir ao menos um argumento diferente de zero (\"0\')\n");
		exit (ZERO_DUPLO);
	}
	
	if (argv[1][0] == '-' || argv[2][0] == '-')			/* Erro se primeiro caractere for hifen dos dois argumentos */
	{	
		printf ("Caractere invalido: '-'\n");
		printf ("Uso: %s <inteiro-nao-negativo-longo-longo>\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	
	termo1 = strtoull (argv [1], &verificacao, 10);
	if (*verificacao != END_OF_STRING)	/* Erro se primeiro argumento possuir caractere invalido */
	{
		printf ("Argumento 1 contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	termo2 = strtoull (argv [2], &verificacao, 10);
	if (*verificacao != END_OF_STRING)	/* Erro se segundo argumento possuir caractere invalido */
	{
		printf ("Argumento 2 contem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (errno == ERANGE)	/* Erro se alguma variavel for maior que valor maximo para unsigned long long */
	{
		printf ("Entrada excede o valor maximo permitido para \"unsigned long long\" (%llu)\n", ULLONG_MAX);
		exit (VALOR_MAXIMO_ULL_EXCEDIDO);
	}

/* /\ TRATAMENTO DE ERROS /\ ---------------------------------------------------------------------- */


/* \/ CHAMADA FUNCAO PRINCIPAL \/ ----------------------------------------------------------------- */
		
	printf ("MDC (%llu, %llu) = %llu\n", termo1, termo2, CalcularMaximoDivisorComum (termo1, termo2));	

	return OK;

/* /\ CHAMADA FUNCAO PRINCIPAL /\ ----------------------------------------------------------------- */

}

/* $RCSfile$ */
