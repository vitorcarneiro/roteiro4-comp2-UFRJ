/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte da funcao CalcularTermoSerieFibonacci utilizando recursividade

$Author$
$Date$
$Log$

*/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us indiceTermoFibonacci)
{
	ull resultado = 0;

	if (indiceTermoFibonacci == 0)
		resultado = 0;
	
	else if (indiceTermoFibonacci == 1)
		resultado = 1;

	else
		resultado = (CalcularTermoSerieFibonacci (indiceTermoFibonacci - 1) + CalcularTermoSerieFibonacci (indiceTermoFibonacci - 2));
	
	return resultado;
}


/* $RCSfile$ */
