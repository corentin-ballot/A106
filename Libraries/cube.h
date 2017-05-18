GLuint CUBE = -1;

GLuint texture[6];

void construire_cube() {
  float COTE = 0.5;
  vecteur sommet[6][4]={{{+COTE,-COTE,+COTE},{+COTE,-COTE,-COTE},{+COTE,+COTE,-COTE},{+COTE,+COTE,+COTE}},   /* face 0 */
                      {{+COTE,-COTE,-COTE},{-COTE,-COTE,-COTE},{-COTE,+COTE,-COTE},{+COTE,+COTE,-COTE}},   /* face 1 */
                      {{-COTE,-COTE,-COTE},{-COTE,-COTE,+COTE},{-COTE,+COTE,+COTE},{-COTE,+COTE,-COTE}},   /* face 2 */
                      {{-COTE,-COTE,+COTE},{+COTE,-COTE,+COTE},{+COTE,+COTE,+COTE},{-COTE,+COTE,+COTE}},   /* face 3 */
                      {{-COTE,+COTE,+COTE},{+COTE,+COTE,+COTE},{+COTE,+COTE,-COTE},{-COTE,+COTE,-COTE}},   /* face 4 */
                      {{-COTE,-COTE,-COTE},{+COTE,-COTE,-COTE},{+COTE,-COTE,+COTE},{-COTE,-COTE,+COTE}}};  /* face 5 */

  vecteur normale[6]={{1.,0.,0.},{0.,0.,-1.},{-1.,0.,0.},{0.,0.,1.},{0.,1.,0.},{0.,-1.,0.}};

  int f;

  CUBE=glGenLists(1);
  glNewList(CUBE,GL_COMPILE);

  for(f=0;f<6;f++){
    glBindTexture(GL_TEXTURE_2D,texture[f]);

      glBegin(GL_QUADS);

      glNormal3f(normale[f].x,normale[f].y,normale[f].z);

      glTexCoord2f(0.,0.);
      glVertex3f(sommet[f][0].x,sommet[f][0].y,sommet[f][0].z);
      glTexCoord2f(1.,0.);
      glVertex3f(sommet[f][1].x,sommet[f][1].y,sommet[f][1].z);
      glTexCoord2f(1.,1.);
      glVertex3f(sommet[f][2].x,sommet[f][2].y,sommet[f][2].z);
      glTexCoord2i(0.,1.);
      glVertex3f(sommet[f][3].x,sommet[f][3].y,sommet[f][3].z);

      glEnd();

    glBindTexture(GL_TEXTURE_2D,0);

    }

  glEndList();
}
