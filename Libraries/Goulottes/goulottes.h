GLuint GOULOTTES = -1;

void construire_goulottes() {

    char* image= "Libraries/Goulottes/Textures/goulottes.tga";

    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    GOULOTTES = glGenLists(1);
    glNewList(GOULOTTES, GL_COMPILE);

    glPushMatrix();
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
