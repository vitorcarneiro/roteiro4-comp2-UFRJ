/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte da funcao CalcularExponencial utilizando recursividade

$Author$
$Date$
$Log$

*/

#include <math.h>

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{
	if (expoente == 0)
		return 1;

	else if (expoente < 0 && base == 0)
		#if defined (__STRICT_ANSI__) && defined (__linux__)
			return 1.0/0.0;
		#else
			return INFINITY;
		#endif
	
	else if (expoente > 0)
		return base * CalcularExponencial (base, expoente - 1);

	else
		return 1 / CalcularExponencial (base,  expoente * -1);
}

/* $RCSfile$ */
