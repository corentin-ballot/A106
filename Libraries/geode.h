GLuint GEODE = -1;

void dessine_triangle(vecteur a, vecteur b, vecteur c) {

    vecteur an = normalise(a);
    vecteur bn = normalise(b);
    vecteur cn = normalise(c);

    glNormal3f(an.x, an.y, an.z);
    glVertex3f(a.x, a.y, a.z);

    glNormal3f(cn.x, cn.y, cn.z);
    glVertex3f(c.x, c.y, c.z);

    glNormal3f(bn.x, bn.y, bn.z);
    glVertex3f(b.x, b.y, b.z);
}

void dessine_triangle_rec(vecteur a, vecteur b, vecteur c, int profondeur) {
    if(profondeur == 0) {
        dessine_triangle(a, b, c);
    } else {
        vecteur d = {(a.x + b.x)/2, (a.y + b.y)/2, (a.z + b.z)/2};
        vecteur e = {(c.x + b.x)/2, (c.y + b.y)/2, (c.z + b.z)/2};
        vecteur f = {(a.x + c.x)/2, (a.y + c.y)/2, (a.z + c.z)/2};

        d = normalise(d);
        e = normalise(e);
        f = normalise(f);

        double rayon = norme(a);

        d = produit(d, rayon);
        e = produit(e, rayon);
        f = produit(f, rayon);

        dessine_triangle_rec(a, d, f, profondeur -1);
        dessine_triangle_rec(d, b, e, profondeur -1);
        dessine_triangle_rec(f, e, c, profondeur -1);
        dessine_triangle_rec(f, d, e, profondeur -1);
    }
}

#define X 1.0
#define Z 1.618
vecteur sommets[12] = {{-X, 0, Z}, {X, 0, Z}, {-X, 0, -Z}, {X, 0, -Z}, {0, Z, X}, {0, Z, -X}, {0, -Z, X}, {0, -Z, -X}, {Z, X, 0}, {-Z, X, 0}, {Z, -X, 0}, {-Z, -X, 0}};
int sindex[20][3] = {{0, 4, 1}, {0, 9, 4}, {9, 5, 4}, {4, 5, 8}, {4, 8, 1}, {8, 10, 1}, {8, 3, 10}, {5, 3, 8}, {5, 2, 3}, {2, 7, 3}, {7, 10, 3}, {7, 6, 10}, {7, 11, 6}, {11, 0, 6}, {0, 1, 6}, {6, 1, 10}, {9, 0, 11}, {9, 11, 2}, {9, 2, 5}, {7, 2, 11}};

void construire_geode(int profondeur) {
    int i;
    GEODE = glGenLists(1);
    glNewList(GEODE, GL_COMPILE);

    glBegin(GL_TRIANGLES);
    for (i = 0; i < 20; i++) {
        dessine_triangle_rec(sommets[sindex[i][0]], sommets[sindex[i][1]], sommets[sindex[i][2]], profondeur);
    }
    glEnd();
    glEndList();
}
