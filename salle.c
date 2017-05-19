// cd /mnt/f/Corentin/Documents/COURS/M1/Infographie
// ./comp salle

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "GL/glut.h"
#include "tga.h"
#include "Libraries/reflexion.h"
#include "Libraries/vecteur.h"
#include "Libraries/cube.h"
#include "Libraries/cylindre.h"
#include "Libraries/geode.h"

#include "Libraries/Chaise/chaise.h"
#include "Libraries/Ecran/ecran.h"
#include "Libraries/Ordinateur/ordinateur.h"
#include "Libraries/Table/table.h"
#include "Libraries/Tableau/tableau.h"
#include "Libraries/Porte/porte.h"
#include "Libraries/Goulottes/goulottes.h"
#include "Libraries/Ecran_videoproj/ecran_videoproj.h"
#include "Libraries/Clavier/clavier.h"
#include "Libraries/Radiateur/radiateur.h"
#include "Libraries/Exterieur/exterieur.h"
#include "Libraries/Fenetre/fenetre.h"
#include "Libraries/Imprimante/imprimante.h"
#include "Libraries/Salle/salle.h"

#define FPS 30

int lum_enable = 1;
int lumieres[8] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};

double angle = -M_PI/2, tetha = 0, distance = 50., rayon = 20.;

float observateur_x = 0.0,  observateur_y  = 170.0, observateur_z = 8.0;
float pointvise_x   = 0.0,  pointvise_y    = 0.0  , pointvise_z   = 0.0;
float orientation_x = 0.0,  orientation_y  = 1.0  , orientation_z = 0.0;

void placementLumieres() {
    int i;
    for (i = 0; i < 4; i++) {
        float l1[4] = { 610.0/4, 274.0, -990.0/2 + (i+1)*990.0/5, 1},
              l2[4] = {-610.0/4, 274.0, -990.0/2 + (i+1)*990.0/5, 1};
        glLightfv(lumieres[i],   GL_POSITION, l1);
        glLightfv(lumieres[i+1], GL_POSITION, l2);
    }
}

void afficher() {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  /* VISUALISATION : mise en place de l'observateur */

  glMatrixMode(GL_MODELVIEW);                           /* active la matrice de MODELISATION           */
  glLoadIdentity();                                     /* charge la matrice IDENTITE                  */
  gluLookAt(observateur_x,observateur_y,observateur_z,  /* Observateur */
              pointvise_x,  pointvise_y,  pointvise_z,  /* Point visé  */
            orientation_x,orientation_y,orientation_z); /* Orientation */
                                                        /* specifie les param�tres de VISUALISATION  : */
                                                        /* Observateur  : (0.0,0.0,8.0)                */
                                                        /* Point vis�   : (0.0,0.0,0.0)                */
                                                        /* Orientation  : (0.0,1.0,0.0)                */

  /*float l1[4] = { observateur_x, observateur_y, observateur_z, 1};
  glLightfv(lumieres[0],   GL_POSITION, l1);*/
  /* MODELISATION : construction de la sc�ne */

  glCallList(SALLE);

  placementImprimante();
  placement_exterieur();

  placement_fenetres();

  placementTables();
  placementChaises();
  placementOrdinateurs();
  placementEcrans();
  placementPortes();
  placement_ecran_videoproj();
  placementClaviers();

  // Animation des portes
  if(PORTE_OPENING && OUVERTURE_PORTE < 1)
    OUVERTURE_PORTE += 0.05;
  else if(!PORTE_OPENING && OUVERTURE_PORTE > 0.0)
    OUVERTURE_PORTE -= 0.05;

  // Animation des clanches
  if(CLANCHE_OPENING && OUVERTURE_CLANCHE < 1)
    OUVERTURE_CLANCHE += 0.05;
  else if(!CLANCHE_OPENING && OUVERTURE_CLANCHE > 0.0)
    OUVERTURE_CLANCHE -= 0.05;

  // Animation ecran videoproj
  if(ECRANVIDEOPROJ_OPENING && OUVERTURE_ECRANVIDEOPROJ < 1)
    OUVERTURE_ECRANVIDEOPROJ += 0.005;
  else if(!ECRANVIDEOPROJ_OPENING && OUVERTURE_ECRANVIDEOPROJ > 0.0)
    OUVERTURE_ECRANVIDEOPROJ -= 0.005;

  glutSwapBuffers();

  int err = glGetError();
  if(err != 0)
    printf("%s\n", gluErrorString(err));
}

void rafraichir(int l, int h) {
  /* l et h sont les dimensions recuperees de la fenetre */
  int l_init = l, h_init = h;

  if(l>3./2.*h) l=3./2.*h;                  /* permet de conserver le ratio largeur hauteur */
  else h=2./3.*l;

  glViewport(((float)(l_init - l))/2.0,((float)(h_init - h))/2.0,l,h);                    /* definition de la zone ecran au centre de la fenetre */

  glMatrixMode(GL_PROJECTION);              /* active la matrice de PROJECTION       */
  glLoadIdentity();                         /* charge la matrice IDENTITE            */
  glFrustum(-1.8,1.8,-1.2,1.2,5.0 ,200000.0); /* definit le volume de vue :            */
                                            /* gauche : -1.8,    droit : 1.8         */
                                            /* bas    : -1.2,    haut  : 1.2         */
                                            /* avant-plan : 5, arri�re-plan : 10     */
}

void animate(int id) {
  glutTimerFunc(1000/FPS, &animate, 0);
	glutPostRedisplay();
}

void initPointVise() {
    rayon=distance*cos(tetha);
    pointvise_x=observateur_x + rayon*cos(angle);
    pointvise_z=observateur_z + rayon*sin(angle);
    pointvise_y=observateur_y + distance*sin(tetha);
}

void key(unsigned char key, int x, int y) {
  int i;
  vecteur obs = {observateur_x, 0, observateur_z};
  vecteur pov = {pointvise_x, 0, pointvise_z};
  vecteur deplacement = milieu(obs, pov);
  deplacement.x = deplacement.x - observateur_x;
  deplacement.z = deplacement.z - observateur_z;
	switch(key) {
    case 'z':
      observateur_x += deplacement.x;
      observateur_z += deplacement.z;
			break;
    case 's':
      observateur_x -= deplacement.x;
      observateur_z -= deplacement.z;
  		break;
    case 'q': // Utilisation de la matrice de rotation
      observateur_x += deplacement.x * cos(rad(90)) + deplacement.z * sin(rad(90));
      observateur_z += deplacement.x * -sin(rad(90)) + deplacement.z * cos(rad(90));
    	break;
    case 'd': // Utilisation de la matrice de rotation
      observateur_x -= deplacement.x * cos(rad(90)) + deplacement.z * sin(rad(90));
      observateur_z -= deplacement.x * -sin(rad(90)) + deplacement.z * cos(rad(90));
      break;
    case 'l': // Lumières
      if(lum_enable) {
          for (i = 0; i < 8; i++) {
              glDisable(lumieres[i]);
          }
          lum_enable = 0;
      } else {
          for (i = 0; i < 8; i++) {
              glEnable(lumieres[i]);
          }
          lum_enable = 1;
      }
      break;
    case 'e': // Porte
      if(PORTE_OPENING) {
          PORTE_OPENING = 0;
      } else if(OUVERTURE_CLANCHE > 0.7 || OUVERTURE_PORTE > 0) { // La clanche doit être appuié à au moins 70% pour ouvrir la porte
          PORTE_OPENING = 1;
      }
      break;
    case 'a': // Clanche
      if(CLANCHE_OPENING) {
          CLANCHE_OPENING = 0;
      } else {
          CLANCHE_OPENING = 1;
      }
      break;
    case 'r': // Ecran videoproj
      if(ECRANVIDEOPROJ_OPENING) {
          ECRANVIDEOPROJ_OPENING = 0;
      } else {
          ECRANVIDEOPROJ_OPENING = 1;
      }
      break;

      case 'x': // Ecran videoproj
        observateur_y += 10;
        break;
        case 'w': // Ecran videoproj
          observateur_y -= 10;
          break;
		default:
			break;
	}

  // Restriction de déplacement dans la salle
  // Restriction X
  /*if(observateur_x >= 610.0/2.0-20)
    observateur_x = 610.0/2.0-10;
  if(observateur_x <= -610.0/2.0+20)
    observateur_x = -610.0/2.0+10;

  // Restriction Y
  if(observateur_y >= 275.0-20)
    observateur_y = 275.0-20;
  if(observateur_y <= 0.0+20)
    observateur_y = 0.0+20;

  // Restriction Z
  if(observateur_z >= 990.0/2.0-20)
    observateur_z = 990.0/2.0-20;
  if(observateur_z <= -990.0/2.0+20)
    observateur_z = -990.0/2.0+20;*/

  // Mise à jour du point de visé
  initPointVise();
}

int prev_x = 0, prev_y = 0;
void mousedrag(int x, int y) {
    if(x > prev_x)
      angle += 0.01;
    else if(x < prev_x)
      angle -= 0.01;

    if(y > prev_y)
      tetha -= 0.01;
    else if(y < prev_y)
      tetha += 0.01;

    if(tetha > 1.0)
      tetha = 1.0;
    if(tetha < -1.0)
      tetha = -1.0;

    initPointVise();

    prev_x = x;
    prev_y = y;
}

void initialiser_lumieres() {
  int nb_lum = 8;

  float lum_ambiante[]={0.2/nb_lum,0.2/nb_lum,0.2/nb_lum,1.};    /* composante ambiante de la lumi�re                */
  float lum_diffuse[]={1.0/nb_lum,1.0/nb_lum,1.0/nb_lum,1.};     /* composante diffuse de la lumi�re                 */
  float lum_speculaire[]={1.0/nb_lum,1.0/nb_lum,1.0/nb_lum,1.};  /* composante sp�culaire de la lumiere              */

  int i;
  for (i = 0; i < 8; i++) {
    glLightfv(lumieres[i],GL_AMBIENT,lum_ambiante);
    glLightfv(lumieres[i],GL_DIFFUSE,lum_diffuse);
    glLightfv(lumieres[i],GL_SPECULAR,lum_speculaire);
  }

  if(lum_enable) {
      for (i = 0; i < 8; i++)
          glEnable(lumieres[i]);
  } else {
      for (i = 0; i < 8; i++)
          glDisable(lumieres[i]);
  }
}

void initObjets() {
  construire_cube();
  construire_cylindre(50);
  construire_geode(2);
  construire_table();
  construire_rangee_3_table();
  construire_ordinateur();
  construire_porte();
  construire_ecran();
  construire_chaise();
  construire_clavier();
  construire_fenetre();
  construire_imprimante();
  construire_salle();
}

main(int argc, char **argv)
{
  //system("clear");
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

  /* initialisation de la fenetre principale */

  glutInitWindowSize(1200, 750);
  glutInitWindowPosition(10,10);
  glutCreateWindow("Cube texture");

  /* initialisation pour le rendu des lumieres */

  initialiser_lumieres();
  placementLumieres();
  glEnable(GL_LIGHTING);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);

  glEnable(GL_DEPTH_TEST);                           /* mise en place du Z-buffer */
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);  /* correction de perspective sur les textures */
  glEnable(GL_NORMALIZE);
  glEnable(GL_RESCALE_NORMAL);
  glEnable(GL_TEXTURE_2D);

  initPointVise();
  initObjets();

  glutMotionFunc(&mousedrag);
  glutDisplayFunc(&afficher);
  glutKeyboardFunc(&key);

  glutTimerFunc(1000/FPS, &animate, 0);
  glutReshapeFunc(&rafraichir);
  glutMainLoop();
}
