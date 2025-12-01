// (simplified positional/sequence predictor — that can be expand)
package model

import (
	"sort"

	"github.com/BillyLouis/lottery2026/internal/features"
)

type MarkovModel struct {
	f *features.Features
}

func NewMarkovModel(f *features.Features) *MarkovModel {
	return &MarkovModel{f: f}
}

func (m *MarkovModel) Name() string { return "markov" }

func (m *MarkovModel) Predict() []int {
	// simplistic: aggregate top per position
	type kv struct {
		n int
		s uint64
	}
	score := make(map[int]uint64)
	for pos := range m.f.Positional {
		for num, cnt := range m.f.Positional[pos] {
			score[num] += cnt
		}
	}
	// convert to slice
	type pair struct {
		n int
		c uint64
	}
	var arr []pair
	for n, c := range score {
		arr = append(arr, pair{n, c})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].c > arr[j].c })
	limit := 10
	if len(arr) < limit {
		limit = len(arr)
	}
	out := make([]int, 0, limit)
	for i := 0; i < limit; i++ {
		out = append(out, arr[i].n)
	}
	return out
}
func (m *MarkovModel) PredictAll() []int { //-- Additionals by agent
	// simplistic: aggregate top per position
	type kv struct {
		n int
		s uint64
	}
	score := make(map[int]uint64)
	for pos := range m.f.Positional {
		for num, cnt := range m.f.Positional[pos] {
			score[num] += cnt
		}
	}
	// convert to slice
	type pair struct {
		n int
		c uint64
	}
	var arr []pair
	for n, c := range score {
		arr = append(arr, pair{n, c})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].c > arr[j].c })
	out := make([]int, 0, len(arr))
	for i := 0; i < len(arr); i++ {
		out = append(out, arr[i].n)
	}
	return out
}
