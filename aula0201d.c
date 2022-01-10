/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo Fonte funcao CalcularTermoSerieFibonacci utilizando while

$Author$
$Date$
$Log$

*/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us indiceTermoFibonacci)
{
	ull f[indiceTermoFibonacci];
	us indiceLacoRepeticao;

	f[0] = 0;
	f[1] = 1;

	indiceLacoRepeticao = 2;

	while (indiceLacoRepeticao <= indiceTermoFibonacci)
	{
		f[indiceLacoRepeticao] = f[indiceLacoRepeticao - 1] + f[indiceLacoRepeticao - 2];
		indiceLacoRepeticao++;
	}
	
	return f[indiceTermoFibonacci];

}

/* $RCSfile$ */
