/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte da funcao CalcularExponencial utilizando do...while

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
	
	expoenteLaco = (expoente < 0) ? (expoente * -1) : expoente;	
	
	long double f[expoenteLaco + 1];	
	
	f[0] = 1;
	f[1] = base;

	indiceExpoente = 2;
	
	do
	{	
		f[indiceExpoente] = f[indiceExpoente - 1] * base;
		indiceExpoente++;
	}
	while (indiceExpoente <= expoenteLaco);

	resultadoExpoente = (expoente >= 0) ? f[expoenteLaco] : 1 / f[expoenteLaco];

	return resultadoExpoente;
}

/* $RCSfile$ */
