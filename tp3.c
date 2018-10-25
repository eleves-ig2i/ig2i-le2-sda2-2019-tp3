/**
 *  \file       tp3.c
 *  \brief      Programme de test du module de gestion d'un
 *              arbre binaire de recherche contenant des valeurs
 *              entières
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S T A N D A R D (s)					*/
/* ------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S P É C F I Q U E (s)				*/
/* ------------------------------------------------------------------------ */
#include "tp3.h"
#include "testABR.h"

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main(void)
 *  \brief      Fonction principale unique destinée ici à effectuer les
 *				tests des différentes fonctions réalisées en TP
 *
 *				L'ensemble des tests prévus est encadré des directives
 *				de compilation conditionnelle #if ... #endif.
 *				Il suffit d'extraire de cette zone le test à effectuer
 *				et de l'insérer avant, pour activer le test en question.
 *				Le remettre dans sa zone initiale, lorsqu'il devient
 *				inutile de  l'exécuter.
 *
 *  \param      néant
 *  \return     EXIT_SUCCESS
 */
int main(void)
{
    prologue();

    test_creerDotPng();
    
#if (0)
    test_afficherABR();
    test_afficherInverseABR();
    test_insererABR();
    test_copierABR();
    test_egalABR();
    test_estDansABR();
    test_chercherMinABR();
    test_supprimer1EltABR();
    test_creerDotPng();
#endif
    
    return EXIT_SUCCESS;
}
/* -------------------------------------------------------- End of Tp3.c -- */

