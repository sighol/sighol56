#include <stdio.h>
#include <stdint.h>


// Static counter and seed for generating UUID
static uint32_t seed = 0;

// Simple pseudo-random number generator
static uint32_t rand32(void) {
    seed ^= timer_read32();
    seed = seed * 1664525 + 1013904223; // Linear Congruential Generator
    return seed;
}

// Function to generate a UUID-like string
void generate_uuid(char *buffer, size_t buffer_size) {
    if (buffer_size < 37) {
        // Buffer must be large enough for UUID string plus null terminator
        return;
    }

    // Generate pseudo-random values
    uint32_t rand1 = rand32();
    uint32_t rand2 = rand32();
    uint32_t rand3 = rand32();
    uint32_t rand4 = rand32();
    uint32_t rand5 = rand32();

    // Format the UUID string
    snprintf(buffer, buffer_size,
             "%08lx-%04lx-%04lx-%04lx-%04lx%08lx",
             rand1,
             ((rand2 >> 16) & 0xFFFF),
             (rand2 & 0xFFFF),
             (rand3 & 0xFFFF),
             ((rand4 >> 16) & 0xFFFF),
             rand5);
}
