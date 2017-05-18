#include "luminaire.h"

GLuint PLAFOND = -1;

void construire_plafond() {
    if(LUMINAIRE==-1)
        construire_luminaire();

    char* image= "Libraries/Salle/Textures/plafond.tga";

    charger_image(&texture[0],image);

    int i, j;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    PLAFOND = glGenLists(1);
    glNewList(PLAFOND, GL_COMPILE);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 9; j++) {
            glPushMatrix();
            glTranslatef(-610/2.0 + 61/2.0 + i*61, 275 + 3/2.0, 990.0/2.0 - 110.0/2.0 - j*110.0);
            if((i == 2 || i == 7) && (j%2 == 1)){
                glCallList(LUMINAIRE);
            }else {
                glScalef(61.0, 3, 110.0);
                glCallList(CUBE);
            }
            glPopMatrix();
        }
    }


    glEndList();
}
