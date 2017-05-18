GLuint PLATEAU_TABLE = -1;

void construire_plateau_table(){
    char* image[]={ "Libraries/Table/Textures/bottom.tga",
                    "Libraries/Table/Textures/bottom.tga",
                    "Libraries/Table/Textures/bottom.tga",
                    "Libraries/Table/Textures/bottom.tga",
                    "Libraries/Table/Textures/top.tga",
                    "Libraries/Table/Textures/bottom.tga"};

    charger_image(&texture[0],image[0]);
    charger_image(&texture[4],image[4]);

    int i;
    for(i=0;i<6;i++) if(i != 4) texture[i] = texture[0];
    construire_cube();

    PLATEAU_TABLE = glGenLists(1);
    glNewList(PLATEAU_TABLE, GL_COMPILE);

    glPushMatrix();
    def_material(MATERIAL_TURQUOISE);
    glTranslatef(0.0, 2.5/2, 0.0);
    glScalef(160.0, 2.5, 80.0);
    glCallList(CUBE);
    def_material(MATERIAL_DEFAULT);
    glPopMatrix();

    glEndList();
}
