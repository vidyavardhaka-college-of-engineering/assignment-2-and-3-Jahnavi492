#include <stdio.h>

#define TABLE_SIZE 11

int hash(int key) {
    return key % TABLE_SIZE;
}

int reverse(int key) {
    int reversed = 0;
    while (key > 0) {
        reversed = reversed * 10 + key % 10;
        key /= 10;
    }
    return reversed;
}

void insert(int key, int table[]) {
    int home_slot = hash(key);
    int probe = reverse(key);
    int slot = (home_slot + probe) % TABLE_SIZE;

    while (table[slot]!= 0) {
        probe = (probe + 1) % TABLE_SIZE;
        slot = (home_slot + probe) % TABLE_SIZE;
    }

    table[slot] = key;
    printf("Key %d: Home Slot %d, Probe Sequence: ", key, home_slot);
    if (probe!= 0) {
        printf("%d", probe);
        int next_probe = (probe + 1) % TABLE_SIZE;
        while (next_probe!= probe) {
            printf(", %d", next_probe);
            next_probe = (next_probe + 1) % TABLE_SIZE;
        }
    }
    printf("\n");
}

void print_table(int table[]) {
    printf("Final Hash Table:\n");
    printf("Slot 0 1 2 3 4 5 6 7 8 9 10\n");
    printf("Contents ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main() {
    int table[TABLE_SIZE] = {0};

    insert(43, table);
    insert(23, table);
    insert(1, table);
    insert(0, table);
    insert(15, table);
    insert(31, table);
    insert(4, table);
    insert(7, table);
    insert(11, table);
    insert(3, table);

    print_table(table);

    return 0;
}

