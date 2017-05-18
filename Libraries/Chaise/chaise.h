#include "armature_chaise.h"
#include "assise_chaise.h"

GLuint CHAISE = -1;

void construire_chaise() {
    construire_armature_chaise();
    construire_assise_chaise();

    CHAISE = glGenLists(1);
    glNewList(CHAISE, GL_COMPILE);

    glCallList(ASSISE_CHAISE);
    glCallList(AMATURE_CHAISE);

    glEndList();
}

void placementChaises() {
  int i, j;
  for (i = 0; i < 4; i++) { // Rangées
    for (j = 0; j < 3; j++) { // Tables
      glPushMatrix(); // Prépare "l'environement de transformation"
      glTranslatef(610/2-160/4 - j * 160, 0.0, -990/2 +260 + 170 * i);
      glCallList(CHAISE);
      glPopMatrix();

      glPushMatrix(); // Prépare "l'environement de transformation"
      glTranslatef(610/2-3*160/4 - j * 160, 0.0, -990/2 +260 + 170 * i);
      glCallList(CHAISE);
      glPopMatrix();
    }
  }

  // Chaises enseignant
  glPushMatrix(); // Prépare "l'environement de transformation"
  glTranslatef(610/2-160/4 - 160, 0.0, -990/2 +125);
  glRotatef(180, 0.0, 1.0, 0.0);
  glCallList(CHAISE);
  glPopMatrix();

  glPushMatrix(); // Prépare "l'environement de transformation"
  glTranslatef(610/2-3*160/4 - 160, -40.0, -990/2 +125);
  glRotatef(180, 0.0, 1.0, 0.0);
  glCallList(CHAISE);
  glPopMatrix();
}
