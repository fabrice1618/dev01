#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h> 
#include "lire.h"

#define PRENOM_MAXLEN 50
#define NOTE_MAXLEN 10

//#define PRENOM_STOP "X AE A-XII"
#define PRENOM_STOP "end"

// Prototypes
float str2float( char *, int );

int main( void )
{
    char prenom[PRENOM_MAXLEN];
    char noteStr[NOTE_MAXLEN];
    float note;

    // Report
    int nbEleves = 0;
    float total = 0;
    float moyenne = 0;
    float maxi_note = -1;
    char maxi_prenom[PRENOM_MAXLEN] = "";
    float mini_note = 21;
    char mini_prenom[PRENOM_MAXLEN] = "";

    while ( lire( prenom, PRENOM_MAXLEN, "Prénom: " ) > 0) {
        if ( strcmp(prenom, PRENOM_STOP) == 0 ) {
            break;
        }

        note = lire( noteStr, NOTE_MAXLEN, "Note: " ) > 0 ? str2float( noteStr, 2 ) : -1;

        if ( note >= 0.0 && note <= 20.0 ) {
            // Incrementer le nombre d'eleves
            nbEleves++;

            // Calculer total
            total += note;

            if ( note > maxi_note ) {
                maxi_note = note;
                strcpy( maxi_prenom, prenom );
            }

            if ( note < mini_note ) {
                mini_note = note;
                strcpy( mini_prenom, prenom );
            }

            printf( ">prenom=%s - Note=%5.2f\n", prenom, note);
        }

    }
    
    moyenne = nbEleves > 0 ? round( total / nbEleves * 100 ) / 100 : 0; 
    printf("Moyenne : %5.2f\n", moyenne);
    printf("Note mini : %5.2f %s\n", mini_note, mini_prenom);
    printf("Note maxi : %5.2f %s\n", maxi_note, maxi_prenom);
}

float str2float( char *valueStr, int decimales )
{
    float returnValue = 0.0;    
    char * endPtr;

    returnValue = strtof( valueStr, &endPtr );
            
    if ( endPtr != valueStr ) {
        returnValue = round( returnValue * pow( 10, decimales) ) / pow( 10, decimales); 
    }

    return( returnValue );
}