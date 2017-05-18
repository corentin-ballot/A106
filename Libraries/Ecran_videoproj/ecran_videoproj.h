GLuint ECRAN_VIDEOPROJ = -1;

double OUVERTURE_ECRANVIDEOPROJ = 1;
double ECRANVIDEOPROJ_OPENING = 0;

void construire_ecran_videoproj() {
    char* image[]={ "Libraries/Ecran_videoproj/Textures/border.tga",
                    "Libraries/Ecran_videoproj/Textures/front.tga"};

    charger_image(&texture[0],image[0]);
    charger_image(&texture[3],image[1]);

    int i;
    for(i=1;i<6;i++) if(i!=3) texture[i] = texture[0];
    construire_cube();

    ECRAN_VIDEOPROJ = glGenLists(1);
    glNewList(ECRAN_VIDEOPROJ, GL_COMPILE);

    glPushMatrix();
    glTranslatef(200.0 / 2.0, 5.0/2.0, 5.0/2.0);
    glScalef(200, 5.0, 5.0);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}

void placement_ecran_videoproj() {
    glPushMatrix();
    glTranslatef(610/2 - 472, 210.0, -990/2);
    glCallList(ECRAN_VIDEOPROJ);

        glPushMatrix();
        glTranslatef(5.0, 0.0, 3);
        glScalef(0.95, OUVERTURE_ECRANVIDEOPROJ * 150 / 5.0, 0.1);
        glRotatef(90, 1.0, 0.0, 0.0);
        glCallList(ECRAN_VIDEOPROJ);
        glPopMatrix();

        // Cylindre de fin de rideau
        glPushMatrix();
        glTranslatef(200.0/2.0, -1 - OUVERTURE_ECRANVIDEOPROJ * 150, 3);
        glScalef(196, 2, 2);
        glRotatef(90, 0.0, 0.0, 1.0);
        glCallList(CYLINDRE);
        glPopMatrix();

    glPopMatrix();
}
