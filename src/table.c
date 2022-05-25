#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#define MAX 100


/* Création et initialisation d'un nouveau lien pour les sous listes */
lien_t * creerLien(int j, int val)
{
  lien_t * nouv = (lien_t*) malloc(sizeof(lien_t));

  if (nouv) {
    nouv->j = j;
    nouv->val = val;
    nouv->suiv = NULL;
  }
  else {
    fprintf(stderr, "Erreur: allocation lien.\n");
  }
  return nouv;
}

/* Allocation d'une nouvelle table */
table_t * creerTable()
{
  table_t * nouv = (table_t*) malloc(sizeof(table_t));

  if (nouv) {
    nouv->taille = 0;
    nouv->maj = malloc(MAX*sizeof(couple_t));
  }
  else {
    fprintf(stderr, "Erreur: allocation table.\n");
  }
  return nouv;
}

/* Libération des sous listes */
void freelst(lien_t ** lst)
{
  lien_t * cour = NULL;
  lien_t * suiv = NULL;

  if (lst) {
    cour = *lst;
    while (cour) {
      suiv = cour->suiv;
      free(cour);
      cour = suiv;
    }
    *lst = NULL;
  }
}

/* Libération d'une table */
void freeTable(table_t ** table)
{
  int i;
  couple_t * maj = (*table)->maj;

  if (table) {
    for (i = 0; i < (*table)->taille; ++i) {
      if (maj[i].tete) {
	freelst(&(maj[i].tete));
      }
    }
    free(*table);
    *table = NULL;
  }
}

int rechercheDicho(table_t * table, int i)
{
  int a = 0;
  int b = table->taille;
  int mid;
  couple_t * maj = table->maj;

  while (a < b) {
    mid = (a + b) / 2;
    if (i <= maj[mid].i) {
      b = mid;
    }
    else {
      a = mid + 1;
    }
  }

  return a;
}

/* Décalage des valeurs dans le tableau maj */
void decaleDroite(table_t * table, int a)
{
  int i;
  couple_t * maj = table->maj;

  for (i = table->taille - 1; i >= a; --i) {
    maj[i+1].tete = maj[i].tete;
    maj[i+1].i = maj[i].i;
  }
}

lien_t * ajoutListe(lien_t * lst, lien_t * nouv) {
  lien_t ** prec = &lst;

  // recherche du precedent
  while (*prec && (*prec)->j <= nouv->j) {
    prec = &(*prec)->suiv;
  }
  // test si la valeur existe déjà
  if (*prec && (*prec)->j == nouv->j) {
    fprintf(stderr, "Erreur: la valeur existe déjà");
  }
  else {
    nouv->suiv = *prec;
    *prec = nouv;
  }

  return lst;
}

table_t * ajoutTable(table_t * table, int i, int j, int v)
{
  int k = rechercheDicho(table, i);
  lien_t * nouv = creerLien(j, v);

  if (nouv) {
    if (table->taille > 0 && table->maj[k].i == i) {
      // ajout dans la liste
      table->maj[k].tete = ajoutListe(table->maj[k].tete, nouv);
    }
    else {
      decaleDroite(table, k);
      table->maj[k].tete = nouv;
      table->maj[k].i = i;
      table->taille++;
    }
  }
  else {
    fprintf(stderr, "Erreur: création du lien.\n");
    free(nouv);
  }
  
  return table;
}

int valeurTable(table_t * table, int i, int j)
{
  couple_t * maj = table->maj;
  int k = rechercheDicho(table, i);
  lien_t * lst = NULL;
  int r = -1;

  if (maj[k].i == i) {
    lst = maj[k].tete;
    while (lst && lst->j != j) {
      lst = lst->suiv;
    }
    if (lst) {
      r = lst->val;
    }
    else {
      fprintf(stderr, "Erreur: la valeur n'est pas dans la table.\n");
    }
  }
  else {
    fprintf(stderr, "Erreur: la valeur n'est pas dans la table.\n");
  }

  return r;
}

/* Affiche `table` */
void afficheTable(table_t * table)
{
  int i;
  lien_t * cour;

  for (i = 0; i < table->taille; ++i) {
    printf("i: %d -> ", table->maj[i].i);
    cour = table->maj[i].tete;
    while (cour) {
      printf("[%d: %d] -> ", cour->j, cour->val);
      cour = cour->suiv;
    }
    printf(" [ ]\n\n");
  }
}
