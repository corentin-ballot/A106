GLuint CYLINDRE = -1;

void construire_cylindre(int nb_point) {
    int i = 0; float radius = 0.5;
    CYLINDRE = glGenLists(1);
    glNewList(CYLINDRE, GL_COMPILE);

    // Face haute
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 1, 0);
    glVertex3f(0, radius,0);
    for (i = nb_point; i >= 0; i--) {
        glVertex3f(cos(i * (2 * M_PI) / nb_point) * radius , radius,sin(i * (2 * M_PI) / nb_point) * radius);
    }
    glVertex3f(cos(i * (2 * M_PI) / nb_point) * radius , radius,sin(i * (2 * M_PI) / nb_point) * radius);
    glEnd();

    // Face basse
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, -1, 0);
    glVertex3f(0, -radius,0);
    for (i = 0; i < nb_point; i++) {
        glVertex3f(cos(i * (2 * M_PI) / nb_point) * radius , -radius,sin(i * (2 * M_PI) / nb_point) * radius);
    }
    glVertex3f(cos(i * (2 * M_PI) / nb_point) * radius , -radius,sin(i * (2 * M_PI) / nb_point) * radius);
    glEnd();

    // Faces latérales
    for (i = 0; i < nb_point; i++) {
        glBegin(GL_QUADS);

        vecteur an = {(cos(i * (2 * M_PI) / nb_point) * radius), 0, (sin(i * (2 * M_PI) / nb_point) * radius)};
        //an = normalise(an);

        glNormal3f(an.x, an.y, an.z);

        glVertex3f(cos((i+1)%nb_point * (2 * M_PI) / nb_point) * radius,  radius, sin((i+1)%nb_point * (2 * M_PI) / nb_point) * radius);
        glVertex3f(cos((i+1)%nb_point * (2 * M_PI) / nb_point) * radius, -radius, sin((i+1)%nb_point * (2 * M_PI) / nb_point) * radius);
        glVertex3f(cos( i             * (2 * M_PI) / nb_point) * radius, -radius, sin( i             * (2 * M_PI) / nb_point) * radius);

        glVertex3f(cos( i             * (2 * M_PI) / nb_point) * radius,  radius, sin( i             * (2 * M_PI) / nb_point) * radius);

        glEnd();
    }

    glEndList();
}
