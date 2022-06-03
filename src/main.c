#include <stdio.h>
#include "table.h"

int main(void)
{
  // table_t * tbl = creerTable();
  // ajout de valeurs:
  /* tbl = ajoutTable(tbl, 1, 1, 1); */
  /* tbl = ajoutTable(tbl, 1, 6, 2); */
  /* tbl = ajoutTable(tbl, 1, -1, 3); */
  /* tbl = ajoutTable(tbl, 5, 9, 4); */
  /* tbl = ajoutTable(tbl, 6, 2, 5); */
  /* tbl = ajoutTable(tbl, 3, 6, 6); */
  /* tbl = ajoutTable(tbl, 3, 3, 7); */
  /* tbl = ajoutTable(tbl, 3, 3, 8); */
  /* tbl = ajoutTable(tbl, 2, 1, 9); */
  /* tbl = ajoutTable(tbl, 2, -8, 0); */
  table_t * tbl = tableDepuisFichier("fic_table.txt");

  // test affichage
  afficheTable(tbl);

  // test acces
  printf("tbl[1,6] = %d\n", valeurTable(tbl, 1, 6));
  printf("tbl[2,1] = %d\n", valeurTable(tbl, 2, 1));

  // libération
  freeTable(&tbl);
  return 0;
}
