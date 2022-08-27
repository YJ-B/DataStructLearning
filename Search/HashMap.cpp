//
// Created by 鲍伟 on 2022/8/26.
// 哈希表（散列表）
//
#define SIZE 9

typedef struct Element {
    int key;
} * element;

typedef struct HashTable {
    element * table;
} * HTable;

void initHashTable(HTable hashTable) {
    hashTable->table = (element *)malloc(sizeof(struct Element) * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        hashTable->table[i] = nullptr;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertHashTable(HTable hashTable, element element) {
    int hashCode = hashFunction(element->key);
    hashTable->table[hashCode] = element;
}

bool findHashTable(HTable hashTable, int key) {
    int hashCode = hashFunction(key);
    if (!hashTable->table[hashCode]) return false;
    return hashTable->table[hashCode]->key == key;
}

element createHashNode(int key) {
    auto ele = (element) malloc(sizeof(struct Element));
    ele->key = key;
    return ele;
}

void testForHashMap() {
    struct HashTable table {};
    initHashTable(&table);

    insertHashTable(&table, createHashNode(10));
    insertHashTable(&table, createHashNode(7));
    insertHashTable(&table, createHashNode(13));
    insertHashTable(&table, createHashNode(29));

    printf("%d\n", findHashTable(&table, 1));
    printf("%d\n", findHashTable(&table, 13));
}
