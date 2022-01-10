/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte funcao CalcularTermoSerieFibonacci utilizando do...while

$Author$
$Date$
$Log$

*/

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us indiceTermoFibonacci)
{
	ull f[indiceTermoFibonacci + 2];
	us indiceLacoRepeticao;

	f[0] = 0;
	f[1] = 1; 

	indiceLacoRepeticao = 2;

	do
	{
		f[indiceLacoRepeticao] = f[indiceLacoRepeticao - 1] + f[indiceLacoRepeticao - 2];
		indiceLacoRepeticao++;

	}
	while (indiceLacoRepeticao <= indiceTermoFibonacci);

	return f[indiceTermoFibonacci];
}

/* $RCSfile$ */
