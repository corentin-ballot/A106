GLuint MUR_NORD = -1;

void construire_mur_nord() {
    if(PORTE == -1)
        construire_porte();
    if(TABLEAU == -1)
        construire_tableau();
    if(ECRAN_VIDEOPROJ == -1)
        construire_ecran_videoproj();

    char* image= "Libraries/Salle/Textures/mur.tga";

    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    MUR_NORD = glGenLists(1);
    glNewList(MUR_NORD, GL_COMPILE);

    // Mur
    glPushMatrix();
    glTranslatef((-610+91.8)/2 +10, 71.4/2 + 275-71.4, (-990-3.5)/2.0);
    glScalef(91.8, 71.4, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((610-508.2)/2, 275/2.0, (-990-3.5)/2.0);
    glScalef(508.2, 275, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-610.0/2 + 10/2, 275/2.0, (-990-3.5)/2.0);
    glScalef(10, 275, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Tableau
    glPushMatrix();
    glTranslatef((610 - 400)/2 - 72, 80.0, -990/2);
    glCallList(TABLEAU);
    glPopMatrix();

    glEndList();
}
