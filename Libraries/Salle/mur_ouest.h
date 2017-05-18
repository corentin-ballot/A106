GLuint MUR_OUEST = -1;

void construire_mur_ouest() {
    if(RADIATEUR == -1)
        construire_radiateur();

    char* image= "Libraries/Salle/Textures/mur.tga";
    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    MUR_OUEST = glGenLists(1);
    glNewList(MUR_OUEST, GL_COMPILE);

    // Bas du mur
    glPushMatrix();
    glTranslatef(-610.0/2.0 - 3.5 / 2.0, 93 / 2.0, 0.0);
    glScalef(3.5, 93, 990.0);
    glCallList(CUBE);
    glPopMatrix();

    // Haut du mur
    glPushMatrix();
    glTranslatef(-610.0/2.0 - 3.5 / 2.0,275 -  10 / 2.0, 0.0);
    glScalef(3.5, 10, 990.0);
    glCallList(CUBE);
    glPopMatrix();

    // Pillier 1 (en partant du fond de la salle)
    glPushMatrix();
    glTranslatef(-610.0/2.0 - 3.5 / 2.0 + 12/2.0, 275 / 2.0, 990.0/2 - 13.9/2.0);
    glScalef(3.5 + 12, 275, 13.9);
    glCallList(CUBE);
    glPopMatrix();

    // Pillier 2 (en partant du fond de la salle)
    glPushMatrix();
    glTranslatef(-610.0/2.0 - 3.5 / 2.0 + 14.2/2.0, 275 / 2.0, 990.0/2 - 13.9 - 67.5/2.0 - 222);
    glScalef(3.5 + 14.2, 275, 67.5);
    glCallList(CUBE);
    glPopMatrix();

    // Pillier 3 (en partant du fond de la salle)
    glPushMatrix();
    glTranslatef(-610.0/2.0 - 3.5 / 2.0 + 10/2.0, 275 / 2.0, -990.0/2 + 21.5/2.0);
    glScalef(3.5 + 10, 275, 21.5);
    glCallList(CUBE);
    glPopMatrix();

    // Radiateur 1 (en partant du fond de la salle)
    glPushMatrix();
    glTranslatef(-610.0/2.0 + 10/2.0 + 3, 60 / 2.0 + 20, 990.0/2 - 13.9 - 222/2.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(180, 60, 10);
    glCallList(RADIATEUR);
    glPopMatrix();

    // Radiateur 2 (en partant du fond de la salle)
    glPushMatrix();
    glTranslatef(-610.0/2.0 + 10/2.0 + 3, 60 / 2.0 + 20, 990.0/2 - 13.9 - 222 - 67.5 - 673/2.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(240, 60, 10);
    glCallList(RADIATEUR);
    glPopMatrix();


    glEndList();
}
