
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"



/*************************************************/
/*                                               */
/*                briques de base                */
/*                                               */
/*************************************************/


void initVide( Liste *L)
{
    *L = NULL ;
}

bool estVide(Liste l)
{
    return l == NULL ;
}

int premier(Liste l)
{
    return l->nombre ;
}

Liste ajoute(int x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;
    tmp->nombre = x ;
    tmp->suivant = l ;
    return tmp ;
}

void empile(int x, Liste *L)
{
    *L = ajoute(x,*L) ;
}

Liste suite(Liste l)
{
    return l->suivant ;
}


void depile(Liste *L)
{
    Liste tmp = *L ;
    *L = suite(*L) ;
    free(tmp) ;
}

/*************************************************/
/*                                               */
/*     Affiche, avec les briques de base         */
/*                                               */
/*************************************************/

void affiche_rec(Liste l)
{
    if(estVide(l))
        printf("\n");
    else
    {
        printf("%d ", premier(l));
        affiche_rec(suite(l));
    }
}


void affiche_iter(Liste l)
{
    Liste L2 = l;
    while(!estVide(L2))
    {
        printf("%d ", premier(L2));
        L2 = suite(L2);
    }
    printf("\n");
}

/*************************************************/
/*                                               */
/*     Longueur, sans les briques de base        */
/*                                               */
/*************************************************/

int longueur_rec (Liste l)
{
    if (l == NULL)
        return 0 ;
    else return (1 + longueur_rec(l->suivant)) ;
}


int longueur_iter (Liste l)
{
    Liste P = l;
    int cpt = 0 ;
    while (P ISNOT NULL)
    {   P = P->suivant ;
        cpt++ ;
    }
    return cpt ;
}

/*************************************************/
/*                                               */
/*       VireDernier,                            */
/*               sans les briques de base,       */
/*               ni le "->"                      */
/*                                               */
/*************************************************/

void VD (Liste *L)
// *L non NULL ie liste non vide
{
    if ( ((**L).suivant) == NULL )
        depile(L) ;   // moralement : depile(& (*L)) ;
    else VD (& ( (**L).suivant )) ;
}

void VireDernier_rec (Liste *L)
{
    if ( (*L) ISNOT NULL )
    VD(L);        // moralement : VD(& (*L)) ;
}

void VireDernier_iter (Liste *L)
{
    if ( (*L) ISNOT NULL)
    {
        while ( ((**L).suivant) ISNOT NULL )
        L = & ( (**L).suivant ) ;
        free(*L) ;
        *L = NULL ;
    }
}


/*************************************************/
/*                                               */
/*       Libere la memoire                       */
/*                                               */
/*************************************************/

void VideListe(Liste *L)
{
    if(NOT(estVide(*L)))
    {
        depile(L);
        VideListe(L);
    }

}

/*************************************************/
/*                                               */
/*             Question 1                        */
/*                                               */
/*************************************************/

int ZEPUODOT2(Liste l, int k){

    if (l==NULL OR k==0) {

        return FALSE;

    }

    else {

        if (premier(l)==0) {
            printf("C'est vrai\n");
            return TRUE;
        }
        else {
            printf("C'est faux\n");
            return FALSE;
            

        }


        ZEPUODOT2(suite(l),k-1);


    }


}

int ZEPUODOT(Liste l){

    return ZEPUODOT2(l,3);

}









/*************************************************/
/*                                               */
/*              question 2                       */
/*                                               */
/*************************************************/

int Pluscourte(Liste l1, Liste l2){
    if(l1==NULL){
        printf("La 1ere liste est plus courte\n");
        return TRUE;
    }

    if(l2==NULL){
        printf("La 1ere liste n'est pas plus courte\n");
        return FALSE;
    }

    Pluscourte(l1->suivant, l2->suivant);
}




/******************************************************/
/*                                                    */
/* question 3 recursive terminale avec sous fonction  */
/*                                                    */
/******************************************************/

int ND0APK2( Liste l, int k, int a){
    if (l == NULL OR k<0){
        printf("il y %d fois zero\n",a);
        return a;

    }
    else {

        if (k>=0 AND premier(l)==0){

            a++;
        }

        ND0APK2(suite(l),k-1,a);
    }

}

int ND0APK( Liste l, int k){
    int a = 0;
    return ND0APK2(l,k,a);

}



/******************************************************/
/*                                                    */
/* question 3 recursive terminale avec sous procedure  */
/*                                                    */
/******************************************************/

void ND0APK2P( Liste l, int k, int *a){
    if (l == NULL OR k<0){

        *a+=0;

    }
    else {

        if (k>=0 AND premier(l)==0){

            *a+=1;
        }

        ND0APK2P(suite(l),k-1,a);
    }

}

int ND0APKP( Liste l, int k){
    int a = 0;
    ND0APK2P(l,k,&a);



    return a;

}





/******************************************************/
/*                                                    */
/*                question 3 recursive                */
/*                                                    */
/******************************************************/

int ND0APKR(Liste l, int k){

    if (l==NULL OR k<0 ){
        return 0;
    }

    else if (k>=0){

        int y = ND0APKR(l->suivant,k-1);

        if ((premier(l))==0){
            return y+1;
        }
        else {

            return y;
        }


    }
}


/******************************************************/
/*                                                    */
/*                  question 3 iteratif               */
/*                                                    */
/******************************************************/

int ND0APKI( Liste l, int k){

    Liste p = l;
    int a = 0;
    while (p!=NULL AND k>=0) {

        if(premier(p)==0){

            a++;

        }

        k--;
        p = suite(p);

    }

    printf("il y a %d fois zero\n",a);
    return a;

}






/*************************************************/
/*                                               */
/*              question 4                       */
/*                                               */
/*************************************************/

int ND0ARPK2( Liste l, int k, int a){
    if (l == NULL){
        printf("il y a %d fois apres la position k \n",a);
        return a;

    }
    else if (k<=0){
        if (premier(l)==0){
            a++;
        }

        ND0ARPK2(l->suivant,k-1,a);
    }

    else
        ND0ARPK2(l->suivant,k-1,a);

}

int ND0ARPK( Liste l, int k){
    int a = 0;
    ND0ARPK2(l,k,a);

}


/*************************************************/
/*                                               */
/*              question 5 version recursive     */
/*                                               */
/*************************************************/

Liste BegayeFR(Liste l){

    if(l==NULL){

        Liste l2;
        initVide(&l2);
        return l2;

    }

    else {

        if (premier(l)>0){


            return ajoute(premier(l),ajoute(premier(l),BegayeFR(suite(l))));
        }
        else {

            BegayeFR(suite(l));
        }
    }


}

/*************************************************/
/*                                               */
/*              question 5 version itérative     */
/*                                               */
/*************************************************/


Liste BegayeFI(Liste l){

    Liste p;
    initVide(&p);

    Liste p2;
    initVide(&p2);




    while(l!=NULL ){

        if(premier(l)>0){
            p= ajoute(premier(l),p);
            p= ajoute(premier(l),p);


        }



        l= suite(l);



    }

    while(p!=NULL ){
        empile(premier(p),&p2);
        p=suite(p);
    }



    affiche_iter(p2);


    return p2;

}



/*************************************************/
/*                                               */
/*     question 5 version récurive terminale     */
/*                                               */
/*************************************************/

Liste BegayeFRT2(Liste l, Liste l2){

    if(l==NULL){

        return l2;

    }

    else {

        l2 = BegayeFRT2(suite(l),l2);

        if (premier(l)>0){

            l2 = ajoute(premier(l),l2);
            l2= ajoute(premier(l),l2);

        }

        return l2;
    }



}



Liste BegayeFRT(Liste l){

    Liste l2;
    initVide(&l2);

    Liste l3;
    initVide(&l3);

    l3 = BegayeFRT2(l,l2);
    affiche_iter(l3);
    return l3;

}


/*************************************************/
/*                                               */
/*     question 6 version récurive terminale     */
/*              Prodecudre                       */
/*************************************************/

void BegayePRT2(Liste l, Liste *l2){

    if(l==NULL){

        return;

    }

    else {

        BegayePRT2(suite(l),l2);

        if (premier(l)>0){

            empile(premier(l),l2);
            empile(premier(l),l2);

        }


    }

}



 void BegayePRT(Liste l){

    Liste l2;
    initVide(&l2);


    BegayePRT2(l,&l2);
    affiche_iter(l2);


}


/*************************************************/
/*                                               */
/*     Question 9  liste doublement chainé       */
/*                                               */
/*************************************************/







//
// Created by walid on 04/11/2022.
//
