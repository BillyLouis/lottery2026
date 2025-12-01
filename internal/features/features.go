package features

import "github.com/BillyLouis/lottery2026/internal/data"

// Features holds extracted summary stats
type Features struct {
	Frequency    map[int]uint64
	Positional   map[int]map[int]uint64
	NumbersRange int
	TotalDraws   int
}

// PickK returns expected pick count based on positional map or default 5
func (f *Features) PickK() int {
	if len(f.Positional) > 0 {
		// assume positional map keys are 0..k-1
		for k := range f.Positional {
			_ = k
			// we'll assume 5 by default; this can be extended
			break
		}
	}
	return 5
}

func ExtractAll(draws []data.Draw) *Features {
	f := &Features{
		Frequency:    make(map[int]uint64),
		Positional:   make(map[int]map[int]uint64),
		NumbersRange: 0,
		TotalDraws:   len(draws),
	}
	for _, d := range draws {
		for pos, b := range d.Balls {
			f.Frequency[b]++
			if f.Positional[pos] == nil {
				f.Positional[pos] = make(map[int]uint64)
			}
			f.Positional[pos][b]++
			if b > f.NumbersRange {
				f.NumbersRange = b
			}
		}
	}
	return f
}
func ExtractFrequency(draws []data.Draw) *Features {
	f := &Features{
		Frequency:    make(map[int]uint64),
		Positional:   make(map[int]map[int]uint64),
		NumbersRange: 0,
		TotalDraws:   len(draws),
	}
	for _, d := range draws {
		for _, b := range d.Balls {
			f.Frequency[b]++
			if b > f.NumbersRange {
				f.NumbersRange = b
			}
		}
	}
	return f
}
func ExtractPositional(draws []data.Draw) *Features {
	f := &Features{
		Frequency:    make(map[int]uint64),
		Positional:   make(map[int]map[int]uint64),
		NumbersRange: 0,
		TotalDraws:   len(draws),
	}
	for _, d := range draws {
		for pos, b := range d.Balls {
			if f.Positional[pos] == nil {
				f.Positional[pos] = make(map[int]uint64)
			}
			f.Positional[pos][b]++
			if b > f.NumbersRange {
				f.NumbersRange = b
			}
		}
	}
	return f
}
