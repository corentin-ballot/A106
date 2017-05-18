GLuint PIED_TABLE = -1;

float MATERIAL_PIED_TABLE[4][4] = {{0.0f, 0.0f, 0.0f, 1.0f },{0.01f, 0.01f, 0.01f, 1.0f },{1.0f, 1.0f, 1.0f, 1.0f },{60.0f}} ;

void construire_pied_table(){
    PIED_TABLE = glGenLists(1);
    glNewList(PIED_TABLE, GL_COMPILE);

    glPushMatrix();
    def_material(MATERIAL_PIED_TABLE);
    glTranslatef(0.0, 72.5/2, 0.0);
    glScalef(5.0, 72.5, 5.0);
    glCallList(CYLINDRE);
    def_material(MATERIAL_DEFAULT);
    glPopMatrix();
    glEndList();
}
