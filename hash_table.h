typedef struct hash_table Hash_Table;

Hash_Table *hash_table_create();
void hash_table_print(Hash_Table *hash_table);
void hash_table_insert(Hash_Table *hash_table, int value);
void hash_table_remove(Hash_Table *hash_table, int value);
int hash_table_search(Hash_Table *hash_table, int value);