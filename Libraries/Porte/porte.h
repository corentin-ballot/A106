#include "clanche.h"

GLuint PORTE = -1;

double PORTE_OPENING = 0;
double CLANCHE_OPENING = 0;
double OUVERTURE_PORTE = 0;
double OUVERTURE_CLANCHE = 0;

void construire_porte() {
    construire_clanche();

    char* image[]= {"Libraries/Porte/Textures/back.tga","Libraries/Porte/Textures/front.tga"};

    charger_image(&texture[0],image[0]);
    charger_image(&texture[3],image[1]);

    int i;
    for(i=1;i<6;i++) if(i!=3) texture[i] = texture[0];
    construire_cube();

    PORTE = glGenLists(1);
    glNewList(PORTE, GL_COMPILE);

    glPushMatrix();
    glTranslatef(91.8/2.0, 204.0/2.0, 0.0);
    glScalef(91.8, 203.3, 3.8);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}

void placementPortes() {
    // Porte mur sud
    glPushMatrix();
    glTranslatef(-610.0/2.0 + 10, 0.0, +990.0 / 2.0 + 3.8/2 - 0.1);
    glRotatef(-90 * OUVERTURE_PORTE, 0.0, 1.0, 0.0);
    glCallList(PORTE);
        glPushMatrix();
        glTranslatef(91.8 - 5.5, 203.3/2 +3.0, 0.0);
        glRotatef(45 * OUVERTURE_CLANCHE, 0.0, 0.0, 1.0);
        glCallList(CLANCHE);
        glPopMatrix();
    glPopMatrix();

    // Porte mur nord
    glPushMatrix();
    glTranslatef(-610.0/2.0 + 10, 0.0, -990.0 / 2.0 - 3.8/2 + 0.1);
    glRotatef(-90 * OUVERTURE_PORTE, 0.0, 1.0, 0.0);
    glCallList(PORTE);
        glPushMatrix();
        glTranslatef(91.8 - 5.5, 203.3/2 +3.0, 0.0);
        glRotatef(45 * OUVERTURE_CLANCHE, 0.0, 0.0, 1.0);
        glCallList(CLANCHE);
        glPopMatrix();
    glPopMatrix();

    // Porte mur est (retirer les commentaire pour permettre l'ouverture)
    glPushMatrix();
    glTranslatef(610.0/2.0 + 3.8/2 - 0.1, 0.0, -990.0 / 2.0 + 30);
    glRotatef(-90 /*- 90 * OUVERTURE_PORTE*/, 0.0, 1.0, 0.0);
    glCallList(PORTE);
        glPushMatrix();
        glTranslatef(91.8 - 5.5, 203.3/2 +3.0, 0.0);
        //glRotatef(45 * OUVERTURE_CLANCHE, 0.0, 0.0, 1.0);
        glCallList(CLANCHE);
        glPopMatrix();
    glPopMatrix();
}
