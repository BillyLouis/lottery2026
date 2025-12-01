package sim

/*
#cgo CFLAGS: -O3 -march=native -I${SRCDIR}/eigen_samples/Eigen
#cgo LDFLAGS: -lcrypto
#include <stdlib.h>
#include <stdint.h>
#include "monte.h"
#include "eigenpredictor.h"
*/
import "C"
import (
	"unsafe"
)

// RunMonteC wraps the C Monte Carlo engine
func RunMonteC(iterations, numbersRange, pickK int, base uint64, seedMode int, gameName, dateStr string, iterationIndex uint64) []uint64 {
	if numbersRange <= 0 || pickK <= 0 || pickK > numbersRange {
		return nil
	}

	out := make([]C.uint64_t, numbersRange)

	cGame := C.CString(gameName)
	cDate := C.CString(dateStr)
	defer C.free(unsafe.Pointer(cGame))
	defer C.free(unsafe.Pointer(cDate))

	C.run_monte_c(
		C.uint64_t(iterations),
		C.int(numbersRange),
		C.int(pickK),
		C.uint64_t(base),
		C.int(seedMode),
		cGame,
		cDate,
		C.uint64_t(iterationIndex),
		(*C.uint64_t)(unsafe.Pointer(&out[0])),
	)

	res := make([]uint64, numbersRange)
	for i := 0; i < numbersRange; i++ {
		res[i] = uint64(out[i])
	}

	return res
}

// // RunPredictor wraps the C++ predictor function
// func RunPredictor() {
// 	C.run_predictor()
// }
