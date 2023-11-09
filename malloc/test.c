#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mm.h"
#include "memlib.h"

#define NUM_BLOCKS 3  // Number of blocks to allocate

int main() {
    // Initialize memory manager
    mm_init();

    void *blocks[NUM_BLOCKS];

    // allocate some blocks
    for (int i = 0; i < NUM_BLOCKS; i++) {
        size_t block_size = rand() % 128;  // Random block size (0 to 127 bytes)
        blocks[i] = mm_malloc(block_size);
        if (blocks[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for block %d\n", i);
            return 1;
        }
        printf("Allocated block %d of size %lu bytes\n", i, (unsigned long)block_size);
    }

    // free blocks
    for (int i = 0; i < NUM_BLOCKS; i++) {
        int random_index = rand() % NUM_BLOCKS;  // Randomly choose a block to free
        mm_free(blocks[random_index]);
        printf("Freed block %d\n", random_index);
    }

    return 0;
}
