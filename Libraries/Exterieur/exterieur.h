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
    if(EXTERIEUR == -1)
        construire_exterieur();

    // Fenetre 1 en partant du fond
    glPushMatrix();
    glCallList(EXTERIEUR);
    glPopMatrix();
}
