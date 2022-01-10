/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Codigo fonte funcao CalcularTermoSerieFibonacci utilizando for

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

	for (indiceLacoRepeticao = 2; indiceLacoRepeticao <= indiceTermoFibonacci; indiceLacoRepeticao++)
		f[indiceLacoRepeticao] = f[indiceLacoRepeticao - 1] + f[indiceLacoRepeticao -2];

	return f[indiceTermoFibonacci];
}

/* $RCSfile$ */
