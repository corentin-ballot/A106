GLuint RADIATEUR = -1;

void construire_radiateur(){
    char* image[]={ "Libraries/Radiateur/Textures/right.tga",
                    "Libraries/Radiateur/Textures/front.tga",
                    "Libraries/Radiateur/Textures/right.tga",
                    "Libraries/Radiateur/Textures/front.tga",
                    "Libraries/Radiateur/Textures/top.tga",
                    "Libraries/Radiateur/Textures/top.tga"};

    charger_image(&texture[0],image[0]);
    texture[2] = texture[0];
    charger_image(&texture[1],image[1]);
    texture[3] = texture[1];
    charger_image(&texture[4],image[4]);
    texture[5] = texture[4];
    construire_cube();

    RADIATEUR = glGenLists(1);
    glNewList(RADIATEUR, GL_COMPILE);

    glPushMatrix();
    glCallList(CUBE);
    glPopMatrix();
    glEndList();
}
