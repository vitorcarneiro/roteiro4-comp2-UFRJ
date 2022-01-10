/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Implementação funcao CalcularmaximoDivisorComum com recursividade

$Author$
$Date$
$Log$

*/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull termo1, ull termo2)
{
	if (termo2 != 0)
		return CalcularMaximoDivisorComum (termo2, termo1 % termo2);

	else
		return termo1;

}

/* $RCSfile$ */