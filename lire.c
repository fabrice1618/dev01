#include <stdio.h>
#include <string.h> 

#define FLOOD 1024

/* lire une chaine de caracteres 'chaine' d'une longueur maximum 'maxlen'
Retourne le nombre de caractères lus jusqu'à \n ou maxlen caracteres
Retourne un nombre négatif en cas d'erreur:
-3: fin de fichier EOF
-2: trop de caracteres recus FLOOD
*/
int lire( char *chaine, int maxlen, char *prompt )
{
    int nbChar = 0;
    int cntRead = 0;
    char carac;
    int etape = 0;
    int returnValue;

    printf("%s", prompt);

    while ( etape == 0 ) {
        
        if ( feof(stdin) ) 
            // On detecte un EOF
            etape = -3;
        else {
            carac = getc(stdin);    // Lecture caractere dans STDIN

            // On detecte un EOF
            if ( carac == EOF ) 
                etape = -3;
        }

        // FLOOD de STDIN, trop de caracteres recus
        if ( etape == 0 && ++cntRead >= FLOOD ) 
            etape = -2;

        // Detecte une fin de saisie par LF
        if ( etape == 0 && carac == '\n' ) {
            etape = 1;
        }

        if ( etape == 0 && nbChar < maxlen - 1 ) {
            // Enregistre un caractere
            chaine[nbChar] = carac;
            nbChar++;
        }
    }

    switch ( etape ) {
        case -3:
        case -2:
            chaine[0] = '\0';       // Si erreur, la chaine de sortie est vide
            returnValue = etape; 
            break;
        case 1:
        default:
            chaine[nbChar] = '\0';  // On termine la chaine apres le dernier caractere recu
            returnValue = nbChar; 
    }

    return( returnValue );
}

