GLuint MUR_SUD = -1;

void construire_mur_sud() {
    if(PORTE == -1)
        construire_porte();

    char* image= "Libraries/Salle/Textures/mur.tga";

    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    MUR_SUD = glGenLists(1);
    glNewList(MUR_SUD, GL_COMPILE);

    // Mur
    glPushMatrix();
    glTranslatef((-610+91.8)/2 +10, 71.4/2 + 275-71.4, (990+3.5)/2.0);
    glScalef(91.8, 71.4, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((610-508.2)/2, 275/2.0, (990+3.5)/2.0);
    glScalef(508.2, 275, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-610.0/2 + 10/2, 275/2.0, (990+3.5)/2.0);
    glScalef(10, 275, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
