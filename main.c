#include <stdio.h>
#include <stdlib.h>
#include "liste.h"



int main( void ) {

    Liste l1;

    initVide(&l1);

    empile(1, &l1);
    empile(0, &l1);
    empile(6, &l1);
    empile(7, &l1);
    empile(-5, &l1);
    empile(1, &l1);
    empile(-2, &l1);
    empile(0, &l1);

    affiche_iter(l1);

    Liste l2;

    initVide(&l2);

    empile(1, &l2);
    empile(2, &l2);
    empile(3, &l2);

    /*Question1*/
    ZEPUODOT(l1);

    /* Question 2 */
    Pluscourte(l1,l2);

    /* Q3 version recursive terminale avec sous fonction*/
    ND0APK(l1,3);

    /* Q3 version recursive*/
    printf("il y a %d fois de zero avant la position k \n",ND0APKR(l1,3));


    /* Q3 version recursive terminale avec sous procedure*/
    printf("il y a %d fois de zero avant la position k \n",ND0APKP(l1,3));


    /* Q3 version itérative*/
    ND0APKI(l1,3);


    /* Q4 Nombre de 0 apres k*/
    ND0ARPK(l1,3);

    /*Fonction Begaye version recursive*/
    affiche_rec(BegayeFR(l1));


    /*Fonction Begaye version recursive*/
    BegayeFI(l1);

    BegayeFRT(l1);

    BegayePRT(l1);




















}
