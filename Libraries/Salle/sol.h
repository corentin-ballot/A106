GLuint SOL = -1;

void construire_sol() {
    char* image= "Libraries/Salle/Textures/sol.tga";

    charger_image(&texture[0],image);

    int i;
    for(i=1;i<6;i++) texture[i] = texture[0];
    construire_cube();

    SOL = glGenLists(1);
    glNewList(SOL, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, -10/2, 0.0);
    glScalef(610.0, 10, 990.0);
    glCallList(CUBE);
    glPopMatrix();
    glEndList();
}
