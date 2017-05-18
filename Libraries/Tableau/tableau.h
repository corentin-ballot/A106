GLuint TABLEAU = -1;

void construire_tableau() {
    char* image[]={ "Libraries/Tableau/Textures/bordure.tga",
                    "Libraries/Tableau/Textures/bordure.tga",
                    "Libraries/Tableau/Textures/bordure.tga",
                    "Libraries/Tableau/Textures/front.tga",
                    "Libraries/Tableau/Textures/bordure.tga",
                    "Libraries/Tableau/Textures/bordure.tga"};

    charger_image(&texture[0],image[0]);
    charger_image(&texture[3],image[3]);

    int i;
    for(i=1;i<6;i++) if(i!=3) texture[i] = texture[0];
    construire_cube();

    TABLEAU = glGenLists(1);
    glNewList(TABLEAU, GL_COMPILE);

    // Ardoise
    glPushMatrix();
    glTranslatef(0.0, 120.0/2 + 1.5, 1.5/2);
    glScalef(400, 120, 1.5);
    glCallList(CUBE);
    glPopMatrix();

    // Repose craies
    glPushMatrix();
    glTranslatef(0.0, 1.5/2, 10 / 2.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(400, 10, 1.5);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
