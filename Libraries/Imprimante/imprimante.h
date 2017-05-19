GLuint IMPRIMANTE = -1;

void construire_imprimante(){
    char* image[]={ "Libraries/Imprimante/Textures/left.tga",
                    "Libraries/Imprimante/Textures/back.tga",
                    "Libraries/Imprimante/Textures/left.tga",
                    "Libraries/Imprimante/Textures/front.tga",
                    "Libraries/Imprimante/Textures/top.tga",
                    "Libraries/Imprimante/Textures/top.tga"};

    int i;
    for(i=0;i<6;i++) charger_image(&texture[i],image[i]);
    construire_cube();

    IMPRIMANTE = glGenLists(1);
    glNewList(IMPRIMANTE, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 32.5/2.0, 0.0);
    glScalef(42.0, 32.5, 47.0);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}

