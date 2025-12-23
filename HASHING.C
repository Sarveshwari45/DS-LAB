#include <stdio.h>
#define M 100

typedef struct {
    int key;
    int used;
} record;

int hash(int k) {
    return k % M;
}

int insert(record ht[], int k) {
    int i = hash(k);
    int start = i;
    while (ht[i].used) {
        if (ht[i].key == k) {
            return i;
        }
        i = (i + 1) % M;
        if (i == start) {
            return -1;
        }
    }
    ht[i].key = k;
    ht[i].used = 1;
    return i;
}

int search(record ht[], int k) {
    int i = hash(k);
    int start = i;
    while (ht[i].used) {
        if (ht[i].key == k) {
            return i;
        }
        i = (i + 1) % M;
        if (i == start) {
            break;
        }
    }
    return -1;
}

int main() {
    record ht[M];
    int n, k, i, pos, choice;
    for (i = 0; i < M; i++) {
        ht[i].used = 0;
    }
    printf("Enter number of employee records: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the 4-digit key: ");
        scanf("%d", &k);
        pos = insert(ht, k);
        if (pos == -1) {
            printf("Hash table full, cannot insert %d\n", k);
        }
    }
    do {
        printf("Enter the key to search: ");
        scanf("%d", &k);
        pos = search(ht, k);
        if (pos == -1) {
            printf("Key not found\n");
        } else {
            printf("Key found at address %02d\n", pos);
        }
        printf("Search another key? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);
    return 0;
}
