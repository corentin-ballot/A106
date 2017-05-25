#include "batiment.h"
#include "passerelle.h"
#include "ciel.h"
#include "arbre.h"

GLuint EXTERIEUR = -1;

void construire_exterieur(){

    char* image[]={"Libraries/Exterieur/Textures/front.tga"};

    charger_image(&texture[0],image[0]);
    texture[1] = texture[0];
    texture[2] = texture[0];
    texture[3] = texture[0];
    texture[4] = texture[0];
    texture[5] = texture[0];
    construire_cube();

    EXTERIEUR = glGenLists(1);
    glNewList(EXTERIEUR, GL_COMPILE);

    glPushMatrix();
    glTranslatef(-1500, 0, 0);
    glScalef(1, 6000, 30000);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}

placement_exterieur() {
    if(BATIMENT_EXTERIEUR == -1)
        construire_batiment_exterieur();    
    if(PASSERELLE_EXTERIEUR == -1)
        construire_passerelle_exterieur();
    if(CIEL_EXTERIEUR == -1)
        construire_ciel_exterieur();
    if(ARBRE == -1)
        construire_arbre();

    // Fenetre 1 en partant du fond
    glPushMatrix();
    glCallList(BATIMENT_EXTERIEUR);
    glCallList(PASSERELLE_EXTERIEUR);
    glCallList(CIEL_EXTERIEUR);
    glDisable(GL_DEPTH_TEST);
    glCallList(ARBRE);
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
}
