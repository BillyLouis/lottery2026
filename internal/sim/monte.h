// Run Monte Carlo simulation.
//
// iterations: number of simulated draws (e.g., 1000000) numbersRange: maximum number in pool (e.g. 39 for Fantasy5; 69 for Powerball white)
//  pickK: how many numbers are drawn per draw (usually 5)
//  base: deterministic base value used by most seed generators (client-specified)
//  seedMode: one of SeedMode enum values
//  gameName: (utf-8 c-string) used by SHA256 seed mode: e.g. "fantasy5" or "powerball"
//  dateStr: (utf-8 c-string) used by SHA256 seed mode: e.g. "2026-04-13" or any string
//  iterationIndex: (uint64 value) used by SHA256 seed mode (iteration number) and as auxiliary
//  outCounts: caller-allocated uint64_t array of length numbersRange (counts will be incremented)
//
//  Behavior:
//  - Deterministic: given same inputs (base, seedMode, gameName, dateStr, iterationIndex),
//    run_monte_c produces identical outCounts.
//  - Thread-parallel: internal implementation shards iterations across worker threads and
//    aggregates per-thread local counts into outCounts at the end.
//  - For seed modes other than SHA256, gameName/dateStr may be ignored.
//============================================================================================
#ifndef MONTE_H
#define MONTE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Seed selection modes (keep in sync with Go mapping)
typedef enum {
    SEED_LCG = 0, // Linear Congruential (LCG-derived)
    SEED_FIBONACCI = 1, // Fibonacci Mod 2^64 
    SEED_PRIMEJUMP = 2,// Prime Jump Seed
    SEED_LEHMER = 3, // Lehmer multiplicative (Park-Miller variant)
    SEED_PCG = 4, // PCG initializer: simple mix
    SEED_WEYL = 5, // Weyl sequence
    SEED_GOLDENHASH = 6, // Golden Ratio Hash
    SEED_SHA256 = 7,
    SEED_KEPLER_CONSTANT = 8 // To Be Added
} SeedMode;

void run_monte_c(uint64_t iterations,
                 int numbersRange,
                 int pickK,
                 uint64_t base,
                 int seedMode,
                 const char *gameName,
                 const char *dateStr,
                 uint64_t iterationIndex,
                 uint64_t *outCounts);

#ifdef __cplusplus
}
#endif

#endif // MONTE_H
