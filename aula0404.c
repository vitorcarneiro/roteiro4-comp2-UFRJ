/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Programa de testes para funcao CalcularSerieharmmonicaAlternada

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
#include <float.h>
#include <errno.h>
#include <math.h>

#include "aula0401.h"

#define OK					                    0
#define NUMERO_ARGUMENTOS_INVALIDO		        1
#define ARGUMENTO_INVALIDO			            2
#define VALOR_FLOAT_EXCEDIDO			        3

#define NUMERO_ARGUMENTOS			            2
#define END_OF_STRING				            '\0'

int
main (int argc, char *argv[])
{

/* \/ DECLARACAO DE VARIAVEIS \/ ------------------------------------------------------------------ */
	
	unsigned short int termoAtualN = 0;	/* n representa o termo exemplo S(2) = 1 - 1/2 (n = 2 neste caso) */
	float p, resultadoAnterior = 0, resultadoAtual = 0, modSerie = 0;
	char *verificacao;


/* /\ DECLARACAO DE VARIAVEIS /\ ------------------------------------------------------------------ */


/* \/ TRATAMENTO DE ERROS \/ ---------------------------------------------------------------------- */

	if (argc != NUMERO_ARGUMENTOS)		/* Erro se possuir mais de 2 argumentos */
	{
		printf ("Uso: %s <inteiro-nao-negativo-curto>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	p = strtof (argv [1], &verificacao);
	if (*verificacao != END_OF_STRING)	/* Erro se argumento 1 possuir caractere invalido */
	{
		printf ("Argumento termoAtualNem caractere invalido. \n");
		printf ("Primeiro caractere invalido \'%c\'.\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (p < 0 || p > 1)
	{
		printf ("Argumento deve ser maior que 0 e menor que 1.\n");
		exit (ARGUMENTO_INVALIDO);
	}	

	if (errno == ERANGE)	/* Erro se entrada for maior ou menor que valor permitido para float */
	{
		printf ("Entrada excede o valor permitido para \"float\" [entre (%.10f) e (%.10f)].\n", FLT_MIN, FLT_MAX);
		exit (VALOR_FLOAT_EXCEDIDO);
	}
	
/* /\ TRATAMENTO DE ERROS /\ ---------------------------------------------------------------------- */


/* \/ CHAMADA FUNCAO PRINCIPAL \/ ----------------------------------------------------------------- */
	
	/* |S(n) - S(n-1)| < p * S(n-1) */

	while(modSerie > p*resultadoAnterior || resultadoAnterior == 0)
	{
		resultadoAnterior = resultadoAtual;
		resultadoAtual = CalcularSerieHarmonicaAlternada(termoAtualN);
		printf("S(%hu) = %.10f\n", termoAtualN, CalcularSerieHarmonicaAlternada(termoAtualN));
		termoAtualN++;

		if((resultadoAtual - resultadoAnterior) > 0)
			modSerie = resultadoAtual - resultadoAnterior;

		else
			modSerie = resultadoAnterior - resultadoAtual;
	}

	if(termoAtualN >= 10)
	{
		printf("Valor maximo para funcao CalcularSerieHarmonicaAlternada alcancado. \n");
	}

	return OK;

/* /\ CHAMADA FUNCAO PRINCIPAL /\ ----------------------------------------------------------------- */

}

/* $RCSfile$ */
