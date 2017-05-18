GLuint ASSISE_CHAISE = -1;

void construire_assise_chaise() {
    char* image= "Libraries/Chaise/Textures/top.tga";
    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    ASSISE_CHAISE = glGenLists(1);
    glNewList(ASSISE_CHAISE, GL_COMPILE);

    def_material(MATERIAL_DEFAULT);
    // Repose fesses
    glPushMatrix();
    glTranslatef(0.0, 44.0, 0.0);
    glScalef(46.0, 0.8, 28.0);
    glCallList(CUBE);
    glPopMatrix();

    // Dossier
    glPushMatrix();
    glTranslatef(0.0, 44.0*1.5, 28.0/2 + 4);
    glRotatef(100, 1.0, 0.0, 0.0);
    glScalef(46.0, 0.8, 45.0);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
