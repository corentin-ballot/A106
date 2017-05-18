#include "pied_table.h"
#include "plateau_table.h"

GLuint TABLE = -1;
GLuint RANGEE_3_TABLE = -1;

void construire_table() {
    construire_pied_table();
    construire_plateau_table();


    TABLE = glGenLists(1);
    glNewList(TABLE, GL_COMPILE);

    glPushMatrix();
    glTranslatef(-75.0, 0.0, -35.0);
    glCallList(PIED_TABLE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 75.0, 0.0, -35.0);
    glCallList(PIED_TABLE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-75.0, 0.0,  35.0);
    glCallList(PIED_TABLE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 75.0, 0.0,  35.0);
    glCallList(PIED_TABLE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 72.5, 0.0);
    glCallList(PLATEAU_TABLE);
    glPopMatrix();

    glEndList();
}

void construire_rangee_3_table() {
    if(TABLE == 0)
        construire_table();

    RANGEE_3_TABLE = glGenLists(1);
    glNewList(RANGEE_3_TABLE, GL_COMPILE);

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glCallList(TABLE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(160.0, 0.0, 0.0);
    glCallList(TABLE);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-160., 0.0, 0.0);
    glCallList(TABLE);
    glPopMatrix();

    glEndList();
}

void placementTables() {
  int i;
  for (i = 0; i < 4; i++) {
      glPushMatrix();
      glTranslatef((610 - 3*160)/2, 0.0, -990/2 +230 + (80 + 90) * i);
      glCallList(RANGEE_3_TABLE);
      glPopMatrix();
  }

  // Tables enseignants
  glPushMatrix();
  glTranslatef((610 - 160)/2 - 160, 0.0, -990/2 +230 - 80);
  glCallList(TABLE);
  glPopMatrix();

  // Tables du fond
  glPushMatrix();
  glTranslatef((610 - 160)/2, 0.0, 990/2 - 80/2);
  glCallList(TABLE);
  glPopMatrix();

  glPushMatrix();
  glTranslatef((610 - 160)/2 - 2*160, 0.0, 990/2 - 80/2);
  glCallList(TABLE);
  glPopMatrix();
}
