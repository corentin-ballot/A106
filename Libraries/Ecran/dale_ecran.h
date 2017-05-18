GLuint DALE_ECRAN = -1;
#define NB_SCREEN 10

void construire_dale_ecran(int id) {
    char screen[36];
    sprintf(screen, "Libraries/Ecran/Textures/front_0%d.tga", id);

    char* image[]={ "Libraries/Ecran/Textures/top.tga",
                    "Libraries/Ecran/Textures/back.tga",
                    "Libraries/Ecran/Textures/top.tga",
                    screen,
                    "Libraries/Ecran/Textures/top.tga",
                    "Libraries/Ecran/Textures/top.tga"};

    charger_image(&texture[1],image[1]);
    charger_image(&texture[3],image[3]);
    charger_image(&texture[0],image[0]);

    int i;
    for(i=2;i<6;i++) if(i!=3) texture[i] = texture[0];
    construire_cube();

    DALE_ECRAN = glGenLists(1);
    glNewList(DALE_ECRAN, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 27.8/2 + 7.3, 4);
    glScalef(46.7, 27.8, 2);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}
