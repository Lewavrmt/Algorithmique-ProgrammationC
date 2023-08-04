#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"




// question 1//


image Construit_Blanc(void){

    return NULL;

}


image Construit_Noir(void){

    image i = malloc(sizeof(bloc_image));
    i-> toutnoir = TRUE;
    i->fils[0]=NULL;
    i->fils[1]=NULL;
    i->fils[2]=NULL;
    i->fils[3]=NULL;
    
    return i;



}


image Construit_Composee(image i0, image i1, image i2, image i3){

    
    image i = malloc(sizeof(bloc_image));
    i-> toutnoir = FALSE;
    i->fils[0]=  i0;
    i->fils[1]=  i1;
    i->fils[2]=  i2;
    i->fils[3]=  i3;

    return i;


}


// question 2 //

void affiche_image(image i){
    affiche_image2(i);
    printf("\n");
}


void affiche_image2(image i){

    if ( i==NULL){

        printf("B");
    }

    else if ( i->toutnoir == TRUE ) {
        printf("N");
    }

    else {
        printf("(");
        affiche_image2(i->fils[0]);
        affiche_image2(i->fils[1]);
        affiche_image2(i->fils[2]);
        affiche_image2(i->fils[3]);
        printf(")");
    }


}



void affiche_image_pronfondeur(image i){

    affiche_image_pronfondeur2(i, 0);
    printf("\n");

}

void affiche_image_pronfondeur2(image i, int p){
        
         
    if ( i==NULL){

        printf("B%d",p);
    }

    else if ( i->toutnoir == TRUE ) {
        printf("N%d",p);
    }

    else {
        printf("(");
        affiche_image_pronfondeur2(i->fils[0], p+1);
        affiche_image_pronfondeur2(i->fils[1], p+1);
        affiche_image_pronfondeur2(i->fils[2], p+1);
        affiche_image_pronfondeur2(i->fils[3], p+1);
        printf(")");
    }

            
    
    
}

// question 3//
// lecture marche pour une image simple ,  une image composée simple mais pas composée de composée
/*image Lecture(void){
    
    
    printf("entrer la chaine de caratere associe a l'image souhaite\n");
    
    char c[250];
    scanf("%s", &c); 


    printf("taille de la chaine est %d \n",strlen(c));

    image i = Lecture2(c,0);
        
        
        
    affiche_image(i);
    
    
    return i;
} */
/*
image Lecture2(char c[],int j){

    
    if( c[j] == 'B')
        return Construit_Blanc();
    
    else if ( c[j] == 'N')  
        return Construit_Noir();

    
    
    
    else {
    
    
        if ( c[j] == '(') {
        
            
            return Construit_Composee(Lecture2(c,j+1),Lecture2(c,j+2),Lecture2(c,j+3),Lecture2(c,j+4));

        }

        else 

            return Construit_Composee(Lecture2(c,j+5),Lecture2(c,j+6),Lecture2(c,j+7),Lecture2(c,j+8));


    
    }
    
  
}
*/
/*

image Lecture2(char c[],int j){

    
    if( c[j] == 'B')
        return Construit_Blanc();
    
    else if ( c[j] == 'N')  
        return Construit_Noir();

    
    
    
    else {
    
    
        if ( c[j] == '(') {
        
            
            if ( ( c[j+1] != '(') && ( c[j+2] != '(') && ( c[j+3] != '(') && ( c[j+4] != '('))

                return Construit_Composee(Lecture2(c,j+1),Lecture2(c,j+2),Lecture2(c,j+3),Lecture2(c,j+4));

            else {

                if ( c[j+1] == '(') {
                    int u = j;
                    return Construit_Composee(Construit_Composee(Lecture2(c,j+2),Lecture2(c,j+3),Lecture2(c,j+4),Lecture2(c,j+5)),Lecture2(c,j+7),Lecture2(c,j+8),Lecture2(c,j+9));

                }

                else if ( c[j+2] == '(') {
                    int u = j;
                    return Construit_Composee(Lecture2(c,j+1),Construit_Composee(Lecture2(c,j+3),Lecture2(c,j+4),Lecture2(c,j+5),Lecture2(c,j+6)),Lecture2(c,j+8),Lecture2(c,j+9));


                }

                else if ( c[j+3] == '(') {
                    int u = j;
                    return Construit_Composee(Lecture2(c,j+1),Lecture2(c,j+2),Construit_Composee(Lecture2(c,j+4),Lecture2(c,j+5),Lecture2(c,j+6),Lecture2(c,j+7)),Lecture2(c,j+9));

                }

                else if ( c[j+1] == '(') {
                    int u = j;
                    return Construit_Composee(Lecture2(c,j+1),Lecture2(c,j+2),Lecture2(c,j+3),Construit_Composee(Lecture2(c,j+5),Lecture2(c,j+6),Lecture2(c,j+7),Lecture2(c,j+8)));
                }
                
                
                
            }


            
            
            
            
           

        }



        else 
            return Construit_Composee(Lecture2(c,j+1),Lecture2(c,j+2),Lecture2(c,j+3),Lecture2(c,j+4));

             


    
    }
    
    
}


*/





// question 4//

bool EstNoire(image i){
    if(i == NULL){
        //printf("False\n");//
        return FALSE;
    }    
    
    else if (i->toutnoir){
       // printf("True\n");//
        return TRUE;
    }
    else     
        return EstNoire(i->fils[0]) && EstNoire(i->fils[1]) && EstNoire(i->fils[2]) && EstNoire(i->fils[3]) ;
}


bool EstBlanche(image i) {
    if( i == NULL){
        //printf("True\n");//
        return TRUE;
    }    
    
    else if ( i->toutnoir){
        printf("False\n");//
        return FALSE;
    }
    else 
        return EstBlanche(i->fils[0]) && EstBlanche(i->fils[1]) && EstBlanche(i->fils[2]) && EstBlanche(i->fils[3]) ; 

}


//question 5//


image Diagonale(int p) {

    if (p==0) 

        return Construit_Noir();


    else 
        return Diagonale2(p);

}




image Diagonale2(int p){

    if (p==1){

        image i0 = Construit_Noir();
        image i1 = Construit_Blanc();
        image i2 = Construit_Blanc();
        image i3 = Construit_Noir();

        
        return Construit_Composee(i0,i1,i2,i3);
            
    }

    else 

        return Construit_Composee(Diagonale(p-1),Construit_Blanc(),Construit_Blanc(),Diagonale(p-1));
    

}








// question 6//

image QuartDetour(image i){

    if( i == NULL || (i)->toutnoir){
        
        return i; 
 
    }

    else 
        return Construit_Composee(QuartDetour(i->fils[2]),QuartDetour((i)->fils[0]),QuartDetour(i->fils[3]),QuartDetour(i->fils[1]));
        

}


// question 7//

void negatif(image *i){

    if( *i == NULL){
        *i = Construit_Noir();
    }


    else {

        if( (*i)->toutnoir) {
            *i = Construit_Blanc();
        }

        else {
        
        negatif(&(*i)->fils[0]);
        negatif(&(*i)->fils[1]);
        negatif(&(*i)->fils[2]);
        negatif(&(*i)->fils[3]);

        }
  

    }


}


// Question 8 //

void SimplifieProfP(image *i, int p){

     
     SimplifieProfP2(&(*i),p);

}




void SimplifieProfP2(image *i, int p){

    
    if ( p == 1 ){

        if( *i != NULL && !(*i)->toutnoir){
            
            if( ((*i)->fils[0]) == NULL && ((*i)->fils[1]) == NULL && ((*i)->fils[2]) == NULL && ((*i)->fils[3]) == NULL ){
            
                *i = Construit_Blanc();

            }

            else {
                
                if ( ((*i)->fils[0])->toutnoir &&  ((*i)->fils[1])->toutnoir && ((*i)->fils[2])->toutnoir &&  ((*i)->fils[3])->toutnoir){
                    *i = Construit_Noir();
                }

                else 
                    return;

            }

            
        }
    }

    else {

        SimplifieProfP2(&(*i)->fils[0], p-1);
        SimplifieProfP2(&(*i)->fils[1], p-1);
        SimplifieProfP2(&(*i)->fils[2], p-1);
        SimplifieProfP2(&(*i)->fils[3], p-1);

    }

} 



// Question 9 //

bool Incluse(image i1, image i2){

   // (EstBlanche(i1) && EstBlanche(i2)) || ( EstNoire(i1) && EstNoire(i2)   //
    
    if( i2 == NULL || (i2)->toutnoir){
        
        if ( Bis(i1,i2)){
            printf("vrai\n");
            return TRUE;
        } 

        else {
            printf("faux\n");
            return FALSE;
        }

 
    }

    else {
        
         if ( Bis(i1,i2)){
            printf("vrai\n");
            return TRUE;
        } 

        else 
            return Incluse(i1, i2->fils[0]) || Incluse(i1, i2->fils[1]) || Incluse(i1, i2->fils[2]) || Incluse(i1, i2->fils[3]);
    }

    
}



bool Bis(image i1, image i2){
     
    if( ( i1 == NULL || (i1)->toutnoir ) && (i2 == NULL || (i2)->toutnoir) ) {

             if (EstBlanche(i1) && EstBlanche(i2) ) {

                        printf("vrai\n");
                        return TRUE;

             }

             else {
                
                if ( EstNoire(i1) && EstNoire(i2) ) {

                    printf("vrai\n");
                    return TRUE;
                }

                else {

                    printf("faux\n");
                    return FALSE;

                }    
            
             }

    }


    else {

        if( ( i1 == NULL || (i2)->toutnoir ) && !(i2 == NULL || (i2)->toutnoir) ) {

            printf("faux\n");
            return FALSE;

        }

        else {

            if( !( i1 == NULL || (i2)->toutnoir ) && (i2 == NULL || (i2)->toutnoir) ) {

            printf("faux\n");
            return FALSE;

            }


            return Bis(i1->fils[0], i2->fils[0]) && Bis(i1->fils[1], i2->fils[1]) && Bis(i1->fils[2], i2->fils[2]) && Bis(i1->fils[3], i2->fils[3]);


        }
        
        
        
        
        return Bis(i1->fils[0], i2->fils[0]) && Bis(i1->fils[1], i2->fils[1]) && Bis(i1->fils[2], i2->fils[2]) && Bis(i1->fils[3], i2->fils[3]);
    
    
    }


}




// Question 10 //


int HMB(image i){

    if ( i == NULL) {
         return 0;
    } 

    else 
        if ( EstNoire(i))
            return -1;
        
        else 
            return HMB2(i);
}



int HMB2(image i){
    
   
    if ( i == NULL || (i)->toutnoir )
         return 0;


    else {

        if(EstBlanche(i))
                
                return 1+ MAX4(HMB2(i->fils[0]),HMB2(i->fils[1]),HMB2(i->fils[2]),HMB2(i->fils[3]));


            else    
                return MAX4(HMB2(i->fils[0]),HMB2(i->fils[1]),HMB2(i->fils[2]),HMB2(i->fils[3])); 
    }            

}



/*

jai essayé des versions plus optimé mais renvoie pas le bon resultat ou tourne a l'infini


int HMB2(image i){
    
   
    if ( i == NULL) {
         return 0;
    }
    
    else {
         
        if ( i ->toutnoir)
            return -1;

        else {

            
            
            if(  !((i)->toutnoir) && (i->fils[0]) == NULL && (i->fils[1]) == NULL && (i->fils[2]) == NULL && (i->fils[3]) == NULL )
                    
                return 1;


            else  {
            
                if ( ( (i->fils[0]) ->toutnoir ) && ( (i->fils[1]) ->toutnoir ) && ( (i->fils[2]) ->toutnoir ) && ( (i->fils[3]) ->toutnoir ) )
                    
                    return -1;

                else {
                            

                   if ( ( (i->fils[0]) != NULL ) && ( (i->fils[1]) != NULL ) && ( (i->fils[2]) != NULL ) && ( (i->fils[3]) != NULL ) )

                        if ( ( (i->fils[0]) ->toutnoir ) || ( (i->fils[1]) ->toutnoir ) || ( (i->fils[2]) ->toutnoir ) || ( (i->fils[3]) ->toutnoir ) )
                        
                        return MAX4(HMB2(i->fils[0]),HMB2(i->fils[1]),HMB2(i->fils[2]),HMB2(i->fils[3]));

                    else 
                        return 1+ MAX4(HMB2(i->fils[0]),HMB2(i->fils[1]),HMB2(i->fils[2]),HMB2(i->fils[3]));

                }    

            }
            
        }

    
    }
}


*/



/*

int HMB2(image i){
    
    if ( i == NULL || (i)->toutnoir ) 
        return 0;

    else  {   
    
    
        if(  !((i)->toutnoir) && (i->fils[0]) == NULL && (i->fils[1]) == NULL && (i->fils[2]) == NULL && (i->fils[3]) == NULL )
                    
            return 1;

        else {
            
            if ( (i->fils[0])->toutnoir) {

                if ( (((i->fils[1]) == NULL ) || ( (i->fils[1])->toutnoir) ) && (((i->fils[2]) == NULL ) || ( (i->fils[2])->toutnoir) ) && (((i->fils[3]) == NULL ) || ( (i->fils[3])->toutnoir) ) )
                    return 0; 

                else {
                    if ( (i->fils[1])->toutnoir) {

                        if ( (((i->fils[0]) == NULL ) || ( (i->fils[0])->toutnoir) ) && (((i->fils[2]) == NULL ) || ( (i->fils[2])->toutnoir) ) && (((i->fils[3]) == NULL ) || ( (i->fils[3])->toutnoir) ) )
                            return 0;  

                        else {
                            if ( (i->fils[2])->toutnoir) {

                                if ( (((i->fils[0]) == NULL ) || ( (i->fils[0])->toutnoir) ) && (((i->fils[1]) == NULL ) || ( (i->fils[1])->toutnoir) ) && (((i->fils[3]) == NULL ) || ( (i->fils[3])->toutnoir) ) )
                                    return 0;

                                else {

                                    return 0;

                                }       
                            
                            }      

                        }     

                    }

                }


            }
            else 

                return 1 + MAX4(HMB2(i->fils[0]),HMB2(i->fils[1]),HMB2(i->fils[2]),HMB2(i->fils[3]));

        }             

    }
}


*/

    




int max(int a, int b){
    if(a > b){
        return a;
    }
    
    else{
        return b;
    }
}

int MAX4(int a , int b, int c, int d) {

    return max(max(a,b),max(c,d));

}
