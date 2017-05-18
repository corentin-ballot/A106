GLuint CLANCHE = -1;

void construire_clanche() {
    CLANCHE = glGenLists(1);
    glNewList(CLANCHE, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 0, 0.0);
    glScalef(5.5, 5.5, 5.5);
    glRotatef(90, 1.0, 0.0, 0.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0, 0.0);
    glScalef(2.0, 2.0, 18.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0, 9.0);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0, -9.0);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0, 0, 9.0);
    glScalef(12.0, 2.0, 2.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0, 0, -9.0);
    glScalef(12.0, 2.0, 2.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glCallList(CYLINDRE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12.0, 0, 9.0);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12.0, 0, -9.0);
    glScalef(0.535, 0.535, 0.535);
    glCallList(GEODE);
    glPopMatrix();

    glEndList();
}
