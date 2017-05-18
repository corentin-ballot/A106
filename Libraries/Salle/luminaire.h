GLuint LUMINAIRE = -1;

void construire_luminaire() {
    char* image= "Libraries/Salle/Textures/luminaire.tga";

    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    LUMINAIRE = glGenLists(1);
    glNewList(LUMINAIRE, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(61.0, 3, 110.0);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
