#include "plafond.h"
#include "sol.h"
#include "mur_est.h"
#include "mur_ouest.h"
#include "mur_nord.h"
#include "mur_sud.h"

GLuint SALLE = -1;

void construire_salle() {
    construire_sol();
    construire_plafond();
    construire_mur_est();
    construire_mur_ouest();
    construire_mur_nord();
    construire_mur_sud();

    SALLE = glGenLists(1);
    glNewList(SALLE, GL_COMPILE);

    glCallList(PLAFOND);
    glCallList(SOL);
    glCallList(MUR_EST);
    glCallList(MUR_OUEST);
    glCallList(MUR_NORD);
    glCallList(MUR_SUD);

    placementImprimante();
    placementTables();
    placementChaises();
    placementOrdinateurs();
    placementEcrans();
    placementClaviers();
    placement_fenetres();

    glEndList();
}
