GLuint ORDINATEUR = 0;

void construire_ordinateur(){
    char* image[]={ "Libraries/Ordinateur/Textures/right.tga",
                    "Libraries/Ordinateur/Textures/back.tga",
                    "Libraries/Ordinateur/Textures/left.tga",
                    "Libraries/Ordinateur/Textures/front.tga",
                    "Libraries/Ordinateur/Textures/top.tga",
                    "Libraries/Ordinateur/Textures/top.tga"};

    int i;
    for(i=0;i<5;i++) charger_image(&texture[i],image[i]);
    texture[5] = texture[4];
    construire_cube();

    ORDINATEUR = glGenLists(1);
    glNewList(ORDINATEUR, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 47.0/2.0, 0.0);
    glScalef(17.3, 47.0, 41.3);
    glCallList(CUBE);
    glPopMatrix();
    glEndList();
}

void placementOrdinateurs() {
  int i,j;

  // Deux premiers rang
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(610/2 - 160*i - 20, 75.0, -990/2 +230 + (80 + 90) * j);
        glCallList(ORDINATEUR);
        glPopMatrix();
    }
  }

  // Troisième rang
  j = 2;
  for (i = 0; i < 2; i++) {
      glPushMatrix();
      glTranslatef(610/2 - 160*i - 20, 75.0, -990/2 +230 + (80 + 90) * j);
      glCallList(ORDINATEUR);
      glPopMatrix();
  }
  for (i = 2; i < 4; i++) {
      glPushMatrix();
      glTranslatef(610/2 - 160*i + 20, 75.0, -990/2 +230 + (80 + 90) * j);
      glCallList(ORDINATEUR);
      glPopMatrix();
  }


  // Quatrième rang
  j = 3;
  for (i = 0; i < 3; i++) {
      glPushMatrix();
      glTranslatef(610/2 - 160*i - 20, 75.0, -990/2 +230 + (80 + 90) * j);
      glCallList(ORDINATEUR);
      glPopMatrix();
  }
  glPushMatrix();
  glTranslatef(610/2 - 160*3 + 20, 75.0, -990/2 +230 + (80 + 90) * j);
  glCallList(ORDINATEUR);
  glPopMatrix();

}
