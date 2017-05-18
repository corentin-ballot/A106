#include "pied_ecran.h"
#include "dale_ecran.h"

GLuint ECRAN[NB_SCREEN];
int ecran_id[14];

void construire_ecran() {
    construire_pied_ecran();

    int i;
    for(i = 0; i < NB_SCREEN; i++) {
        construire_dale_ecran(i);

        ECRAN[i] = glGenLists(1);
        glNewList(ECRAN[i], GL_COMPILE);
        glCallList(PIED_ECRAN);
        glCallList(DALE_ECRAN);

        glEndList();
    }

    srand(time(NULL));
    for(i = 0; i < 14; i++) {
        ecran_id[i] = (rand() % NB_SCREEN);
    }

}

void placementEcrans() {
  int i,j;

  // Deux premiers rangs (ecran 0 à 5)
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(610/2 - 160*i - 80, 75.0, -990/2 +230 + (80 + 90) * j - 20);
        glCallList(ECRAN[ecran_id[i+3*j]]);
        glPopMatrix();
    }
  }

  // Troisieme rang (ecran 6 à 10)
  j=2;
  for (i = 0; i < 2; i++) {
      
      glPushMatrix();
      glTranslatef(610/2 - 160*i - 80, 75.0, -990/2 +230 + (80 + 90) * j - 20);
      glCallList(ECRAN[ecran_id[6+i]]);
      glPopMatrix();
  }

  
  glPushMatrix();
  glTranslatef(610/2 - 160*2 - 30, 75.0, -990/2 +230 + (80 + 90) * j - 20);
  glCallList(ECRAN[ecran_id[8]]);
  glPopMatrix();

  
  glPushMatrix();
  glTranslatef(610/2 - 160*2 - 100, 75.0, -990/2 +230 + (80 + 90) * j - 20);
  glCallList(ECRAN[ecran_id[9]]);
  glPopMatrix();

  // Quatrieme rang (ecran 11 à 14)
  j=3;
  
  glPushMatrix();
  glTranslatef(610/2 - 160*0 - 80, 75.0, -990/2 +230 + (80 + 90) * j - 20);
  glCallList(ECRAN[ecran_id[10]]);
  glPopMatrix();

  
  glPushMatrix();
  glTranslatef(610/2 - 160*1 - 60, 75.0, -990/2 +230 + (80 + 90) * j - 20);
  glCallList(ECRAN[ecran_id[11]]);
  glPopMatrix();

  
  glPushMatrix();
  glTranslatef(610/2 - 160*1 - 130, 75.0, -990/2 +230 + (80 + 90) * j - 20);
  glCallList(ECRAN[ecran_id[12]]);
  glPopMatrix();

  
  glPushMatrix();
  glTranslatef(610/2 - 160*2 - 80, 75.0, -990/2 +230 + (80 + 90) * j - 20);
  glCallList(ECRAN[ecran_id[13]]);
  glPopMatrix();
}
