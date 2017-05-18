GLuint MUR_EST = -1;

void construire_mur_est() {
    if(PORTE == -1)
        construire_porte();
    if(GOULOTTES == -1)
        construire_goulottes();

    char* image= "Libraries/Salle/Textures/mur.tga";

    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    MUR_EST = glGenLists(1);
    glNewList(MUR_EST, GL_COMPILE);

    glPushMatrix();
    glTranslatef(610.0/2.0 + 3.5 / 2.0, 275 / 2.0, (990-868.2)/2.0);
    glScalef(3.5, 275, 868.2);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(610.0/2.0 + 3.5 / 2.0, 275 / 2.0, -(990-30)/2.0);
    glScalef(3.5, 275, 30);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(610.0/2.0 + 3.5 / 2.0,  71.4/2 + 275-71.4, -(990-91.8)/2.0+30);
    glScalef(3.5, 71.4, 91.8);
    glCallList(CUBE);
    glPopMatrix();

    // Tuyau
    glPushMatrix();
    glTranslatef(610.0/2.0 - 2.0, 275 - 80/2.0, -990.0/2.0 + 5.0);
    glScalef(1.0, 80, 1.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    // Goulottes electrique
    glPushMatrix();
    glTranslatef(610/2.0 - 5/2.0, 75 + 10, 990/2.0 - 850/2.0);
    glScalef(5.0, 10, 850);
    glCallList(GOULOTTES);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(610/2.0 - 5/2.0, 75 + 185/2.0 + 15, 990/2.0 - 850 + 10/2.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(5.0, 10, 185);
    glCallList(GOULOTTES);
    glPopMatrix();






    glEndList();
}
