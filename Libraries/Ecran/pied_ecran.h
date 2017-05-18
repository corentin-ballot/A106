GLuint PIED_ECRAN = 0;

void construire_pied_ecran() {
    char* image="Libraries/Ecran/Textures/top.tga";
    charger_image(&texture[0], image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    PIED_ECRAN = glGenLists(1);
    glNewList(PIED_ECRAN, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 1.0/2, 0.0);
    glScalef(18.0, 1.0, 16.5);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 9.5/2, 0.0);
    glScalef(7.1, 8.5, 3.0);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 11.0, 2.0);
    glRotatef(135, 1.0, 0.0, 0.0);
    glScalef(7.1, 2.0, 6.5);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
