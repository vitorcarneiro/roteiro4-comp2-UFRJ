/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte da funcao CalcularSerieHarmonicaAlternada utilizando recursividade

$Author$
$Date$
$Log$

*/

#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada(unsigned short int n)
{
	if (n == 0)
		return 0;

	else if (n % 2 == 0)
		return  -1/CalcularExponencial(n, n)+ CalcularSerieHarmonicaAlternada(n - 1);
		
	else
		return 1/CalcularExponencial(n, n)+ CalcularSerieHarmonicaAlternada(n - 1);
}

/* $RCSfile$ */
