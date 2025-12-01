#include "monte.h"
#include <stdint.h>
#include <string.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

// SplitMix64 for default
static inline uint64_t splitmix64(uint64_t *state) {
    uint64_t z = (*state += 0x9E3779B97F4A7C15ULL);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}

// SEED_PCG simple version
static inline uint64_t pcg64(uint64_t *state) {
    uint64_t x = *state;
    *state = x * 6364136223846793005ULL + 1;
    uint64_t r = ((x >> 18u) ^ x) >> 27u;
    return r;
}

// SEED_LCG (Linear Congruential Generator)
static inline uint64_t lcg64(uint64_t *state) {
    *state = 6364136223846793005ULL * (*state) + 1;
    return *state;
}

// SEED_FIBONACCI
static inline uint64_t fibonacci_mod64(uint64_t *state) {
    uint64_t s = *state;
    uint64_t next = (s + (s >> 1) + 1) & 0xFFFFFFFFFFFFFFFFULL;
    *state = next;
    return next;
}

// SEED_PRIMEJUMP
static inline uint64_t prime_jump(uint64_t *state) {
    *state += 0x9E3779B97F4A7C15ULL; // jump by golden prime
    return *state;
}

// SEED_LEHMER
static inline uint64_t lehmer64(uint64_t *state) {
    *state = (*state * 48271ULL) % 0x7fffffff;
    return *state;
}

// SEED_WEYL
static inline uint64_t weyl(uint64_t *state) {
    *state += 0x61c8864680b583ebULL;
    return *state;
}

// SEED_GOLDENHASH
static inline uint64_t golden_hash(uint64_t *state) {
    uint64_t z = *state;
    z ^= 0x9e3779b97f4a7c15ULL;
    z *= 0xbf58476d1ce4e5b9ULL;
    *state = z;
    return z;
}

// SEED_SHA256 using OpenSSL
static inline uint64_t sha256_seed(const char *gameName, const char *dateStr, uint64_t iterationIndex) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "%s%s%llu", gameName ? gameName : "", dateStr ? dateStr : "", (unsigned long long)iterationIndex);
    SHA256((unsigned char*)buffer, strlen(buffer), hash);
    uint64_t r;
    memcpy(&r, hash, sizeof(r)); // first 8 bytes
    return r;
}

// SEED_KEPLER_CONSTANT stub
static inline uint64_t kepler_constant(uint64_t *state) {
    *state += 0x9E3779B97F4A7C15ULL; // placeholder
    return *state;
}

// run_monte_c main function
void run_monte_c(uint64_t iterations,
                 int numbersRange,
                 int pickK,
                 uint64_t base,
                 int seedMode,
                 const char *gameName,
                 const char *dateStr,
                 uint64_t iterationIndex,
                 uint64_t *outCounts)
{
    if (!outCounts || numbersRange <= 0 || pickK <= 0 || pickK > numbersRange) return;

    uint64_t state = base;

    // zero output counts
    for (int i = 0; i < numbersRange; i++) outCounts[i] = 0;

    for (uint64_t i = 0; i < iterations; i++) {
        uint64_t r = 0;
        switch(seedMode) {
            case SEED_LCG: r = lcg64(&state); break;
            case SEED_FIBONACCI: r = fibonacci_mod64(&state); break;
            case SEED_PRIMEJUMP: r = prime_jump(&state); break;
            case SEED_LEHMER: r = lehmer64(&state); break;
            case SEED_PCG: r = pcg64(&state); break;
            case SEED_WEYL: r = weyl(&state); break;
            case SEED_GOLDENHASH: r = golden_hash(&state); break;
            case SEED_SHA256: r = sha256_seed(gameName, dateStr, iterationIndex + i); break;
            case SEED_KEPLER_CONSTANT: r = kepler_constant(&state); break;
            default: r = splitmix64(&state); break;
        }

        // pickK numbers from numbersRange
        for (int k = 0; k < pickK; k++) {
            int idx = r % numbersRange;
            outCounts[idx]++;
            r = r >> 8; // simple scrambling for next pick
        }
    }
}
