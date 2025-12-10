#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

const int ARRAY_SIZE = 10;

typedef struct {
  char state; // F = free, O = occupied, R = Removed
  int value;
} hash_table_row;

struct hash_table {
  hash_table_row *rows;
};

Hash_Table *hash_table_create() {
  Hash_Table *new_hash_table = (Hash_Table *)malloc(sizeof(Hash_Table));
  new_hash_table->rows =
      (hash_table_row *)malloc(ARRAY_SIZE * sizeof(hash_table_row));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    new_hash_table->rows[i].state = 'F';
    new_hash_table->rows[i].value = -1;
  }
  return new_hash_table;
}

void hash_table_print(Hash_Table *hash_table) {
  printf("|I\t|S\t|V\t|\n"); // Index | State | Value
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("|%i\t|%c\t|%i\t|\n", i, hash_table->rows[i].state,
           hash_table->rows[i].value);
  }
  printf("\n\n");
}

void hash_table_insert(Hash_Table *hash_table, int value) {
  int h = value % ARRAY_SIZE;
  int removido = -1;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    int idx = (h + i * i) % ARRAY_SIZE;
    char state = hash_table->rows[idx].state;

    if (state == 'O') {
      if (hash_table->rows[idx].value == value) {
        return; 
      }
    } 
    else if (state == 'R') {
      if (removido == -1) {
        removido = idx; 
      }
    } 
    else if (state == 'F') {
      if (removido != -1) {
        hash_table->rows[removido].state = 'O';
        hash_table->rows[removido].value = value;
      } else {
        hash_table->rows[idx].state = 'O';
        hash_table->rows[idx].value = value;
      }
      return; 
    }
  }
}

void hash_table_remove(Hash_Table *hash_table, int value) {
  int h = value % ARRAY_SIZE;

  for (int i = 0; i <ARRAY_SIZE; i++) {
    int idx = (h + i*i) % ARRAY_SIZE;
    char state = hash_table->rows[idx].state;

    if (state =='F') {
      return;
    } else if (state == 'O') {
      if (hash_table->rows[idx].value == value){
      hash_table->rows[idx].state = 'R';
      hash_table->rows[idx].value = -1;
      return;
      }
    } else if (state =='R'){
      continue;
    } 
  }
}

int hash_table_search(Hash_Table *hash_table, int value) {
  int h = value % ARRAY_SIZE;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    int idx = (h + i*i) % ARRAY_SIZE;
    char state = hash_table->rows[idx].state;

    if (state == 'F') {
      return -1;
    } else if (state == 'O') {
      if (hash_table->rows[idx].value == value) {
        return idx;
      } else {
        continue;
      }
    } else if (state == 'R') {
      continue;
    }
  }
  return -1;
}