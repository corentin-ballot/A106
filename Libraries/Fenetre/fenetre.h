GLuint FENETRE = -1;

void construire_fenetre(){
    if(CLANCHE == -1)
        construire_clanche();

    char* image[]={"Libraries/Fenetre/Textures/top.tga"};

    charger_image(&texture[0],image[0]);
    texture[1] = texture[0];
    texture[2] = texture[0];
    texture[3] = texture[0];
    texture[4] = texture[0];
    texture[5] = texture[0];
    construire_cube();

    FENETRE = glGenLists(1);
    glNewList(FENETRE, GL_COMPILE);

    // Encadrement bas
    glPushMatrix();
    glTranslatef(0, 8.0/2.0, 3.5/2.0);
    glScalef(222.0 - 16, 8.0, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Encadrement milieu
    glPushMatrix();
    glTranslatef(0, 8.0 + 8.0/2.0 + 109, 3.5/2.0);
    glScalef(222.0 - 16, 8.0, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Encadrement haut
    glPushMatrix();
    glTranslatef(0, 8.0 + 109 + 8 + 39 + 8.0/2.0, 3.5/2.0);
    glScalef(222.0 - 16, 8.0, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Encadrement droite
    glPushMatrix();
    glTranslatef(222.0/2.0 - 8.0/2.0, 172/2.0, 3.5/2.0);
    glScalef(8.0, 172.0, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Encadrement gauche
    glPushMatrix();
    glTranslatef(-222.0/2.0 + 8.0/2.0, 172/2.0, 3.5/2.0);
    glScalef(8.0, 172.0, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Encadrement interieur gauche
    glPushMatrix();
    glTranslatef(-222/2.0 + 52 + 8.0/2.0, 172.0 - 8.0 - 39.0/2.0, 3.5/2.0);
    glScalef(8.0, 39, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Encadrement interieur droit
    glPushMatrix();
    glTranslatef(-222/2.0 + 127 + 8.0/2.0, 8 + 109.0/2.0, 3.5/2.0);
    glScalef(8.0, 109, 3.5);
    glCallList(CUBE);
    glPopMatrix();

    // Clanche
    def_material(MATERIAL_BLACK_PLASTIC);
    glPushMatrix();
    glTranslatef(222.0/2.0 - 8.0/2.0, 8 + 109.0/2.0, 3.5/2.0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.7, 1.0, 0.5);
    glCallList(CLANCHE);
    glPopMatrix();
    def_material(MATERIAL_DEFAULT);

    glEndList();
}

placement_fenetres() {
    // Fenetre 1 en partant du fond
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-990/2 + 13.9 + 222/2.0, 93, -610/2.0 - 3.5);
    glCallList(FENETRE);
    glPopMatrix();

    // Fenetre 2 en partant du fond
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-990/2 + 13.9 + 222 + 67.5 + 222/2.0, 93, -610/2.0 - 3.5);
    glCallList(FENETRE);
    glPopMatrix();

    // Fenetre 3 en partant du fond
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-990/2 + 13.9 + 222 + 67.5 + 222 + 222/2.0, 93, -610/2.0 - 3.5);
    glCallList(FENETRE);
    glPopMatrix();

    // Fenetre 4 en partant du fond
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-990/2 + 13.9 + 222 + 67.5 + 222 + 222 + 222/2.0, 93, -610/2.0 - 3.5);
    glCallList(FENETRE);
    glPopMatrix();
}
