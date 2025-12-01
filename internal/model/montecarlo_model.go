package model

import (
	"sort"

	"github.com/BillyLouis/lottery2026/internal/features"
	"github.com/BillyLouis/lottery2026/internal/sim"
)

type MonteCarloModel struct {
	f        *features.Features
	sim      *sim.Simulator
	SeedMode int
}

func NewMonteCarloModel(f *features.Features, s *sim.Simulator, seed int) *MonteCarloModel {
	return &MonteCarloModel{f: f, sim: s, SeedMode: seed}
}

func (m *MonteCarloModel) Name() string { return "montecarlo" }

func (m *MonteCarloModel) Predict() []int {
	iter := 200000
	pickK := m.f.PickK()
	counts := m.sim.RunMonteWithSeed(iter, m.f.NumbersRange, pickK, m.SeedMode)

	type kv struct {
		n int
		c uint64
	}
	var arr []kv
	for i, c := range counts {
		arr = append(arr, kv{n: i + 1, c: c})
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
