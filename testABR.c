/* ------------------------------------------------------------------------ */
/**
 *  \file       testABR.c
 *  \brief      Implémentation d'un module de test des fonction de gestion
 *				d'arbres binaires de recherche
 *
 *  \date       25 Septembre 2018
 *  \author     S. El Khattabi
 *  \version    1.0
 *
 */
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S T A N D A R D (s)					*/
/* ------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------ */
/*					I N C L U D E (s)   S P É C F I Q U E (s)				*/
/* ------------------------------------------------------------------------ */
#include "testABR.h"


#define	PROMPT	"\nNombre de tentatives d'insertion dans l'ABR"	\
"(. pour terminer) : "
/* ------------------------------------------------------------------------ */
void	test_afficherABR(void)
{
    noeudABR_t * a = NULL;
    
    printf("Affichage d'un arbre vide\n");
    afficherABR(a);
    
    printf("Affichage d'un arbre reduit a un seul noeud\n");
    a = creer1Noeud(19, NULL, NULL);
    afficherABR(a);
    
    printf("Affichage d'un arbre de plusieurs noeuds\n");
    a->gauche = creer1Noeud(12, NULL,
                            creer1Noeud(16, creer1Noeud(14, NULL, NULL),
                                            creer1Noeud(18, NULL, NULL)));
    
    a->droit  = creer1Noeud(34,
                             creer1Noeud(24, creer1Noeud(21, NULL, NULL),
                                            creer1Noeud(30, NULL, NULL)), NULL);
    
    afficherABR(a);
    a = supprimerABR(a);
}

/* ------------------------------------------------------------------------ */
void	test_afficherInverseABR(void)
{
    noeudABR_t * a = NULL;
    
    printf("Affichage inverse d'un arbre vide\n");
    afficherInverseABR(a);
    
    printf("Affichage inverse d'un arbre reduit a un seul noeud\n");
    a = creer1Noeud(19, NULL, NULL);
    afficherInverseABR(a);
    
    printf("Affichage inverse d'un arbre de plusieurs noeuds\n");
    a->gauche = creer1Noeud(12,
                            NULL,
                            creer1Noeud(16,
                                        creer1Noeud(14, NULL, NULL),
                                        creer1Noeud(18, NULL, NULL)));
    a->droit  = creer1Noeud(34,
                             creer1Noeud(24,
                                         creer1Noeud(21, NULL, NULL),
                                         creer1Noeud(30, NULL, NULL)
                                         ),
                             NULL);
    afficherInverseABR(a);
    
    a = supprimerABR(a);
}

/* ------------------------------------------------------------------------ */
void test_insererABR(void)
{
    noeudABR_t *a = NULL;
    int i, nb;
    unsigned int n;
    
    /*while(printf(PROMPT), scanf("%d", &nb))
    {
        for (i = 0; i < nb; i++)
            a = insererABR(1 + rand() % nb, a);
        
        afficherABR(a);
        n =  nbNoeudsABR(a);
        printf("Nombre effectif de noeuds = %u\n", n);
        printf("Pourcentage de reussite d'insertion = %.1f%%\n",
               (nb == 0)? 100. : 100. * n /nb);
        printf("Hauteur de l'ABR = %d\n", hauteurABR(a));
        
        a = supprimerABR(a);
    }
    while (getchar() != '\n');*/
    a = creer1Noeud(19, NULL, NULL);
    a->gauche = creer1Noeud(12,
                            NULL,
                            creer1Noeud(16,
                                        creer1Noeud(14, NULL, NULL),
                                        creer1Noeud(18, NULL, NULL)));
    a->droit  = creer1Noeud(34,
                            creer1Noeud(24,
                                        creer1Noeud(21, NULL, NULL),
                                        creer1Noeud(30, NULL, NULL)
                            ),
                            NULL);
    a=insererABR(17,a);
    afficherABR(a);
    printf("Hauteur de l'ABR = %d\n", hauteurABR(a));
    printf("Nombre effectif de noeuds = %u\n", nbNoeudsABR(a));

}

/* ------------------------------------------------------------------------ */
void	test_estDansABR(void)
{
    /* -------------------------------------------------------------------- */
    /*						À    C O M P L É T E R							*/
    /*																		*/
    /*	1)	vérifier que la recherche dans un arbre vide est correcte		*/
    /*	2)	construire un ABR en effectuant une dizaine de tentatives		*/
    /*		d'insertions : cf. test_insererABR()							*/
    /*	3)	Prendre quelques valeurs différentes (~ 3 valeurs) et			*/
    /*		afficher "la valeur xx est presente dans l'ABR" si elle s'y		*/
    /*		trouve et "la valeur xx est absente de l'ABR si c'est le cas	*/
    /*																		*/
    /*	Prévoir l'affichage de l'ABR pour le contrôle des résultats			*/
    /*																		*/
    /* -------------------------------------------------------------------- */
    printf("Test de estDansABR()\n---------------------\n");

    noeudABR_t *a = NULL;

    printf("Dans un arbre vide :\n");
    afficherABR(a);
    printf("estDansABR(18,a) = %d\n",estDansABR(18,a) );

    printf("On effectue une dizaine d'insertions :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++)
        a = insererABR(1 + rand() % nb, a);
    afficherABR(a);
    int test = 1 + rand() % nb;
    printf("estDansABR(%d,a) = %d\n",test,estDansABR(test,a) );
}

/* ------------------------------------------------------------------------ */
void	test_copierABR(void)
{
    /* -------------------------------------------------------------------- */
    /*						À    C O M P L É T E R							*/
    /*																		*/
    /*	1)	vérifier que la copie d'un arbre vide est un arbre vide			*/
    /*	2)	construire un ABR en effectuant une dizaine de tentatives		*/
    /*		d'insertions et l'afficher										*/
    /*	3)	créer la copie et l'afficher									*/
    /*	4)	supprimer l'orginal et s'assurer que sa copie est intacte		*/
    /*	5)	supprimer tous les arbres créés dans ce test					*/
    /*																		*/
    /* -------------------------------------------------------------------- */
    noeudABR_t *monArbre = NULL, *copie = NULL;
    printf("Test de copierABR()\n---------------------\n");

    printf("On copie un arbre vide dans un arbre vide. Affichage de copie :\n");
    copie = copierABR(monArbre);
    afficherABR(copie);

    printf("On effectue une dizaine d'insertions dans monArbre. Affichage de monArbre :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++)
        monArbre = insererABR(1 + rand() % nb, monArbre);
    afficherABR(monArbre);

    printf("On copie cet arbre dans la copie. Affichage de copie :\n");
    copie = copierABR(monArbre);
    afficherABR(copie);

    printf("On modifie l'arbre original, affichage de copie :\n");
    monArbre = insererABR(325,monArbre);
    afficherABR(copie);
    printf("Affichage de monArbre :\n");
    afficherABR(monArbre);

    copie = supprimerABR(copie);
    monArbre = supprimerABR(monArbre);

}


/* ------------------------------------------------------------------------ */
void	test_egalABR(void)
{
    /* -------------------------------------------------------------------- */
    /*						À    C O M P L É T E R							*/
    /*																		*/
    /*	1)	vérifier que deux arbres vides sont égaux						*/
    /*	2)	vérifier qu'un arbre vide ne peut être égal à un arbre non vide	*/
    /*	2)	construire deux ABR en effectuant une dizaine de tentatives		*/
    /*		d'insertions les afficher puis les comparer 					*/
    /*	3)	créer une copie de l'un des deux et la comparer à l'original	*/
    /*	4)	supprimer tous les arbres créés dans ce test					*/
    /*																		*/
    /* -------------------------------------------------------------------- */
    printf("Test de egalABR()\n---------------------\n");

    printf("On vérifie que 2 arbres vides sont égaux.\n");
    printf("egalABR(NULL,NULL) == %d\n",egalABR(NULL,NULL));

    noeudABR_t *monArbre1 = NULL;
    noeudABR_t *monArbreCopie = NULL;
    monArbre1 = insererABR(18,NULL);
    noeudABR_t *monArbre2 = NULL;
    printf("On crée un ABR, qui est une feuille.\n");
    printf("egalABR(monArbre1,NULL) == %d && egalABR(NULL,monArbre1) == %d\n",egalABR(monArbre1,NULL),egalABR(NULL,monArbre1));

    printf("On effectue une dizaine d'insertions dans monArbre1 et monArbre2. Affichage de monArbre1 :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++) {
        monArbre1 = insererABR(1 + rand() % nb, monArbre1);
        monArbre2 = insererABR(1 + rand() % nb, monArbre2);
    }
    afficherABR(monArbre1);
    printf("Affichage de monArbre2 :\n");
    afficherABR(monArbre2);
    printf("egalABR(monArbre1,monArbre2) == %d\n",egalABR(monArbre1,monArbre2));

    printf("On copie monArbre1 dans monArbreCopie. Affichage de monArbreCopie :\n");
    monArbreCopie = copierABR(monArbre1);
    afficherABR(monArbreCopie);
    printf("egalABR(monArbre1,monArbreCopie) == %d && egalABR(monArbreCopie,monArbre1) == %d",egalABR(monArbre1,monArbreCopie),egalABR(monArbreCopie,monArbre1));

    monArbreCopie = supprimerABR(monArbreCopie);
    monArbre1 = supprimerABR(monArbre1);
    monArbre2 = supprimerABR(monArbre2);
}

/* ------------------------------------------------------------------------ */
void	test_supprimer1EltABR(void)
{
    noeudABR_t *a = NULL;
    int i, nb, e;
    elt_t Val;
    
    /*while(printf(PROMPT), scanf("%d", &nb))
    {
        for (i = 0; i < nb; i++) {
            e = 1 + rand() % nb;
            a = insererABR(e, a);
            printf("Element inséré : ")
        }*/

        a = creer1Noeud(19, NULL, NULL);
        a->gauche = creer1Noeud(12,
                                NULL,
                                creer1Noeud(16,
                                            creer1Noeud(14, NULL, NULL),
                                            creer1Noeud(18, NULL, NULL)));
        a->droit  = creer1Noeud(34,
                                creer1Noeud(24,
                                            creer1Noeud(21, NULL, NULL),
                                            creer1Noeud(30, NULL, NULL)
                                ),
                                NULL);
        a=insererABR(17,a);
        afficherABR(a);
        printf("Nombre de noeuds de l'arbre = %u\n", nbNoeudsABR(a));
        printf("Hauteur de l'arbre = %d\n", hauteurABR(a));
        
        while (printf("\nQuelle valeur faut-il supprimer (. pour arreter) ? "), scanf("%d", &Val))
        {
            a = supprimer1EltABR(Val, a);
            afficherABR(a);
            printf("Nombre de noeuds de l'arbre = %u\n", nbNoeudsABR(a));
            printf("Hauteur de l'arbre = %d\n", hauteurABR(a));
        }
        while (getchar() != '\n');
        a = supprimerABR(a);
    }
    //while (getchar() != '\n');
    
//}

/* ------------------------------------------------------------------------ */
void    test_chercherMinABR(void)
{
    printf("Test de chercherMinABR()\n---------------------\n");

    printf("On vérifie qu'un arbre vide renvoie une valeur d'erreur (ici 1024).\n");
    printf("chercherMinABR(NULL) == %d\n",chercherMinABR(NULL));

    noeudABR_t *monArbre = NULL;
    printf("On effectue une dizaine d'insertions dans monArbre. Affichage de monArbre :\n");
    unsigned int nb = 10;
    for (unsigned int i = 0; i < nb; i++)
        monArbre = insererABR(1 + rand() % nb, monArbre);
    afficherABR(monArbre);

    printf("chercherMinABR(monArbre) == %d\n",chercherMinABR(monArbre));

    monArbre = supprimerABR(monArbre);


}
/* ------------------------------------------------------------------------ */
void	test_creerDotPng(void)
{
    noeudABR_t * a = NULL;
    unsigned int i;
    unsigned int nb;
    unsigned int val;
    
    /*while(printf("Nombre d'insertions dans l'ABR (. pour terminer) : "), scanf("%d", &nb))
    {
        for (i = 0; i < nb; )
        {
            val = 1 + rand() % nb;
            if (! estDansABR(val, a))
            {
                a = insererABR(val, a);
                creerDotABR(a, "Abr");
                i++;
            }
        }
        a = supprimerABR(a);
    }
    while (getchar() != '\n');*/
    /*a = creer1Noeud(3, NULL, NULL);
    GAUCHE(a) = creer1Noeud(2, creer1Noeud(1,NULL,NULL),NULL);
    DROIT(a) = creer1Noeud(4,NULL,creer1Noeud(5,NULL,NULL));
    afficherABR(a);*/
    a = creer1Noeud(19, NULL, NULL);
    a->gauche = creer1Noeud(12,
                            NULL,
                            creer1Noeud(16,
                                        creer1Noeud(14, NULL, NULL),
                                        creer1Noeud(18, NULL, NULL)));
    a->droit  = creer1Noeud(34,
                            creer1Noeud(24,
                                        creer1Noeud(21, NULL, NULL),
                                        creer1Noeud(30, NULL, NULL)
                            ),
                            NULL);
    //a=insererABR(17,a);

    printf("On crée l'image PNG de l'arbre suivant :\n");
    afficherABR(a);
    creerDotABR(a,"testFinal");

    a = supprimerABR(a);
}
