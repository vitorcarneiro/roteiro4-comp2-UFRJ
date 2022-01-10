/* 
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Vitor Carneiro Silva de Oliveira
Descricao: Funcao CalcularMaximoDivisorComum utilizando for

$Author$
$Date$
$Log$



*/

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull termo1, ull termo2)
{
    ull indice, resultadoMdc; 

    for(indice = 1; indice <= termo1 && indice <= termo2; indice++)
    {
        /* Checa se o indice eh o mdc */
        if(termo1 % indice == 0 && termo2 % indice == 0)
            resultadoMdc = indice;
    }

    return resultadoMdc; 
}

/* $RCSfile$ */