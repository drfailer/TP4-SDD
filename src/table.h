#ifndef __TABLE__
#define __TABLE__

/* STRUCTURES: */

typedef struct lien
{
  int j;
  int val;
  struct lien * suiv;
} lien_t;

typedef struct
{
  int i;
  lien_t * tete;
} couple_t;

typedef struct
{
  int taille;
  couple_t * maj;
} table_t;

/* FONCTION: */

table_t * creerTable();
void freeTable(table_t **);
table_t * ajoutTable(table_t *, int, int, int);
int valeurTable(table_t *, int, int);
void afficheTable(table_t * table);

#endif
