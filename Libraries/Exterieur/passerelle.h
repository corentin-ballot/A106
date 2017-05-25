GLuint PASSERELLE_EXTERIEUR = -1;

void construire_passerelle_exterieur(){

    char* image[]={"Libraries/Exterieur/Textures/passerelle.tga"};

    charger_image(&texture[0],image[0]);
    texture[1] = texture[0];
    texture[2] = texture[0];
    texture[3] = texture[0];
    texture[4] = texture[0];
    texture[5] = texture[0];
    construire_cube();

    PASSERELLE_EXTERIEUR = glGenLists(1);
    glNewList(PASSERELLE_EXTERIEUR, GL_COMPILE);

    glPushMatrix();
    glTranslatef(-1000, 0, 1415);
    glRotatef(30, 0, 1, 0);
    glScalef(1, 1000, 2000);
    glCallList(CUBE);
    glPopMatrix();


    glEndList();
}
