#include "hash_table.h"
#include <stdio.h>

int main(void) {
  Hash_Table *hash_table = hash_table_create();
  hash_table_insert(hash_table, 16);
  hash_table_insert(hash_table, 12);
  hash_table_insert(hash_table, 25);
  hash_table_insert(hash_table, 39);
  hash_table_insert(hash_table, 6);
  hash_table_insert(hash_table, 5);
  hash_table_insert(hash_table, 68);
  hash_table_insert(hash_table, 75);

  hash_table_print(hash_table);
  // Valor esperado:
  // |I  |S  |V  |
  // |0  |F  |-1 |
  // |1  |O  |75 |
  // |2  |O  |12 |
  // |3  |F  |-1 |
  // |4  |O  |5  |
  // |5  |O  |25 |
  // |6  |O  |16 |
  // |7  |O  |6  |
  // |8  |O  |68 |
  // |9  |O  |39 |

  hash_table_remove(hash_table, 39);
  hash_table_remove(hash_table, 5);
  hash_table_remove(hash_table, 6);
  hash_table_remove(hash_table, 94);
  hash_table_insert(hash_table, 45);

  hash_table_print(hash_table);
  // Valor esperado:
  // |I  |S  |V  |
  // |0  |F  |-1 |
  // |1  |O  |75 |
  // |2  |O  |12 |
  // |3  |F  |-1 |
  // |4  |R  |5  |
  // |5  |O  |25 |
  // |6  |O  |16 |
  // |7  |R  |6  |
  // |8  |O  |68 |
  // |9  |O  |45 |

  // Valor esperado: "Valor 75 com Index 1"
  printf("Valor %i com Index %i", 75, hash_table_search(hash_table, 75));

  // Valor esperado: "Valor 16 com Index 6"
  printf("Valor %i com Index %i", 16, hash_table_search(hash_table, 16));

  // Valor esperado: "Valor 6 com Index -1"
  printf("Valor %i com Index %i", 6, hash_table_search(hash_table, 6));

  // Valor esperado: "Valor 94 com Index -1"
  printf("Valor %i com Index %i", 94, hash_table_search(hash_table, 94));
}
