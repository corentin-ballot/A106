struct vecteur{double x,y,z;};       /* definition d'un vecteur */
typedef struct vecteur vecteur;

double norme(vecteur X) {
    return(sqrt(X.x*X.x+X.y*X.y+X.z*X.z));
}

vecteur normalise(vecteur X) {
    double n;
    vecteur Y;

    n=norme(X);
    Y.x=X.x/n;
    Y.y=X.y/n;
    Y.z=X.z/n;
    return(Y);
}

vecteur milieu(vecteur X, vecteur Y) {
    vecteur W;
    W.x = (X.x + Y.x)/2;
    W.y = (X.y + Y.y)/2;
    W.z = (X.z + Y.z)/2;
    return(W);
}

vecteur produit(vecteur X, double n) {
    vecteur W;
    W.x = X.x * n;
    W.y = X.y * n;
    W.z = X.z * n;
    return(W);
}

float rad(float angle) {
  return (angle/180.)*M_PI;
}

float deg(float angle) {
  return (angle/M_PI)*180.;
}
