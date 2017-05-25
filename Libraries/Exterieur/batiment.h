GLuint BATIMENT_EXTERIEUR = -1;

void construire_batiment_exterieur(){

    char* image[]={"Libraries/Exterieur/Textures/batiment.tga"};

    charger_image(&texture[0],image[0]);
    texture[1] = texture[0];
    texture[2] = texture[0];
    texture[3] = texture[0];
    texture[4] = texture[0];
    texture[5] = texture[0];
    construire_cube();

    BATIMENT_EXTERIEUR = glGenLists(1);
    glNewList(BATIMENT_EXTERIEUR, GL_COMPILE);

    int i;
    for(i=0; i<27; i++){
        glPushMatrix();
        glTranslatef(-1500, 0, 500 -100*i);
        glScalef(1, 1000, 100);
        glCallList(CUBE);
        glPopMatrix();
    }

    int j;
    for(j=0; j<15; j++){
        glPushMatrix();
        glTranslatef(-1500 + 50 + 100*j, 0, 500 +50 -100*i);
        glRotatef(90, 0, 1, 0);
        glScalef(1, 1000, 100);
        glCallList(CUBE);
        glPopMatrix();
    }

    glEndList();
}
