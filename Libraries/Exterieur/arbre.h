GLuint ARBRE = -1;

void construire_arbre(){

    char* image[]={"Libraries/Exterieur/Textures/arbre.tga"};

    charger_image(&texture[0],image[0]);
    texture[1] = texture[0];
    texture[2] = texture[0];
    texture[3] = texture[0];
    texture[4] = texture[0];
    texture[5] = texture[0];
    construire_cube();

    ARBRE = glGenLists(1);
    glNewList(ARBRE, GL_COMPILE);

    int i;
    float nb_faces = 2.0;
    for(i = nb_faces; i>=0; i--){
        glPushMatrix();
        glTranslatef(-500, -100, 0);
        glRotatef(i*180.0/nb_faces, 0, 1, 0);
        glScalef(200, 200, 0.001);
        glCallList(CUBE);
        glPopMatrix();
    }


    glEndList();
}
