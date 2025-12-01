// package sim

// // sim_wrapper.go
// // Thin Go wrapper around the cgo Monte Carlo function (RunMonteC).
// // Provides a Simulator struct with convenient methods for calling the C engine.

// type Simulator struct{}

// // NewSimulator returns a ready-to-use Simulator instance.
// func NewSimulator() *Simulator { return &Simulator{} }

// // RunMonte runs the Monte Carlo engine with explicit parameters.
// // - iterations: number of simulated draws
// // - numbersRange: highest number in the pool (e.g., 39 for Fantasy5)
// // - pickK: how many numbers drawn per simulated draw (e.g., 5)
// // - base: deterministic base seed (uint64) used by the C seed generators
// // - seedMode: corresponds to the SeedMode enum in monte.h (as int)
// // - gameName: string (e.g., "fantasy5" or "powerball") — used by SHA256 seed mode
// // - dateStr: string used by SHA256 seed mode (e.g., "2026-04-13")
// // - iterIndex: auxiliary uint64 used for deterministic variation (commonly the predict offset)
// func (s *Simulator) RunMonte(iterations int, numbersRange int, pickK int, base uint64, seedMode int, gameName string, dateStr string, iterIndex uint64) []uint64 {
// 	return RunMonteC(iterations, numbersRange, pickK, base, seedMode, gameName, dateStr, iterIndex)
// }

// // RunMonteSimple is a convenience wrapper using defaults for base/seedMode/iterIndex.
// // It uses the provided baseSeed and seedMode if you want deterministic runs but don't need
// // the full param set every time.
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
package sim

/*
#cgo CFLAGS: -O3 -march=native
#include "monte.h"
*/
import "C"
import "unsafe"

// Simulator wrapper
type Simulator struct{}

// NewSimulator returns a ready-to-use Simulator
func NewSimulator() *Simulator { return &Simulator{} }

// RunMonte default for backward compatibility (SEED_PCG)
func (s *Simulator) RunMonte(iterations, numbersRange, pickK int) []uint64 {
	return s.RunMonteWithSeed(iterations, numbersRange, pickK, SEED_PCG)
}

// RunMonteWithSeed allows passing seed dynamically
func (s *Simulator) RunMonteWithSeed(iterations, numbersRange, pickK int, seedMode int) []uint64 {
	out := make([]C.uint64_t, numbersRange)
	C.run_monte_c(
		C.uint64_t(iterations),
		C.int(numbersRange),
		C.int(pickK),
		C.uint64_t(42), // base seed
		C.int(seedMode),
		nil, // gameName
		nil, // dateStr
		C.uint64_t(0),
		(*C.uint64_t)(unsafe.Pointer(&out[0])),
	)
	res := make([]uint64, numbersRange)
	for i := 0; i < numbersRange; i++ {
		res[i] = uint64(out[i])
	}
	return res
}

// Enum mapping
const (
	SEED_LCG          = 0
	SEED_FIBONACCI    = 1
	SEED_PRIMEJUMP    = 2
	SEED_LEHMER       = 3
	SEED_PCG          = 4
	SEED_WEYL         = 5
	SEED_GOLDENHASH   = 6
	SEED_SHA256       = 7
	SEED_KEPLER_CONST = 8
)

// // Add to the existing Simulator type
// func (s *Simulator) RunPredictor() {
// 	RunPredictor()
// }
