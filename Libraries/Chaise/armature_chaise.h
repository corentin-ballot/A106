GLuint AMATURE_CHAISE = -1;

float MATERIAL_ARMATURE_CHAISE[4][4] = {{ 0.2f, 0.2, 0.0, 1.0f },{0.8, 0.8, 0.0, 1.0f },{1.0, 1.0, 1.0, 1.0f },{80.0f}} ;

void construire_armature_chaise() {
    AMATURE_CHAISE = glGenLists(1);
    glNewList(AMATURE_CHAISE, GL_COMPILE);

    // Réaction à la lumière
    glPushMatrix();
    def_material(MATERIAL_ARMATURE_CHAISE);

    glPushMatrix();
    glTranslatef(46.0/2, 44.0/2, -28.0/2);
    glScalef(2.0, 44.0, 2.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.0/2, 44.0, -28.0/2);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.0/2, 44.0, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(2.0, 28.0, 2.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.0/2, 44.0, 28.0/2);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(46.0/2, 45.0/2, 28.0/2 + 5.75);
    glRotatef(-15, 1.0, 0.0, 0.0);
    glScalef(2.0, 45.0, 2.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    // SYMETRIE
    glPushMatrix();
    glTranslatef(-46.0/2, 44.0/2, -28.0/2);
    glScalef(2.0, 44.0, 2.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-46.0/2, 44.0, -28.0/2);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-46.0/2, 44.0, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(2.0, 28.0, 2.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-46.0/2, 44.0, 28.0/2);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-46.0/2, 45.0/2, 28.0/2 + 5.75);
    glRotatef(-15, 1.0, 0.0, 0.0);
    glScalef(2.0, 45.0, 2.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    def_material(MATERIAL_DEFAULT);
    glPopMatrix();

    glEndList();
}
