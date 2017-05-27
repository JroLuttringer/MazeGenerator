#ifndef GRAPH_H
#define GRAPH_H

/** \struct fenetre
 * structure virtuelle vide (aucun accès direct à cette structure)
 */

/** \memberof fenetre
 *  ouvre une fenêtre de taille larg x haut pixels
 * \return -
 * \param [in] larg
 * \param [in] haut
 */
void initgraph(int larg, int haut);

/** \memberof fenetre
 * ferme la fenêtre
 * \return -
 * \param -
 */
void closegraph(void);

/** \memberof fenetre
 * force l'affichage (bufferisé sinon)
 * \return -
 * \param -
 * 
 */
void flushgraph(void);

/** \memberof fenetre
 * crée un nouvel identifiant de couleur : R,V,B \in [0.0, 1.0] 
 * \return un identifiant de couleur
 * \param [in] rouge composante rouge, réel entre 0 et 1.
 * \param [in] vert composante verte, réel entre 0 et 1.
 * \param [in] bleu composante bleue, réel entre 0 et 1.
 * 
 */
unsigned long newcolor(float rouge, float vert, float bleu);

/** \memberof fenetre
 * change la couleur de tout ce qui est affiché en la couleur (identifiant)
 * \return -
 * \param [in] fgcolor un identifiant de couleur, retourné par la fonction \b newcolor
 */
void setcolor(unsigned long fgcolor);

/** \memberof fenetre
 * efface la fenêtre
 * \return -
 * \param -
 */
void cleargraph(void);

/** \memberof fenetre
 * trace un point dans la fenêtre, aux coordonnées (x,y).
 * \return -
 * \param [in] x coordonnée x (entre 0 et \a larg - 1)
 * \param [in] y coordonnée y (entre 0 et \a haut - 1)
 */
void putpixel(int x, int y);

/** \memberof fenetre
 * trace un segment de droite
 * \return -
 * \param [in] x1 coordonnée x de l'origine de la droite
 * \param [in] y1 coordonnée y de l'origine de la droite
 * \param [in] x2 coordonnée x de l'extrémité de la droite
 * \param [in] y2 coordonnée y de l'extrémité de la droite
 */
void line(int x1, int y1, int x2, int y2);

/** \memberof fenetre
 * rafraichit la fenêtre
 * \return -
 * \param -
 */
void refresh(void);

/** \memberof fenetre
 * attend que l'utilisateur appuie sur une touche
 * \return -
 * \param -
 */
void waitgraph(void);

#endif /* ! GRAPH_H */
