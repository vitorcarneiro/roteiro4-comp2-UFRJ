/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte da funcao CalcularExponencial utilizando for

$Author$
$Date$
$Log$

*/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{
	int indiceExpoente, expoenteLaco;
	long double resultadoExpoente;	

    if (expoente < 0 && base == 0)
		#if defined (__STRICT_ANSI__) && defined (__linux__)
			return 1.0/0.0;
		#else
			return INFINITY;
		#endif
	
	expoenteLaco = (expoente >= 0) ? expoente : expoente * -1;
	
	long double f[expoenteLaco + 1];

	f[0] = 1;
	f[1] = base;

	for (indiceExpoente = 2; indiceExpoente <= expoenteLaco; indiceExpoente++)
		f[indiceExpoente] = f[indiceExpoente - 1] * base;

	resultadoExpoente = (expoente >= 0) ? f[expoenteLaco] : 1/f[expoenteLaco];	

	return resultadoExpoente;

}

/* $RCSfile$ */
