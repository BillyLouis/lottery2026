package model

import (
	"sort"

	"github.com/BillyLouis/lottery2026/internal/features"
)

type FrequencyModel struct {
	f *features.Features
}

func NewFrequencyModel(f *features.Features) *FrequencyModel {
	return &FrequencyModel{f: f}
}

func (m *FrequencyModel) Name() string { return "frequency" }

func (m *FrequencyModel) Predict() []int {
	type kv struct{ n, c int }
	var arr []kv
	for n, c := range m.f.Frequency {
		arr = append(arr, kv{n, int(c)})
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
func (m *FrequencyModel) PredictAll() []int { //-- Additionals by agent
	type kv struct{ n, c int }
	var arr []kv
	for n, c := range m.f.Frequency {
		arr = append(arr, kv{n, int(c)})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].c > arr[j].c })
	out := make([]int, 0, len(arr))
	for i := 0; i < len(arr); i++ {
		out = append(out, arr[i].n)
	}
	return out
}
