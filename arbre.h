#ifndef ARBRE_H
#define ARBRE_H


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
/*          definition type image                */
/*                                               */
/*************************************************/


typedef struct bloc_image{
     bool toutnoir ;
     struct bloc_image * fils[4] ;
} bloc_image ;

typedef bloc_image *image ;




// construit une image blanche à partir de rien //
image Construit_Blanc();

// construit une image blanche à partir de rien //
image Construit_Noir();


// Construit une image composée de sous images
image Construit_Composee(image i0, image i1, image i2, image i3);


// affiche en mode simple //

void affiche_image(image i);

// sous procedure affichage simple//
void affiche_image2(image i);


// affiche en mode profondeur//
void affiche_image_pronfondeur(image i);

// sous procedure en mode profondeur //
void affiche_image_pronfondeur2(image i,int p);



// rend l'image associé a la chaine de caratere tapé au clavier //
image Lecture(void);


// sous fonction qui construit l'image //
image Lecture2(char c[],int j);


// rend vrai si image noir//

bool EstNoire(image i);


// rend vrai si image Blanche//

bool EstBlanche(image i);

// rend une image avec une diagonale noir peut importe la profondeur//
image Diagonale(int p);

image Diagonale2(int p);

// rend le quart de tour de l'image donnée en argument //

image QuartDetour(image i);

// modifie  l'image en negatif //

 void negatif(image *i);

// simplifie a une prondeur donnée //


void SimplifieProfP(image *i, int p);

void SimplifieProfP2(image *i, int p);

// regarde si la 1ere image est incluse dans l'autre //

bool Incluse(image i1, image i2);

bool Bis(image i1, image i2);

// rend le max des hauteurs des sous images blanches //

int HMB(image i);

int HMB2(image i);

int max(int a, int b);

int MAX4(int a , int b, int c, int d);













#endif