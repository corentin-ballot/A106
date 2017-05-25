GLuint CIEL_EXTERIEUR = -1;

void construire_ciel_exterieur(){

    char* image[]={"Libraries/Exterieur/Textures/ciel.tga", "Libraries/Exterieur/Textures/terre.tga"};

    charger_image(&texture[0],image[0]);
    charger_image(&texture[4],image[1]);

    texture[1] = texture[0];
    texture[2] = texture[0];
    texture[3] = texture[0];
    texture[5] = texture[0];
    construire_cube();

    CIEL_EXTERIEUR = glGenLists(1);
    glNewList(CIEL_EXTERIEUR, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0, 500, 0);
    glScalef(5000, 1, 5000);
    glCallList(CUBE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -500, 0);
    glScalef(5000, 1, 5000);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
