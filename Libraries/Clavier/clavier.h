GLuint CLAVIER = -1;

void construire_clavier(){
    char* image[]={ "Libraries/Clavier/Textures/top.tga",
                    "Libraries/Clavier/Textures/front.tga"};

    charger_image(&texture[4],image[0]);
    charger_image(&texture[0],image[1]);

    int i;
    for(i=1;i<5;i++) if(i !=4) texture[i] = texture[0];
    construire_cube();

    CLAVIER = glGenLists(1);
    glNewList(CLAVIER, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 3.0/2.0, 0.0);
    glScalef(45.3, 1.0, 14.5);
    glCallList(CUBE);
    glPopMatrix();

    glEndList();
}

void placementClaviers() {
  int i,j;

  // Deux premiers rangs
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(610/2 - 160*i - 80, 75.0, -990/2 +230 + (80 + 90) * j + 10);
        glCallList(CLAVIER);
        glPopMatrix();
    }
  }

  // Troisieme rang
  j=2;
  for (i = 0; i < 2; i++) {
      glPushMatrix();
      glTranslatef(610/2 - 160*i - 80, 75.0, -990/2 +230 + (80 + 90) * j + 10);
      glCallList(CLAVIER);
      glPopMatrix();
  }
  glPushMatrix();
  glTranslatef(610/2 - 160*2 - 30, 75.0, -990/2 +230 + (80 + 90) * j + 10);
  glCallList(CLAVIER);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(610/2 - 160*2 - 100, 75.0, -990/2 +230 + (80 + 90) * j + 10);
  glCallList(CLAVIER);
  glPopMatrix();

  // Quatrieme rang
  j=3;
  glPushMatrix();
  glTranslatef(610/2 - 160*0 - 80, 75.0, -990/2 +230 + (80 + 90) * j + 10);
  glCallList(CLAVIER);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(610/2 - 160*1 - 60, 75.0, -990/2 +230 + (80 + 90) * j + 10);
  glCallList(CLAVIER);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(610/2 - 160*1 - 130, 75.0, -990/2 +230 + (80 + 90) * j + 10);
  glCallList(CLAVIER);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(610/2 - 160*2 - 80, 75.0, -990/2 +230 + (80 + 90) * j + 10);
  glCallList(CLAVIER);
  glPopMatrix();
}
