/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Funcao CalcularMaximoDivisorComum utilizando do...while

$Author$
$Date$
$Log$

*/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull termo1, ull termo2)
{
	ull termoTemporario;

	do
	{
		termoTemporario = termo2;
		termo2 = termo1 % termo2;
		termo1 = termoTemporario;
	}
	while (termo2 != 0);

	return termo1;	
}

/* $RCSfile$ */
