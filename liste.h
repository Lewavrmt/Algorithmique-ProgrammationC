#ifndef LISTE_H
#define LISTE_H

/*************************************************/
/*                                               */
/*                sucre syntaxique               */
/*                                               */
/*************************************************/

#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
#define then

typedef enum { FALSE, TRUE} bool;

/*************************************************/
/*                                               */
/*          definition type liste                */
/*                                               */
/*************************************************/

typedef struct Bloc
{
    int nombre;
    struct Bloc *suivant;
} Bloc;

typedef Bloc *Liste ;


/*************************************************/
/*                                               */
/*     definition type liste doublement chainé   */
/*                                               */
/*************************************************/

typedef struct BlocDC
{
    int nombre;
    struct BlocDC *suivant;
    struct BlocDC *pred;
      
} BlocDC;

typedef BlocDC *ListeDC;
typedef BlocDC *Entrée; 





/*************************************************/
/*                                               */
/*                predeclarations                */
/*                                               */
/*************************************************/

/* initialise une Liste � vide */
void initVide(Liste *L);

/* renvoie 1 si la Liste en parametre est vide, 0 sinon */
bool estVide(Liste l);

/* renvoie le premier element de la Liste en parametre */
int premier(Liste l);

/* renvoie une nouvelle Liste correspondant a celle en parametre, avec l'element x ajoute en haut de la pile */
Liste ajoute(int x, Liste l);

/* modifie la Liste en parametre: x est ajoute comme premier element */
void empile(int x, Liste* L);

/* renvoie une nouvelle Liste correspondant a celle en parametre sans son premier element */
Liste suite(Liste l);

/* modifie la Liste en parametre: le premier element est retire */
void depile(Liste* l);

/* affichage simple en recursif et en iteratif */
void affiche_rec(Liste l);
void affiche_iter(Liste l);

/* longueur en recursif et en iteratif */
int longueur_rec (Liste l);
int longueur_iter (Liste l);

/*  Elimination du dernier element en recursif et en iteratif  */
/*  VD est la sousprocedure utilitaire de la version recursive */
void VD (Liste *L);
void VireDernier_rec (Liste *L);
void VireDernier_iter (Liste *L);

/*Vide la liste L*/
void VideListe(Liste *L);


/*0 en pos 1,2 ou 3 sous fonction 2*/
int ZEPUODOT2(Liste L, int k);

/*0 en pos 1,2 ou 3*/
int ZEPUODOT(Liste L);

/* Verifie si la 1ere liste est plus courte*/

int Pluscourte(Liste l1, Liste l2);



/*nombre de avant la postion k */

int ND0APK( Liste L, int k);



/* fonction auxilaire  de nombre de 0 avant position k*/
int ND0APK2( Liste L, int k, int a);

/*version recursif de ND0APK*/
int ND0APKR(Liste l, int k);

/*Version iterative  question 3*/
int ND0APKI( Liste l, int k);


/*nombre de après la postion k */

int ND0ARPK( Liste L, int k);



/* fonction auxilaire  de nombre de 0 après position k*/
int ND0ARPK2( Liste L, int k, int a);


/* Prend une liste en parametre et rend une nouvelle liste avec tout les elements positif de la liste
prit en parametre en double.

version recursive
*/
Liste BegayeFR(Liste l);



/* Prend une liste en parametre et rend une nouvelle liste avec tout les elements positif de la liste
prit en parametre en double.

version itérative
*/
Liste BegayeFI(Liste l);



/* Prend une liste en parametre et rend une nouvelle liste avec tout les elements positif de la liste
prit en parametre en double.

version sous fouction BegayeFRT
*/

Liste BegayeFRT2(Liste l, Liste l2);

/* Prend une liste en parametre et rend une nouvelle liste avec tout les elements positif de la liste
prit en parametre en double.

version recursive terminale
*/

Liste BegayeFRT(Liste l);

/* Prend une liste en parametre et la modifie en doublant les termes positifs et en depilant le reste

version recursive terminale en procedure
*/

void BegayePRT2(Liste l, Liste *l2);

/* Prend une liste en parametre et la modifie en doublant les termes positifs et en depilant le reste

version recursive terminale en procedure
*/

void BegayePRT(Liste l);


/*VERSION PRINCIPALE SOUS PROCEDURE */
int ND0APKP( Liste l, int k);

/*VERSION SOUS PROCEDURE */

void ND0APK2P( Liste l, int k, int *a);





#endif